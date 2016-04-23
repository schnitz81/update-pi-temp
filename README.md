update-pi-temp
==============
Fetch the current chip temp of your Raspberry Pi and write it to RAM as a file in /run/ every five seconds. This is handy in order to fetch the current system temperature from another application, for example a PHP application on a web server. Doing this through running a compiled binary instead of a bash script only takes up below half as much memory usage.

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
