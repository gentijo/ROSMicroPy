#!/bin/sh


NET_NAME=rosnet

NET_EXISTS=$(docker network list | grep $NET_NAME )
if [ -z "$NET_EXISTS" ]; then
    echo "Creating Network " $NET_NAME
    docker network create $NET_NAME
fi 

IMAGE_NAME=rosteleopkey.img 
DOCKER_DEF=Dockerfile.TeleopKey

IMAGE_EXISTS=$(docker image list | grep $IMAGE_NAME )
if [ -z "$IMAGE_EXISTS" ]; then
   echo "Building " $IMAGE_NAME " image"
   cd docker
   docker build -t $IMAGE_NAME -f $DOCKER_DEF .
   cd -
fi

docker run -it --rm --net=$NET_NAME  $IMAGE_NAME

