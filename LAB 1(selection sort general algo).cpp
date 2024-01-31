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

void selection_sort(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        int j = i;
        for(int k = i+1; k<n; k++)
        {
            if(arr[k] < arr[j])
                j = k;
        }
        swap(arr[i], arr[j]);
    }
}

int main()
{
    int p =0;
    float a[5][2];
    int *arr = new int(100000);

    for(int i=500 ; i<=10000; i= i + 500)
    {
        arr = gen_input(arr, i);
        auto start = high_resolution_clock::now();
        for(int j = 1; j<=10; j++)
        {
            selection_sort(arr , i);
        }
        auto stop = high_resolution_clock::now();

        auto dur = (duration_cast<nanoseconds>(stop - start))/10;

        cout << "Inputs = " << i << "\t Time = " << dur.count() << endl;
    }

    return 0;
}
