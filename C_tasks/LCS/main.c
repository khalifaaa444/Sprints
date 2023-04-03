#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int8_t insertionSort(int32_t *array, uint8_t arraySize);

void printArray(int32_t *array, uint8_t arraySize);

int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS);

void check_error(int32_t *array , int arraySize ,int state);

int main()
{
int state =0;

printf("press '1' to show insertionSort test cases or any button to show lcsGetSize test cases:  ");
scanf("%d",&state);

if (state == 1)
{

int i;
int arr1[10]={9, 0, 7, 5, 3, 8, -10, 4, 2, 1};
int arr2[2];
int arr3[12]={9, 0, 7, 5, 3, 8, -10, 4, 2, 1, 6, 12};
int arr4[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int check[4];
check[0] = insertionSort(arr1,10);
check[1] = insertionSort(arr2,0);
check[2] = insertionSort(arr3,12);
check[3] = insertionSort(arr4,10);

check_error(arr1,10,check[0]);
check_error(arr2,0,check[1]);
check_error(arr3,12,check[2]);
check_error(arr4,10,check[3]);
}
else
{
    /*Follow the below algorithm to test your algorithm
1. Test Case 1
- Ask the user to enter array elements
- Enter the following elements
- [9, 0, 7, 5, 3, 8, -10, 4, 2, 1]
- Print the LCS size
2. Test Case 2
- Ask the user to enter array elements
- Press Enter without entering any element
3. Test Case 3
- Ask the user to enter array elements
- Enter the following elements
- [9, 0, 7, 5, 3, 8, -10, 4, 2, 1, 6, 12]
4. Test Case 4
- Ask the user to enter array elements
- Enter the following elements
- [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
- Print the LCS size
5. Test Case 5
- Ask the user to enter array elements
- Enter the following elements
- [2, 8, 4, 10, 6, 20, 16, 12, 14, 16]*/

int arr1[10]={9, 0, 7, 5, 3, 8, -10, 4, 2, 1};
int arr2[2];
int arr3[12]={9, 0, 7, 5, 3, 8, -10, 4, 2, 1, 6, 12};
int arr4[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int arr5[10]={2, 8, 4, 10, 6, 20, 16, 12, 14, 16};

int its_size;
int checkk = lcsGetSize(arr1,10,&its_size);
if (checkk == 0 )printf("the size = %i",its_size);

checkk = lcsGetSize(arr2,0,&its_size);
if (checkk == 0 )printf("the size = %i",its_size);

checkk = lcsGetSize(arr3,12,&its_size);
if (checkk == 0 )printf("the size = %i",its_size);

checkk = lcsGetSize(arr4,10,&its_size);
if (checkk == 0 )printf("the size = %i",its_size);

checkk = lcsGetSize(arr5,10,&its_size);
if (checkk == 0 )printf("the size = %i",its_size);

}



    return 0;
}

int8_t insertionSort(int32_t *array, uint8_t arraySize)
{
    int flag=0;
    if(array == NULL)
    {
        flag =-1;
    }
    else if((arraySize >10)||(arraySize==0))
    {
        flag = -2;
    }
    else if((arraySize < 10 )&&(arraySize >0))
    {
        int i,j,ele;
        for(i=1;i<arraySize;i++)
        {
            j=i-1;
            ele = array[i];
            while((j>=0)&&(array[j]>ele))
            {
                array[j+1] = array[j];
                j=j-1;

            }
            array[j+1] = ele;
        }
    }
    return flag;
}


void printArray(int32_t *array, uint8_t arraySize)
{
    int i;
    for(i=0;i<arraySize;i++)
    {
        printf("%d ",array[i]);
    }
}


int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS)
{

int flag=0,i=0,LCS_count=1;

 	 if(array == NULL)
     {
          flag = -1;
     }


 	 else if(arraySize == 0 || arraySize>10)
     {
          flag = -2;
     }



    else
    {
         uint8_t LCS_count =1;
 	 *sizeofLCS = 0 ;
 	 for( i=0 ;i<arraySize-1;i++){
 	     if (((array[i + 1]) - (array[i])) == 1)
 	    	 LCS_count++;
 	    else
 	    	LCS_count=1;

 		 if(LCS_count>*sizeofLCS)
 		 	  *sizeofLCS= LCS_count;

 	 }
    if(LCS_count == 1)
    {
        flag = -3; // No sequence
    }

    }


if(flag!=0)
{
    printf("Error number %i ... \n",flag);
}


 	 return flag;

  }

void check_error(int32_t *array , int arraySize ,int state)
{
    if(state == 0)
    {
        printArray(array,arraySize);
        printf("\n");
    }
    else
    {
        printf("Error in this function & it's num : %i \n",state);
    }
}


