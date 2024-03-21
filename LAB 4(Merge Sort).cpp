#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int* gen_input(int arr[], int k)
{
    for (int i = 0; i < k; i++)
    {
        arr[i] = rand();
    }
    return arr;
}

int* merge_arr(int a[], int low, int mid, int high)
{
    int *c = new int[100000];
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high) {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j <= high) {
        c[k] = a[j];
        j++;
        k++;
    }
    for (int k = low; k <= high; k++) {
        a[k] = c[k];
    }
    delete[] c;
    return a;
}

int* merge_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        a = merge_arr(a, low, mid, high);
    }
    return a;
}

int main()
{
    int* arr = new int[100000];

    for (int i = 500; i <= 100000; i += 500)
    {
        arr = gen_input(arr, i);
        auto start = high_resolution_clock::now();
        for (int j = 1; j < 10; j++)
        {
            arr = merge_sort(arr, 0, i - 1);
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start) / 10;
        cout << "inputs \t" << i << "\t Time taken: " << duration.count() << "nanoseconds" << endl;
    }
    return 0;
}
