#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int stringLengde(char enString[], char stopChar)
{
    int count = 0;
    while(enString[count] != stopChar) count++;
    return count;
}


int areEqual(char setning1[], char setning2[]){

    if(stringLengde(setning1, '\0') != stringLengde(setning2, '\0')) return 0;
    for(int i = 0; i < stringLengde(setning1, '\0'); i++) if(setning1[i] != setning2[i]) return 0;
    return 1;
}


void makeLowercase(char* string)
{
	int i = 0;
	while(string[i])
	{
		string[i] = tolower(string[i]);
		i++;
	}
}


void makeUppercase(char* string, int length)
{
	for(int i = 0; i<length; i++) string[i] = toupper(string[i]);
}


void removeNewline(char* string, int length)
{
	// strchr() returns a pointer to the first location of the char given.
	// isANewline = strrchr(string, '\n');
	// if(isANewline)
	for(int i; i < length; i++)
	{
		if(string[i] == '\n') {
			string[i] = '\0';
			return;
		}
	}
}


void strSplit(char* from, char* left, char* right)
{
    size_t length = stringLengde(from, '\0');
    size_t middle = length/2;
    for(size_t i = 0; i<middle; i++) left[i] = from[i];
    for(size_t j = middle; j<length; j++) right[j - middle] = from[j];
}


int isSubstring(char *haystack, char *object)
{
    int objectLen = stringLengde(object, '\0');
    int hayLen = stringLengde(haystack, '\0');

    for(int i = 0; i<hayLen; i++){
        if(haystack[i] == object[0]) {
            int count = 0;
            for(int j = 0; j<objectLen; j++) {
                if(haystack[i+j] == object[j]) {
                    count++;
                    if(count == objectLen) return 1;
                }
            }
        }
    }
    return 0;
}


void getCharInfo()
{
	char theChar;
	printf("Skriv en bokstav\n");
	while ((theChar = getchar()) != '\n'){
		printf("Letter or Number %d\n", isalnum(theChar));
		printf("Alphabetic Char %d\n", isalpha(theChar));
		printf("Standard Blank %d\n", isblank(theChar));
		printf("Ctrl Char %d\n", iscntrl(theChar));
		printf("Number Char %d\n", isdigit(theChar));
		printf("Anything But Space %d\n", isgraph(theChar));
		printf("Lowercase %d\n", islower(theChar));
		printf("Uppercase %d\n", isupper(theChar));
		printf("Anything not a Letter, Number or Space %d\n\n", ispunct(theChar));
		printf("Any Space %d\n", isspace(theChar));
	}
}


void mystrncpy(char* src, char* dest, int len)
{
    for(int i = 0; src[i] != '\0' && i<len; i++) dest[i] = src[i];
}


void reverse_strncpy(char* src, char* dest, int len)
{
    for(int i = 0; src[i] != '\0' && i<len; i++) dest[len-2-i] = src[i];
    dest[len-1] = '\0';
}


char* reverse_str(char* src, int len)
{
    char* dest = (char*) malloc(len);
    for(int i = 0; src[i] != '\0' && i<len; i++) dest[len-2-i] = src[i];
    return dest;
}


void main()
{
	char* string = {"Hallo"};
	char* string2 = {"Hei"};
	charArray(string);
	//strcpy(string, string2);
}