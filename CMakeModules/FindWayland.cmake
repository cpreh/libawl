include(
	FindPkgConfig
)

pkg_check_modules(
	WAYLAND
	${WAYLAND_FIND_REQUIRED}
	${WAYLAND_FIND_QUIETLY}
	wayland-client
)
