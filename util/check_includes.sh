#!/bin/bash

set -e -u

INCLUDE_BINARY="check_includes"

"${INCLUDE_BINARY}" include

"${INCLUDE_BINARY}" src/impl/include
