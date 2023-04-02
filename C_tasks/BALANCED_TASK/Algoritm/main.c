#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define STACK_SIZE 10


typedef struct stack {
	uint8_t elements[STACK_SIZE];
	int8_t top;
}ST_stack_t;

int8_t isBalancedParanthethes(uint8_t* expression);
int8_t isEmpty(ST_stack_t* stack);
int8_t getStackTop(ST_stack_t* stack, uint8_t* topData);
int8_t printStack(ST_stack_t* stack);
int8_t pop(ST_stack_t* stack, uint8_t* data);
int8_t push(ST_stack_t* stack, uint8_t data);
void createEmptyStack(ST_stack_t* stack);

int8_t i;

int main() {

	uint8_t ch;

	ST_stack_t stack;

	createEmptyStack(&stack);
    printf("Enter 5 charecters : ");
    char inp[10];
    for(i=0;i<5;i++)
    {
        scanf(" %c",&inp[i]);
    }

	for(i=0;i<5;i++)
    {
        push(&stack, inp[i]);
    }

	printStack(&stack);

	pop(&stack, &ch);

	printf("Top after popping one character: \n");
	getStackTop(&stack, &ch);

	printf("Stack after popping one character: \n");
    printStack(&stack);


    printf("Enter 7 charecters : ");

    for(i=0;i<7;i++)
    {
        scanf(" %c",&inp[i]);
    }

	for(i=0;i<7;i++)
    {
        push(&stack, inp[i]);
    }



	printf("Top after pushing 7 characters:- \n");
	getStackTop(&stack, &ch);

	printf("Stack after pushing 7 characters:- \n");
	printStack(&stack);

	for ( i = 0; i < 4; i++) {
		pop(&stack, &ch);
	}
	printf("Top after popping 4 characters:- \n");
	getStackTop(&stack, &ch);

	printStack(&stack);

	for ( i = 0; i < 7; i++) {
		pop(&stack, &ch);
	}
	printf("Top after popping 7 characters:- \n");
	getStackTop(&stack, &ch);

	printStack(&stack);

	return 0;
}





void createEmptyStack(ST_stack_t* stack) {
	stack -> top = -1;
	for ( i = 0; i < STACK_SIZE; i++) {
		stack->elements[i] = 0;
	}
}


int8_t push(ST_stack_t* stack, uint8_t data) {

	if (stack->top == (STACK_SIZE-1)) {
		return -1;
	}
	stack->top++;
	stack->elements[stack->top] = data;
	return 0;
}

int8_t pop(ST_stack_t* stack, uint8_t* data) {
	if (stack->top == -1) {
		return -2;
	}
	*data = stack->elements[stack->top];
	stack->top--;
	return 0;

}

int8_t printStack(ST_stack_t* stack) {
	if (stack->top == (STACK_SIZE - 1)) {
		printf("Stack is FULL!\n");
		return -1;
	}
	else if (stack->top == -1) {
		printf("Stack is EMPTY!\n");
		return -2;
	}
	else {
		for ( i = stack->top; i >= 0; i--) {
			printf("%c ", stack->elements[i]);
		}
		printf("\n");
		return 0;
	}
}


int8_t getStackTop(ST_stack_t* stack, uint8_t* topData) {
	if (stack->top == -1) {
		return -2;
		printf("Stack is EMPTY!\n");
	}
	*topData = stack->elements[stack->top];
	printf(" %c\n", *topData);
	return 0;
}

int8_t isEmpty(ST_stack_t* stack) {
	if (stack->top == -1) {
		return -2;
	}
	return 0;
}

int8_t isBalancedParanthethes(uint8_t* expression) {
	ST_stack_t MyStack;
	createEmptyStack(&MyStack);


	for ( i = 0; i < strlen(expression); i++) {
		uint8_t temp = 0;
		getStackTop(&MyStack, &temp);

		if (expression[i] == '{' || expression[i] == '(') {
			push(&MyStack, expression[i]);
		}
		else if (expression[i] == ')' || expression[i] == '}') {
			if (MyStack.top == -1) {
				return -1;
			}

			if ((expression[i] == '}' && temp == '{') || (expression[i] == ')' && temp == '(')) {
				pop(&MyStack, &temp);
			}
			else {
				return -1;
			}
		}
	}
	if (MyStack.top == -1) {
	return -2;
	}
	return 0;
}

