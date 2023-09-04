#!/bin/sh

docker run -it --rm --net=host microros/micro-ros-agent:humble udp4 -p 8888
