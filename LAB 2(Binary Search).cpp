#include<iostream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

int *gen_input(int arr[], int k)
{
    for(int i = 0; i<k ; i++)
    {
        arr[i] = i+1;
    }
    return arr;
}

void binary_search(int arr[], int low,int high, int key)
{
    int mid;
    if(low == high)
    {
        if(arr[low] == key)
        {
            //cout << low;
        }
        else
            return;
    }
    else
    {
        while(low<=high)
        {
            mid = (low+high)/2;
            if(key == arr[mid])
            {
                //cout << mid;
            }
            else if(key < arr[mid])
                high = mid - 1;
            else if(key > arr[mid])
                    low = mid + 1;
        }
    }

}

int main()
{
    int *arr = new int(100000);

    for(int i=5; i<=10000; i= i*2)
    {
        arr = gen_input(arr, i);
        auto start = high_resolution_clock::now();
        for(int j = 1; j<=10; j++)
        {
            binary_search(arr ,0, i, i/2);
        }
        auto stop = high_resolution_clock::now();

        auto dur = (duration_cast<nanoseconds>(stop - start))/10;

        cout << "Inputs = " << i << "\t Time = " << dur.count() << endl;
    }

    return 0;
}



