#include <iostream>
#include <random>
#include <ctime>

template<typename T>
void bubble_sort(T* arr , int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(arr[i] > arr[j])
            {
                T tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
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
    bubble_sort(arr , 10);
    print(arr , 10);
    delete[] arr;
    return 0;
}