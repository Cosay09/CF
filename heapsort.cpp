#include <bits/stdc++.h>
using namespace std;

void heapsort(int A[], int n);
void build_max_heap(int A[], int n);
void max_heapify(int A[], int idx, int heap_size);

int main()
{
    int A[10] = {4, 5, 3, 6, 8, 7, 9, 2, 1, 10};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Given array: ";

    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";

    heapsort(A, n);
    cout << "\nSorted array is: ";

    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";
    cout << endl;
}

void heapsort(int A[], int n)
{
    build_max_heap(A, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(A[0], A[i]);
        max_heapify(A, 0, i);
    }
}

void build_max_heap(int A[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        max_heapify(A, i, n);
    }
}

void max_heapify(int A[], int idx, int heap_size)
{
    int largest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (left < heap_size && A[left] > A[largest])
    {
        largest = left;
    }
    if (right < heap_size && A[right] > A[largest])
    {
        largest = right;
    }
    if (largest != idx)
    {
        swap(A[idx], A[largest]);
        max_heapify(A, largest, heap_size);
    }
}
/*
#include <bits/stdc++.h>
using namespace std;

void heapsort(int A[], int n);
void build_max_heap(int A[], int n);
void max_heapify(int A[], int idx, int heap_size);

int main()
{
    int A[10] = {4, 5, 3, 6, 8, 7, 9, 2, 1, 10};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Given array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    heapsort(A, n);

    cout << "\nSorted array is: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

void heapsort(int A[], int n)
{
    build_max_heap(A, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(A[0], A[i]);
        max_heapify(A, 0, i); // i is the reduced heap size
    }
}

void build_max_heap(int A[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        max_heapify(A, i, n);
    }
}

void max_heapify(int A[], int idx, int heap_size)
{
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap_size && A[left] > A[largest])
        largest = left;

    if (right < heap_size && A[right] > A[largest])
        largest = right;

    if (largest != idx)
    {
        swap(A[idx], A[largest]);
        max_heapify(A, largest, heap_size);
    }
}

*/
