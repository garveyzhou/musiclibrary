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
  list = insert_order(list,"Sad","Trump");
  print_list(list);
  printf("\n");
  list = insert_order(list,"Sadder","America");
  print_list(list);
  
  printf("\n\ntesting searches\n");
  printf("looking for pearl jam\n");
  struct song_node * found = search_artist(list,"pearl jam");
  printf("%s : %s\n",found->artist,found->name);
  found = search_artist(list,"no way");
  printf("looking for no way\n");
  printf("%s \n",found);
  
  found = search_both(list,"even flow", "pearl jam");
  printf("looking for pearl jam : even flow\n");  
  printf("%s : %s\n",found->artist,found->name);
  printf("looking for pearl jam : Nani\n");
  found = search_both(list,"Nani", "pearl jam");
  printf("%s \n",found);

  
  return 0;
}
