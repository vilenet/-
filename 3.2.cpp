/**********************************************************************
 1. ����� ����� ������������� ��������� �������.
 2. ����� ������������ �������� �������, ������������� �����
    ������������ �� ������ � ����������� �� ������ ����������.
 3. ����������� �������� �� ��������.
**********************************************************************/
 
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   const int N = 10;
   int a[N] = {-3, 1, -5, 2, 2, 2, 2, 2, 8, -4};
   int posSum = 0, productSum = 1;
   int maxElem = a[0];
   int minI = 0, maxI = 0;

   //1 ������� ����� ������������� ���������
   for(int i=0; i < N; ++i)
       if(a[i] > 0) posSum += a[i];

    // ������� ������������(�������) ��� �� ������ � ���� �� ������ ���������
    for( int i = 1; i < N; ++i){
        if( abs( a[i] ) > maxElem){
            maxElem = a[i];
            maxI = i;
        }
        if(abs(a[i]) < abs(a[minI]))
            minI = i;
    }

    //2 ������������ ��������, ������������� ����� ���� � ��� �� ������ ����������.
    for( int i = minI + 1; i < maxI ; ++i)
      productSum *= a[i];

    //3 ��������� ������ �� ��������
    for( int i = N; i > 0; --i )
       for( int j = 0; j < N; ++j)
          if( a[j + 1] > a[j] ){
             int temp = a[j + 1];
             a[j + 1] = a[j];
             a[j] = temp;
          }

    cout<<"1 Sum of positive elements: " << posSum << endl;
    cout<<"2 The product of elements between the min and max element: "<<productSum<<endl;
    cout<<"3 Sorting array: ";
    for( int i = 0; i < N; ++i )
        cout << a[i] << " ";

    cout << endl;
}
