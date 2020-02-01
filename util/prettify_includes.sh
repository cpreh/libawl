#!/usr/bin/env bash

LIBS=(--library awl --library fcppt)
DIRS=(examples include src)

prettify_includes "${LIBS[@]}" "${DIRS[@]}"
