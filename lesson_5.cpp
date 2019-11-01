#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

//тип имя (список параметров){
//    ...
//}

bool valid(int a, int b, int c){
    return (a <= b && b < c);
}

int main(){
    int n;
    cin >> n;
    int cnt = 0, num = 1;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int a[113][113];
    for(int i = 0; i < 113; i++){
        fill(a[i], a[i] + 113, 1000000);
    }
    int i = 0, j = 0, dir = 0; // dx[dir], dy[dir] - направление движения
    while (cnt != n * n){
        if (valid(0, i, n) && valid(0, j, n) && a[i][j] == 1000000){
            a[i][j] = num;
            num++;
            cnt++;
        }
        int new_i = i + dx[dir];
        int new_j = j + dy[dir];
        if (valid(0, new_i, n) && valid(0, new_j, n) && a[new_i][new_j] == 1000000){
            i = new_i;
            j = new_j;
        }
        // 0 -> 1, 1 -> 2, 2 -> 3, 3 -> 0
        else {
            dir = (dir + 1) % 4;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

#include <bits/stdc++.h>
// iostream, string, algorithm, iomanip, cmath
using namespace std;

//тип имя (список параметров){
//    ...
//}

//float -> float
//double -> real
//long double -> extended

int main(){
    string s;
    cin >> s;
    cout << s << endl;
    int a, b;
    cin >> a >> b;
    long double pi = 3.14159265359, d = 2e-1;
    double c = (a + 0.0) / b;
    cout.setf(ios::fixed);
    cout.precision(8);
    cout << fixed << setprecision(8) << abs(c) << " " << sqrt(c) << endl;
    c = a / (b + 0.0);
    cout << sin(pi) << " " << cos(0.0) << endl;
    cout << d << endl;
    cout << c << " ";
    c = a * 1.0 / b;
    cout << c << " ";
    cout << floor(c) << " " << ceil(c) << " ";
    cout << hypot(3, 4) << " " << sqrt(3 * 3 + 4 * 4);
}

http://www.cplusplus.com/reference/

#include <bits/stdc++.h>
// iostream, string, algorithm, iomanip, cmath
using namespace std;

// найти (a ^ b) % m, a <= 10^9, b <= 10^9, m <= 10^9
// (a * b) % m = ((a % m) * (b % m)) % m
// (a + b) % m = ((a % m) + (b % m)) % m
// (a ^ b) = (a ^ (b / 2)) ^ 2, b - четное
// (a ^ b) = (a ^ (b - 1)) * a, b - нечетное
// (a ^ b) ^ c = a ^ (bc)
// (a ^ b) * (a ^ c) = a ^ (b + c)
// a ^ 17 = a ^ 16 * a = (a ^ 8) ^ 2 * a = ((a ^ 4) ^ 2) ^ 2) * a = ... =
// ((((a ^ 2) ^ 2) ^ 2) ^ 2) * a = ((((a * a) ^ 2) ^ 2) ^ 2) * a 
// 0! = 1, 1! = 1, ..., n! = (n - 1)! * n = 1 * 2 * ... * n
long long factorial(int n){
    if (n < 2){
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}
// a^0 = 1, a ^ n = a ^ (n - 1) * a
long long power(int a, int n){
    if (n == 0){
        return 1;
    }
    else {
        return a * power(a, n - 1);
    }
}

long long binary_power_mod(long long a, long long n, long long m){
    if (n == 0){
        return 1 % m;
    }
    long long t;
    if (n % 2 != 0){
        t = binary_power_mod(a, n - 1, m); // t будет всегда меньше m, т. к. (a ^ (n - 1)) % m < m
        return ((a % m) * t) % m;
    }
    else {
        t = binary_power_mod(a, n / 2, m);
        return (t * t) % m;
    }
}

int main(){
    cout << binary_power_mod(3, 0, 1);
}
