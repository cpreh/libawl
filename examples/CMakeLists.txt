include(
	CMakeParseArguments
)

include(
	GNUInstallDirs
)

set(
	AWL_INSTALL_EXAMPLE_DIR
	"${CMAKE_INSTALL_BINDIR}"
	CACHE
	STRING
	"Example installation directory"
)

function(
	add_awl_example
	EXAMPLE_NAME
)
	set(
		MULTI_ARGS
		INCLUDE_DIRS
		LINK_LIBS
	)

	cmake_parse_arguments(
		""
		""
		""
		"${MULTI_ARGS}"
		${ARGN}
	)

	fcppt_utils_add_example(
		${FCPPT_UTILS_PROJECT_SOURCE_DIR}/examples
		${EXAMPLE_NAME}
		INCLUDE_DIRS
			${_INCLUDE_DIRS}
		LINK_LIBS
			${awl_TARGET}
			${_LINK_LIBS}
		INSTALL_DIR
			"${AWL_INSTALL_EXAMPLE_DIR}"
	)
endfunction()

add_awl_example(
	main
	LINK_LIBS
		${fcppt_core_TARGET}
		${fcppt_log_TARGET}
)

add_awl_example(
	resize
	LINK_LIBS
		${fcppt_core_TARGET}
		${fcppt_log_TARGET}
)

add_awl_example(
	show
	LINK_LIBS
		${fcppt_core_TARGET}
		${fcppt_log_TARGET}
)

add_awl_example(
	timer
	LINK_LIBS
		${fcppt_core_TARGET}
		${fcppt_log_TARGET}
)

if(
	AWL_X11_BACKEND
)
	add_awl_example(
		xim
		LINK_LIBS
			PkgConfig::X11
			${fcppt_core_TARGET}
			${fcppt_log_TARGET}
	)
endif()
