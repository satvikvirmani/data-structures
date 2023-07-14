#include <stdio.h>

int display(int[], int);
int binary_search(int[], int, int, int);
int swap(int * , int * );

int main() {
  int n;
  printf("Enter the number of items in an array: ");
  scanf("%d", & n);

  int arr[n];

  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", & arr[i]);
  }

  display(arr, n);

  insertionSortRecursion(arr, n, 1);

  display(arr, n);

  return 0;
}

int swap(int * a, int * b) {
  * a = * a ^ * b;
  * b = * a ^ * b;
  * a = * a ^ * b;

  return 1;
}

int binary_search(int arr[], int start, int end, int val) {
  if (start < end) {
    int mid = (start + end) / 2;

    if (val == arr[mid]) {
      return val;
    } else if (val < arr[mid]) {
      return binary_search(arr, start, mid, val);
    } else {
      return binary_search(arr, mid + 1, end, val);
    }
  }

  return -1;
}

int display(int arr[], int n) {

  printf("\n");

  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}
