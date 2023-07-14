#include <stdio.h>

void selectionSort(int[], int);
void bubbleSort(int[], int);
void insertionSortLoopedSwap(int[], int);
void insertionSortLoopedKey(int[], int);
void insertionSortRecursion(int[], int, int);
void quickSortAscending(int[], int, int);
void quickSortDescending(int[], int, int);
void mergeSortAscending(int[], int, int);
void mergeAscending(int[], int, int, int);
void mergeSortDescending(int[], int, int);
void mergeDescending(int[], int, int, int);
void heapSortAscending(int[], int);
void heapifyAscendingRecursive(int[], int, int);
void heapifyAscendingIerative(int[], int, int);
void heapifyDescending(int[], int, int);

int main()
{
	int arr[10] = {12,23,45,-8,6,49,-12,15,3,0};
	
	int i;
	
	printf("Original: \n");
	for(i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	
	selectionSort(arr, 9);
	
	printf("\nSorted: \n");
	for(i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 1;
}

void selectionSort(int arr[], int n)
{
	int i, j;
	int minIndex;
	int temp;
	
	for(i = 0; i <= n; i++)
	{
		minIndex = i;
		for(j = i + 1; j <= n; j++)
		{
			if(arr[j] < arr[minIndex])
			{
				minIndex = j;	
			}
		}
		
		temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
	}	
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	int temp;
	
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= i; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;	
			}
		}
	}
}

void insertionSortRecursion(int arr[], int n, int i) {
  if (i < n) {
    int temp = i;
    int key = arr[i];

    while (key < arr[temp - 1] && temp > 0) {
      arr[temp] = arr[temp - 1];
      temp--;
    }

    arr[temp] = key;

    insertion_looped_recursion(arr, n, i + 1);
  }
}

void insertionSortLoopedSwap(int arr[], int n) {

  int i, comp_index;

  for (i = 1; i < n; i++) {

    comp_index = i;

    while (arr[comp_index] < arr[comp_index - 1] && comp_index > 0) {
      swap( & arr[comp_index], & arr[comp_index - 1]);
      comp_index--;
    }

  }
}

void insertionSortLoopedKey(int arr[], int n) {

  int i, comp_index, key;

  for (i = 1; i < n; i++) {

    comp_index = i;
    key = arr[i];

    while (key < arr[comp_index - 1] && comp_index > 0) {
      arr[comp_index] = arr[comp_index - 1];
      comp_index--;
    }

    arr[comp_index] = key;
  }
}

