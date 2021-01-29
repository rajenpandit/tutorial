#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("file1.txt","a+");
    if(fp == NULL)
    {
        printf("Couldn't open file\n");
        return -1;
    }
    while(1){
        char name[20];
        printf("Enter a name:");
        scanf("%s",name);
        if(strcmp(name,"n")==0)
            break;
        fputs("Name:",fp);
        fputs(name, fp);
        fputc('\n',fp);
        fputs("-----------------------\n",fp);
    }
    printf("Exiting program\n");
}