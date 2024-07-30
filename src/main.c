/* main.c */
#include<stdio.h>
#include "mystring.h"

int main()
{
	char str1[] = "abcdefg";
	char str2[] = "be";

	char *rep = ms_search(str1 , str2);

	printf("%s\n", rep);

	return 0;
}
