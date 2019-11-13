#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

// -inf 1 2 3 3 3 4 5 +inf

int binary_search_left(int a[], int n, int x){
    int l = -1, r = n;
    while (l < r - 1){
        int m = (l + r) / 2;
        if (a[m] >= x){
            r = m;
        }
        else {
            l = m;
        }
    }
    return r;
}

int binary_search_right(int a[], int n, int x){
    int l = -1, r = n;
    while (l < r - 1){
        int m = (l + r) / 2;
        if (a[m] > x){
            r = m;
        }
        else {
            l = m;
        }
    }
    return r;
}

int main(){
    int a[113], n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    cout << binary_search_left(a, n, 3) << " " << binary_search_right(a, n, 3) << endl;
    int pos1 = lower_bound(a, a + n, -7) - a;
    int pos2 = upper_bound(a, a + n, 7) - a;
    cout << pos1 << " " << pos2;
}

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

// f(x) -inf 1 2 3 3 3 4 5 +inf
// x     -1  0 1 2 3 4 5 6   7
// y = x ^ 2, y = f(x) = x ^ 2
// n стойл (n <= 10 ^ 5), k коров (0 < k <= n)
// каждое стойло задается координатой a[i] (0 <= a[i] <= 10^9)
// разместить k коров так, чтобы минимальное расстояние между двумя
// коровами было максимально

/*bool can(int a[], int n, int k, int d){
    int cnt = 1, last = 0;
    for(int i = 1; i < n; i++){
        if (a[i] - a[last] >= d){
            last = i;
            cnt++;
        }
    }
    return (cnt >= k);
}*/

// f(x) = x ^ 3 - возрастающая
// f(x) = x ^ 2 - возрастающая на отрезке [0; +inf],
// убывающая на отрезке [-inf; 0]
// Есть ли x такой, что f(x) = root(C, n)? (f(x) должна быть либо возрастающей, либо)
// убывающей
// если есть, то вывести с 6 знаками после запятой
// x ^ n = C
long double f(long double x, int n){
    return (pow(x, n));
}

long double FindLeftBoard(long double C, int n){
    long double x = -1;
    while (f(x, n) > C){
        x *= 2;
    }
    return x;
}

long double FindRightBoard(long double C, int n){
    long double x = 1;
    while (f(x, n) < C){
        x *= 2;
    }
    return x;
}

int main(){
    /*int n, k, a[100013];
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int l = 0, r = 1e9 + 1;
    int ans = 0;
    while (l < r){
        int m = (l + r) / 2;
        if (can(a, n, k, m)){
            ans = m;
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    if (can(a, n, k, l)){
        ans = l;
    }
    cout << ans;*/
    int n;
    long double C, l, r;
    cin >> n >> C;
    l = FindLeftBoard(C, n), r = FindRightBoard(C, n);
    long double eps = 1e-7;
    while (fabs(r - l) > eps){
        long double m = (l + r) / 2;
        if (f(m, n) + eps < C){
            l = m;
        }
        else {
            r = m;
        }
    }
    // бинарный поиск на фиксированное число ходов (150 - 300)
    /*for(int i = 0; i < 200; i++){
        long double m = (l + r) / 2;
        if (f(m, n) + eps < C){
            l = m;
        }
        else {
            r = m;
        }        
    }*/
    cout.setf(ios::fixed);
    cout.precision(7);
    cout << (l + r) / 2;
}

