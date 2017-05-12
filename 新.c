#include <stdio.h>
#define MAX_NUM 1000

int main()
{
	int a[MAX_NUM], n = 0, i, j;
	int insert;
	char c;

	while (scanf("%d%c", a + (n++), &c) && c != '\n');
	scanf("%d", &insert);

	for (i = 0; i < n && insert < a[i]; i++);
	for (j = n; j > i; j--) a[j] = a[j - 1];
	a[i] = insert;
	n++;

	for (i = 0; i < n; i++)
		printf("%d\n", a[i]);
	return 0;
}
