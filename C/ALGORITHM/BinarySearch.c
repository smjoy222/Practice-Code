// Binary Search in C

#include <stdio.h>

int binarySearch(int array[], int x, int low, int high) {

  while (low <= high) {
    int mid = (high + low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main() {
    int n,x;
  printf("Enter number of elements\n");
  scanf("%d", &n);
int array[n];
  printf("Enter %d integers\n", n);

  for ( int c = 0; c < n; c++)
    scanf("%d", &array[c]);

  printf("Enter value to find\n");
  scanf("%d",&x);

  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("%d Element is found at index %d",x, result);
  return 0;
}


/*
In Recursive Way
int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (array[mid] == x)
      return mid;

    // Search the left half
    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    // Search the right half
    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}
*/