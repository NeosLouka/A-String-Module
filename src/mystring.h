/* mystring.h */
#include<stdio.h>
#include<assert.h>
#include<stddef.h>


size_t ms_length(const char pcStr[]);
char *ms_copy(char first[] , char second[]);
char *ms_ncopy(char first[] , char second[] , size_t n);
char *ms_concat(char first[] , char second[] );
char *ms_nconcat(char first[] , char second[] , size_t n);
int ms_compare(char first[] , char second[]);
int ms_ncompare(char first[] , char second[] , size_t n);
char *ms_search(const char str[] , const char search[]);
