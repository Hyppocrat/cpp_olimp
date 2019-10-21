
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    int sz = s.size();
    s[sz - 1];
    for (int i = 0; i < s.size(); i++){
        ...
    }
    if (s.find(t) != - 1){ // если t не входит в s, то s.find(t) возвращает -1
        //cout << s.substr(s.find(t), t.size());
        cout << s.find(t); // возвращает позицию первого вхождения строки t в строку s
    }
    if (s.rfind(t) != - 1){ // если t не входит в s, то s.rfind(t) возвращает -1
        //cout << s.substr(s.rfind(t), t.size());
        cout << s.rfind(t); // возвращает позицию последнего вхождения строки t в строку s
    }
}

/*  
    string s;
    cin >> s;
    string s1 = s.substr(3, 4);
    string s2 = s.substr(3);
    cout << s1 << " " << s2;
    islower(c)
    isupper(c)
    isalpha(c)
    isdigit(c)
    isalnum(c)
    char c;
    cin >> c;
    if (islower(c)){
        c = toupper(c);
    }
    else if (isupper(c)){
        c = tolower(c);
    }
    if (c == '0'){
        ...
    }
    cout << c;
    
        string s, s1;
    cin >> s >> s1;
    cout << s << " " << s1 << endl;
    s += s1;
    cout << s;*/
