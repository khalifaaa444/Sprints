#include "stack.h"

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




void STACK_RUN()
{
      ST_stack_t NewST;
     createEmptyStack(&NewST);
     uint8_t choice;
     int8_t result;
     uint8_t data;
     //int data_2;
    while(1)
    {
        printf("choose your order :  1. push   2. pop   3. print topStack   4. print all stack    :- \t \t ");
        scanf(" %c",&choice);
        if(choice == '1' )
        {
            printf("enter Data :   ");

            scanf(" %c",&data);

            result = push(&NewST,data);
            if(result == 0)
            {
                printf("data: '%c' is pushed successfully\n",data);
            }
            else
            {
                printf("Stack is full\n");
            }
        }
        else if(choice == '2')
        {

            result = pop(&NewST,&data);
            if(result == 0)
            {
                printf("data: '%c'  is poped successfully\n",data);
            }
            else
            {
                printf("Stack is empty\n");
            }

        }

        else if(choice == '3')
        {
            result = getStackTop(&NewST,&data);
            if(result == 0)
            {
                printf("data: '%c' is in top of stack \n",data);
            }
            else
            {
                printf("Stack is empty\n");
            }
        }

        else if(choice == '4')
        {
            result = printStack(&NewST);
            if(result == 0)
            {
                printf("Note : Stack isn't full\n");

            }
            else if(result == -2)
            {
                printf("Note :Stack is full \n");
            }
            else
            {
                printf("Stack is empty\n");
            }
        }

        else
        {
            printf("\nTry again .... \n");
        }
    }

}


