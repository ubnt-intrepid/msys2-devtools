#!/bin/bash

export VIMRUNTIME=$(cygpath -w /mingw64/share/vim/vim74)
exec /mingw64/bin/gvim.exe "$@"

