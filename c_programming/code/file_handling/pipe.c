#include <stdio.h>

int main(int argc, char** argv)
{
    if(argc > 1)
    {
        FILE* p = popen("testPipe", "w");
        if(p == NULL)
            return -1;
        fprintf(p,"%s",argv[1]);
        pclose(p);
    }
    else
    {
        FILE *p = popen("testPipe","r");
        if(p == NULL)
            return -1;
        char str[50];
        fscanf(p,"%s",str);
        printf("%s\n",str);
    }
    return 0;
}