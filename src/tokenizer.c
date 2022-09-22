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
    str +=1;
  }
  return str;
}/*searching where the words ends.*/
char *word_terminator(char *str){
  while(*str){
    if(!non_space_char(*str)){
      return str;
    }
    str++;
  }
  return str;
}
/*Count How many words there are in the sentence.*/
int count_words(char *str){
  int count=0;
  while (*str != '\0'){
    str = word_start(str);
    str = word_terminator(str);
    count +=1;
  }
  return count;
}
/*creating a copy of the string and adding a ending factor \0 */
char *copy_str(char *inStr, short len){
  int p = 0;
  char *copy = malloc((len+1) * sizeof(char));
  while(p <= len){
    copy[p] = inStr[p];
    p++;
  }
  copy[p] = '\0';
  return copy;
}
char **tokenize( char *str){
  int wcount = count_words(str);
  char **token = malloc((wcount + 1) * sizeof(char*));
  char **tokens = token;
  char * endw = str;
  while(wcount>0){
    str = word_start(str);
    endw = word_terminator(str);
    *token = copy_str(str, endw - str);
    str = endw;
    token++;
    wcount--;
  }
  token = '\0';
  return tokens;
}
void print_tokens(char **tokens){
  int index = 0;
  while(*tokens){
    printf("tokens[%d]: %s\n",index,*tokens);
    tokens++;
    index++;
  }
}
void free_tokens(char **tokens){
  int index= 0;
  while (*(tokens + index) !=0){
    free(*(tokens + index));
    index++;
  }
  free(tokens);
  puts("All Tokens have been released");
}
