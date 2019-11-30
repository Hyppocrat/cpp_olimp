#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
using namespace std;

long long gcd(long long a, long long b){
    while (b != 0){
        a %= b;
        swap(a, b);
    }
    return a;
}

// НОК(A, B) = A * B / НОД(А, B)

long long lcm(long long a, long long b){
    return a / gcd(a, b) * b;
}

// A * X + B * Y = НОД(A, B), X - ?, Y - ?
// A * X + B * Y = C, если C не делится на НОД(А, В), то
// решений не существует
// A * X + B * Y = G
// B = 0 -> X = 1, Y = 0
// A, B -> B, A % B
// B * X1 + (A % B) * Y1 = G
// A % B = A - B * (A / B)
// 12 % 9 = 12 - 9 * (12 / 9) = 12 - 9 * 1 = 3
// -12 % 9 = -12 - 9 * (-12 / 9) = -12 - 9 * (-1) = -12 + 9 = -3
// B * X1 + (A - B * (A / B)) * Y1 = G
// A * Y1 + B * (X1 - (A / B) * Y1) = G
// X = Y1, Y = X1 - (A / B) * Y1
long long gcdex(long long a, long long b, long long &x, long long &y){
    // cout << a << " " << x << " " << b << " " << y << endl;
    if (b == 0){
        x = 1, y = 0;
        return a;
    }
    long long x1, y1, g;
    g = gcdex(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    // cout << a << " " << x << " " << b << " " << y << endl;
    return g;
}

// множества
// 

int main(){
    /*long long a, b, x, y;
    cin >> a >> b;
    long long g = gcdex(a, b, x, y);
    cout << x << " " << y;*/
    //set <тип> имя;
    // st.find(x); найти элемент x во множестве st
    // если x есть во множестве st, то st.find(x) != st.end()
    // иначе st.find(x) == st.end()
    // пересечение - элементы, которые есть в обоих множествах
    // одновременно
    // объединение - элементы, которые есть или там, или там, или одновременно в двух множествах
    // разность множеств A и B - элементы, которые есть в A,
    // но их нет в B
    // симметрическая разность - объединение разностей множеств
    // A и B и B и A {1, 2, 3} {3, 4, 5} 
    // {1, 2} {4, 5}
    // {1, 2, 4, 5}
    // симметрическая разность - разность объединения и пересечения двух множеств
    // A = {1, 2, 4, 8}
    // U = {1, 2, 3, 4, 5, 6, 7, 8}
    // дополнение A до U = {3, 5, 6, 7}
    
    set <int> st;
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        st.insert(t);
    }
    /*for(auto i: st){
        i -= 10;
        cout << i << " ";
    }
    cout << endl;*/
    cin >> m;
    int ans = 0;
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        // ищем первый элемент во множестве, который больше либо равен, чем t
        //if (st.lower_bound(t) != st.end()){
        //    cout << *st.lower_bound(t) << endl;
        //}
        // ищем первый элемент во множестве, который больше, чем t
        if (st.upper_bound(t) != st.end()){
            cout << *st.upper_bound(t) << endl;
        }
        /*if (st.count(t) > 0){
            ans++;
        }*/
    }
    cout << ans;
}


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;




int main(){
    //map <тип1, тип2> имя;
    //тип1 - тип номеров в массиве (ключи)
    //тип2 - тип значений в массиве (значения)
    /*map <string, int> workers;
    workers.insert({"Ivanov", 6500});
    workers.insert({"Petrov", 10000});
    workers["Sidorov"] = 12000;
    cout << workers.lower_bound("Olegov") -> first << endl;
    cout << workers.lower_bound("Olegov") -> second << endl;
    cout << workers.upper_bound("Sidor") -> first << endl;
    cout << workers.upper_bound("Sidor") -> second << endl;
    workers.erase("Ivanov");
    // workers.count(x) > 0, если ключ x есть в мапе
    // workers.find(x) == workers.end() - если ключа нет
    // workers.find(x) != workers.end() - если ключ есть
    // workers.lower_bound(x) - ищет 1й ключ, >= x
    // workers.upper_bound(x) - ищет 1й ключ, > x
    // workers.size();
    //cout << workers["Sidorov"] << " " << workers["Petroff"];
    /*map <string, string> workers;
    workers.insert({"Ivanov", "6500"});
    workers.insert({"Petrov", "10000"});
    workers["Sidorov"] = "12000";
    //cout << workers["Sidorov"] << " " << workers["Petroff"];
    for (auto i: workers){
        //cout << i.first << " " << i.second << endl;
        // first - ключ, second - значение
    }*/
    int n;
    cin >> n;
    map <int, int> dates;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        dates[t] = 1;
    }
    int m, ans = 0;
    cin >> m;
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        if (dates.count(t) > 0){
            ans++;
        }
    }
    cout << ans;
}#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
using namespace std;

