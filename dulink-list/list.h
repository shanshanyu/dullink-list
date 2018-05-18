#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef int elemtype;
typedef int status;
typedef struct dulnode {
	elemtype data;
	struct dulnode *prior;
	struct dulnode *next;
}dulnode,*dulinklist;
extern status initlist(dulinklist *l);
extern status destroylist(dulinklist *l);
extern dulinklist getelemp(dulinklist l, int i);
extern int listlength(dulinklist l);
extern status listinsert(dulinklist l, int i, elemtype e);
extern status listtraverse(dulinklist l);
#endif