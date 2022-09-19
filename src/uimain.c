#include <stdio.h>
#include "history.h"
#include "tokenizer.h"
#include <stdlib.h>

int main()
{
  while(1){
    char choice [10];
    char sentence [100];
    printf("please choose the an option\n a) Tokenizer\n b) History\n q) quit \n>");
    fgets(choice,sizeof(choice),stdin);
    switch(choice[0]){
    case 'a':
      printf("You have choosen the Tokenizer option \n please enter a sentecne or word: \n>");
      fgets(sentence, sizeof(sentence),stdin); //getting the sentence or words.
      printf("1:true 0:false [%d]\n",space_char(sentence[0])); //getting the sentence to the Token object.
      printf("1:true 0:false [%d]\n",non_space_char(sentence[0]));
      break;
    case 'b':
      break;
    case 'q':
      goto done;
    }
  }
 done:
 return 0;
  
}
