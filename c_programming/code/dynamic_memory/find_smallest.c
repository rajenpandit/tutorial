#include <stdio.h>
#include <stdlib.h>

int findSecondSmallest(int* p, size_t s){
    
    if(p == NULL || s == 0)
        return -1;
    
    // int min = __INT_MAX__;
    // int s_min = __INT_MAX__;
    // int i = 0;

    int min = *p;
    int s_min = *p;
    int i = 1;

    for( ; i < s; ++i ){
        if( min > p[i]){
            s_min = min;
            min = p[i];  // *(p+i)
        }
        else if(s_min > p[i]){
            s_min = p[i];
        }
    }
    return s_min;
}


int main(){
    int n_numbers;
    printf("Enter size of array:");
    scanf("%d",&n_numbers);
    int* p = (int*) malloc(sizeof(int) * n_numbers);
    printf("Enter %d numbers:",n_numbers);
    for(int i=0 ; i<n_numbers; ++i){
        // scanf("%d",&p[i]);  // &(*(p+i))
        scanf("%d",p+i);
    }
    int s = findSecondSmallest(p, n_numbers);
    printf("Second  Smalles:%d\n", s);
    free(p);
}
