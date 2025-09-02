# URSim Development Setup

The `programs` folder is what URSim currently reads to load scripts and custom programs.

Currently developing using the official Docker image:  
👉 [universalrobots/ursim_e-series](https://hub.docker.com/r/universalrobots/ursim_e-series)

---

## Table of Contents
- [URSim Development Setup](#ursim-development-setup)
  - [Table of Contents](#table-of-contents)
  - [Pull the Image](#pull-the-image)
  - [Run the Image](#run-the-image)

---

## Pull the Image
```bash
docker pull universalrobots/ursim_e-series
```

## Run the Image
Then run image with 
```bash 
docker run --rm -it universalrobots/ursim_e-series 
```

Current development is done using a vcn interface on web broswer with the following

```bash
docker run --rm -it -p 5900:5900 -p 6080:6080 universalrobots/ursim_e-series
```

-p 5900:5900 will publish the VNC port to the host, allowing the host to view the robots user interface with a VNC application, by connecting to localhost:5900.

-p 6080:6080 allows the host to view the robots user interface through a web browser with URL http://localhost:6080/vnc.html?host=localhost&port=6080⁠

To add pathing of the scripts that are in this repo, add to your command the pathing based on where it's stored. this default to /home/programs (linux distros only, adjust for yourself)
```bash
-v "${HOME}/programs:/ursim/programs" universalrobots/ursim_e-series
```


Which means, run 
```bash
docker run --rm -it -p 5900:5900 -p 6080:6080 -v "${HOME}/programs:/ursim/programs" universalrobots/ursim_e-series
```
Then access on
```bash
http://localhost:6080/vnc.html?host=localhost&port=6080⁠    
```