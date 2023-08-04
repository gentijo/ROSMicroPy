export NODENAME=microrospy

docker rm $NODENAME

docker run -it \
 --name $NODENAME \
 -h $NODENAME \
 --privileged  \
 -v `pwd`:/opt/rosmicropy  \
 -v /dev:/dev \
 rosmicropy.img bash 

 

