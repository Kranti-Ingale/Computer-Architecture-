#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



void countSort(long int arr[], int n, int exp)
{
	int output[n]; 
	int i, count[10] = { 0 };

	
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void radixsort(long int arr[], int n)
{

//	int m = getMax(arr, n);
	long int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];


	for (int exp = 1; mx / exp > 0; exp =exp * 10)
		countSort(arr, n, exp);
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
	
	radixsort(arr, max);

		return 0;
}
