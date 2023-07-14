#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "complex.h"

int main()
{
	int n;
	char ch[10];
	scanf("%s %d", ch, &n);

	if (strcmp(ch, "MOD") == 0)
	{
		Complex c = INIT(n);
		for (int i = 0; i < n; i++)
			scanf("%f", &(c->terms[i]));

		printf("%.2f\n", MOD(c));
	}
	else
	{
		Complex c1 = INIT(n);
		Complex c2 = INIT(n);

		for (int i = 0; i < n; i++)
			scanf("%f", &(c1->terms[i]));

		for (int i = 0; i < n; i++)
			scanf("%f", &(c2->terms[i]));

		if (strcmp(ch, "ADD") == 0)
		{
			Complex c = ADD(c1, c2);
			for (int i = 0; i < c->num; i++)
				printf("%f ", c->terms[i]);
			printf("\n");
		}
		else if (strcmp(ch, "SUB") == 0)
		{
			Complex c = SUB(c1, c2);
			for (int i = 0; i < c->num; i++)
				printf("%f ", c->terms[i]);
			printf("\n");
		}
		else if (strcmp(ch, "DOT") == 0)
			printf("%.2f\n", DOT(c1, c2));
		else if (strcmp(ch, "COS") == 0)
			printf("%f\n", COS(c1, c2));
		else
			printf("INVALID\n");
	}

	return 0;
}