#! /bin/sh
# This script is to run limon on windows subsystem for linux where gmp libraries are not automatically loaded.

LD_LIBRARY_PATH=/usr/local/lib $(dirname "$0")/../bin/limon $@
