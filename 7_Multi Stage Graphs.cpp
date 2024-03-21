#include<iostream>
#include<cmath>
using namespace std;

int num_stages(int cost[7][7], int n, int i, int count)
{
    count++;
    if(i == n)
    {
        return count;
    }
    else
    {
        int j = 1;
        while(cost[i-1][j-1] == 0)
        {
            j++;
        }
        i = j;
        count = num_stages(cost, n, i, count);
        return count;
    }
}

int findr(int j, int cost[7][7], int fcost[7], int n)
{
    float min = INFINITY;
    int r;

    for(int i = j+1; i<n; i++)
    {
        if(cost[j][i] != 0)
        {
            if(cost[j][i] + fcost[i] < min)
            {
                r = i;
                min = cost[j][i] + fcost[i];
            }
        }
    }
    return r;
}

void fcost(int cost[7][7], int n, int k)
{
    int fcost[n];
    int d[n];
    int p[n];
    fcost[n-1] = 0;

    for(int j = n-2; j>=0; j--)
    {
        int r = findr(j, cost, fcost, 7);

        fcost[j] = cost[j][r] + fcost[r];
        d[j] = r;
    }
    p[0] = 0;
    p[k-1] = n-1;

    for(int j = 1; j<=k-2; j++)
    {
        p[j] = d[p[j-1]];
    }

    cout << "The path traversed is:" << endl;
    for(int i = 0; i<k; i++)
    {
        cout << p[i] + 1 << "\t";
    }
    cout << endl;
}

int main()
{
    int cost[7][7] = {{0,2,3,3,0,0,0},
                      {0,0,0,0,8,0,0},
                      {0,0,0,0,5,7,0},
                      {0,0,0,0,0,6,0},
                      {0,0,0,0,0,0,9},
                      {0,0,0,0,0,0,1},
                      {0,0,0,0,0,0,0}};

    int count = 0;
    count = num_stages(cost, 7, 1, count);
    cout << "Number of stages in the graph: " << count << endl << endl;

    fcost(cost, 7, count);

    return 0;
}

