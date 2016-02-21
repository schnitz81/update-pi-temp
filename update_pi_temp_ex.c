#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define INTERVAL 5  // How often the temperature file is updated.

char temp[4];
typedef enum { false, true } bool;  // bool type without extra header call.

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

void writetemp(char *path)
{   
    FILE *file;
    file = fopen(path,"w");
    if (file == NULL){
        perror("Error");
        exit(1);
    }
    fprintf(file,temp);
    fclose(file);
}

int main(int argc, char *argv[])
{   
    // Check input arguments
    if(argc>2){
        printf("Too many arguments!\n");
        exit(1);
    }
    else if(argc<2){
        printf("Usage: (Start command) /path/to/target/file\n");
        exit(1);
    }

    // Get user input file path.
    char *path = argv[1];

    // Read and write loop.
    while (true){
        gettemp();
        writetemp(path);
        sleep(INTERVAL);
    }
}
