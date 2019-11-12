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
