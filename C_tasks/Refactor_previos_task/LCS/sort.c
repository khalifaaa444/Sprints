
#include "sort.h"
#define NULL "\0"

int8_t insertionSort(int32_t *array, uint8_t arraySize)
{
       int32_t key,i,j,flag=0;
        if(array == NULL)
        {
            flag=-1;
        }
        else if((arraySize == 0)||(arraySize >10))
        {
            flag = -2;
        }
        else
        {
            for(i=1;i<arraySize;i++)
       {
           j=i-1;
           key = array[i];

           while((j>=0)&&(key<array[j]))
           {
               array[j+1]=array[j];
               j--;
           }
           array[j+1]=key;
       }

        }

       return flag;
}



void printArray(int32_t *array, uint8_t arraySize)
{
    int32_t i;
    for(i=0;i<arraySize;i++)
    {
        printf("%i\n",array[i]);
    }
}
