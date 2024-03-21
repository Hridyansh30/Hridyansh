#include<iostream>
#include<chrono>
#include<cstdlib>
using namespace std;
using namespace std::chrono;

int *gen_input(int arr[], int k)
{
    for(int i = 0; i<k ; i++)
    {
        arr[i] = rand();
    }
    return arr;
}

int MaxMin(int arr[], int low, int high, int *max, int *min)
{
    if(low == high)
    {
        *max = arr[low];
        *min = arr[low];
    }

    else if(low == high - 1)
    {
        if(arr[low] > arr[high])
        {
            *max = arr[low];
            *min = arr[high];
        }
        else
        {
            *max = arr[high];
            *min = arr[low];
        }
    }

    else
    {
        int mid = (low + high)/2;
        MaxMin(arr, 0, mid, max, min);
        int min1, max1;
        MaxMin(arr, mid+1, high, &max1, &min1);

        if(max1 > *max)
        {
            *max = max1;
        }

        if(min1 < *min)
        {
            *min = min1;
        }
    }
}

int main()
{
    int *arr = new int(100000);
    int max, min;
    for(int i=5 ; i<=100000; i= i*2)
    {
        arr = gen_input(arr, i);

        auto start = high_resolution_clock::now();
        for(int j = 1; j<=2; j++)
        {
            MaxMin(arr , 0, i-1, &max, &min);
        }
        auto stop = high_resolution_clock::now();

        auto dur = (duration_cast<nanoseconds>(stop - start))/10;

        cout << "Inputs = " << i << "\t Time = " << dur.count() << endl;
    }

    return 0;
}
