#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
using namespace std;


// LIFO - Last In First Out (стек)
// 1. добавить элемент
// 2. взять верхний элемент (добавленный последним)
// 3. удалить верхний элемент
// 4. проверить на пустоту

// FIFO - First In First Out (очередь)
// 1. добавить элемент в конец очереди
// 2. взять самый первый добавленный элемент
// 3. взять последний добавленный элемент
// 4. удалить самый первый добавленный элемент
// 5. проверить на пустоту
 
// Дек = очередь + стек
// знаем, что лежит в начале и в конце
// добавляем/удаляем из начала и из конца

// Дана последовательность, состоящая из круглых и квадратных скобок
// Скобочная последовательность называется правильной (ПСП),
// если она удовлетворяет 1 из 3 условий
// 1. Пустая скобочная последовательность - ПСП
// 2. если A - ПСП, то (A), [A] - тоже ПСП
// 3. если A и B - ПСП, то AB - тоже ПСП
// () () ()
// (()()) -> ()()
// ((())-> (() -> (
// ())(  -> () )( -> )(

// ([[]]([))]
// (
// [ (
// [((


int main(){
    // stack <тип> имя;
    // queue <тип> имя;
    /*stack <int> st; // пустой стек
    st.push(10); // 10
    if (!st.empty()){
        cout << st.top() << endl;
    }
    st.push(7); // 7 10
    if (st.size() > 0){
        cout << st.top() << endl;
    }
    st.pop(); // 10
    st.pop(); // пустой стек
    //st.pop();
    //cout << st.top() << endl;
    queue <int> q;
    q.push(10); // 10
    q.push(7); // 10 7
    q.pop(); // 7
    q.push(7); // 7 7
    cout << q.front() << " " << q.back() << endl;
    cout << q.size() << endl;
    //deque <int> dq;
    list <int> dq;
    dq.push_front(7); // 7
    dq.push_front(10); // 10 7
    dq.pop_front(); // 7
    dq.push_back(13); // 7 13
    dq.pop_back(); // 7
    cout << dq.front() << " " << dq.back() << endl;
    cout << dq.size();*/
    //string s;
    //cin >> s;
    /*int balance = 0;
    bool pp = 1;
    for(int i = 0; i < s.size(); i++){
        if (s[i] == '('){
            balance++;
        }
        else {
            balance--;
        }
        if (balance < 0){
            pp = 0;
            break;
        }
    }
    if (pp){
        if (balance == 0){
            cout << "YES";
        }
        else {
            cout << "NO";
        }
    }
    else {
        cout << "NO";
    }*/
    /*stack <char> brackets;
    bool pp = 1;
    for(int i = 0; i < s.size(); i++){
        if (s[i] == '(' || s[i] == '['){
            brackets.push(s[i]);
        }
        else {
            if (s[i] == ')'){
                if (brackets.top() != '('){
                    pp = 0;
                    break;
                }
                else {
                    brackets.pop();
                }
            }
            else {
                if (brackets.top() != '['){
                    pp = 0;
                    break;
                }
                else {
                    brackets.pop();
                }                
            }
        }
    }
    if (pp){
        if (brackets.empty()){
            cout << "YES";
        }
        else {
            cout << "NO";
        }
    }
    else {
        cout << "NO";
    }*/
    /*int x;
    //queue <int> q;
    stack<int> q;
    cin >> x;
    while (x != 0){
        q.push(x);
        cin >> x;
    }
    while (!q.empty()){
        //cout << q.front() << " ";
        cout << q.top() << " ";
        q.pop();
    }*/
    // pair <тип, тип> имя
    // pair < pair <int, int> , int > point3D
    // point3D.first.first
    // point3D.first.second
    // point3D.second
    stack <pair <int, int> > st;
    int x;
    //cin >> x;
    //st.push({x, x});
    //st.push(make_pair(x, x));
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if (st.empty()){
            st.push({x, x});
        }
        else {
            st.push({x, min(x, st.top().second)});
        }
        cout << st.top().first << " " << st.top().second << endl;
    }
    while (!st.empty()){
        cout << st.top().second << endl;
        st.pop();
    }
}
