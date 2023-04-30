#include "balanced.h"


int8_t isBalancedParanthethes(uint8_t *expression)
{
    uint8_t count1=0,count2=0,i=0;
    int8_t flag=0;

    uint8_t len = strlen(expression);
    for(i=0;i<len;i++)
    {
        if((expression[i]=='[')||(expression[i]==']')||(expression[i]=='<')||(expression[i]=='>'))
        {
            flag = -2;
            break;
        }
        if(expression[i]=='{')
            {
                count1++;
            }
        if(expression[i]=='}')
            {
                count1--;
            }
        if(expression[i]=='(')
            {
                count2++;
            }
        if(expression[i]==')')
            {
                count2--;
            }
        if((count1<0)||(count2<0))
        {
            flag=-1;
            break;
        }
    }
    if(i == (len))
    {
        if((count1>0)||(count2>0))
        {
            flag=-1;
        }
    }

    //printf("%i\n",flag);
    return flag;



}



void BALANCED_RUN()
{

      char st[11];
while(1)
{
    printf("Write an expression: ");
    scanf("%s",st);
    int8_t result = isBalancedParanthethes(st);
    if(result == 0)
    {
        printf("balanced\n");
    }
    else if(result == -1)
    {
        printf("unbalanced\n");
    }
    else if(result == -2)
    {
        printf("the neither of paranthethes is used\n");
    }
}

}


