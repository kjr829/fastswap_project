#!/bin/bash

sudo zramctl --size 1G /dev/zram0

sudo mkswap /dev/zram0
sudo swapon -p 10 /dev/zram0
