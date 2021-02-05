#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if(argc > 1){
        if(strcmp(argv[1],"--help")==0)
        {
            printf("pass some argument to print those\n");
            exit(0);
        }
    }
    for(int i=0; i<argc; ++i)
    {
        printf("%s\n",argv[i]);
    }
}