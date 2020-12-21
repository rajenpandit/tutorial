#include <stdio.h>

int main()
{
    int var[3][2];

    // var[3] ###// var[0] var[1] var[2]
    // var[3][2]  ## var[0][0] var[0][1] , var[1][0] var[1][1], var[2][0] var[2][1]

    // var[3][2][2]  ## var[0][0][0], var[0][0][1], 

    for(int i=0; i<3 ; i++)
    {
        for(int j=0; j<2 ; j++)
        {
            printf("Address of %d:%d: %p\n", i,j, &var[i][j]);
        }
    }
}