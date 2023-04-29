#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 10

typedef unsigned char uint8_t;
typedef signed char  int8_t;

typedef struct stack {
uint8_t elements[STACK_SIZE];
int8_t top;
}ST_stack_t; // Type

void createEmptyStack(ST_stack_t *stack);
int8_t push(ST_stack_t *stack, uint8_t data);
int8_t pop(ST_stack_t *stack, uint8_t *data);
int8_t printStack(ST_stack_t *stack);
int8_t getStackTop(ST_stack_t *stack, uint8_t *topData);
int8_t isFull(ST_stack_t *stack);
int8_t isEmpty(ST_stack_t *stack);
int8_t isBalancedParanthethes(uint8_t *expression);
int main()
{
    char st[11];
while(1)
{
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

    return 0;
}

void createEmptyStack(ST_stack_t *stack)
{
    int i=0;

    for(i=0;i<STACK_SIZE;i++)
    {
        stack->elements[i] = 0;
    }
    stack->top = -1;

}

int8_t push(ST_stack_t *stack, uint8_t data)
{
    int8_t flag=0;
   if(stack->top == STACK_SIZE -1 )
   {
       flag=-1;
   }
   else
   {
       stack->top++;
       stack->elements[stack->top]=data;

   }
   return flag;
}


int8_t pop(ST_stack_t *stack, uint8_t *data)
{
    int8_t flag =0;
    if(stack->top == -1)
    {
        flag =-2;
    }

    else
    {
        *data = stack->elements[(stack->top)];
        stack->top--;
        //printf("%i",stack->top);
    }
    return flag;
}

int8_t printStack(ST_stack_t *stack)
{
    int8_t flag=0;
    int8_t temp = stack->top;

    if(temp == STACK_SIZE -1)
    {
        flag = -2;
        while(temp != -1)
        {
            temp--;
            printf("%c\n",stack->elements[temp+1]);
        }
    }
    else if(temp == -1)
    {
        flag = -1;
    }
    else
    {
        while(temp != -1)
        {
            temp--;
            printf("%c\n",stack->elements[temp+1]);
        }
    }

    return flag;

}


int8_t getStackTop(ST_stack_t *stack, uint8_t *topData)
{
    int8_t flag;
    if(stack->top == -1)
    {
        flag =-2;
    }
    else
    {
        *topData=stack->elements[stack->top];
        flag=0;
    }

    return flag;


}


int8_t isFull(ST_stack_t *stack)
{
    int8_t flag=0;

    if(stack->top == STACK_SIZE -1)
    {
        flag=-1;
    }
    return flag;

}

int8_t isEmpty(ST_stack_t *stack)
{
    int8_t flag =0;

    if(stack->top == -1)
    {
        flag=-2;
    }

    return flag;

}



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



