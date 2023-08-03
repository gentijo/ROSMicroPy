export NODENAME=rosberrypy

docker rm $NODENAME

docker run -it \
 --name $NODENAME \
 -h $NODENAME \
 --privileged  \
 -v `pwd`:/opt/rosberrypy  \
 -v /dev:/dev \
 rosberrypy.img bash 

 

