#include<stdio.h>
int main(int argc, char *argv[]){
    int status;
    if(argc!=3){
        status = remove(argv[1]);
    }
    else{
        status = remove(argv[2]);   
    }
    if(status==0){
        if(argc==3){
            printf("Removing directory : %s\n",argv[2]);
        }
    }
    else{
        printf("Unable to delete file\n");
    }
    return 0;
}