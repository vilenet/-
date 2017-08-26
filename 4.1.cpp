/*****************************************************************
 ���� ������������� ������������� �������. ����������:
 1) ���������� �����, �� ���������� �� ������ �������� ��������;
 2) ������������ �� �����, ���p��������� � �������� ���p��� ����� ������ p���.
*****************************************************************/

#include <iostream>
using namespace std;

const int N = 4;

//** 2. ������������ �� �����, ���p��������� � �������� ���p��� ����� ������ p���.
void repeatMoreOne(int arr[N][N], int N){

    int B[2][N*N];
    int BSize = 0;

    for(int i = 0; i < N*N; i++)
        B[1][i] = 0;

    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        int k;
        for(k = 0; k < BSize; k++){
          if(arr[i][j] == B[0][k]){
            B[1][k]++;
            break;
          }
        }
        if(!(k < BSize)){
          BSize++;
          B[0][k] = arr[i][j];
        }
      }
    }

    int maxIndex = -1;

    for(int i = 0; i < BSize; i++){
      if(B[1][i] > 0){
        maxIndex = i;
        break;
      }
    }

    if(maxIndex != -1){
      for(int i=maxIndex + 1; i<BSize; i++)
        if(B[0][i] > B[0][maxIndex] && B[1][i] > 0)
          maxIndex = i;

        cout<< "\n������������ ��������, ������������� � �������� ������� ����� ������ ����: "
            << B[0][maxIndex] << endl;
    }
    else
        cout << "� ������� ��� ��������, ������������� ����� ������ ����" << endl;
}
//**


int main()
{
    setlocale(LC_ALL,"Rus");


    int arr[N][N] = { {1,2,3,0},
                      {1,9,8,7},
                      {7,6,7,8},
                      {1,2,2,3} };

    int numberLines = N, maxNumber = arr[0][0];

    // 1. ������� ���������� �����, �� ���������� �� ������ �������� ��������;
    for( int i = 0; i < N; ++i )
      for( int j = 0; j < N; ++j )
        if( arr[i][j] == 0 ){
          --numberLines;
          break;
        }

    cout << "���������� �����, �� ���������� �� ������ �������� ��������: "
         << numberLines << endl;

    // 2.
    repeatMoreOne(arr, N);

}

