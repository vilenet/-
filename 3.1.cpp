/*************************************************************************
 1. Найти сумму отрицательных элементов массива.
 2. Найти произведение элементов массива, расположенных между максимальным
    и минимальным элементами.
 3. Упорядочить элементы массива по возрастанию.
*************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    const int N = 10;
    int a[N] = {1, 3, -5, 2, 2, 2, 2, 2, 8, -4};
    int imax = 0, imin = 0, negSum = 0, productSum = 0;

    for(int i=0; i < N; ++i){
       //1 Находим сумму отрицательных элементов
       if(a[i] < 0) negSum += a[i];

       // Находим расположение(индексы) мин и макс элементов
       if(a[i] > a[imax]) imax = i;
       if(a[i] < a[imin]) imin = i;
    }

    //2 Находим произведение между мин и макс элементами
    productSum = a[imin+1];
    for(int j = imin+1; j < imax-1; ++j)
       productSum *= a[j+1];

    //3 Sort array
    for( int i = 0; i < N - 1; ++i )
       for( int j = N - 1; j > 0; --j)
          if( a[j - 1] > a[j] ){
             int temp = a[j - 1];
             a[j - 1] = a[j];
             a[j] = temp;
          }

    cout<<"1 Sum of negative elements: " << negSum << endl;
    cout<<"2 The product of elements between the min and max element: "<<productSum<<endl;
    cout<<"3 Sorting array: ";
    for( int i = 0; i < N; ++i )
        cout << a[i] << " ";

    cout << endl;
}

