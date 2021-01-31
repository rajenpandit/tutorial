#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("file1.txt","r+");
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
        fseek(fp, 5, SEEK_SET);
        fputs("Name:",fp);
        fputs(name, fp);
        fputc('\n',fp);
        fputs("-----------------------\n",fp);
    }
    printf("Exiting program\n");
}