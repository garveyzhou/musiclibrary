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

  printf("TESTING LIBRARY\n");

  printf("add_song:\n");
  struct library * myLib = malloc(sizeof(struct library)); 
  myLib = add_song(myLib, "Palm Trees", "FBZ");
  myLib = add_song(myLib, "Inf Beams", "FBZA");
  myLib = add_song(myLib, "Bounce", "FBZB");
  myLib = add_song(myLib, "R.I.P.C.D", "FBZC");
  myLib = add_song(myLib, "New Phone, Who Dis?", "FBZD");
  myLib = add_song(myLib, "Acension", "FBZE");
  myLib = add_song(myLib, "Tradeoff", "FBZF");
  myLib = add_song(myLib, "A Spike Lee Joint", "FBZG");

  printf("print_library:\n");
  print_library(myLib);

  printf("find_song:\n");
  printf("Looking for This Is It by FBZH: \n");
  print_song(find_song(myLib, "This Is It", "FBZI"));

  printf("search_arist:\n");
  printf("Looking for song by FBZ: \n");
  print_song(search_arist(myLib, "FBZ"));

  printf("print_letter\n");
  printf("Songs by artists starting with 'F'\n");
  print_letter(myLib, 'F');

  printf("print_artist\n");
  printf("Songs by 'FBZA':\n");
  print_artist(myLib, "FBZA");

  printf("print_shuffle\n");
  print_shuffle(myLib);

  printf("delete_song\n");
  printf("Deleting A Spike Lee Joint by FBZG\n");
  myLib = delete_song(myLib, "A Spike Lee Joint", "FBZG");
  print_lib(myLib);

  printf("clear_library\n");
  clear_lib(myLib -> table);
  return 0;
}

