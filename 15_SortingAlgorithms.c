#include <stdio.h>
#include <stdlib.h>

// ---------------------------------------------------------------------------
// Returnerer en peker til en heltallstabell med nTall ifra minValue til maxValue
// ---------------------------------------------------------------------------
int* Heltalltabell(int nTall, int minValue, int maxValue) {

	int* tabell = malloc(sizeof(int) * nTall);
	for(int i = 0; i<nTall; i++) tabell[i] = rand() % maxValue;
	return tabell;
}

void printArray(int* array, int arrayLength) {
	for(int i = 0; i<arrayLength; i++) printf("%d, ", array[i]);
}

void swap(int array[], int index1, int index2) {
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

// ---------------------------------------------------------------------------
// Utvalgsortering
// ---------------------------------------------------------------------------
void Utvalgsortering(int array[], int arrayLength)
{
	int* table = array;
	int minValue;
	int minIndex;
	for(int i = 0; i<arrayLength; i++){
		minValue = table[i];
		minIndex = i;
		for(int j = i; j<arrayLength; j++) {
			if(table[j] < minValue){
				minIndex = j;
				minValue = table[j];
			}
		}
		swap(table, i, minIndex);
	}
}

// ---------------------------------------------------------------------------
// Bubblesort
// parametere: arrayet og dets lengde
// ---------------------------------------------------------------------------
void Bubblesort(int array[], int arrayLength) {
	int counter = arrayLength;
	while(counter>0) {
		for(int i = 0; i<arrayLength-1; i++) {
			if(array[i] > array[i+1]) swap(array, i, i+1);
		}
	counter -= 1;
	}
}

// ---------------------------------------------------------------------------
// Quicksort
// parametere: arrayet, og index range som skal sorteres
// eksempel: quicksort(arrayet, 0, arraylengde - 1)
// ---------------------------------------------------------------------------
void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    // partisjonering
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        // bytter plass
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    // rekursjon
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

// ---------------------------------------------------------------------------
// Hanoi
// ---------------------------------------------------------------------------
void Hanoi(char A, char B, char C, int n) {

	if(n == 1) printf("Brikke %d fra %c til %c\n", n, A, C);
	else {
		Hanoi(A, C, B, n-1);
		printf("Brikke %d fra %c til %c\n", n, A, C);
		Hanoi(B, A, C, n-1);
	}
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------
int main() {

	int size = 1000;
	int* tab = Heltalltabell(size, 0, 1000000);
	printArray(tab, size);
	printf("\n");
	// Utvalgsortering(tab, 10);
	quickSort(tab, 0, size - 1);
	printArray(tab, size);
	return 0;
}