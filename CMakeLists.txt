cmake_minimum_required(VERSION 3.27.0)

project(awl)

include(GNUInstallDirs)

include(CMakeParseArguments)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(fcppt REQUIRED)

set(FCPPT_UTILS_CLANG_TIDY_WHITELIST "fcppt" "awl")

list(APPEND FCPPT_UTILS_CLANG_TIDY_ADDITIONAL_CHECKS
     "-cppcoreguidelines-avoid-const-or-ref-data-members")

include(FcpptCMakeUtils)

set(CMAKE_MODULES_SOURCE_DIR ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/cmake/modules)

set(CMAKE_MODULES_PUBLIC ${CMAKE_MODULES_SOURCE_DIR}/public)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_MODULES_PUBLIC}"
     "${CMAKE_MODULES_SOURCE_DIR}/private")

include(FcpptSymbol)

fcppt_utils_handle_so_version(AWL_SO_VERSION AWL_USED_SO_VERSION "0.1")

include(FindPkgConfig)

if(WIN32)
  set(AWL_WINDOWS_BACKEND TRUE)
elseif(UNIX)
  set(AWL_POSIX_BACKEND TRUE)

  pkg_check_modules(X11 IMPORTED_TARGET x11)

  option(ENABLE_X11 "Build the X11 backend" ${X11_FOUND})

  if(ENABLE_X11)
    set(AWL_X11_BACKEND TRUE)
  endif()

  pkg_check_modules(WAYLAND IMPORTED_TARGET wayland-client wayland-cursor)

  option(ENABLE_WAYLAND "Build the wayland backend" ${WAYLAND_FOUND})

  if(ENABLE_WAYLAND)
    set(AWL_WAYLAND_BACKEND TRUE)
  endif()

  if(NOT ENABLE_X11 AND NOT ENABLE_WAYLAND)
    message(FATAL_ERROR "Neither X11 nor Wayland is enabled.")
  endif()
else()
  message(FATAL_ERROR "This configuration is not supported!")
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  set(AWL_LINUX_BACKEND TRUE)
endif()

if(NOT DEFINED ENABLE_SDL)
  find_package(SDL2)
endif()

option(ENABLE_SDL "Enable the SDL2 backend" ${SDL2_FOUND})

if(ENABLE_SDL)
  find_package(SDL2 REQUIRED)

  find_library(SDL2_LIBRARY SDL2)

  set(AWL_SDL_BACKEND TRUE)
endif()

configure_file(${FCPPT_UTILS_PROJECT_SOURCE_DIR}/cmake/config.hpp.in
               ${FCPPT_UTILS_PROJECT_BINARY_DIR}/include/awl/config.hpp)

set(AWL_STATIC_LINK_FLAG AWL_STATIC_LINK)

fcppt_generate_symbol_header(STATIC_LINK_FLAG ${AWL_STATIC_LINK_FLAG}
                             EXPORTS_NAME awl SYMBOL_NAME AWL_DETAIL)

fcppt_utils_load_source_files(awl_base_files.txt AWL_BASE_FILES)
list(APPEND AWL_FILES ${AWL_BASE_FILES})

