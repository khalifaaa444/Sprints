#include <stdio.h>
#include <stdlib.h>

#include "lcs.h"
#include "sort.h"

int main()
{
    int32_t arr[]={2, 8, 4, 10, 6, 20, 16, 12, 14, 16};

    uint32_t lennn = sizeof(arr) / 4;
    uint8_t num_LCS=0;
    int8_t result = lcsGetSize(arr,lennn,&num_LCS);
    if(result == -1)
    {
        printf("there is no array\n");
    }
    else if(result == -2)
    {
        printf("this array is empty or bigger than 10 elements\n");

    }
    else if(result == -3)
    {
        printArray(arr,lennn);
        printf("LCS = 0 \n");

    }

    else
    {
        printArray(arr,lennn);
       printf("LCS = %i\n",num_LCS);
    }

    return 0;
}


