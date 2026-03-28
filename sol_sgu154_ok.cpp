#include <bits/stdc++.h>
 
using namespace std;
 
int f(int n){
    long long k = 0;
    while (n > 0){
        k += (n / 5);
        n /= 5;
    }
    return k;
}
 
int main(){
    int q;
    cin >> q;
    int l = 1, r = 1e9;
    while (l < r){
        int m = (l + r) / 2;
        if (f(m) < q){
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    if (f(r) == q){
        cout << r;
    }
    else {
        cout << "No solution";
    }
}
