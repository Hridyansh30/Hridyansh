#include<iostream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

void gen_square(int n)
{
	int magicSquare[n][n];

    for (int i = 0; i < n; i++)
    {
		for (int j = 0; j < n; j++)
		{
			magicSquare[i][j] = 0;
		}
	}

	int i = n / 2;
	int j = n - 1;

	for (int num = 1; num <= n*n;)
    {
		if (i == -1 && j == n)
		{
			j = n - 2;
			i = 0;
		}
		else
		{
			if (j == n)
				j = 0;

			if (i < 0)
				i = n - 1;
		}
		if (magicSquare[i][j])
		{
			j = j- 2;
			i++;
			continue;
		}
		else
			magicSquare[i][j] = num++;

		j++;
		i--;
	}
}

int main()
{
    // Works only when n is odd

	for(int i=5; i<=10000; i= i+50)
    {
        auto start = high_resolution_clock::now();
        for(int j = 1; j<=10; j++)
        {
            gen_square(i);
        }
        auto stop = high_resolution_clock::now();

        auto dur = (duration_cast<nanoseconds>(stop - start))/10;

        cout << "Inputs = " << i << "\t Time = " << dur.count() << endl;
    }
	return 0;
}


