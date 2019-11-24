#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
using namespace std;


// x - простое => 2x, 3x, ... - составные
// phi(n) - фунция Эйлера (количество чисел от 1 до n,
// взаимно простых с n)
// phi(12) = 3 (5, 7, 11)
// phi(21) = 11 (2, 4, 5, 8, 10, 11, 13, 16, 17, 19, 20)
// gcd(x, x + 1) = 1
// phi(p) = p - 1, если p - простое
// phi(p ^ a) = p ^ a - p ^ (a - 1), если p - простое
// phi(a * b) = phi(a) * phi(b), если a и b - взаимно просты
// n = p1 ^ a1 * p2 ^ a2 * ... * pk ^ ak
// phi(n) = phi(p1 ^ a1 * p2 ^ a2 * ... * pk ^ ak) =
// phi(p1 ^ a1) * phi(p2 ^ a2) * ... phi(pk ^ ak) =
// (p1 ^ a1 - p1 ^ (a1 - 1)) * (p2 ^ a2 - p2 ^ (a2 - 1)) * ...
// ... * (pk ^ ak - pk ^ (ak - 1)) =
// p1 ^ a1 * (1 - 1 / p1) * p2 ^ a2 * (1 - 1 / p2) * ... * pk ^ ak * (1 - 1 / pk) =
// p1 ^ a1 * p2 ^ a2 * ... * pk ^ ak * (1 - 1 / p1) * (1 - 1 / p2) * ...
// n * (1 - 1 / p1) * (1 - 1 / p2) * ... * (1 - 1 / pk)


// n - n / p1 = n * (1 - 1 / p1)
// (a ^ phi(m)) % m = 1 (теорема Эйлера)
// (a ^ k) % m = 1 -> k % phi(m) = 0
// k % phi(m) = 0 -> k = t * phi(m)
// a ^ (t * phi(m)) = (a ^ phi(m)) ^ t
// (a ^ phi(m)) % m = 1 -> (1 ^ t) % m = 1
// m - простое -> a ^ (m - 1) % m = 1 (малая теорема Ферма) 
// k = 4
// m = k++;
// cout << m << " " << k << endl;
// m = ++k;
// cout << m << " " << k << endl;
int phi (int n) {
	int result = n;
	for (long long i = 2; i * i <= n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

int main(){
    int n;
    cin >> n;
    // vector <тип> имя;
    vector <char> prime(n + 1, 1);
    // массив из n + 1 элемента (нумерация: 0, 1, ..., n)
    // состоящий из 1
    // prime.resize(10);
    // prime.assign(10, 1);
    // vector <string> s(10, "aaa");
    // vector < vector<int> > a(n, vector<int>(m, 1));
    // a.push_back(x);
    // a.pop_back();
    // cout << a.back();
    // http://www.cplusplus.com/reference/vector/
    // a.clear()
    // sort(a.begin(), a.end());
    // prime[i] = 0, если i - составное, prime[i] = 1, если i - простое
    // i = 3 -> 6, 9, 12, 15, ... - составные
    // i = 5 -> 10, 15, 20, ... - составные
    prime[0] = prime[1] = 0;
    for(long long i = 2; i * i <= n; i++){
        if (prime[i]){
            for(long long j = i * i; j <= n; j += i){
                prime[j] = 0;
            }
        }
    }
    int i = 2;
    while (n != 1){
        if (prime[i] && n % i == 0){
            int cnt = 0;
            cout << i << " ";
            while (n % i == 0){
                n /= i;
                cnt++;
            }
            cout << cnt << endl;
        }
        i++;
    }
}
