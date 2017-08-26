/**************************************************************************
 1. Найти максимальный элемент массива.
 2. Найти сумму элементов массива, расположенных до последнего положительного
    элемента.
 3. Сжать массив, удалив из него все элементы, модуль которых находится в интер-
    вале [a, b]. Освободившиеся в конце массива элементы заполнить нулями.
**************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int count = 0;

void print(int arr[], int N){
  for( int  i = 0; i < N; ++i)
     cout << arr[i] << " ";
   cout << endl;
}

void CompressArray(int arr[], int a, int b, int N){
   int begin = -1,  end = -1;

   for( int i = 0; i < N; ++i ){
     if( abs( a ) == abs( arr[i] ) && begin == -1)
        begin = i;
     if( abs( b ) == abs( arr[i] ) && begin >=0)
        end = i;
   }

   if(end >= -1){
     for(; end <= N; ++end, ++begin )
          arr[begin+1] = arr[end];

     for(int i = begin+1; i < end; ++i, ++count);

     for( int i = N; count >= 0; --i, --count)
        arr[i] = 0;
   }
   else
     cout << "interval not found" << endl;
}

int main()
{

   const int N = 10;
   int arr[] = { 1, 3, -2, 7, 1, 8, 6, -4, 2, -2};

   int maxElem = arr[0];
   int lastPosElem = -1;
   int sum = 0;

   for( int i = 0; i < N; ++i){
     if( arr[i] > maxElem )
        maxElem = arr[i];

     if( arr[i] > 0)
        lastPosElem = i;
   }

   for( int i = 0; i <= lastPosElem; ++i)
     sum += arr[i];



   cout << "max element of array: " << maxElem << endl;
   cout << "sum of the elements until the last positive: " << sum << endl;
   print(arr, N);
   CompressArray(arr, -2, -4, N);
   print(arr, N);
}










