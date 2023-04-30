#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8_t ;
typedef signed char int8_t ;
typedef signed int int32_t;
typedef unsigned int uint32_t;

int8_t insertionSort(int32_t *array, uint8_t arraySize);
void printArray(int32_t *array, uint8_t arraySize);
int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS);

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





