#include<iostream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

long int power(int x, int n)
{
    int m = n;
    int power = 1;
    int z = x;

    while(m > 0)
    {
        if(m|2==0)
        {
            z = z*z;
            m = m/2;
        }
        else
        {
            power = power*z;
            m = m-1;
        }
    }

    return power;
}

int main()
{
    long int p;
    int *arr = new int(100000);

    for(int i=5; i<=10000; i= i*2)
    {
        //arr = gen_input(arr, i);
        auto start = high_resolution_clock::now();
        for(int j = 1; j<=10; j++)
        {
            p = power(2, i);
        }
        auto stop = high_resolution_clock::now();

        auto dur = (duration_cast<nanoseconds>(stop - start))/10;

        cout << "Inputs = " << i << "\t Time = " << dur.count() << endl;
    }

    return 0;
}