function(add_awl_backend BACKEND)
  set(option_args HAS_IMPL_DIR)
  cmake_parse_arguments("" "${option_args}" "" "" ${ARGN})

  set(BACKEND_DIR backends/${BACKEND})
  fcppt_utils_load_source_files(${BACKEND_DIR}/files.txt BACKEND_FILES)
  list(APPEND AWL_FILES ${BACKEND_FILES})

  set(BACKEND_INCLUDE_DIR ${BACKEND_DIR}/include)
  install(DIRECTORY ${BACKEND_INCLUDE_DIR}/
          DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
  list(APPEND AWL_INCLUDE_DIRS ${BACKEND_INCLUDE_DIR})

  if(${_HAS_IMPL_DIR})
    list(APPEND AWL_IMPL_INCLUDE_DIRS ${BACKEND_DIR}/impl/include)
  endif()

  set(AWL_FILES
      ${AWL_FILES}
      PARENT_SCOPE)
  set(AWL_INCLUDE_DIRS
      ${AWL_INCLUDE_DIRS}
      PARENT_SCOPE)
  set(AWL_IMPL_INCLUDE_DIRS
      ${AWL_IMPL_INCLUDE_DIRS}
      PARENT_SCOPE)
endfunction()

if(AWL_X11_BACKEND)
  add_awl_backend(x11 HAS_IMPL_DIR)
endif()

if(AWL_WAYLAND_BACKEND)
  add_awl_backend(wayland HAS_IMPL_DIR)
endif()

if(AWL_POSIX_BACKEND)
  add_awl_backend(posix)
endif()

if(AWL_LINUX_BACKEND)
  add_awl_backend(linux)
endif()

if(AWL_WINDOWS_BACKEND)
  add_awl_backend(windows)
endif()

if(AWL_SDL_BACKEND)
  add_awl_backend(sdl HAS_IMPL_DIR)
endif()

fcppt_utils_append_source_dir_and_make_groups("${AWL_FILES}" AWL_FILES_ABS)

fcppt_utils_static_shared()

fcppt_utils_link_target(awl)

function(make_awl_library TARGETNAME VARIANT)
  if(${VARIANT} STREQUAL INTERFACE)
    add_library(${TARGETNAME} ${VARIANT})
  else()
    add_library(${TARGETNAME} ${VARIANT} ${AWL_FILES_ABS})
  endif()

  if(NOT ${VARIANT} STREQUAL INTERFACE)
    set_target_properties(${TARGETNAME} PROPERTIES VERSION
                                                   ${AWL_USED_SO_VERSION})

    fcppt_utils_set_target_compiler_flags(${TARGETNAME})
  endif()

  fcppt_utils_interface_static_link(${TARGETNAME} ${VARIANT}
                                    ${AWL_STATIC_LINK_FLAG})

  foreach(CUR_DIR ${AWL_INCLUDE_DIRS})
    list(APPEND AWL_BUILD_INCLUDE_DIRS
         "$<BUILD_INTERFACE:${FCPPT_UTILS_PROJECT_SOURCE_DIR}/${CUR_DIR}>")
  endforeach()

  set(PUBLIC_INCLUDES
      "$<BUILD_INTERFACE:${FCPPT_UTILS_PROJECT_BINARY_DIR}/include>"
      "$<BUILD_INTERFACE:${FCPPT_UTILS_PROJECT_SOURCE_DIR}/include>"
      "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
      ${AWL_BUILD_INCLUDE_DIRS})

  target_include_directories(${TARGETNAME} INTERFACE ${PUBLIC_INCLUDES})

  target_link_libraries(${TARGETNAME} INTERFACE fcppt_core_interface
                                                fcppt_log_interface)

  if(AWL_WINDOWS_BACKEND)
    target_link_libraries(${TARGETNAME} INTERFACE fcppt_filesystem_interface)
  endif()

  if(NOT FCPPT_NARROW_STRING)
    set(WINDOWS_COMPILE_DEFINITIONS _UNICODE UNICODE)
  endif()

  if(NOT ${VARIANT} STREQUAL INTERFACE)
    set_target_properties(${TARGETNAME} PROPERTIES FOLDER awl)

    foreach(CUR_DIR ${AWL_IMPL_INCLUDE_DIRS})
      list(APPEND AWL_BUILD_IMPL_INCLUDE_DIRS
           "$<BUILD_INTERFACE:${FCPPT_UTILS_PROJECT_SOURCE_DIR}/${CUR_DIR}>")
    endforeach()

    set(PRIVATE_INCLUDES
        "$<BUILD_INTERFACE:${FCPPT_UTILS_PROJECT_SOURCE_DIR}/impl/include>"
        ${AWL_BUILD_IMPL_INCLUDE_DIRS})

    target_include_directories(${TARGETNAME} PRIVATE ${PUBLIC_INCLUDES}
                                                     ${PRIVATE_INCLUDES})

    target_link_libraries(${TARGETNAME} PRIVATE ${fcppt_core_TARGET}
                                                ${fcppt_log_TARGET})

    # FIXME: This is broken. Clients that use the backends must also include
    # this
    if(AWL_X11_BACKEND)
      fcppt_utils_link_imported_targets(${TARGETNAME} PRIVATE PkgConfig::X11)
    endif()

    if(AWL_WAYLAND_BACKEND)
      fcppt_utils_link_imported_targets(${TARGETNAME} PRIVATE
                                        PkgConfig::WAYLAND)
    endif()

    # TODO: Link to certain windows libs
    if(AWL_WINDOWS_BACKEND)
      target_compile_definitions(${TARGETNAME}
                                 PRIVATE ${WINDOWS_COMPILE_DEFINITIONS})

      target_link_libraries(${TARGETNAME} PRIVATE ${fcppt_filesystem_TARGET})
    endif()

    if(AWL_SDL_BACKEND)
      fcppt_utils_link_imported_targets(${TARGETNAME} PRIVATE SDL2::SDL2)

      # sdl2-config.cmake is broken
      target_link_libraries(${TARGETNAME} PRIVATE ${SDL2_LIBRARY})
    endif()
  endif()

  if(AWL_WINDOWS_BACKEND)
    target_compile_definitions(${TARGETNAME}
                               INTERFACE ${WINDOWS_COMPILE_DEFINITIONS})
  endif()

  fcppt_utils_export_install_target(${TARGETNAME})
endfunction()

fcppt_utils_interface_link_name(awl INTERFACE_NAME)

make_awl_library(${INTERFACE_NAME} INTERFACE)

if(ENABLE_STATIC)
  fcppt_utils_static_link_name(awl STATIC_NAME)

  make_awl_library(${STATIC_NAME} STATIC)
endif()

if(ENABLE_SHARED)
  make_awl_library(awl SHARED)
endif()

option(ENABLE_EXAMPLES "Build the examples" ON)

if(ENABLE_EXAMPLES)
  add_subdirectory(examples)
endif()

fcppt_utils_generate_config(CONFIG_PATH ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/cmake
                            MODULES_PATH ${CMAKE_MODULES_PUBLIC})

install(DIRECTORY ${FCPPT_UTILS_PROJECT_SOURCE_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(DIRECTORY ${FCPPT_UTILS_PROJECT_BINARY_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_MODULES_PUBLIC}/AwlMainGenerator.cmake
              ${CMAKE_MODULES_PUBLIC}/main_prototype.cpp.in
        DESTINATION ${FCPPT_UTILS_INSTALL_CMAKEMODULES_DIR})
