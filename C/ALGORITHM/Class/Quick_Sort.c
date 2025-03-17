#include <stdio.h>

int partition_ascending(int a[], int l, int r)
{
  int pivot = a[l];
  while (l != r)
  {
    if (pivot == a[l])
    {
      if (a[r] > pivot)
      {
        r--;
      }
      else
      {
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        pivot = a[r];
        l++;
      }
    }
    else if (pivot == a[r])
    {
      if (a[l] < pivot)
      {
        l++;
      }
      else
      {
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        pivot = a[l];
        r--;
      }
    }
  }
  return l;
}

int partition_descending(int a[], int l, int r)
{
  int pivot = a[l];
  while (l != r)
  {
    if (pivot == a[l])
    {
      if (a[r] < pivot)
      {
        r--;
      }
      else
      {
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        pivot = a[r];
        l++;
      }
    }
    else if (pivot == a[r])
    {
      if (a[l] > pivot)
      {
        l++;
      }
      else
      {
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        pivot = a[l];
        r--;
      }
    }
  }
  return l;
}

void quicksort_ascending(int a[], int l, int r)
{
  if (l < r)
  {
    int pivot = partition_ascending(a, l, r);
    quicksort_ascending(a, l, pivot - 1);
    quicksort_ascending(a, pivot + 1, r);
  }
}

void quicksort_descending(int a[], int l, int r)
{
  if (l < r)
  {
    int pivot = partition_descending(a, l, r);
    quicksort_descending(a, l, pivot - 1);
    quicksort_descending(a, pivot + 1, r);
  }
}

int main()
{
  int a[] = {6, 2, 8, 1, 4, 9, 3, 7, 5};
  int length = sizeof(a) / sizeof(a[0]);
  quicksort_ascending(a, 0, length - 1);
  printf("Sorted array in Ascending: ");
  for (int i = 0; i < length; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
  quicksort_descending(a, 0, length - 1);
  printf("Sorted array in Descending: ");
  for (int i = 0; i < length; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
