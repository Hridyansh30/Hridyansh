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

int horner_rule(int arr[], int n, int m, int x)
{
    if(n==m)
        return arr[m];
    else
        return(arr[n] + x*horner_rule(arr, n+1, m, x));
}

int main()
{
    int *arr = new int(100000);
    int x = 10;
    int result;
    for(int i=5 ; i<=10000; i= i*2)
    {
        arr = gen_input(arr, i);
        auto start = high_resolution_clock::now();
        for(int j = 1; j<=10; j++)
        {
            result = horner_rule(arr , 0, i, x);
        }
        auto stop = high_resolution_clock::now();

        auto dur = (duration_cast<nanoseconds>(stop - start))/10;

        cout << "Inputs = " << i << "\t Time = " << dur.count() << endl;
    }

    return 0;
}

