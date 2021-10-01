#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int A[], int p, int r)
{
    int pivot = A[r]; // pivot element is declared to be the last element
    int i = (p - 1); // This is the current best position of pivot so far which is the index of the smallest element

    for (int j = p; j <= r - 1; j++)
    {
        if (A[j] < pivot) // If current element is smaller than the pivot element
        {
            i++; //move the index of smaller element to the next element
            swap(&A[i], &A[j]); //swap the elements
        }
    }
    swap(&A[i + 1], &A[r]); //swapping for the last element which does not requires checking
    return (i + 1);
}

void quickSort(int A[], int p, int r)
{
    if (p < r)    {

        int q = partition(A, p, r); //Calculating the partitioning element q.
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main()
{
    int size;
    cout<<"Enter size of array to generate: ";
    cin>>size;
    int arr[size];
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
     arr[i]=rand()%1000;
    }
    cout<<"Original order of elements in Array: \n";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<"  ";
    }
    quickSort(arr, 0, n - 1);
    cout << "\n\nSorted array: \n";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<"\n\n";
    return 0;
}
