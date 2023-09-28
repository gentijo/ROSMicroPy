#!/bin/sh
cd docker/
docker build -t rosteleopkey.img -f Dockerfile.TeleopKey .
docker run -it --rm --net=rosnet  rosteleopkey.img

