# The ROS Console 
 This is a specialized container that will allow the user to run ROS graphical apps by utilizing a connection to the Hosts XWindowing System

 This runs out of the box on Linux
 For Mac, you need to very that ZQuartz is install
 On WSL2 Windows, this will run out of the box if the container is started from a WSL2 command prompt
 On plain Windows, this start up script will needs some love and care
 - First you need to install an XWindows server, this is not a recomendation for an XWindows server, this is just what came up from a Google search. Your milage may vary with each of them
    - https://x.cygwin.com
    - http://www.straightrunning.com/XmingNotes
    - https://sourceforge.net/projects/vcxsrv/

The main mechinism to support this mode includes
 - Running in privladged mode
 - Mapping the Dev file system to the containerhttps://sourceforge.net/projects/vcxsrv/
 - Mappng the Unix socket that communicates to the XServer to the container.

 This also needs to use the xhost command (called from start script) to allow permissions. Currently this is set to * allowing any access to the XWindows system, if you would like to narrow this access, [read the XHost man pages](https://wiki.archlinux.org/title/Xhost) and use xhost to remove the access or just reboot your computer. 

 An XWindows server does not allow a remote program to run a program on your host system. It allows a remoote program to open a windows on the host system and display its interface there. 
 