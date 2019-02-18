#include <stdio.h>
#include <string.h>

#define MAXLINE 100 /* Maximum input line size */

void reverse(char from[], char to[]);

int main()
{
	char line[MAXLINE];
	char lineRev[MAXLINE];

	fgets(line, MAXLINE, stdin);

	reverse(line, lineRev);
	printf("%s\n", lineRev);
		
	return 0;
}

void reverse(char from[], char to[])
{
	int i, j;
	j = 0;
		
	for (i = strlen(from)-1; i >= 0; --i) {
		if (from[i] != '\0' && from[i] != '\n') {
			to[j] = from[i];
			++j;
		}
	}
	
	to[j] = '\0';

}
