#include<iostream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

int *gen_input(int arr[2][5], int k, int l)
{
    for(int i = 0;i<k;i++)
    {
        for(int j = 0; i<l ; i++)
        {
            arr[i][j] = rand();
        }
    }
   // return arr;
}

int partition(int arr[2][5], string choice, int low, int high)
{
    if(choice == "profit")
    {
        int pivot = arr[0][low];
        int i = low;
        int j = high;

        do
        {
            while(arr[0][i] <= pivot && i < high)
            {
                i++;
            }

            while(arr[0][j] >= pivot && j > low)
            {
                j--;
            }

            if(i < j)
            {
                swap(arr[0][i], arr[0][j]);
                swap(arr[1][i], arr[1][j]);
            }
        }while(i < j);

        swap(arr[0][low], arr[0][j]);
        swap(arr[1][low], arr[1][j]);
        return j;
    }
}

void quick_sort(int arr[2][5], string choice, int low, int high)
{
    if(low < high)
    {
        int j = partition(arr, choice, low, high);
        quick_sort(arr, choice, low, j-1);
        quick_sort(arr, choice, j+1, high);
    }
}

int main()
{
    //int *arr = new int(2 * 5);
    int arr[2][5] = {{3,5,6,8,2}, {2,1,3,4,5}};
    quick_sort(arr, "profit", 0, 4);

    for(int i = 0;i<2;i++)
    {
        for(int j = 0; j<5 ; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    //gen_input(arr, 2, 5);


    return 0;
}

