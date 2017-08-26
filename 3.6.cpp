/****************************************************************************
 1. Найти минимальный элемент массива.
 2. Найти сумму элементов массива, расположенных между первым и последним  2
    положительными элементами.
 3. Преобразовать массив таким образом, чтобы сначала располагались все элементы,
    равные нулю, а потом — все остальные.
*****************************************************************************/

 #include <iostream>
 using namespace std;

 int minElem(int arr[], int N){
   int minelem = arr[0];
   for(int i = 0; i < N; ++i)
     if(arr[i] < minelem)
       minelem = arr[i];

   return minelem;
 }

 void sumInterval(int arr[], int N){
    int first = -1, last = -1, sum = 0;

    for(int i = 0; i < N; ++i)
      if(arr[i] > 0 && first == -1)
        first = i;

    for(int i = N; i > 0; --i)
      if(arr[i] > 0 && last == -1)
        last = i;

    if(first >= 0 && last >= 0){
      for(int i = first + 1; i < last; ++i)
        sum += arr[i];

      cout << "sum " << sum << endl;
    }
    else
      cout << "interval not found!" << endl;
 }

 void transformArray(int arr[], int N){
    int temp;

    for( int i = 0; i < N; ++i ){
      if( arr[i] != 0 ){
        for( int j = i+1; j < N;  ++j )
          if(arr[j] == 0){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
          }
       }
    }
 }

 int main()
 {
     const int N = 10;
     int arr[] = { 1, 3, 0, 7, 0, 8, 6, -4, 2, -2};

     cout << minElem(arr, N) << endl;

     sumInterval(arr, N);
     transformArray(arr, N);

     for(int i = 0; i < N; ++i)
        cout << arr[i] << " ";
     cout << endl;
}
