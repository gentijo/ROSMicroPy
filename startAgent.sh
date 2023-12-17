#!/bin/sh

NET_NAME=rosnet

NET_EXISTS=$(docker network list | grep $NET_NAME )
if [ -z "$NET_EXISTS" ]; then
    echo "Creating Network " $NET_NAME
    docker network create $NET_NAME
fi 

docker run -it --rm --net=rosnet --privileged  -p 8888:8888/udp microros/micro-ros-agent:humble udp4 -p 8888
