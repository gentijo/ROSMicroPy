#!/bin/sh
echo Network disable is expected
echo Edit xhost settings in this file for fine grained control
echo this line may fail on non-linux hosts
xhost +

NET_NAME=rosnet
IMAGE_NAME=ros_humble.img

cd docker/

NET_EXISTS=$(docker network list | grep $NET_NAME )
if [ -z "$NET_EXISTS" ]; then
echo "Creating Network " $NET_NAME
docker network create $NET_NAME
fi

IMAGE_EXISTS=$(docker image list | grep $IMAGE_NAME )
if [ -z "$IMAGE_EXISTS" ]; then
   echo "Building " $IMAGE_NAME " image"
   docker build -t ros_humble.img -f Dockerfile.humble .
fi

docker run -it --rm --net=$NET_NAME --privileged --env DISPLAY=unix$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix -v /dev:/dev ros_humble.img bash
