#include "list.h"
int main() {
	dulinklist l;
	initlist(&l);
	int a[] = { 1,2,3,4,5 };
	for (int i = 1;i <= 5;i++)listinsert(l, i, a[i - 1]);
	listtraverse(l);
	destroylist(&l);
	system("pause");
	return 0;
}