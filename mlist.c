#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "mlist.h"

void print_list(struct song_node *x){
  struct song_node *head = x;
  while (head){
    printf("%s : %s,  ", head->artist,head->name);
    head = head->next;
  }
}

struct song_node * insert_front(struct song_node * x, char* s1,char* s2){
  struct song_node *new_node = malloc(sizeof(struct song_node));
  strcpy(new_node->name, s1);
  strcpy(new_node->artist, s2);
  new_node->next = x;
  return new_node;
}

struct song_node * free_list(struct song_node * x){
  struct song_node * temp;
  struct song_node * head = x;
  while(head){
    temp = head->next;
    free(head);
    head = temp;
  }
  return head;
}

struct song_node * insert_order(struct song_node * x,char* s1,char* s2){
  if(x){
   return insert_front(x,s1,s2);
  }
  struct song_node * new_node = malloc(sizeof(struct song_node));
  strcpy(new_node->name, s1);
  strcpy(new_node->artist, s2);
  struct song_node * before = NULL;
  while(x){
    if(strcmp(x->artist,new_node->artist) == 0){
      if(strcmp(x->name,new_node->name) <= 0){
	before->next = new_node;
	new_node->next = x;
	return new_node;
      }
    }
    if(strcmp(new_node->artist,x->artist) < 0){
      before->next = new_node;
      new_node->next = x;
      return new_node;
    }
    before = x;
    x= x->next;
  }
  return new_node;
}

struct song_node * search_both(struct song_node * x, char * s1, char * s2){
  struct song_node * head = x;
  while(head){
    if(!(strcmp(head->name,s1)) && !(strcmp(head->artist,s2))){
      return head;
    }
    head = head->next;
  }
  return NULL;
}

struct song_node * search_artist(struct song_node * x, char * s2){
  struct song_node * head = x;
  while(head){
    if(!(strcmp(head->artist,s2))){
      return head;
    }
    head = head->next;
  }
  return NULL;
}

struct song_node * random_node(struct song_node * x){
  struct song_node * head = x;
  struct song_node * length = x;
  int counter = 0;
  while(length){
    counter++;
    length = length->next;
  }
  counter = rand() % counter;
  while(counter){
    counter --;
    length = length -> next;
  }
  return length;
}

struct song_node * delete_node(struct song_node * x, char * s1,char * s2){
  struct song_node * head = x;
  struct song_node * before;
  struct song_node * after;
  while(head){
    if(!(strcmp(head->name,s1)) && !(strcmp(head->artist,s2))){
      
      return head;
    }
    head = head -> next;
  }
  return 0;
}


    
