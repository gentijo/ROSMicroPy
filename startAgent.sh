#!/bin/sh
docker run -it --rm --net=rosnet --privileged  -p 8888:8888/udp microros/micro-ros-agent:humble udp4 -p 8888
