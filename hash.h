#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 10
#define MAX_NAME 100

typedef struct person {
    char name[MAX_NAME];
    int age;
    struct person* next;
} person;

/* return a pointer to the hash table of pointers to persons */
person** make_hash_table(void) {
    person** h = malloc(sizeof(person*) * TABLE_SIZE);
    /* initializing the hash table */
    for (int i = 0; i < TABLE_SIZE; i++) {
        h[i] = NULL;
    }
    return h;
}


/* return the hash to the given string */
int hash_function(char* s) {
    unsigned result = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        result += s[i];
        result = result * s[i];
    }
    return result % TABLE_SIZE;
}

/* print out the hash table */ 
void print_hash_table (person ** table) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == NULL) {
            printf("%d -----> NULL\n", i);
        } else {
            person* try = table[i];
            printf("%d -----> ", i);
            while (try != NULL) {
                printf("%s %d -> ", try->name, try->age);
                try = try->next;
            }
            printf("END\n");
        }
    }
}


void add_to_hash_table(person** h, person* p) {
    unsigned index = hash_function(p->name);
    
    //person* temp = p;
    p->next = h[index];
    h[index] = p;
}

person* extract_from_hash_table(person*p, person** h) {
    unsigned index = hash_function(p->name);
    person* temp = h[index];
    while (temp != NULL) {
        if (strcmp(temp->name, p->name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


person* make_person(char* n, int a) {
    person* new = malloc(sizeof(person));

    strcpy(new->name, n);
    new->age = a;
    new->next = NULL;

    return new;
}

void delete_from_hash_table(person* p, person** h) {
    unsigned index = hash_function(p->name);

    person* temp = h[index];
    person* prev = NULL;
    while (temp->next != NULL) {
        if (strcmp(temp->name, p->name) == 0) {
            prev->next = temp->next;
        }
        prev = temp;
        temp = temp->next;
    }
}