long long gcd(long long a, long long b){
    while (b != 0){
        a %= b;
        swap(a, b);
    }
    return a;
}

// НОК(A, B) = A * B / НОД(А, B)

long long lcm(long long a, long long b){
    return a / gcd(a, b) * b;
}

// A * X + B * Y = НОД(A, B), X - ?, Y - ?
// A * X + B * Y = C, если C не делится на НОД(А, В), то
// решений не существует
// A * X + B * Y = G
// B = 0 -> X = 1, Y = 0
// A, B -> B, A % B
// B * X1 + (A % B) * Y1 = G
// A % B = A - B * (A / B)
// 12 % 9 = 12 - 9 * (12 / 9) = 12 - 9 * 1 = 3
// -12 % 9 = -12 - 9 * (-12 / 9) = -12 - 9 * (-1) = -12 + 9 = -3
// B * X1 + (A - B * (A / B)) * Y1 = G
// A * Y1 + B * (X1 - (A / B) * Y1) = G
// X = Y1, Y = X1 - (A / B) * Y1
long long gcdex(long long a, long long b, long long &x, long long &y){
    // cout << a << " " << x << " " << b << " " << y << endl;
    if (b == 0){
        x = 1, y = 0;
        return a;
    }
    long long x1, y1, g;
    g = gcdex(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    // cout << a << " " << x << " " << b << " " << y << endl;
    return g;
}

// множества
// 

int main(){
    /*long long a, b, x, y;
    cin >> a >> b;
    long long g = gcdex(a, b, x, y);
    cout << x << " " << y;*/
    //set <тип> имя;
    // st.find(x); найти элемент x во множестве st
    // если x есть во множестве st, то st.find(x) != st.end()
    // иначе st.find(x) == st.end()
    // пересечение - элементы, которые есть в обоих множествах
    // одновременно
    // объединение - элементы, которые есть или там, или там, или одновременно в двух множествах
    // разность множеств A и B - элементы, которые есть в A,
    // но их нет в B
    // симметрическая разность - объединение разностей множеств
    // A и B и B и A {1, 2, 3} {3, 4, 5} 
    // {1, 2} {4, 5}
    // {1, 2, 4, 5}
    // симметрическая разность - разность объединения и пересечения двух множеств
    // A = {1, 2, 4, 8}
    // U = {1, 2, 3, 4, 5, 6, 7, 8}
    // дополнение A до U = {3, 5, 6, 7}
    
    set <int> st;
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        st.insert(t);
    }
    /*for(auto i: st){
        i -= 10;
        cout << i << " ";
    }
    cout << endl;*/
    cin >> m;
    int ans = 0;
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        // ищем первый элемент во множестве, который больше либо равен, чем t
        //if (st.lower_bound(t) != st.end()){
        //    cout << *st.lower_bound(t) << endl;
        //}
        // ищем первый элемент во множестве, который больше, чем t
        if (st.upper_bound(t) != st.end()){
            cout << *st.upper_bound(t) << endl;
        }
        /*if (st.count(t) > 0){
            ans++;
        }*/
    }
    cout << ans;
}


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;




int main(){
    //map <тип1, тип2> имя;
    //тип1 - тип номеров в массиве (ключи)
    //тип2 - тип значений в массиве (значения)
    /*map <string, int> workers;
    workers.insert({"Ivanov", 6500});
    workers.insert({"Petrov", 10000});
    workers["Sidorov"] = 12000;
    cout << workers.lower_bound("Olegov") -> first << endl;
    cout << workers.lower_bound("Olegov") -> second << endl;
    cout << workers.upper_bound("Sidor") -> first << endl;
    cout << workers.upper_bound("Sidor") -> second << endl;
    workers.erase("Ivanov");
    // workers.count(x) > 0, если ключ x есть в мапе
    // workers.find(x) == workers.end() - если ключа нет
    // workers.find(x) != workers.end() - если ключ есть
    // workers.lower_bound(x) - ищет 1й ключ, >= x
    // workers.upper_bound(x) - ищет 1й ключ, > x
    // workers.size();
    //cout << workers["Sidorov"] << " " << workers["Petroff"];
    /*map <string, string> workers;
    workers.insert({"Ivanov", "6500"});
    workers.insert({"Petrov", "10000"});
    workers["Sidorov"] = "12000";
    //cout << workers["Sidorov"] << " " << workers["Petroff"];
    for (auto i: workers){
        //cout << i.first << " " << i.second << endl;
        // first - ключ, second - значение
    }*/
    int n;
    cin >> n;
    map <int, int> dates;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        dates[t] = 1;
    }
    int m, ans = 0;
    cin >> m;
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        if (dates.count(t) > 0){
            ans++;
        }
    }
    cout << ans;
}
