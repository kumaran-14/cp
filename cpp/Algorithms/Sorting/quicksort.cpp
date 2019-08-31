// kumaran_14
#include <bits/stdc++.h>
using namespace std;

#define fast_io()                   \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

void swap(int arr[], int left, int right)
{
  int temp = arr[right];
  arr[right] = arr[left];
  arr[left] = temp;
}

int partition(int arr[], int left, int right, int pivot)
{
  while (left <= right)
  {
    while (arr[left] < pivot)
    {
      left++;
    }
    while (arr[right] > pivot)
    {
      right--;
    }
    if (left <= right)
    {
      swap(arr, left, right);
      left++;
      right--;
    }
  }
  return left;
}

void quicksort(int arr[], int left, int right)
{
  if (left >= right)
  {
    return;
  }
  int pivot = arr[(left + right) / 2];
  int index = partition(arr, left, right, pivot);
  quicksort(arr, left, index - 1);
  quicksort(arr, index, right);
}

int main()
{
  fast_io();
  int arr[] = {14, 100, 1, 8, 2, 2, 40};
  cout << "Array before sort: ";
  for (auto x : arr)
    cout << x << " ";
  quicksort(arr, 0, 6);
  cout << endl;
  cout << "Array after sort: ";
  for (auto x : arr)
    cout << x << " ";
  return 0;
}
