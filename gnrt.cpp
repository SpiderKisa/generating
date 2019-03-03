#include <iostream>
#include <cstring>
#include "gnrt.h"


using namespace std;

const char *generate(char* s){
    if (strlen(s) == 0 || strlen(s) == 1){
        return s;
    }

    int n(1);
    for (int i = 1; i <= strlen(s); n = n * i, i++);
    char *all = new char [n];

    for (int i = 0; i < strlen(s); i++){
        char current = s[i];
        char *remaining = new char [strlen(s) - 1];
        strncpy(remaining, s, i);
        memcpy(remaining + strlen(remaining), s + i + 1, strlen(s) - i - 1 );
        const char *perms = generate(remaining);
        for (int j = 0; j < strlen(perms); j += strlen(s) - 1){
            char *add = new char [strlen(s)];
            add[0] = current;
            memcpy(add + 1, perms + j, strlen(s) - 1);
            strcat(all, add);
        }
    }

    return all;
}

void  printPerms(char* s){
    const char *perms = generate(s);
    for (int i = 0, count = 1; i < strlen(perms); i += strlen(s), count++){
        char *print = new char [strlen(s) +1];
        memcpy(print, perms + i, strlen(s));
        print[strlen(s)] = '\0';
        printf("%d.\t%s\n", count, print);
    }
}