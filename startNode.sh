export NODENAME=rosmicropy

docker rm $NODENAME

docker run -it \
 --name $NODENAME \
 -h $NODENAME \
 --privileged  \
 -v `pwd`:/opt/rosmicropy  \
 -v /dev:/dev \
 rosmicropy50.img bash



