#include <iostream>
#include <sstream>
using namespace std;

void heapify(int arr[], int n, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != root)
    {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    string input;
    cout << "Enter space-separated Elements: ";
    getline(cin, input);

    istringstream iss(input);
    int n = 0;
    int temp;
    while (iss >> temp)
        n++;

    int heap_arr[n];

    iss.clear();
    iss.seekg(0);

    for (int i = 0; i < n; i++)
        iss >> heap_arr[i];

    cout << "Input array:\n";
    displayArray(heap_arr, n);

    heapSort(heap_arr, n);

    cout << "Sorted array:\n";
    displayArray(heap_arr, n);

    return 0;
}
