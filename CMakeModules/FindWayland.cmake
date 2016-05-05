include(
	FindPkgConfig
)

pkg_check_modules(
	WAYLAND_CLIENT
	${WAYLAND_FIND_REQUIRED}
	${WAYLAND_FIND_QUIETLY}
	wayland-client
)

pkg_check_modules(
	WAYLAND_CURSOR
	${WAYLAND_FIND_REQUIRED}
	${WAYLAND_FIND_QUIETLY}
	wayland-cursor
)

if(
	WAYLAND_CLIENT_FOUND
	AND
	WAYLAND_CURSOR_FOUND
)
	set(
		WAYLAND_FOUND
		TRUE
	)
endif()
