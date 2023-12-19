NODENAME=rosmicropy

IMAGE_NAME=Dockerfile.DevEnvironment
IMAGE_EXISTS=$(docker image list | grep $IMAGE_NAME )
if [ -z "$IMAGE_EXISTS" ]; then
   cd  docker
   echo "Building " $IMAGE_NAME " image"
   docker build -t ros_humble.img -f Dockerfile.humble .
   cd -
fi

docker rm $NODENAME

docker run -it \
 --name $NODENAME \
 -h $NODENAME \
 --privileged  \
 --net=host \
 -v `pwd`:/opt/rosmicropy  \
 -v /dev:/dev \
 rosmicropy.img bash 

 

