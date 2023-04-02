#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define STACK_SIZE 10


typedef struct stack
{
    uint8_t elements[STACK_SIZE];
    int8_t top;
} ST_stack_t;

void createEmptyStack(ST_stack_t* stack);


int8_t push(ST_stack_t* stack, uint8_t data);

int8_t pop(ST_stack_t* stack, uint8_t* data);

int8_t printStack(ST_stack_t* stack);

int8_t getStackTop(ST_stack_t* stack, uint8_t* topData);

int8_t isBalancedParanthethes(uint8_t* expression);




int8_t i;


int main()
{
    int8_t state = 0;
   // uint8_t array[10] = "{(2+3)}";
   uint8_t array[10];
  while(1)
  {


   printf("Enter your string :  ");
   scanf("%s",array);
    state=isBalancedParanthethes(array);
    switch (state)
    {
    case 0:
        printf("it is balanced\n",array);
        break;
    case -1:
        printf("It is not balanced\n",array);
        break;
    case -2:
        printf("It doesn't include paranthethes\n",array);
        break;
    }
    printf("press 'y' if want to try another expression: ");
    char ch;

    scanf(" %c",&ch);

    if(ch != 'y')
    {
        break;
    }
  }
    return 0;
}




void createEmptyStack(ST_stack_t* stack)
{
    stack -> top = -1;
    for ( i = 0; i < STACK_SIZE; i++)
    {
        stack->elements[i] = 0;
    }
}


int8_t push(ST_stack_t* stack, uint8_t data)
{

    if (stack->top == (STACK_SIZE-1))
    {
        return -1;
    }
    stack->top++;
    stack->elements[stack->top] = data;
    return 0;
}

int8_t pop(ST_stack_t* stack, uint8_t* data)
{
    if (stack->top == -1)
    {
        return -2;
    }
    *data = stack->elements[stack->top];
    stack->top--;
    return 0;

}

int8_t printStack(ST_stack_t* stack)
{
    if (stack->top == (STACK_SIZE - 1))
    {
        return -1;
    }
    else if (stack->top == -1)
    {
        return -2;
    }
    else
    {
        for ( i = stack->top; i >= 0; i--)
        {
            printf("%c ", stack->elements[i]);
        }
        printf("\n");
        return 0;
    }
}

int8_t getStackTop(ST_stack_t* stack, uint8_t* topData)
{
    if (stack->top == -1)
    {
        return -2;
    }
    *topData = stack->elements[stack->top];
    return 0;
}

int8_t isEmpty(ST_stack_t* stack)
{
    if (stack->top == -1)
    {
        return -2;
    }
    return 0;
}

int8_t isBalancedParanthethes(uint8_t* expression)
{
    ST_stack_t MyStack;
    createEmptyStack(&MyStack);
    uint8_t temp = 0;

    for ( i = 0; i < strlen(expression); i++)
    {

        getStackTop(&MyStack, &temp);

        if (expression[i] == '{' || expression[i] == '(')
        {
            push(&MyStack, expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == '}')
        {
            if (MyStack.top == -1)
            {
                return -1;
            }
            pop(&MyStack, &temp);
            if ((expression[i] == '}' && temp != '{') || (expression[i] == ')' && temp != '('))
            {
                return -1;
            }

        }
    }
    if (MyStack.top != -1)
    {
        return -1;
    }

    else if (temp == '\0')
    {
        return -2;
    }

    return 0;

}

