/**************************************************************************
 1. Найти номер максимального элемента массива.
 2. Найти произведение элементов массива, расположенных между первым и вто-
    рым нулевыми элементами.
 3. Преобразовать массив таким образом, чтобы в первой его половине располага-
    лись элементы, стоявшие в нечетных позициях, а во второй половине — элементы,
    стоявшие в четных позициях.
**************************************************************************/

#include <iostream>
using namespace std;

void product(int[], int);
void transformArray(int[], int);
void print(int[], int);

int main()
{
    const int N = 10;
    int arr[] = { 1, 3, 0, 4, 2, 0, 6, -4, 2, -2};

    // для 3 условия, создадим массив в котором элементы будут соответствовать индексам
    int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int num = 0, index = 0;

    //1
    for(int i = 0; i < N; ++i)
        if( arr[i] > num ){
            num = arr[i];
            index = i;
        }

    cout << "Index of the maximum element: " << index << endl;
    product(arr, N);
    cout << "Unchanged array: "; print(arr2, N);
    transformArray(arr2, N);
    cout << "Modified array:  ";  print(arr2, N);
}


void product(int arr[], int N){
     int first = -1, second = -1, sum = 1;

     for(int i = 0; i < N, second == -1; ++i){
       if( arr[i] == 0 && first == -1 )
         first = i++;
       if( arr[i] == 0 && first != -1 && second == -1 )
         second = i;
     }

     cout << first << " " << second << endl;

     for(int i = first + 1; i < second; ++i)
        sum *= arr[i];

     if( second != -1)
        cout << "Sum interval: " << sum << endl;
     else
        cout << "Interval not found!" << endl;
}

void transformArray(int arr[], int N){
    int temp[N], n = 0;

    for(int i = 0; i < N; i+=2)
       temp[n++] = arr[i];

    for(int i = 1; i < N; i+=2)
       temp[n++] = arr[i];

    for(int i = 0; i < N; ++i)
       arr[i] = temp[i];
}

void print(int arr[], int N){
    for(int i = 0; i < N; ++i)
       cout << arr[i] << " ";
    cout << endl;
}










