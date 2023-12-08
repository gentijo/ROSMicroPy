export NODENAME=rosmicropy

cd  docker
docker build -t rosmicropy.img -f Dockerfile.rbpy .
cd -

docker rm $NODENAME

docker run -it \
 --name $NODENAME \
 -h $NODENAME \
 --privileged  \
 --net=host \
 -v `pwd`:/opt/rosmicropy  \
 -v /dev:/dev \
 rosmicropy.img bash 

 

