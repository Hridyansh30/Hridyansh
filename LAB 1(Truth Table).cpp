#include<iostream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;


char* truth_table(char arr[], int k, int n)
{
    if(k==n+1)
        return (arr);
    else
    {
        arr[k] = 'T';
        truth_table(arr, k+1, n);
        arr[k] = 'F';
        truth_table(arr, k+1, n);
    }
}

int main()
{
    char *arr = new char(100000);
    for(int i=5; i<=10000; i= i*2)
    {
        auto start = high_resolution_clock::now();
        for(int j = 1; j<=10; j++)
        {
            arr = truth_table(arr , 0, i);
        }
        auto stop = high_resolution_clock::now();

        auto dur = (duration_cast<nanoseconds>(stop - start))/10;

        cout << "Inputs = " << i << "\t Time = " << dur.count() << endl;
    }

    return 0;
}


