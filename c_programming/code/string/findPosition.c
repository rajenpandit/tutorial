#include <string.h>
#include <stdio.h>

// int findPosition(char* str, char c)
// {
//     char* base_str = str;
//     while(*base_str != c && (*base_str != '\0'))
//     {
//         base_str++;
//     }
//     return base_str - str;
// }

// int findPosition(char* str, char c)
// {
//     int pos = 0;
//     while((*str != c) && (*str != '\0'))
//     {
//         pos++;
//         str++;
//     }
//     if(str == '\0')
//         return -1;
//     return pos;
// }

// int findPosition(char* str, char c)
// {
//     int pos = 0;
//     while((*(str + pos) != c) && (*(str + pos) != '\0'))
//     {
//         pos++;
//     }
//     if(*(str + pos) == '\0')
//         return -1;
//     return pos;
// }

int findPosition(char* str, char c)
{
    int pos = 0;
    while((str[pos] != c) && (str[pos] != '\0'))
    {
        pos++;
    }
    if(str[pos] == '\0')
        return -1;
    return pos;
}


// int findPosition(char* str, char c)
// {
//     int pos;
//     for( pos = 0 ; (str[pos] != c) && (str[pos] != '\0') ; pos++)
//     {
//     }

//     if(str[pos] == '\0')
//         return -1;
//     return pos;
// }

int reverseFindPosition(char* str, char c)
{
    int length = strlen(str);
    int pos = length - 1; 
    while((pos >= 0) && (str[pos] != c))
    {
        pos--;
    }
    if(pos < 0)
        return -1;
    return pos;
}

int main()
{
    char arr[] = {"Hello World"};
    int  pos1 = findPosition(arr, 'l');
    int  pos2 = reverseFindPosition(arr, 'l');
    for(int i=pos1 ; i<= pos2 ; ++i )
    {
        printf("%c",arr[i]);
    }
    printf("\n");

}