#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void selectionSort(long int arr[], int n)
{
 int i, j, min_idx;
  long int t;
   
    for (i = 0; i < n-1; i++)
    {
        
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
  
      
t=arr[min_idx];
arr[min_idx]=arr[i];
arr[i]=t;

        //swap(&arr[min_idx], &arr[i]);
    }
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
	selectionSort(arr, max);
	//printf("Sorted array: \n");
	//printArray(arr, max);
	return 0;
}

