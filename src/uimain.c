#include <stdio.h>
#include "history.h"
#include "tokenizer.h"
#include <stdlib.h>

short word_Lenght(char *s){
  short count = 0;
  while(*s !='\0'){
    count +=1;
    s++;
  }
  return count;
}

int main()
{
  char *p = malloc((100) * sizeof(char));
  char *copy = p;
  char *stp = malloc((100) * sizeof(char));
  char *scopy= stp;
  List *history = init_history();
  while (1)
    {
    char str [100];
    char c[100];
    char *x,*y;
    printf("please choose the an option\n a) Tokenizer\n b) History\n q) quit \n>");
    fgets(c,sizeof(c),stdin);
    switch(c[0]){
    case 'a':
      x= word_start(c);
      y= word_terminator(c);
      p = copy_str(c,y-x);
      add_history(history,p);
      printf("You have choosen the Tokenizer option \n please enter a sentecne or word: \n>");
      fgets(str, sizeof(str),stdin);//getting the sentence or words.
      
      /* debbuging <- phases delete or remove this part and the last (* /)
      printf("1:true 0:false [%d]\n",space_char(str[0])); //getting the sentence to the Token object.
      printf("1:true 0:false [%d]\n",non_space_char(str[0]));
      puts(word_start(str));
      puts(word_terminator(str));
      printf("The total amount of words are: [%d]\n",count_words(str));
      char *stest = word_start(str);
      char *etest = word_terminator(str);
      char *test = copy_str(str, etest - stest);
      puts(test);
      */
      stp = copy_str(str, word_Lenght(str));
      add_history(history,stp);
      char **tokens = tokenize(str);
      print_tokens(tokens);
      free_tokens(tokens);
      break;
    case 'b':
      x= word_start(c);
      y= word_terminator(c);
      p = copy_str(c,y-x);
      add_history(history,p);
      print_history(history);
      break;
    case 'q':
      goto done;
    default:
      puts("Not a choice try again!!");
      break;
    }
    p++;
    stp++;
  }
 done:
  free_history(history);
  return 0;
}
