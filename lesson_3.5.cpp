#include <iostream>
using namespace std;
int main(){
  int a[113][113]; // объявление массива
  //считывание массива: сначала размерности, потом сами элементы
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  //вывод массива на экран
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << a[i][j] << " "'
    }
    //вывели строку двумерного массива, перевод строки
    cout << endl;
  }
}
