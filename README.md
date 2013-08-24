update-pi-temp
==============

Fetch the current chip temp of your Raspberry Pi and write it to RAM as a file in /run/ every five seconds. This is handy in order to fetch the current system temperature from another application, for example a PHP application in a web server. Doing this through running a compiled binary instead of a bash script only takes up below half as much memory usage.
