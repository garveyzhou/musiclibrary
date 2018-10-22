#ifndef MUSIC_H
#define MUSIC_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mlist.h"
//s1 = song name ,s2 = artist
struct song_node * x;
void add_song(struct song_node * x, char * s1, char *s2);
struct song_node * search_song(struct song_node * x, char * s1,char *s2);
struct song_node * search_artist(struct song_node * x,char *s2);
void print_lib(struct song_node *x);
void print_artist(struct song_node * x,char * s2);
void print_letter(struct song_node * x,char * letter);
void print_shuffle(struct song_node * x);
void delete_song(struct song_node * x,char * s1, char *s2);
void clear_lib(struct song_node * x);
void print_artist (struct song_node * x, char * artist);

#endif
