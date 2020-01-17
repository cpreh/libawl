#!/usr/bin/env bash

ARGS=(--library awl --library fcppt)

find examples include src \( \( -name '*.hpp' -o -name '*.cpp' \) \) -exec update_headers.sh '{}' "${ARGS[@]}" \;
