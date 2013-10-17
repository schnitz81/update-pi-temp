#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

char temp[4];

void gettemp()
{
    FILE *p;
    char buff[20];
    p = popen("/opt/vc/bin/vcgencmd measure_temp", "r");  
    if (! p){
        perror("Failed to run command\n");
        exit(0);
    }
    fgets( buff, sizeof buff, p );
    pclose(p);
    if( isdigit(buff[0]) )
        memcpy(&temp, &buff,4);
    else
        memcpy(&temp, &buff[5],4);
}

void writetemp()
{
    FILE *file;
    file = fopen("/run/temp","w");
    fprintf(file,temp);
    fclose(file);
}

int main()
{
    while (true){
        gettemp();
        writetemp();
        sleep(5);
    }  
}
