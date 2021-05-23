#include<time.h>
#include<stdio.h>
#include <unistd.h>
#include<sys/wait.h>
int main(int argc, char* argv[]){
    if(argc!=2){
        time_t gmt_now;
        gmt_now=time(NULL);
        gmtime(&gmt_now);
        printf("%s",asctime(gmtime(&gmt_now)));
    }
    else{
        time_t now;
        time(&now);
        printf("%s",ctime(&now));
    }
    return 0;
}