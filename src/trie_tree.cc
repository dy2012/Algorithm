#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define maxn 26
struct Trie {
    int num;
    struct Trie *next[maxn];
};

struct Trie *root = (struct Trie*)malloc(sizeof(struct Trie));

void initialize() {
    root->num = 0;
    for (int i = 0; i < maxn; ++i) {
        root->next[i] = NULL;
    }
}

void insert(char *str) {
    int len = strlen(str);
    struct Trie *p = root;
    for (int i = 0; i < len; ++i) {
      int pos = str[i] - 'a';
      if (p->next[pos] == NULL) {
          struct Trie *temp = (struct Trie*) malloc(sizeof(struct Trie));
          temp->num = 1;
          for (int j = 0; j < maxn; ++j) {
              temp->next[j] = NULL;
          }
          p->next[pos] = temp;
          p = p->next[pos];
      } else {
        p = p->next[pos];
        p->num++;
      }
    }
}

int find(char *str) {
    struct Trie *p = root;
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
      int pos = str[i] - 'a';
      p = p->next[pos];
      if (p == NULL) {
          return 0;
      }
    }
    return p->num;
}

int main() {
    char s[15];
    initialize();
    while(gets(s) && strlen(s)) {
        insert(s);
    }
    while (gets(s)) {
        int ans = find(s);
        printf("%d\n", ans);
    }
    return 0;
}
