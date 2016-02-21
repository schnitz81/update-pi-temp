#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// How often the temperature file is updated.
#define INTERVAL 5

// Path to file for temperature output.
#define filepath "/run/temp"  

typedef enum { false, true } bool; // bool type without extra header call.
char temp[4];

void gettemp()
{
    FILE *p;
    char buff[20];
    p = popen("/opt/vc/bin/vcgencmd measure_temp", "r");  
    if (! p){
        perror("Failed to fetch temperature. Make sure the vcgencmd binary is present.\n");
        exit(1);
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
    file = fopen(filepath,"w");
    if (file == NULL){
        perror("Error");
        exit(1);
    }
    fprintf(file,temp);
    fclose(file);
}

int main()
{
    while (true){
        gettemp();
        writetemp();
        sleep(INTERVAL);
    }  
}
