#include <iostream>
#include <vector>

using namespace std;

int partition(int arr[], int left, int right) 
{
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) 
    {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quicksort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        int pi = partition(arr, left, right);
        quicksort(arr, left, pi - 1);
        quicksort(arr, pi + 1, right);
    }
}

int main() 
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    quicksort(arr, 0, n - 1);
    
    for (int i = 0; i < n; ++i) 
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}
