#include<iostream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

void tower_hanoi(int n, char from, char use, char to)
{
    if(n == 0)
        return;
    else
    {
        tower_hanoi(n-1, from, to, use);
        //cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;
        tower_hanoi(n-1, use, from, to);
    }
}

int main()
{
    for(int i=5 ; i<=100; i= i+5)
    {
        auto start = high_resolution_clock::now();
        for(int j = 1; j<=10; j++)
        {
            tower_hanoi(i , 'A', 'B', 'C');
        }
        auto stop = high_resolution_clock::now();

        auto dur = (duration_cast<nanoseconds>(stop - start))/10;

        cout << "Inputs = " << i << "\t Time = " << dur.count() << endl;
    }

    return 0;
}
