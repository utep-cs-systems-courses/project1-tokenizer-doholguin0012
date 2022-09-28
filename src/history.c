#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  List *list = malloc(sizeof(List));
  list->root = NULL;
  return list;
}
void add_history(List *list, char *str){
  int id = 1;
  Item *temp = list->root;// getting the pointer address.
  Item *new = malloc(sizeof(Item));
  if(temp == NULL){// check if the items is Empty
    //puts("Im here");
    list->root = new;
    new->id = id;
    new->str = str;
    new->next = NULL;
  }
  else{
    // puts("Im in else");
    id++;
    while(temp->next != NULL){// travers to the end of the pointer
      // puts("did I enter here ");
      id++;
      temp = temp-> next;
    }
    temp->next = new; // adding a new Item on next pointer
    new->id = id;// id
    new->str = str;//string 
    new->next= NULL;//setting the next pointer to null
  }
}
char *get_history(List *list, int id){
  Item *temp = list->root;// create a temporary root item.
  if(temp->id == id){
    return temp->str;
  }
  else{
    while(temp !=NULL){// traversing the list
      if(temp->id == id){//check if id same
	return temp->str;
      }
      temp = temp->next;
    }
    return NULL;
  }
}
void print_history(List *list){
  Item *temp = list->root;
  if(temp == NULL){
    return;
  }
  else{
    while(temp !=NULL){
      printf("History number[%d]: %s\n",temp->id, temp->str);
      temp = temp->next;
    }
  }
}
void free_history(List *list){
  Item *temp = list ->root;
  Item *empty;
  if(temp == NULL){
    printf("there is nothing to be free \n");
    return;
  }
  else{
    while(temp !=NULL){
      empty = temp;
      temp = temp->next;
      free(empty);
    }
    printf("History has been free.\n");
  }
}
