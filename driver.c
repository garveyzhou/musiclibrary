#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "mlist.h"

int main(){
  struct song_node * list = 0; 
  printf("testing print_list\n");
  print_list(list);
  printf("testing insert_front\n");
  int i = 0;
  while(i < 5){
    list = insert_front(list,"Song","artist");
    i++;
  }
  print_list(list);
  return 0;
}
