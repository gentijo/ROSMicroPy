#!/bin/bash

set -eu

cd /opt/rosmicropy
git pull

sudo apt update -yq
sudo apt install -yq python3-pip
source $IDF_PATH/export.sh

pip3 install catkin_pkg lark-parser empy colcon-common-extensions importlib-resources

set +u
