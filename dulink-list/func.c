#include "list.h"
status initlist(dulinklist *l) {
	*l = malloc(sizeof(dulnode));
	if (!*l) return ERROR;
	(*l)->next = (*l)->prior = *l;
	return OK;
}

status destroylist(dulinklist *l) {
	dulinklist p = (*l)->next, q;
	while (p != *l) {
		q = p->next;
		free(p);
		p = q;
	}
	free(*l);
	*l = NULL;
	return OK;
}
dulinklist getelemp(dulinklist l,int i) {
	dulinklist p = l;
	int j;
	for (j = 1;j <= i;j++)p = p->next;
	return p;
}

int listlength(dulinklist l) {
	int i = 0;
	dulinklist p = l->next;
	while (p!=l) {
		i++;
		p = p->next;
	}
	return i;
}

status listinsert(dulinklist l, int i, elemtype e) {
	dulinklist p, new;
	if (i<1 || i>listlength(l) + 1) return ERROR;
	if (!(p = getelemp(l,i))) return ERROR;
	new = malloc(sizeof(dulnode));
	if (!new) return ERROR;
	new->prior = p->prior;
	p->prior->next = new;
	new->next = p;
	p->prior = new;
	new->data = e;
	return OK;
}

status listtraverse(dulinklist l) {
	dulinklist p = l->next;
	while (p!=l) {
		printf("%d\n", p->data);
		p = p->next;
	}
	return OK;
}