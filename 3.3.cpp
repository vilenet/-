/*************************************************************************
 1. Ќайти произведение элементов массива с четными номерами.
 2. Ќайти сумму элементов массива, расположенных между первым и последним
    нулевыми элементами.
 3. ѕреобразовать массив таким образом, чтобы сначала распологались
    все положительные элементы, а потом - все отрицательные
    (элементы, равные 0, считать положительными).
*************************************************************************/

#include <iostream>
using namespace std;

//** 1. Ќайти произведение элементов массива с четными номерами.
void SumElemEvenIndex(int arr[], int N){
    int sum = 1;

    if(N > 1)
      for( int i = 1; i < N; ++i)
        if( i % 2  == 0 )
          sum *= arr[i];

    if(N > 1)
      cout << "The product of even-numbered elements: " << sum << endl;
    else
      cout << "There is only one element in an array " << endl;
}
//**

//** 2 сумма элементов массива, расположенных между первым и последним нулевыми элементами.
void SumInterval(int arr[], int N){
    int firstNull = -1, lastNull = -1;

     for( int i = 0; i < N; ++i)
        if( arr[i] == 0){
           firstNull = i;
           break;
        }
     for( int j = N - 1; j >= 0; --j)
        if( arr[j] == 0){
           lastNull = j;
           break;
        }

     if( ( firstNull == -1) || ( lastNull == -1) )
        cout << "There are no two zero elements in the array.";
     else{
        int sum = 0;
        for( int i = firstNull + 1; i < lastNull; ++i)
        sum += arr[i];
        cout << "The sum of the elements between the first and last zero element: " << sum;
        cout << endl;
     }
}
//**

//** 3. ѕреобразование, сначала положительные потом отрицательные элементы
void transformation(int arr[], int N){
    for(int i = 0; i < N - 1; i++)
      for(int j = i + 1; j < N; j++)
        if (arr[i] < arr[j]) {
          int t = arr[i];
          arr[i] = arr[j];
          arr[j] = t;
     }
}
//**

int main()
{
  const int N = 10;
  int arr[N] = { 2, -3, 2, 0, 5, 7, 2, -8, 2, 0};

  SumElemEvenIndex(arr, N);
  SumInterval(arr, N);
  transformation(arr, N);

  for(int i = 0; i < N; ++i)
      cout << arr[i] << " ";
    cout<<endl;
}
