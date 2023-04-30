#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "balanced.h"


uint8_t choice;

int main()
{
  printf("enter 1 for stack OR 2 for balanced exp :   ");
  scanf(" %c",&choice);

  if(choice=='1')
  {
      STACK_RUN();
  }
  else if(choice=='2')
  {
      BALANCED_RUN();
  }

  else
  {
      printf("Wrong number \n");
  }

    return 0;
}


