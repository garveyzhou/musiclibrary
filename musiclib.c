#include <stdx.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mlist.h"


int char_to_index (char c) {
  if (isalpha(c)) {
    return c -'A';
  }
  return 26;
}

struct song_node * add_song (struct song_node * x, char * name, char * artist) {
  x -> table[char_to_index(artist[0])] = insert_order(x -> table[char_to_index(artist[0])], name, artist);
  x -> totalSongs = x -> totalSongs + 1;
  return x;
}

struct song_node * search_song (struct song_node * x, char * name, char * artist) {
  return get_song(x -> table[char_to_index(artist[0])], name, artist);
}

struct song_node * search_arist (struct song_node * x, char * artist) {
  return get_artist(x -> table [char_to_index(artist[0])], artist);
}

struct song_node * random_node (struct song_node * x) {
  struct song_node * random = x -> table [0];
  while (get_length(random) < 1) {
    random = x -> table [rand() % 26];
  } 
  return random_node(random);
}

void print_letter (struct song_node * x, char c) {
  print_song(x -> table[char_to_index(c)]);
}

void print_artist (struct song_node * x, char * artist) {
  struct song_node * temp = x -> table[char_to_index(artist[0])];
  while (get_artist(temp, artist) != NULL) {
    printf("-%s\n", get_artist(temp, artist) -> name);
    temp = get_artist(temp, artist) -> next;
  }
}

void print_lib(struct song_node * x){
    for(int i = 0; i < 27; i++){
      struct song_node * n = x->table[i];
      if (n) {
        printf("-------------------------\n");
        print_song_node(n);
        printf("-------------------------\n");
      }
    }
}

void print_shuffle (struct song_node * x) {
  for (int i = 0; i < 3; i++) {
    struct song_node * temp = random_node(x);
    printf("-%s by %s\n", temp -> name, temp -> artist);
  }
}

struct song_node * delete_song(struct song_node * x, char * name, char * artist){
    x->table[char_to_index(artist[0])] = delete_node(x->table[char_to_index(artist[0])], name, artist);
    x->totalSongs--;
    return x;
} 

void clear_lib(struct song_node * lib [27]){
   for (int i = 0; i < 27; i++) {
    free_list(lib[i]);
    lib[i] = NULL;
  }
}