#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(long int* a, long int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (long int arr[], int low, int high)
{
	long int pivot = arr[high],t; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		
		if (arr[j] < pivot)
		{
			i++; 
			t=arr[i];
			arr[i]=arr[j];
			arr[j]=t;
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void quickSort(long int arr[], int low, int high)
{
	if (low < high)
	{
		
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


int main(int argc,char* argv[])
{
	
	int max;
	max = atoi(argv[1]);
	time_t t;
	
	srand(100);
	long int *arr = (long int*)malloc(max*sizeof(long int));


	for(int i=0;i<max;i++)
	{
	arr[i]=rand();

	}

	
	quickSort(arr,0, max);
	
	
	return 0;
}



