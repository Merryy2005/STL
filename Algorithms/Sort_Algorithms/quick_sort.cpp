#include <iostream>
#include <random>
#include <ctime>


template<typename T>
int partition(T* arr , int s , int e)
{
    T pivot = arr[e];
    int ind = s;
    for(int i = s ; i < e ; i++)
    {
        if(arr[i] < pivot)
        {
            T tmp = arr[i];
            arr[i] = arr[ind];
            arr[ind++] = tmp;
        }
    }
    T tmp = arr[e];
    arr[e] = arr[ind];
    arr[ind] = tmp;
    return ind;
}

template<typename T>
void quick_sort(T* arr , int s , int e)
{
    if(s >= e)
    {
        return;
    }
    int ind = partition(arr , s , e);
    quick_sort(arr , s , ind-1);
    quick_sort(arr , ind+1 , e);
    return;
}

template<typename T>
void init(T* arr , int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        arr[i] = rand() % 10;
    }
}

template<typename T>
void print(T* arr , int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    srand(time(0));
    int* arr = new int[10];
    init(arr , 10);
    print(arr , 10);
    quick_sort(arr , 0 , 9);
    print(arr , 10);
    delete[] arr;
    return 0;
}