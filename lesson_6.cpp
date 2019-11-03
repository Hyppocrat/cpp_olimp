#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



// НОД(a, b) = НОД(a - b, b);
// НОД(a, b) = НОД(b, a % b);
// НОД(a, 0) = a
int main(){
    long long n;
    cin >> n;
    long long divisors[10013], cnt = 0;
    for(long long i = 1; i * i <= n; i++){
        if (n % i == 0){
            divisors[cnt] = i;
            cnt++;
            if (i != (n / i)){
                divisors[cnt] = n / i;
                cnt++;
            }
        }
    }
    sort(divisors, divisors + cnt);
    for(int i = 0; i < cnt; i++){
        cout << divisors[i] << " ";
    }
}
/*
long long gcd(long long a, long long b){
    if (b == 0){
        return a;
    }
    else{ 
        return gcd(b, a % b);
    }
}

void my_swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
    int a, b;
    cin >> a >> b;
    my_swap(a, b);
    cout << a << " " << b;
    bool is_simple(long long n){
        for(long long i = 2; i * i <= n; i++){
            if (n % i == 0){
                return 0;
            }
        }
        return (n != 1);
    }
    // n - составное, если существует i <= sqrt(n)
    // такое, что n % i == 0
    // пусть n - составное и i > sqrt(n)
    // n % i == 0 -> n % (n / i) == 0, n / i > sqrt(n)
    // i * (n / i) == n > sqrt(n) * sqrt(n) = n !!!
    // i <= sqrt(n) ->  i ^ 2 <= n
    bool simp[1000013];
    // b[i] = 1, если число i - простое
    // b[i] = 0, если число i - составное
    int n;
    cin >> n;
    fill(simp, simp + 1000013, 1);
    simp[0] = simp[1] = 0;
    for(int i = 2; i <= n; i++){
        if (simp[i]){
            for(long long j = i * 1ll * i; j <= n; j += i){
                simp[j] = 0;
            }
        }
    }
    long double a, b;
    cin >> a >> b;
    long double eps = 1e-6;
    if (fabs(a - b) < eps  a == b ){
        
    }
    else if (a > b + eps){
        
    }
    else if (a + eps < b){
        
    }*/
