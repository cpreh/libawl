#!/bin/bash

function die()
{
	exit -1
}

function update_main()
{
	local cmakefile="CMakeLists.txt"

	update_cmake \
		"${cmakefile}" \
		"${@:1}" \
		|| die 

	mv "${cmakefile}".new "${cmakefile}" || die
}

update_main \
	AWL_BASE_INCLUDE_FILES \
	-n \
	include/awl \
	-r \
	include/awl/mainloop \
	include/awl/system \
	include/awl/window

update_main \
	AWL_BASE_SRC_FILES \
	-n \
	src \
	-r \
	src/mainloop \
	src/system \
	src/window

update_main \
	AWL_X11_INCLUDE_FILES \
	include/awl/backends/x11

update_main \
	AWL_X11_SRC_FILES \
	src/backends/x11

update_main \
	AWL_WINDOWS_INCLUDE_FILES \
	include/awl/backends/windows

update_main \
	AWL_WINDOWS_SRC_FILES \
	src/backends/windows