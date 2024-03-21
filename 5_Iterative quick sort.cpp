#include<iostream>
#include<cstdlib>
#include<chrono>
#include<algorithm> // for swap
using namespace std;
using namespace std::chrono;

int count = 0;

class stack
{
    int *data = new int[100000];
    int top = 0;

public:
    void push(int value)
    {
        if(top == 100000)
        {
            cout << "No free space available." << endl;
        }
        else
        {
            top++;
            data[top] = value;
        }
    }

    int pop()
    {
        if(top == 0)
        {
            cout << "Stack is empty." << endl;
            return -1; // Return a value to indicate error
        }
        else
        {
            int a = data[top];
            top--;
            return a;
        }
    }

    bool isEmpty()
    {
        return top == 0;
    }

    ~stack() {
        delete[] data; // Free allocated memory
    }
};

int *gen_input(int arr[], int k)
{
    for(int i = 0; i<k ; i++)
    {
        arr[i] = rand();
    }
    return arr;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    do
    {
        while(arr[i] <= pivot && i < high)
        {
            i++;
        }

        while(arr[j] >= pivot && j > low)
        {
            j--;
        }

        if(i < j)
            swap(arr[i], arr[j]);

    }while(i < j);

    swap (arr[low], arr[j]);
    return j;
}

void quick_sort(int arr[], int low, int high)
{
    if(low >= high)
        return;

    stack s;
    int j;
    while(1)
    {
        while(low<high)
        {
            j = partition(arr, low, high);
            if(j-low <= high-j)
            {
                s.push(j+1);
                s.push(high);
                high = j-1;

            }
            else
            {
                s.push(low);
                s.push(j-1);
                low = j+1;

            }
        }
        if(s.isEmpty() == true)
        {
            return;
        }
        high = s.pop();
        low = s.pop();
    }

}

int main()
{
    int *arr = new int[100000];

    for(int i=5 ; i<=100000; i= i*2)
    {
        arr = gen_input(arr, i);
        auto start = high_resolution_clock::now();
        for(int j = 1; j<=10; j++)
        {
            quick_sort(arr , 0, i-1);
        }
        auto stop = high_resolution_clock::now();

        auto dur = (duration_cast<nanoseconds>(stop - start))/10;

        cout << "Inputs = " << i << "\t Time = " << dur.count() << endl;
    }

    delete[] arr; // Free allocated memory

    return 0;
}
