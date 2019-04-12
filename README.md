update-pi-temp
==============
Fetch the current chip temp of your Raspberry Pi and write it as a temporary file (/run/cputemp) every five seconds. This is handy in order to fetch the current system temperature from another application, e.g. a PHP application on a web server. This application takes up less than half the RAM usage compared to a running bash script doing the same thing. This might be useful when memory optimization is crucial. 

Usage
=====
Compile update_pi_temp.c with gcc:

  gcc -o fetchtemp update_pi_temp.c
  
Copy the compiled program to desired location and call it from a startup script, like rc.local.

Example of added line in rc.local:
  
  nice -n 18 /root/fetchTemp &
  
Extended version
================
The extended version lets the user choose target file for temperature writing by an parameter instead of using a predefined destination.
