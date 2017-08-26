/************************************************************************
 1. Найти сумму элементов массива с нечетными номерами.
 2. Найти сумму элементов массива, расположенных между первым и последним
    отрицательными элементами.
 3. Сжать массив, удалив из него все элементы, модуль которых не превышает 1
    Освободившиеся в конце массива элементы заполнить нулями.
************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int count = 0;

void print(int arr[], int N){
  for(int i = 0; i < N; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

//** 1
int Odd_Numbers(int arr[], int N)
{
    int sum = 0;
    for(int i = 0; i < N; ++i)
      if(i % 2 != 0)
        sum += arr[i];
    return sum;
}
//**

//** 2
void Sum_Interval(int arr[], int N)
{
    int sum = 0;
    int first = -1, last = -1;

    for(int i = 0; i < N; ++i){
      if( arr[i] < 0 && first == -1)
        first = i;
      if( arr[i] < 0 && first >= 0 )
        last = i;
    }

    if(first >=0 && last > 1){

       for( int i = first + 1; i < last; ++i)
         sum += arr[i];

       cout << "The sum of array elements located\n"
            << " between the first and last Negative elements: "
            << sum << endl;
    }
    else
       cout << "Interval not found" << endl;

    cout << endl;
}
//**

//** 3 ------------------------------------------------------------
// Обмен элементов масива
void swap(int arr[], int index, int N){
   if( arr[index + 1] < N)
     arr[index] = arr[index + 1];
   count++;
}

void helper(int arr[], int index, int N){
   for( int i = index; i < N; ++i)
      swap(arr, i, N);
}

void CompressArray(int arr[], int N){
     for( int  i = 0; i <= N; ++i)
        if( abs( arr[i] ) <= 1)
           helper(arr, i, N);
}

//** --------------------------------------------------------------

int main()
{
  const int N = 10;
  int arr[] = { 1, 3, -2, 7, 1, 8, 6, -4, 2, 0};

  // 1
  cout <<"Sum elements of array with odd numbers: "
       << Odd_Numbers(arr, N) << endl << endl;;
  // 2
  Sum_Interval(arr, N);

  // 3

  CompressArray(arr, N);
  print(arr, N);
}
