#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "mlist.h"

int main(){
  struct song_node * list = NULL; 
  printf("testing print_list\n");
  print_list(list);
  printf("testing insert_front\n");
  list = insert_front(list,"Warriors","Imagine Dragons");
  print_list(list);
  printf("\ntesting insert_order\n");
  list = insert_order(list,"Song","artist");
  print_list(list);
  printf("\n");
  list = insert_order(list,"even flow","pearl jam");
  print_list(list);
  printf("\n");
  list = insert_order(list,"daughter","pearl jam");
  print_list(list);
  printf("\n");
  list = insert_order(list,"Sad","Tick");
  print_list(list);
  printf("\n");
  list = insert_order(list,"Sadder","Aight");
  print_list(list);
  
  printf("\n\ntesting searches\n");
  printf("looking for pearl jam\n");
  struct song_node * found = search_artist(list,"pearl jam");
  printf("%s : %s\n",found->artist,found->name);
  
  printf("looking for no way artist\n");
  search_artist(list,"no way");
  
  found = search_both(list,"even flow", "pearl jam");
  printf("looking for pearl jam : even flow\n");  
  printf("%s : %s\n",found->artist,found->name);
  printf("looking for pearl jam : Nani\n");
  search_both(list,"Nani", "pearl jam");
  
  printf("testing deleting\n");
  printf("deleting Aight:Sadder\n");
  list = delete_node(list,"Sadder","Aight");
  print_list(list);
  printf("\ndeleting pearl jam: even flow\n");
  list = delete_node(list,"even flow","pearl jam");
  print_list(list);

  printf("\ntesting random\n");
  struct song_node * random_one = random_node(list);
  printf("%s : %s\n", random_one ->artist, random_one->name);
  random_one = random_node(list);
  printf("%s : %s\n", random_one ->artist, random_one->name);
  random_one = random_node(list);
  printf("%s : %s\n", random_one ->artist, random_one->name);


  printf("\ntesting clear_list\n");
  list = free_list(list);
  printf("printing list: \n");
  print_list(list);
  return 0;
}
