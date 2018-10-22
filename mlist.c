#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "mist.h"

struct song_node * insert_front (struct song_node * n, char * song_name, char * song_artist) {
  struct song_node * head = malloc(sizeof(struct song_node));
  strcpy(head -> name, song_name);
  strcpy(head -> artist, song_artist);
  head -> next = n;
  return head;
}

void print_song (struct song_node * n) {
  while (n) {
    printf("%p (%s by %s) -> %p\n", n, n->name, n->artist, n->next);
    n = n-> next;
  }
}

int compare_song(struct song_node * one, struct song_node * two){
  if(strcmp(one->artist, two->artist) < 0){
    return -1;
  }else if(strcmp(one->artist, two->artist) > 0){
    return 1;
  }else{
    if(strcmp(one->name, two->name) < 0){
      return -1;
    }
    else{
      return 1;
    }
  }
}

struct song_node * insert_order( struct song_node * head, char name[100], char artist[100]){
  struct song_node * add = malloc(sizeof(sizeof(struct song_node)));
  strcpy(add->name, name);
  strcpy(add->artist, artist);

  if(head == NULL || compare_song(add, head) < 0){
    return insert_front(head, name, artist);
  }else if((head->next) == NULL){ 
    if(compare_song(add, head) < 0){ 
      return insert_front(head, name, artist);
    }else{ 
      head->next = add;
      add->next = NULL;
      return head;
    }
  }else{

    struct song_node * current = head;

    while((current->next != NULL) && (compare_song(add, current->next) > 0)){
      current = current->next;
    }
    if(current->next){ 
      add->next = current->next;
      current->next = add;
    }else{ 
      current->next = add;
      add->next = NULL;
    }

    return head;
  }
}

struct song_node * get_song (struct song_node * head, char * name, char * artist) {
   while (head){
    if(strcmp(head -> name, name) == 0 && strcmp(head -> artist, artist) == 0) {
      return head;
    }
    head = head -> next;
  }
}

struct song_node * get_artist (struct song_node * head, char * artist) {
  while (head) {
    if (strcmp(head -> artist, artist) == 0) {
      return head;
    }
    head = head -> next;
  }
  return NULL;
}

int get_length (struct song_node * head) {
  int count = 0;
  while (head) {
    count++;
    head = head -> next;
  }
  return count - 1;
}

struct song_node * random_node (struct song_node * head) {
  int num = rand() % get_length(head);
  int cur = 0;
  while (cur < num) {
    head = head -> next;
    cur++;
  }
  return head;
}

struct song_node * delete_node(struct song_node *head, char *name, char *artist) {
    struct song_node *temp = head;
    if ( !strcmp(head->name, name) && !strcmp(head->artist, artist) ) {
        temp = head;
        free(head);
        head = NULL;
        head = temp->next;
    }
    else {
        while(head->next) {
            if ( !strcmp((head->next)->name, name) && !strcmp((head->next)->artist, artist) ) {
                temp = head->next;
                free(head->next);
                head->next = (temp->next)->next;
            }
        head = head->next;
    }
      return head;
  }
}

struct song_node * free_list(struct song_node * n){
  while (n) {
    struct song_node * temp = n->next;
    free(n);
    n = temp;
    }
    return NULL;
}
