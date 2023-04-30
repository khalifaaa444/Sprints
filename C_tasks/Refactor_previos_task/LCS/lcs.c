
#include "lcs.h"


int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS)
{
    int32_t curr=0,i=0,max=0;
    int8_t flag=insertionSort(array,arraySize);
    //*sizeofLCS=0;

    if(flag==-1)
    {
        flag=-1;
    }
    else if(flag ==-2)
    {
        flag = -2;
    }
    else
    {
        for(i=0;i<arraySize;i++)
    {
        if(array[i+1]==array[i]+1)
            {

                curr++;

            }
        else
            {
                if((curr!=0) && (max<=curr))
                {
                    max=curr;
                    *sizeofLCS=curr+1;

                    curr=0;
                    flag = 0;

                }
                else if(max==0)
                {
                    flag = -3;

                }
            }
    }
    }


    return flag;

}





