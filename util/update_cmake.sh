#!/bin/sh

set -e -u

update_main()
{
	update_cmake \
		"CMakeLists.txt" \
		"${@}"
}

update_main \
	AWL_BASE_INCLUDE_FILES \
	-n \
	include/awl \
	-r \
	include/awl/cursor \
	include/awl/main \
	include/awl/system \
	include/awl/visual \
	include/awl/window

update_main \
	AWL_BASE_SRC_FILES \
	-n \
	src \
	-r \
	src/cursor \
	src/main \
	src/system \
	src/visual \
	src/window

# Cocoa begin
update_main \
	AWL_COCOA_INCLUDE_FILES \
	include/awl/backends/cocoa/window \
	include/awl/backends/cocoa/system

update_main \
	AWL_COCOA_SRC_FILES \
	-e '.*\.(mm|cpp)?' \
	src/backends/cocoa
# Cocoa end

# X11 begin
update_main \
	AWL_X11_INCLUDE_FILES \
	include/awl/backends/x11

update_main \
	AWL_X11_SRC_FILES \
	src/backends/x11
# X11 end

# Wayland begin
update_main \
	AWL_WAYLAND_INCLUDE_FILES \
	include/awl/backends/wayland

update_main \
	AWL_WAYLAND_SRC_FILES \
	src/backends/wayland
# Wayland end

# Linux begin
update_main \
	AWL_LINUX_INCLUDE_FILES \
	include/awl/backends/linux

update_main \
	AWL_LINUX_SRC_FILES \
	src/backends/linux
# Linux end

# Windows begin
update_main \
	AWL_WINDOWS_INCLUDE_FILES \
	include/awl/backends/windows

update_main \
	AWL_WINDOWS_SRC_FILES \
	src/backends/windows
# Windows end
