#pragma comment(linker, "/STACK:1000000000")
#include<bits/stdc++.h>
#define eps 1e-6

using namespace std;

int ans(const vector<int> &p){
    int cnt = 1, last = 0;
    for(int i = 1; i < p.size(); i++){
        if (p[i] > p[last]){
            last = i;
            cnt++;
        }
    }
    return cnt;
}

long double factorial(int n){
    if (n < 2){
        return 1;
    }
    return n * factorial(n - 1);
}

long double gcd(long double a, long double b){
    if (b < eps){
        return a;
    }
    return gcd(b, a - (a / b) * b);
}

int main() {
    int n;
    cin >> n;
    vector <int> p(n), a(n + 1, 0);
    for(int i = 0; i < n; i++){
        p[i] = i + 1;
    }
    do{
        a[ans(p)]++;
    }while (next_permutation(p.begin(), p.end()));
    long double k = factorial(n);
    for(int i = 1; i <= n; i++){
        cout << i << "   -   " << a[i] << "/" << k << endl;
    }
    long double mat_oz = 0.0;
    for(int i = 1; i <= n; i++){
        mat_oz += a[i] * i;
    }
    //mat_oz  factorial(n);
    cout.setf(ios::fixed);
    cout.precision(0);
    cout << mat_oz << " / " << k;
}
