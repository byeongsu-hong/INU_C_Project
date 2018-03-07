#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

typedef struct idn {
    char *id;
    char *name;
}IdName;

#define MAXNAMEID 10000
#define HASHSIZE 2503
#define MAXLINE 1000
#define MAXWORD 100
#define MAXARGS 3

static char *getName(void *object);
static char *getId(void *object);

static HashTable    *ByName, *ById;

static int NumStudents = 0;
static IdName Students[MAXNAMEID];

int
main(int argc, char **argv) {
    char line[MAXLINE];
    char arg[MAXARGS][MAXWORD];
    int n;

    ByName = createHash(HASHSIZE, getName);
    ById = createHash(HASHSIZE, getId);

    while(fgets(line, MAXLINE, stdin) != (char *) NULL) {
        n = sscanf(line, "%s%s%s", arg[0], arg[1], arg[2]);

        if(n < 1) continue;
        if(strcmp(arg[0], "read") == 0) {

        } else if(strcmp(arg[0], "write") == 0) {

        } else if(strcmp(arg[0], "name") == 0) {
            
        } else if(strcmp(arg[0], "id") == 0) {
            
        } else if(strcmp(arg[0], "add") == 0) {
            if(n != 3) {
                printf("add: an id-name pair expected.\n"); continue;
            }
            addStudent(arg[1], arg[2]);
        } else if(strcmp(arg[0], "remove") == 0) {
            if(n != 3) {
                printf("remove: usage: remove (name|id) pattern\n"); continue;
            }
            if(strcmp(arg1[], "id") == 0) {
                if(!(pidName = lookUpHash(ById, arg[2]))){
                    printf("remove: unknown id \"%s\".\n", arg[2]; continue;)
                }
                removeStudent(pidName);
            } else if(strcmp(arg[1], "name") == 0) {
                if(!(pidName = lookUpHash(ByName, arg[2]))) {
                    printf("remove: unknown name \"%s\".\n", args[2]); continue;
                }
                removeStudent(pidName);
            }
        } else if(strcmp(arg[0], "quit") == 0) break;
        else if(strcmp(arg[0], "exit") == 0) break;
    }
}

addStudent(char *id, char *name)    {
    IdName *pidName;

    if(lookUpHash(ById, id)) {
        printf("add : id %s already exists.\n", id); return;
    }

    if(lookUpHash(ByName, name)) {
        printf("add : name %s already exists.\n", name); return;
    }

    pidName = Students + NumStudents++;
    pidName->id = strdup(id);
    pidName->name = strdup(name);
    installHash(ByName, (void *) pidName);
    installHash(ById, (void *) pidName);
}

static void
removeStudent(IdName *pidName) {
    IdName *pidName2;
    
    uninstallHash(ByName, pidName->name);
    uninstallHash(ById, pidName->id);
    free((void *) pidName->name);
    free((void *) pidName->id);
}

static char *
getName(void *object) {
    return (((IdName *) object)->name);
}

static char *
getId(void *object) {
    return (((IdName *) object)->name);
}