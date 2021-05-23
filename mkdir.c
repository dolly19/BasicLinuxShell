#include <unistd.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    int perm;
    
    if(argc == 3){
        perm=0763;
        if(mkdir(argv[2],perm)!=-1){
            printf("Created Directory : %s\n",argv[2]);
        }
        else{
            printf("Error Creating Directory\n");
        }
    }
    else if(argc==4){
        perm=atoi(argv[2]);
        
        if(mkdir(argv[3],perm)!=-1){
            int index=0;
        }
        else
        {
            printf("Error Creating Directory\n");
        }
        
    }
    else{
        perm=0763;
        if(mkdir(argv[1],perm)!=-1){
            int index=0;
        }
        else
        {
            printf("Error Creating Directory\n");
        }
        
    }
    return 0;
}