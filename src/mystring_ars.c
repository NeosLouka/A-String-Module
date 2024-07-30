/* mystring_ars.c */
#include <stdio.h>
#include <stddef.h>
#include <assert.h>


/*Return the length of string psStr.
	It is a checked runtime error for pcStr to be NULL */
size_t ms_length(const char pcStr[])
{
	size_t uiLength = 0U;
	assert(pcStr != NULL);
	while(pcStr[uiLength] != '\0')
	uiLength++;
	return uiLength;
}

/*Copies 'second' string to 'first' string 
  It is a checked runtime error for 'second' to be NULL
  Returns the address of first element of the copied array*/
char *ms_copy(char first[] , const char second[])
{
	size_t i = 0U;
	assert(second != NULL);
	while (second[i] != '\0')
	{
		first[i] = second[i];
		i++;
	}
	first[i] = '\0';
	return first;
	
}

/*Copies  n characters o*function in cf the 'second' string to 'first' string 
  It is a checked runtime error for 'second' to be NULL
  Returns the address for the first element of the copied array*/
char *ms_ncopy(char first[] , const char second[] , size_t n)
{

	size_t i;

	assert(second != NULL);
	for(i = 0; i < n; i++)
		first[i] = second[i];
	for(	; i < n ; i++)
		first[i] = '\0';
	return first;
}


/*Concatinates the end of the 'first' string with the 'second'.
It is a checked runtime error for 'second ' to be NULL
Returns the address for the  first element of the concatinated string 'first'*/
char *ms_concat(char first[] , const char second[] )
{
	size_t first_len = ms_length(first);
	size_t i;

	assert(second != NULL);

	for(i = 0; second[i] != '\0'; i++)
		first[first_len + i] = second[i];
	first[first_len + i ] = '\0';

	return first;
}



/*Concatinates n characters from the 'second' string to the end of the 'first' string.
It is a checked runtime error for 'second ' to be NULL
Returns the address for the  first element of the concatinated string 'first'*/
char *ms_nconcat(char first[] , const char second[] , size_t n)
{
	size_t first_len = ms_length(first);
	size_t i;

	assert(second != NULL);

	for(i = 0; i < n && second[i] != '\0'; i++)
		first[first_len + i] = second[i];
	first[first_len + i] = '\0';

	return first;

}

/*Compares the 'first' and 'second' string lexicographically
It is a checked runtime error for 'first' to be NULL
It is a checked runtime error for 'second' to be NULL
If 'first_string' == 'second_string' return 0
if 'first_string' > 'second_string' return positive number
if 'first_string' < 'second_string' return negative number*/
int ms_compare(const char first[] , const char second[])
{
	size_t i;
	assert(first != NULL);
	assert(second != NULL);

	for( i = 0; first[i] != '\0' || second[i] != '\0'; i++ )
	{
		if( first[i] == second[i] ) continue;
		else if( first[i] > second[i] ) return (first[i] - second[i]);
		else if( first[i] < second[i] ) return (first[i] - second[i]);
	}

	return 0;
}




/*Compares the first n characters ofthe 'first' and 'second' string lexicographically
It is a checked runtime error for 'first' to be NULL
It is a checked runtime error for 'second' to be NULL
If 'first_string' == 'second_string' return 0
if 'first_string' > 'second_string' return positive number
if 'first_string' < 'second_string' return negative number*/
int ms_ncompare(const char first[] , const char second[] , size_t n)
{
	size_t i;
	assert(first != NULL);
	assert(second != NULL);

	for( i = 0; i < n && (first[i] != '\0' || second[i] != '\0'); i++ )
	{
		if( first[i] == second[i] ) continue;
		else if( first[i] > second[i] ) return (first[i] - second[i]);
		else if( first[i] < second[i] ) return (first[i] - second[i]);
	}

	return 0;

}




/*char *ms_search( char str[] , const char search[])
{	size_t j = 0U;
	char *substring;

	while(*str != '\0'){
		if( *str == *search)
		{
			substring = str;
			for( ; *search != '\0'; search++)
			{	j++;
				substring++;
				if(*search == '\0') return str;

				if(*search != *substring )
				{
					search -= j;
					break;
				}
			}
		}
		str++;
	}
	return NULL;
}
*/


/*It returns a pointer to the first occurrence of 'search' in 'str' or a 
null pointer if 'search' is not part of 'str'*/
char *ms_search( char str[] , const char search[]){
	while(*str != '\0')
	{
		if((*str == *search) && ms_compare(str , search))
			return str;
		str++;
	}
	return NULL;
}
