#!/bin/bash
wget -P /tmp/ https://raw.githubusercontent.com/EllaRepo/alx-low_level_programming/master/0x18-dynamic_libraries/crand.so
export LD_PRELOAD=/tmp/crand.so