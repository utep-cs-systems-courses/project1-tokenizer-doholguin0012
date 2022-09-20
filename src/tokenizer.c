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
  return (c != ' ' && c != '\t' && c != '\0')? 1:0;
}
/*searching for the initial words letter*/
char *word_start(char *str){
  while (space_char(*str) && *str){
    printf("char <%c>\n",str);
    str +=1;
  }
  return str;
}
char *word_terminator(char *str){
  while(*str){
    if(!non_space_char(*str)){
      printf("char: <%c>\n", *str);
      return str;
    }
    str++;
  }
  return str;
}
int count_words(char *str){
  int count=0;
  while (*str != '\0'){
    str = word_start(str);
    str = word_terminator(str);
    count +=1;
  }
  return count;
}
