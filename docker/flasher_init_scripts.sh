#!/bin/bash

set -eu

cd /opt/rosmicropy
echo Updating REPO
git pull

source $IDF_PATH/export.sh

set +u
