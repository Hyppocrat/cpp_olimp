#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

vector<char> signs;
void rec(string s, int k, int n, int &ans){
    if (k == n){
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < signs.size() / 2; i++){
            if (signs[i] == '-'){
                sum1 -= (s[i] - '0');
            }
            else {
                sum1 += (s[i] - '0');
            }
        }
        for(int i = signs.size() / 2; i < signs.size(); i++){
            if (signs[i] == '-'){
                sum2 -= (s[i] - '0');
            }
            else {
                sum2 += (s[i] - '0');
            }
        }
        if (sum1 == sum2){
            ans++;
        }
        return ;
    }
    signs.push_back('+');
    rec(s, k + 1, n, ans);
    signs.pop_back();
    signs.push_back('-');
    rec(s, k + 1, n, ans);
    signs.pop_back();
}

int main() {
    string ticket;
    cin >> ticket;
    int ans = 0;
    rec(ticket, 0, ticket.size(), ans);
    cout << ans;
    return 0;
}


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    string num;
    cin >> num;
    int digit_sum = 0, k = 2;
    // 123
    for(int i = 0; i < num.size(); i++){
        if (isdigit(num[i])){
            digit_sum += (num[i] - '0');
            k = max(k, num[i] - '0');
        }
        else {
            digit_sum += (10 + num[i] - 'A');
            k = max(k, 10 + num[i] - 'A');
        }
    }
    k++;
    for(int i = k; i <= 36; i++){
        if (digit_sum % (i - 1) == 0){
            cout << i;
            return 0;
        }
    }
    cout << "No solution";
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
using namespace std;
 
 
int main () {
    int n, m, t;
    cin >> n >> m;
    set<int> a, b;
    for(int i = 0; i < n; i++){
        cin >> t;
        a.insert(t);
    }
    for(int i = 0; i < m; i++){
        cin >> t;
        b.insert(t);
    }
    set<int> inter;
    for(auto i: a){
        if (b.count(i)){
            inter.insert(i);
        }
    }
    cout << "INTERSECTION: " << inter.size() << endl;
    set<int> uni;
    for (auto i: a){
        uni.insert(i);
    }
    for (auto i: b){
        uni.insert(i);
    }
    cout << "UNION: " << uni.size() << endl;
    set<int> sub;
    for (auto i: a){
        if (!b.count(i)){
            sub.insert(i);
        }
    }
    cout << "A SUBTRACT B: " << sub.size() << endl;
}


#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
using namespace std;
 
 
int main () {
    map <int, int> cnt, contests;
    int n, m, t;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> t;
        cnt[t] += 1;
        contests[cnt[t]] += 1;
        if (contests[cnt[t]] == n){
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
}

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
using namespace std;
 
 
int main () {
    map <string, int> schools;
    int n;
    cin >> n;
    string t;
    getline(cin, t);
    for(int i = 0; i < n; i++){
        getline(cin, t);
        string number;
        int j = 0;
        while (!isdigit(t[j])){
            j++;
        }
        while (j < t.size() && isdigit(t[j])){
            number += t[j];
            j++;
        }
        schools[number] += 1;
    }
    for (auto i: schools){
        cout << i.first << " " << i.second << endl;
    }
}
