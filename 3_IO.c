#include <stdio.h>


// ---------------------------------------------------------------------------
// ############ scanf() ############
// ---------------------------------------------------------------------------
// scanf() returnerer antall characters skrevet, hvis ikke et negativt tall.
// Kan overskrive minne utenfor arrayet.
// Brukeren vil ikke kunnet taste inn mellomrom med mindre det er definert hvordan.
// char firstName[30], lastName[30];
// printf("What is your name?\n");
// scanf("%s %s", firstName, lastName);
// printf("Your name is %s %s\n", firstName, lastName);

// ---------------------------------------------------------------------------
// ############ getchar, putchar and buffering ############
// ---------------------------------------------------------------------------
void readAndPrintBack()
{
	printf("Skriv s for a ga videre");
	char theChar;
	while((theChar = getchar()) != 's') {
		putchar(theChar);
	}
}
// ---------------------------------------------------------------------------
// ############ gets(), puts() ############
// ---------------------------------------------------------------------------
// gets() leser til '\n' er trykket. Sjekker ikke om det er plass i arrayet.
// puts() mottar en string og printer den ut etterfulgt av newline.
// char name[20];
// printf("What is your name? ");
// gets(name);
// puts(name);
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// ############ fgets(), fputs() ############
// ---------------------------------------------------------------------------
// fgets() leser til array lengden eller '\n' og tar med '\n'
// fputs() printer arrayet uten '\n'
// printf("What is your name? ");
// fgets(name, 20, stdin);
// fputs() prints strings without a \n
// fputs(name, stdout);
// ---------------------------------------------------------------------------

void stringInput(char enString[], int length)
{
    int position = 0;
    char theChar;
    while ((theChar = getchar()) != '\n' && position < length){
        enString[position] = theChar;
        position++;
    }
    enString[position] = '\0';
}

void stringOutput(char *aString)
{
	// while continues until it reaches a null character
	char* String = aString;
	while(*String) putchar(*String++);
}


void strReverseOutput(char *aString) {

    printf("The word reversed is '");
    int len = stringLengde(aString, '\0')-1;
    char* String = aString + len;
    while(len > -1){
        putchar(*String--);
        len--;
    }
    printf("'\n");
}