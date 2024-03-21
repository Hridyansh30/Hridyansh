#include<iostream>
#include<cstdlib>
#include<chrono>
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

void precise(int arr[], int size)
{
    int pivot = 0;
    int low = 1;
    int high = size - 1;

    while(low < high)
    {
        while(arr[low] < arr[pivot])
        {
            low++;
        }
        while(arr[high] > arr[pivot])
        {
            high--;
        }
        if(low < high)
            swap(arr[low], arr[high]);

    }
    swap(arr[pivot], arr[high]);
}

int main()
{
    int *arr = new int(100000);
    for(int i=5 ; i<=100000; i= i*2)
    {
        arr = gen_input(arr, i);
        auto start = high_resolution_clock::now();
        for(int j = 1; j<=2; j++)
        {
            precise(arr , i);
        }
        auto stop = high_resolution_clock::now();

        auto dur = (duration_cast<nanoseconds>(stop - start))/10;

        cout << "Inputs = " << i << "\t Time = " << dur.count() << endl;
    }

    return 0;
}
