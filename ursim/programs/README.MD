The programs folder is what the ursim currently reads to load scripts and custom programs.

Currently developing using https://hub.docker.com/r/universalrobots/ursim_e-series 

Pull image with docker pull universalrobots/ursim_e-series
Then run image with docker run --rm -it universalrobots/ursim_e-series
Current development is done using a vcn interface on web broswer with the following
docker run --rm -it -p 5900:5900 -p 6080:6080 universalrobots/ursim_e-series

-p 5900:5900 will publish the VNC port to the host, allowing the host to view the robots user interface with a VNC application, by connecting to localhost:5900.

-p 6080:6080 allows the host to view the robots user interface through a web browser with URL http://localhost:6080/vnc.html?host=localhost&port=6080⁠

To add pathing of the scripts that are in this repo, add to your command

-v "${HOME}/programs:/ursim/programs" universalrobots/ursim_e-series


Which means, run 

docker run --rm -it -p 5900:5900 -p 6080:6080 -v "${HOME}/programs:/ursim/programs" universalrobots/ursim_e-series

Then access on

http://localhost:6080/vnc.html?host=localhost&port=6080⁠