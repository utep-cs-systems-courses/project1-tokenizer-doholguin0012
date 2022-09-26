#include <stdio.h>
#include "history.h"
#include "tokenizer.h"
#include <stdlib.h>

int main()
{
  while(1){
    char str [100];
    char c[100];
    List *history = init_history();
    printf("please choose the an option\n a) Tokenizer\n b) History\n q) quit \n>");
    fgets(c,sizeof(c),stdin);
    int clen = count_words(c);
    
    char *copy_c = copy_str(c, (word_terminator(c))-c);
    add_history(history, copy_c);
    switch(c[0]){
    case 'a':
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
      add_history(history,str);
      char **tokens = tokenize(str);
      print_tokens(tokens);
      free_tokens(tokens);
      break;
    case 'b':
      printf("string at [1]: %s \n",get_history(history,1));
      break;
    case 'q':
      goto done;
    default:
      puts("Not a choice try again!!");
      break;
    }
  }
 done:
 return 0;
  
}
