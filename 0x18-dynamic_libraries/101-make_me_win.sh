#!/bin/bash
wget -P /tmp/ https://github.com/EllaRepo/alx-low_level_programming/blob/18e0a0b6d929c52b98c3c1352b983483afa3a24d/0x18-dynamic_libraries/librand.so
export LD_PRELOAD=/tmp/librand.so