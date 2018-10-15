struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
};
void print_list(struct song_node *x);
struct song_node * insert_front(struct song_node * x,char[] s1, char[] s2);
struct song_node * free_list(struct song_node * x);
struct song_node * insert_order(struct song_node * x,char[] s1, char[] s2);
struct song_node * search_both(struct song_node * x,char[] s1, char[] s2);
struct song_node * search_artist(struct song_node * x,char [] s2);
struct song_node * random_node(struct song_node * x);
struct song_node * delete_node(struct song_node * x,char[] s1,char[] s2);
