#include <stdio.h>
int main(int argc, char *argv[]){
    FILE *fptr;
    if(argc==3){
        fptr= fopen(argv[2],"r");
    }
    else{
       fptr= fopen(argv[1],"r");
    }
    if(fptr == NULL){
        printf("Cannot Open File\n");
    }
    int line=1;
    char ch=fgetc(fptr);
    while(ch!=EOF){
        printf("%c",ch);
        if(argc==3){
            if(ch=='\0' || ch=='\n'){
                printf("%d  ",line);
                line++;
            }
        }
        ch=fgetc(fptr);
    }
    printf("\n");
    fclose(fptr);
    return 0;
}