#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include<string.h>
int main(){
    FILE* fp;
    char fileName[50]; //filename_14_1_2021;
    printf("Enter file name:");
    scanf("%s",fileName);
    time_t t = time(NULL);
    struct tm* localTime = localtime(&t);
    // char* c_time=asctime(localTime);
    // strcat(fileName,"_");
    // strcat(fileName,c_time);
    sprintf(fileName,"%s_%s_%d",fileName,asctime(localTime),1);
    printf("%s\n",fileName);
   // fp = fopen(fileName,"rw+");


    const char *p = "test_123";
    char str[10];
    int num;
    sscanf(p,"%4s_%d",str,&num);
    printf("str=%s, num=%d\n",str, num);


}