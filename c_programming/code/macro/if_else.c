#include <stdio.h>

#define FEATURE_SUM    // also can be defined from command line .. ex: gcc -DFEATURE_SUM if_else.c -o if_else
//#define FEATURE_SUB




#if defined(FEATURE_SUM)  ///  #if <condtion>     [condition: X==Y, 1, 0, 1>0, X>=Y]
int sum(int x, int y)
{
    return x+y;
}
#endif

// #if defined(FEATURE_SUB)
#ifdef FEATURE_SUB    // also can be used like this.
int sub(int x, int y)
{
    return x+y;
}
#endif

int main()
{
    int x, y;
#if defined(FEATURE_SUM)
    printf("Enter two value for sum:\n");
    scanf("%d%d",&x,&y);
    printf("Sum is :%d\n", sum(x,y));
#endif
#if defined(FEATURE_SUB)
    printf("Enter two value for subtract:\n");
    scanf("%d%d",&x,&y);
    printf("Sub is :%d\n", sub(x,y));
#endif

/*
    if(...)
    {

    }
    else if(...)
    {

    }
    else if(...)
    {

    }
    else{
        
    }
*/
/*
#if <condition>
    ....
#else
    #if <condition>
        ....
    #else
        #if <condition>
            ...
        #else
            ...
        #endif
    #endif
#endif


#if <condition>
#elif <condition>
#elif <condition>
#elif <condition>
#else
#endif

*/



}
