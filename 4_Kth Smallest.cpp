#include<iostream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

int *gen_input(int arr[], int k)
{
    for(int i = 0;i<k;i++)
    {
            arr[i] = rand();
    }
    return arr;
}

int partition(int arr[], int low, int high)
{
        int pivot = arr[low];
        int i = low;
        int j = high;

        do
        {
            while(arr[i] <= pivot && i < high)
            {
                i++;
            }

            while(arr[j] >= pivot && j > low)
            {
                j--;
            }

            if(i < j)
            {
                swap(arr[i], arr[j]);
            }
        }while(i < j);

        swap(arr[low], arr[j]);
        return j;
}

int k_smallest(int arr[], int low, int high, int k)
{
    int j;
    if(low == high)
    {
        return arr[low];
    }
    if(low < high)
    {
        j = partition(arr, low, high);
        if(k == j+1)
            return arr[j];
        else if(k < j+1)
            k_smallest(arr, low, j-1, k);
        else
            k_smallest(arr, j+1, high, k);

    }
}

int main()
{
    int ans;
    int *arr = new int(100000);

    for(int i=5 ; i<=100000; i= i*2)
    {
        arr = gen_input(arr, i);
        auto start = high_resolution_clock::now();
        for(int j = 1; j<=10; j++)
        {
            ans = k_smallest(arr, 0, i-1, i/2);
        }
        auto stop = high_resolution_clock::now();

        auto dur = (duration_cast<nanoseconds>(stop - start))/10;

        cout << "Inputs = " << i << "\t Time = " << dur.count() << endl;
    }

    return 0;
}
