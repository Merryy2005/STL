#include <iostream>
#include <random>
#include <ctime>


template<typename T>
void merge(T* arr , int s , int m , int e)
{
    if(s >= e)
    {
        return;
    }
    int size = e - s + 1;
    int size1 = m - s + 1;
    int size2 = size - size1;
    T* arr1 = new T[size1];
    T* arr2 = new T[size2];
    for(int i = 0 ; i < size1 ; i++)
    {
        arr1[i] = arr[s+i];
    }
    for(int i = size1 ; i < size ; i++)
    {
        arr2[i-size1] = arr[s+i];
    }
    int ind1 = 0;
    int ind2 = 0;
    int ind = s;
    while(ind1 < size1 && ind2 < size2)
    {
        if(ind1 < size1 && ind2 < size2 && arr1[ind1] <= arr2[ind2])
        {
            arr[ind++] = arr1[ind1++];
        }
        else if(ind1 < size1 && ind2 < size2 && arr1[ind1] > arr2[ind2])
        {
            arr[ind++] = arr2[ind2++];
        }
    }
    while(ind1 < size1)
    {
        arr[ind++] = arr1[ind1++];
    }
    while(ind2 < size2)
    {
        arr[ind++] = arr2[ind2++];
    }
    delete[] arr1;
    delete[] arr2;
    return;
}

template<typename T>
void merge_sort(T* arr , int s , int e)
{
    if(s >= e)
    {
        return;
    }
    int m = s + (e - s) / 2;
    merge_sort(arr , s , m);
    merge_sort(arr , m+1 , e);
    merge(arr , s , m , e);
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
    merge_sort(arr , 0 , 9);
    print(arr , 10);
    delete[] arr;
    return 0;
}