update-pi-temp
==============
Fetch the current chip temp of your Raspberry Pi and write it to RAM as a file in /run/ every five seconds. This is handy in order to fetch the current system temperature from another application, for example a PHP application in a web server. Doing this through running a compiled binary instead of a bash script only takes up below half as much memory usage.

Usage
=====
Compile update_pi_temp.c with gcc:

  gcc -o fetchTemp update_pi_temp.c
  
Copy the compiled program to desired location and call it from a startup script, like rc.local.

Example of added line in rc.local:
  
  nice -n 18 /root/fetchTemp &
  
