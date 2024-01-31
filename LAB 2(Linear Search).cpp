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

void linear_search(int arr[], int n, int key)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(arr[i] == key)
        {
            //cout << i;
        }
    }
    if(i == n+1)
    {
        //cout<< "Key not present";
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
            linear_search(arr , i, 20000);
        }
        auto stop = high_resolution_clock::now();

        auto dur = (duration_cast<nanoseconds>(stop - start))/10;

        cout << "Inputs = " << i << "\t Time = " << dur.count() << endl;
    }

    return 0;
}


