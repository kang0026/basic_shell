#include <stdio.h>
#include <string.h>

void cpuInfo(FILE *fp){                 //get cpu model name
    char str[256];                      //set str size 256 to store strings
    int i = 0;                          //to count line number
    int len = strlen("model name:  ");  //get the length of model name title
    fp = fopen("/proc/cpuinfo", "r");     //open file
    if(fp == NULL){                     //check if file pointer(cpuinfo) is null
        printf("failed to read CPU info");
    }
    while(fgets(str, sizeof(str), fp)){//read a cpuinfo line by line
        i++;
        if(i == 5){                     //if it is 5th line of the cpuinfo file
            printf("CPU Model Name:         %s", len + str ); //print out after the title of the line
            break;                      //exit
        }
    }
    fclose(fp);                         //flush buffer
}

void kernelVersion(FILE *fp){                   //get kernel version
    char str[256];                              //set str size 256 to store strings
    fp = fopen("/proc/version", "r");             //open file
    if(fp == NULL){                             //check if file pointer(version) is null
        printf("failed to read kernel version");
    }
    if(fgets(str, sizeof(str), fp)!= NULL){     //read a version line by line
        printf("Kernel Version:         %s", str);  //print out all
    }
    fclose(fp);                                 //flush buffer
}

void mainMemoryTotal(FILE *fp){                     //get main memory total
    char str[128];                                  //set str size 128 to store strings
    int i = 0;                                      //to count line number
    int len = strlen("MemTotal:  ");                //get the length of MemTotal title
    fp = fopen("/proc/meminfo", "r");
    if(fp == NULL){
        printf("failed to read main memory info");
    }
    while (fgets(str, sizeof(str),fp)) {            //read a meminfo line by line
        i++;
        if(i == 1)                                  //if it is 1st line of the cpuinfo file
        {
            printf("Main Memory Total:%s", len + str ); //print out after the title of the line
            break;                                      //exit
        }
    }
    fclose(fp);
}

void uptime(FILE *fp){                     //get uptime
    char str[128];                         //set str size 128 to store strings
    fp = fopen("/proc/uptime", "r");
    if(fp == NULL){
        printf("failed to read uptime");
    }
    fscanf(fp, "%s", str);                //used fscanf to read before the first space and store in str
    printf("Uptime:                 %s Seconds\n", str);    //print out str
    fclose(fp);
}

int main(void){
    FILE *fp; //FILE pointer
    cpuInfo(fp);
    kernelVersion(fp);
    mainMemoryTotal(fp);
    uptime(fp);
    return 0;
}
