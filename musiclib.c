#include "music.h"

void print_lib(struct song_node * table[]){
  int  i = 0
  while(i < 27){
    print_list(*table[i]);
    i++;
  }
}


void clear_lib(struct song_node * table[]){
  int i = 0;
  for (i < 27){
    *(table)[i] = free_list(lib[i]);
    i++;
  }
}
