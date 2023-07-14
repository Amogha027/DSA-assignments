#include <stdio.h>
#include "node.h"
#include "my_dll.h"
#include <string.h>

int main()
{
	int n, k;
	char ch[20];
	DLL list;
	while (1)
	{
		printf("> ");
		scanf("%s", ch);
		if (strcmp(ch, "quit") == 0)
			break;
		else if (strcmp(ch, "insert") == 0)
		{
			scanf("%d", &n);
			insert(list, n);
		}
		else if (strcmp(ch, "insert_at") == 0)
		{
			scanf("%d %d", &n, &k);
			insert_at(list, n, k);
		}
		else if (strcmp(ch, "delete") == 0)
		{
			scanf("%d", &n);
			delete (list, n);
		}
		else if (strcmp(ch, "find") == 0)
		{
			scanf("%d", &n);
			printf("%d\n", find(list, n));
		}
		else if (strcmp(ch, "prune") == 0)
			prune(list);
		else if (strcmp(ch, "print") == 0)
			print(list);
		else if (strcmp(ch, "print_reverse") == 0)
			print_reverse(list);
		else if (strcmp(ch, "get_size") == 0)
			printf("%d\n", get_size(list));
		else
			printf("INVALID\n");
	}

	return 0;
}