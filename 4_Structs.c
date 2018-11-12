#include <stdio.h>
#include <string.h>

// ------------ ------------ Structs ------------ ------------
// Structs are used when u need more than 1 piece of data of 
// diffrent type to discribe the same thing.
struct sports
{
	char *sport1;
	char *sport2;
};

// med "typedef" refererer "struct Person" til "Person"
typedef struct Person
{	
	char name[20];
	int studentID;
	int age;
	struct sports favoriteSports;
} Person;

void Struct(Person* thePerson)
{
	// Output
	printf("Personinfo:\n");
	printf("Name: %s\n", thePerson->name);
	printf("StudentID: %d\n", thePerson->studentID);
	printf("Age: %i\n", thePerson->age);
	printf("Sport1: %s\n", (*thePerson).favoriteSports.sport1);
	printf("Sport2: %s\n\n", (*thePerson).favoriteSports.sport2);

	// Output memory location
	printf("Memory locations:\n");
	printf("Name: %p\n", &(thePerson->name));
	printf("StudentID: %p\n", &thePerson->studentID);
	printf("Age: %p\n", &thePerson->age);
	printf("Sport1: %p\n", &(*thePerson).favoriteSports.sport1);
	printf("Sport2: %p\n\n", &(*thePerson).favoriteSports.sport2);
}


void strInput(char enString[], int length)
{
    int position = 0;
    char theChar;
    while ((theChar = getchar()) != '\n' && position < length){
        enString[position] = theChar;
        position++;
    }
    enString[position] = '\0';
}

void UserInputPerson(Person* thePerson)
{
	printf("Enter studentID:\n");
	scanf("%d", &(thePerson)->studentID);
	getchar();

	printf("Enter name:\n");
	strInput((thePerson)->name, 20);

	printf("Enter age:\n");
	scanf("%d", &(thePerson)->age);
	printf("\n");
}

void setPersonName(Person* thePerson, char* newName)
{
	// strncpy((*thePerson).name, newName, 20);
	strncpy(thePerson->name, newName, 20);
}

void setPersonAge(Person* thePerson, int age)
{
	(*thePerson).age = age;
}

void setPersonSport1(Person *thePerson, char* newSport)
{
	(*thePerson).favoriteSports.sport1 = newSport;
	// thePerson->favoriteSports.sport1 = newSport;
}



int main()
{
	// Assign
	Person thePerson = {"Mike", 99, 22, {"Fotball", "Ski"}};
	Struct(&thePerson);
	return 0;
}