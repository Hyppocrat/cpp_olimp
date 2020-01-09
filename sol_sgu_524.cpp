#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    long double b[413], a[413];
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    long double t = 1e20, eps = 1e-4, diff;
    int best_i = -1, best_j = -1;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            a[i] = b[i];
            a[j] = b[j];
            diff = (b[j] - b[i]) / (j - i);
            long double sm = 0;
            for(int k = i + 1; k < j; k++){
                a[k] = a[k - 1] + diff;
            }
            for(int k = i - 1; k > 0; k--){
                a[k] = a[k + 1] - diff;
            }
            for(int k = j + 1; k <= n; k++){
                a[k] = a[k - 1] + diff;
            }
            for(int k = 1; k <= n; k++){
                sm += abs(a[k] - b[k]);
            }
            if (t > sm + eps){
                t = sm;
                best_i = i;
                best_j = j;
            }
        }
    }
    cout.setf(ios::fixed);
    cout.precision(8);
    cout << t << endl;
    diff = (b[best_j] - b[best_i]) / (best_j - best_i);
    for(int i = best_i + 1; i < best_j; i++){
        b[i] = b[i - 1] + diff;
    }
    for(int i = best_i - 1; i > 0; i--){
        b[i] = b[i + 1] - diff;
    }
    for(int i = best_j + 1; i <= n; i++){
        b[i] = b[i - 1] + diff;
    }
    for(int i = 1; i <= n; i++){
        cout << b[i] << " ";
    }
	return 0;
}
