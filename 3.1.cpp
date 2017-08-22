/*************************************************************************
 1. Найти сумму отрицательных элементов массива.
 2. Найти произведение элементов массива, расположенных между максимальным 
    и минимальным элементами.
 3. Упорядочить элементы массива по возрастанию.
*************************************************************************/

#include <iostream>
#include <locale>
using namespace std;

int main()
{ setlocale(LC_ALL, "Russian");

    const int N = 10;
    int a[N] = {1, 3, -5, 1, -2, 1, -1, 3, 8, 4};
    int i, imax, imin, count;

    for(i = imax = imin = 0; i < N; ++i){
       if(a[i] > a[imax]) imax = i;
       if(a[i] < a[imin]) imin = i;
    }

    cout << "\n\t max= " << a[imax] << " min= " << a[imin];
    int ibeg = imax < imin ? imax : imin;
    int iend = imax < imin ? imin : imax;
    cout << "\n\t ibeg= " << ibeg << " iend= " << iend <<endl;;

    for(int j = imin; j < imax; ++j)
        cout << a[j] << " ";
    cout<<endl;

    for(count = 0, i = ibeg + 1; i < iend; ++i)
       if(a[i] > 0) count++;

    cout<<"Количество положительных: " << count << endl;
}

