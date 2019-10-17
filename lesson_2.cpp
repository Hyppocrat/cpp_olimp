#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n, a[1013];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    // в отсортированном по возрастанию массиве
    // i < j => a[i] <= a[j]
    // (i, j): i < j
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if (a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

    /*int n, a[113], mx, mxind = 1;
    cin >> n;
    cin >> a[0];
    mx = a[0];
    for(int  i = 1; i < n; i++){
        cin >> a[i];
        if (a[i] > mx){
            mx = a[i];
            mxind = i + 1;
        }
    }
    cout << mxind;*/
    //float -> float
    //real -> double
    //extended -> long double
    //string -> string
    //тип имя[количество_элементов];
    /*int a, b;
    cin >> a >> b;
    int pp = 0;
    for (int x = -10000; x <= 10000; x++){
        if (pp == 1){
            break;
        }
        for(int y = -10000; y <= 10000; y++){
            if (a * x + b * y == 1){
                cout << x << " " << y;
                pp = 1;
                //return 0;
                break;
            }
        }
    }*/
    /*int n;
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        if (i % 2 == 0){
            continue;
        }
        sum += i;
    }
    cout << sum;*/
    /*int n;
    cin >> n;
    /*for( ; n % 2 == 0; n /= 2){
        
    }
    /*for( ; n % 2 == 0; ){
        n /= 2;
    }
    for(;;){
        
    }
    /*while (n % 2 == 0){
        n /= 2;
    }
    if (n == 1){
        cout << "YES";
    }
    else {
        cout << "NO";
    }*/
    /*int sum = 0;
    for(int i = 1; i <= n; i += 2){
        sum += i;
    }
    cout << sum;
    for(int i = 1; i <= n; i++){
        if (i % 2 != 0){
            sum += i;
        }
    }*/
    /*while (n > 0){
        int a = n % 10;
        sum += a;
        n /= 10; // n = n / 10;
    }
    cout << sum;*/
    /*do{
        cin >> n;
        sum += n;
    }while (n != 0);
    cout << sum;*/
    /*for(инициализация; условие; инкремент){
        
    }*/
