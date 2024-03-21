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

void merge_lists(int arr1[], int arr2[], int size1, int size2)
{
    int size3 = size1 + size2;
    int arr3[size3];
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < size1 && j < size2)
    {
        if(arr1[i] <= arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }

    while(i < size1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    while(j < size2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }

}


int main()
{
    int *arr = new int(100000);
    int *arr1 = new int(100000);
    int *arr2 = new int(100000);

    for(int i=500 ; i<=100000; i= i+500)
    {
        arr = gen_input(arr, i);
        for(int k = 0; k< i/2; k++)
        {
            arr1[k] = arr[k];
        }
        for(int k = i/2; k<i;k++)
        {
            arr1[k] = arr[k];
        }
        auto start = high_resolution_clock::now();
        for(int j = 1; j<=10; j++)
        {
            merge_lists(arr1, arr2 , i/2, i/2);
        }
        auto stop = high_resolution_clock::now();

        auto dur = (duration_cast<nanoseconds>(stop - start))/10;

        cout << "Inputs = " << i << "\t Time = " << dur.count() << endl;
    }

    return 0;
}

