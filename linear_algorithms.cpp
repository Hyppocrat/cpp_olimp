#include <cstdio>
#include <cstring>
 
using namespace std;
//Найти в массиве пару элементов, что правый минус левый – максимально. 
//Более формально, найти такую пару индексов i и j, что i<j , и 
// a[j] - a[i] максимальное.
int main () {
    int n, a[100013];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int best_i = 0, best_j = 1, ans = a[1] - a[0], mnind;
    if (a[1] > a[0]){
        mnind = 0;
    }
    else {
        mnind = 1;
    }
    for(int i = 2; i < n; i++){
        if (a[i] - a[mnind] > ans){
            ans = a[i] - a[mnind];
            best_i = mnind;
            best_j = i;
        }
        if (a[mnind] > a[i]){
            mnind = i;
        }
    }
}


#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
//Найти в массиве пару элементов, что правый минус левый – максимально. 
//Более формально, найти такую пару индексов i и j, что i<j , и 
// a[j] - a[i] максимальное.
int main () {
    int n, a[100013], s[100013];
    // s[i] - сумма первых i элементов массива
    // s[0] = 0
    // s[1] = a[0]
    // s[2] = a[0] + a[1] = s[1] + a[1]
    // s[3] = a[0] + a[1] + a[2] = s[2] + a[2]
    // ...
    // a[l] + a[l + 1] + ... + a[r] = 
    // (a[1] + a[2] + ... + a[l - 1]) - (a[1] + a[2] + ... a[l - 1]) +
    // a[l] + a[l + 1] + ... + a[r] = 
    // s[r] - s[l - 1]
    // 2 1 -3 5
    // найти в массиве s такую пару элементов, что i < j
    // и s[i] - s[j] - максимально/минимально
    cin >> n;
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

}


#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define vi vector <int>
#define ll long long
#define PI 3.14159265
 
using namespace std;
int main () {
    int n, m;
    cin >> n >> m;
    vi a(n), b(m), c(n + m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int i = 0, l1 = 0, l2 = 0;
    while (l1 < n && l2 < m){
        if (a[l1] < b[l2]){
            c[i] = a[l1]; 
            i++; 
            l1++;
        }
        else {
            c[i] = b[l2];
            i++;
            l2++;
        }
    }
    while (l1 < n){
        c[i] = a[l1];
        l1++;
        i++;
    }
    while (l2 < m){
        c[i] = b[l2];
        l2++;
        i++;
    }
}


#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
 
using namespace std;

int main () {
    stack<int> st;
    st.push(0);
    int n, a[100013], ans[100013];
    memset(ans, 0, sizeof(ans));
    cin >> n;
    a[0] = -2000000000;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = n; i >= 1; i--){
        if (a[i] > a[st.top()]){
            ans[i] = st.top();
            st.push(i);
        }
        else {
            while (a[i] <= a[st.top()]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
}
