#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// A file is a block of memory with a name
// The file can be stored across many blocks of memory,
// but the C compiler acts as if it in sequence.


// ------------ ------------ fopen() ------------ ------------
// Files represented as text files.
// fopen() returnerer en peker til fila eller NULL hvis fila ikke ble åpnet.

// r    open for reading
// w    open for overwrite (if doesnt exsist creates it)
// a    open for appending (if doesnt exsist creates it)
// r+   read and write (start beginning)
// w+   read and write/overwrite
// a+   read and append (if doesnt exsist creates it)

// overwrite means it deletes original

// ------------ ------------ set file pointer fseek() ftell() rewind() ------------ ------------

	// SEEK_SET - Move starting from the beginning of the file
	// SEEK_CUR - Move based off of the current position in the file
	// SEEK_END - Move based off of starting at the end of the file
	
/*	fseek(pFile, 12, SEEK_SET); 			// Move 12 spaces from the beginning of the file
	fputs("Files", pFile); 					// Overwrite characters starting at char number 12
	fseek(pFile, -12, SEEK_CUR)				// This moves backwards 12 bytes in the file
	long numberOfBytes = ftell(pFile); 		// ftell() tells you how far you are currently from the beginning of the file
	rewind(pFile);							// sets the pointer back to the beginning of the file 		*/
long getFileSize(char* filePath)
{
    FILE* pFile = fopen (filePath, "r");
    if(pFile == NULL) perror("Error opening file");
    fseek(pFile , 0, SEEK_END);			    // Go to the end of the file
    long fileSize = ftell(pFile);
    rewind(pFile);
    fclose(pFile);
    return fileSize;
}


// ------------ ------------ fclose() ------------ ------------
// fclose() closes the text file to avoid that the program run out of file handlers or memory


// ------------ ------------ fgetc() ------------ ------------
// fgetc(FILE *stream) gets the next character (1 byte) (an unsigned char) 
// from the specified stream and advances the position indicator for the stream.
// This function returns the character read as an unsigned char 
// cast to an int or EOF on end of file or error.
// leser en og en byte helt til \n
void fstrRead(char string[], char* filePath)
{
	FILE* pFile = fopen(filePath, "r");
    int position = 0;
    char theChar;
    while ((theChar = (char)fgetc(pFile)) != '\n'){
        string[position] = theChar;
        position++;
    }
    string[position] = '\0';
    fclose(pFile);
}

// copy chars from a txt file to a string buffer.
void fileToBuffer(char string[], char* filePath)
{
    long fileSize = getFileSize(filePath);
    FILE* pFile = fopen(filePath, "r");
    char theChar;
    for(int i = 0; i<fileSize; i++)
    {
        theChar = (char) fgetc(pFile);
        string[i] = theChar;
    }
    string[fileSize] = '\0';
}

// ------------ ------------ fputc() ------------ ------------
// int fputc(int char, FILE *stream)
// If there are no errors, the same character that has been written is returned.
// If an error occurs, EOF is returned and the error indicator is set.
void fstrWrite(FILE* pFile, char string[], int chars)
{
	for(int i = 0; i<chars; i++) fputc(string[i], pFile);
}


// ------------ ------------ fprintf() ------------ ------------
void writeFile0()
{
   	FILE * pFile = fopen ("file.txt", "w+");
	fprintf(pFile, "%s %s %s %d", "We", "are", "in", 2012);
   	fclose(pFile);
}

// ------------ ------------ fscanf() ------------ ------------

void readFile0() {
	FILE* pFile = fopen("data.txt", "r");
	int number;
	fscanf(pFile, "%i", &number);
	fclose(pFile);
}
// fscanf() returns a number other then 1 if it isn't a string
int readAndPrintFile(char* filePath)
{	
	char buffer[1000];
	FILE* pFile = fopen(filePath, "r");
	
	while(fscanf(pFile, "%s", buffer) == 1) puts(buffer);
	fclose(pFile);
}


// ------------ ------------ fputs() ------------ ------------
int writeFile(char *input, char *filePath)
{   
   FILE * pFile = fopen(filePath, "w");
   if(!pFile) {
		printf("Error : Couldn't Write to File\n");
		return 1;
	}
   fputs(input, pFile);
   fclose(pFile);
   if(fclose(pFile) != 0) printf("Error : File Not Closed\n");
}


// ------------ ------------ fgets() ------------ ------------
// reads up to 1,000 characters per line until
// and returns the value of NULL when it reaches the end of the file
int readFile(char* output, char* filePath, int charsToRead)
{
	FILE* pFile = fopen(filePath, "r");
	if(!pFile){
		printf("Error : Couldn't Read the File\n");
		return 1;
	}
	fgets(output, charsToRead, pFile);
	fclose(pFile);
	if(fclose(pFile) != 0) printf("Error : File Not Closed\n");
}


// ------------ ------------ file IO with structs ------------ ------------
struct Student {
    int studentID;
    char name[20];
    int age;
};

int readStudentFile(struct Student* theStudent, char* filePath) {

    FILE* pFile = fopen(filePath, "r");
    if(!pFile) {
        printf("Error: couldnt read the file\n");
        return 1;
    }
    printf("File is open\n");

    fscanf(pFile, "%i\n", &theStudent->studentID);
    //fstrInput(theStudent->name, pFile);
    fscanf(pFile, "\n%i", &theStudent->age);

    fclose(pFile);
    if(fclose(pFile) != 0) printf("Error: file not closed\n");
}

int writeStudentFile(struct Student* theStudent, char* filePath) {

    FILE* pFile = fopen(filePath, "w");
    if(!pFile) {
        printf("Error: couldnt read the file\n");
        return 1;
    }
    printf("File is open\n");
    fprintf(pFile, "%i\n%s\n%i", theStudent->age, theStudent->name, theStudent->studentID);

    fclose(pFile);
    if(fclose(pFile) != 0) printf("Error: file not closed\n");
}


// ------------ ------------ file IO in binary mode ------------ ------------

// Two functions for binary mode:
// size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *file);            
// size_t fwrite(const void* buffer, size_t buffer_element_size, size_t number_of_elements, FILE *a_file);

void writeToFileBinary(char* filePath)
{	
	FILE* pFile = fopen(filePath, "rb+");						// Opens the file using binary mode
	if(pFile == NULL)
	{
	perror("Error Occurred");									// Prints the string provided followed by the
	printf("Error Code: %d\n", errno);							// standard error message and assign an error
	printf("File Being Created\n");								// code to the variable errno
	pFile = fopen("C:/Users/Eivind/Desktop/Tekst.txt", "wb+");	// Create the file
	if(pFile == NULL)
	{
		perror("Error Occurred");
		printf("Error Code: %d\n", errno);
		exit(1);
	}

	char name[] = "Eivind";
	fwrite(name, sizeof(name[0]), sizeof(name)/sizeof(name[0]), pFile);
	fclose(pFile);
}

void readFromFileBinary(size_t fileSize)
{
    char* buffer = (char*) malloc(sizeof(char)*fileSize);
    if(buffer == NULL)
    {
    	perror("Error Occurred");
		printf("Error Code: %d\n", errno);
    	exit(2);
    }
    size_t dataInFile = fread(buffer, 1, fileSize, pFile);
    if(dataInFile != fileSize)
    {
    	perror("Error Occurred");
		printf("Error Code: %d\n", errno);
    	exit(3);
    }
	printf("%s\n", buffer);
	fclose(pFile);
	free(buffer);
}


int main()
{
	return 0;
}