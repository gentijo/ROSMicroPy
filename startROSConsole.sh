#!/bin/sh
cd docker/
docker build -t ros_humble.img -f Dockerfile.humble .
docker run -it --rm --net=rosnet  --privileged --env DISPLAY=unix$DISPLAY  -v /tmp/.X11-unix:/tmp/.X11-unix -v /dev:/dev ros_humble.img bash
