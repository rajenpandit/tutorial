#include <stdio.h>
/*
name:
rollNum:
age:
*/

typedef struct StudentInfo{
    char name[20];
    int rollNum;
    int age;
}StudentInfo;

int main(){
    StudentInfo s = {"Raj", 123, 23};
    FILE* fp = fopen("test.txt","wb+");
    fwrite(&s, sizeof(s), sizeof(s), fp);
    fclose(fp);


    
    fp = fopen("test.txt","rb+");
    StudentInfo s1;
    do{
        size_t r = fread(&s1, sizeof(s1), sizeof(s1), fp);
        if(r > 0)
            printf("name:%s\nrollNum:%d\nage:%d\n",s1.name,s1.rollNum,s1.age);
    }
    while(!(feof(fp) || ferror(fp)));
    fclose(fp);
    return 0;
}