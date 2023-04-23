#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void swap(long int* xp, long int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}


void bubbleSort(long int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}


void printArray(long int arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("\n%ld ", arr[i]);

}


int main(int argc,char* argv[])
{
	
	int max;
	max = atoi(argv[1]);
	time_t t;
	//srand((unsigned)time (&t));
	srand(100);
	long int *arr = (long int*)malloc(max*sizeof(long int));


	for(int i=0;i<max;i++)
	{
	arr[i]=rand();
	}

	//printArray(arr, max);
	bubbleSort(arr, max);
	printf("Sorted array: \n");
	printArray(arr, max);
	return 0;
}

