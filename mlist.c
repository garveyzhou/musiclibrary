#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node *x){
  struct song_node *head = x;
  while (head){
    printf("%s- %s,  ", head->artist,head->name);
    head = head->next;
  }
}

struct song_node * insert_front(struct song_node * x, char[] s1,char[] s2){
  struct song_node *new_node = malloc(sizeof(struct song_node));
  new_node->name = s1;
  new_node->artist = s2;
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

struct song_node * insert_order(struct song_node * x,char[]s1,char[] s2){
  return x;
}
