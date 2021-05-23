#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include<string.h>
int main(int argc, char **argv)
{
    struct dirent **files;
    int n= scandir(".", &files, NULL, alphasort);

    if (n > 0){
        
        while (n--) {
        if(files[n]->d_name[0]!='.'){
            printf("%s\n", files[n]->d_name);
        }
        else{
            if(argc==3){
                printf("%s\n", files[n]->d_name);
            }
        }
        free(files[n]);
        }
        free(files);
    }
    else {
        perror("Error reading Directory");
    }
    return 0;
}