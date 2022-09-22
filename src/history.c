#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  List *list = malloc(sizeof(List));
  list->root = malloc(sizeof(Item));
  return list;
}
void add_history(List *list, char *str){
  Item *h = (Item*) malloc(sizeof(Item));
  int id = 0;
  h->str = str;

  if(list->id == 0){
    h->next = NULL;
    list->root = h;
  }
  else{
    h->next = list->root;
    list ->root = h;
  }
  list -> id++;
}
char *get_history(List *list, int id){
  Item *temp= list -> root;// temporary list
  while( temp != NULL){
    if( temp -> id == id) {
      return temp -> str;
    }
    temp = temp -> next;
  }
  puts("No History found");
  return NULL;
}
void print_history(List *list){
  if(!list){
    puts("There is no log Histroy!");
  }
  else{
    Item *temp = list-> root;
    while(temp != NULL){
      printf("user input [%d]: %s \n" temp->id ,get_history(list,temp->id));
      temp = temp-> next;
    }
  }
}
