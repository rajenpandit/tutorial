#include <stdio.h>

int copy_file(const char* dstFile, const char* srcFile)
{
    FILE *sf = fopen(srcFile, "rb");
    if(sf == NULL)
        return -1;
    FILE *df = fopen(dstFile, "wb");
    if(df == NULL)
        return -1;
    char ch;
    while(1){
        ch = fgetc(sf);
        if((ch == EOF) && (feof(sf) !=0) )
            break;
        else 
            fputc(ch, df);
    }
    return 0;
}

int main(){
    const char* srcFile = "/Users/rajenpandit/pics.jpeg";
    const char* dstFile = "pics.jpeg";
    if(copy_file(dstFile,srcFile) == -1)
        printf("Couldn't copy file\n");
    else   
        printf("File copied successfully\n");
    return 0;
}