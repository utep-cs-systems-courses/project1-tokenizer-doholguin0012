#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* return true if is a space */
int space_char(char c)
{
  return (c == ' ' || c == '\t')? 1:0;
}
/* checking if the character is not a space or end*/
int non_space_char(char c)
{
  return (c != ' ' || c != '\t' || c != '\0')? 1:0;
}
