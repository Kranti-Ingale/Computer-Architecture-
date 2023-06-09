#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




void merge(long int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
   
    int L[n1], R[n2];
 
   
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
  
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
  
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
   
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(long int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
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
	mergeSort(arr,0, max-1);
	//printf("Sorted array: \n");
	//printArray(arr, max);
	return 0;
}

