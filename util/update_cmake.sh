#!/bin/sh

set -e -u

update_cmake.sh \
	awl_base_files.txt \
	include \
	src \
	impl

update_backend()
{
	local backend_dir=backends/"$1"
	update_cmake.sh \
		"${backend_dir}"/files.txt \
		"${backend_dir}"
}

BACKENDS=(
	linux
	posix
	sdl
	wayland
	windows
	x11
)

for backend in ${BACKENDS[@]} ; do
	update_backend $backend
done