void quickSortAscending(int arr[], int low, int high)
{
	if(low < high)
	{
		int i = low;
		int j = high+1;
		int temp;
		
		do
		{
			do
			{
				i++;
			} while(i <= high && arr[i] < arr[low]);
			do
			{
				j--;
			} while(i <= j && arr[j] > arr[low]);
			
			if(i < j)
			{			
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		} while(i < j);
		
		temp = arr[low];
		arr[low] = arr[j];
		arr[j] = temp;
		
		quickSortAscending(arr, low, j - 1);
		quickSortAscending(arr, j + 1, high);	
	}
	
	return ;
}

void quickSortDescending(int arr[], int low, int high)
{
	if(low < high)
	{
		int i = low;
		int j = high+1;
		int temp;
		
		do
		{
			do
			{
				i++;
			} while(i <= high && arr[i] > arr[low]);
			do
			{
				j--;
			} while(i <= j && arr[j] < arr[low]);
			
			if(i < j)
			{			
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		} while(i < j);
		
		temp = arr[low];
		arr[low] = arr[j];
		arr[j] = temp;
		
		quickSortDescending(arr, low, j - 1);
		quickSortDescending(arr, j + 1, high);	
	}
	
	return ;
}

void mergeSortAscending(int arr[], int low, int high)
{
	if(low < high)
	{
		int mid = (low + high) / 2;
	
		mergeSortAscending(arr, low, mid);
		mergeSortAscending(arr, mid + 1, high);
		
		mergeAscending(arr, low, mid, high);	
	}
	
	return ;
}

void mergeAscending(int arr[], int low, int mid, int high)
{
	int temp[high - low + 1];
	
	int i = low;
	int j = mid + 1;
	int k = 0;	
	
	while(i <= mid && j <= high)
	{
		if(arr[i] < arr[j])
		{
			temp[k] = arr[i];
			k++;
			i++;
		}
		else{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}
	while(i <= mid)
	{
		temp[k] = arr[i];
		k++;
		i++;
	}
	while(j <= high)
	{
		temp[k] = arr[j];
		k++;
		j++;
	}
	
	int x = 0;
	printf("\nInside Merge: (with low = %d mid = %d high = %d) \n", low, mid, high);
	for(x = 0; x < k; x++)
	{
		printf("%d ", temp[x]);
	}
	
	
	int m = 0;
	k = 0;
	
	for(m = low; m <= high; m++, k++)
	{
		arr[m] = temp[k];
	}
	
	return ;
}

void mergeSortDescending(int arr[], int low, int high)
{
	if(low < high)
	{
		int mid = (low + high) / 2;
	
		mergeSortDescending(arr, low, mid);
		mergeSortDescending(arr, mid + 1, high);
		
		mergeDescending(arr, low, mid, high);	
	}
	
	return ;
}

void mergeDescending(int arr[], int low, int mid, int high)
{
	int temp[high - low + 1];
	
	int i = low;
	int j = mid + 1;
	int k = 0;	
	
	while(i <= mid && j <= high)
	{
		if(arr[i] > arr[j])
		{
			temp[k] = arr[i];
			k++;
			i++;
		}
		else{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}
	while(i <= mid)
	{
		temp[k] = arr[i];
		k++;
		i++;
	}
	while(j <= high)
	{
		temp[k] = arr[j];
		k++;
		j++;
	}
	
	int x = 0;
	printf("\nInside Merge: (with low = %d mid = %d high = %d) \n", low, mid, high);
	for(x = 0; x < k; x++)
	{
		printf("%d ", temp[x]);
	}
	
	
	int m = 0;
	k = 0;
	
	for(m = low; m <= high; m++, k++)
	{
		arr[m] = temp[k];
	}
	
	return ;
}

void heapSortAscending(int arr[], int n)
{
	int i;
	
	for(i = n / 2 - 1; i >= 0; i--)
	{
		heapifyAscendingRecursive(arr, i, n);
	}

	for(i = n - 1; i >= 0; i--)
	{
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		
		heapifyAscendingRecursive(arr, 0, i);
	}
	
	return ;
}

void heapifyDescending(int arr[], int i, int n)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int minIndex = i;
	
	if(left < n && arr[minIndex] > arr[left])
	{
		minIndex = left;
	}
	if(right < n && arr[minIndex] > arr[right]){
		minIndex = right;
	}
	
	if(minIndex != i)
	{
		int temp;
		
		temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
		
		heapifyDescending(arr, minIndex, n);
	}
	
	return ;
}

void heapifyAscendingRecursive(int arr[], int i, int n)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int maxIndex = i;
	
	if(left < n && arr[maxIndex] < arr[left])
	{
		maxIndex = left;
	}
	if(right < n && arr[maxIndex] < arr[right]){
		maxIndex = right;
	}
	
	if(maxIndex != i)
	{
		int temp;
		
		temp = arr[maxIndex];
		arr[maxIndex] = arr[i];
		arr[i] = temp;
		
		heapifyAscendingRecursive(arr, maxIndex, n);
	}
	
	return ;
}

void heapifyAscendingIerative(int arr[], int i, int n)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int maxIndex = i;
	
	while(i < n){
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		int maxIndex = i;
		
		if(left < n && arr[maxIndex] < arr[left])
		{
			maxIndex = left;
		}
		if(right < n && arr[maxIndex] < arr[right]){
			maxIndex = right;
		}
		
		if(maxIndex == i)
		{
			break;
		}
		int temp;
			
		temp = arr[maxIndex];
		arr[maxIndex] = arr[i];
		arr[i] = temp;
		
		i = maxIndex;
	}
	return ;
}
