#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("test.txt","r");
#if 0
    char ch;
    size_t size=0;
    int count = 0;
    do{
        size = fread(&ch,1, 1, fp);
        if(size != 0)
            printf("%c",ch);
        count++;
    }while(size != 0);
    printf("Count:%d\n",count);
#else
    int count;
    char buff[100];
    char *p;
    do{
        p = fgets(buff, sizeof(buff), fp);
        if(p!=NULL)
            printf("%s",buff);
        count++;
    }while(p != NULL);
    printf("Count:%d\n",count);
#endif
    fclose(fp);
    return 0;
}


