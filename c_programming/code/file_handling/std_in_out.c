#include <stdio.h>


int main()
{
    #if 0
    printf("Hi.....\n");  //stdout
    perror("Hello\n");   //stderr
    printf("Testing...\n");  //stdout
    #endif
    char name[20];
    //fscanf(stdin,"%s",name);
    int n_char=0;
    do{
        n_char=fscanf(stdin,"%s",name);
        if(n_char > 0)
            printf("%s\n",name);
    }while(n_char>0);
    //fprintf(stderr,"Test\n");


    return 0;
};