#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
// дана прямоугольная доска размера 2 x N.
// сколькими различными способами её можно замостить
// плитками размера 1 x 2? (плитки можно поворачивать на 90 гр)
// dp[i] - количество способов замостить доску  размера 2 x i
// |-- ||- |||
// |-- ||- ||| 
// dp[i] = dp[i - 1] + dp[i - 2]


// на первой ступени лестницы, состоящей из N ступенек, стоит
// заяц. Заяц может подняться на 1 ступень, перепрыгнуть через
// 1 ступень либо перепрыгнуть через 2 ступени
// Сколькими способами он может оказаться на N-й ступени?
// dp[i] - количество способов попасть на ступеньку с номером i
// заяц прыгает не более, чем через k ступеней

// есть числа a[1], a[2], ..., a[n].
// найти количество всевозможных сумм вида 
// k1 * a[1] + k2 * a[2] + ... + a[n] * kn, ki = 0 или 1,
// i = 1, 2, ..., n
// dp[i] = 0, если число i получить нельзя
// dp[i] = 1, если число i получить можно

// Даны N чисел. Найти длину наидлиннейшей возрастающей 
// подпоследовательности среди этих чисел
// Пример
// 5
// 5 4 3 2 1
// Ответ: 1
// 6
// 1 4 2 5 3 -1
// 1 2 2 3 3 1 
// 1 2 3
// 1 4 5
// 1 2 5
// dp[i] - длина возрастающей подпоследовательности, самый большой элемент
// которой равен a[i]
// Ответ: 3

int main(){
    int n, a[113], dp[113];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        dp[i] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if (a[i] > a[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << *max_element(dp, dp + n) << " ";
    cout << *min_element(dp, dp + n);
    /*
        int n, S = 0, a[513], dp[50013];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        S += a[i];
    }
    // 2
    // 3 2
    for(int i = 0; i < n; i++){
        // j = (j - a[i]) + a[i]
        // S = 5
        // i = 0, a[i] = 3;
        // j = 3 .. 5
        // i = 1, a[i] = 2;
        // j = 2 .. 5 
        for(int j = S; j >= a[i]; j--){
            if (dp[j - a[i]] > 0){
                dp[j] = 1;
            }
        }
    }
    for(int i = 0; i <= S; i++){
        if (dp[i] > 0){
            cout << i << " ";
        }
    }
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 4;
    for(int i = 5; i <= n; i++){
        dp[i] = 0;
        for(int j = 1; j <= k; j++){
            dp[i] += dp[i - j];
        }
    }*/
    /*for(int i = 5; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }/*
    /*dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }*/
    
}

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*char ch[35];
int a[35], c[300];
bool b[35]; 
string s;

void rec(int k, int n){
    if (k == n){
        for(int i = 0; i < n; i++){
            cout << ch[i]; 
        }
        cout << endl;
    }
    else {
        for(int i = 0; i < 256; i++){
            if (c[i] > 0){
                ch[k] = i;
                c[i]--;
                rec(k + 1, n);
                c[i]++;
            }
        }
    }
}
    int n;
    cin >> s;
    //sort(s.begin(), s.end()); // сортировка символов строки
    n = s.size();
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    for(int i = 0; i < n; i++){
        c[s[i]]++;
    }
    rec(0, n);*/
// поле n * m, в левом верхнем углу - черепаха
// черепаха может ползти либо в соседнюю справа клетку,
// либо в соседнюю снизу клетку
// в каждой клетке есть число - штраф, который
// черепаха платит, переходя в эту клетку
// добраться до нижнего правого угла, собрав минимальное 
// количество штрафа
// n, m <= 100
// a[i][j] <= 1000000
// (n + m) * 1000000
// inf inf inf inf inf inf inf
// inf 1 5 1 5 inf
// inf 2 1 6 1 inf
// inf 4 1 2 1 inf
// inf inf inf inf inf inf inf


int main(){
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int n, m, a[113][113], dp[113][113];
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i <= m + 1; i++){
        dp[0][i] = dp[n + 1][i] = (n + m) * 1000000;
    }
    for(int i = 1; i <= n; i++){
        dp[i][0] = dp[i][m + 1] = (n + m) * 1000000;
    }
    dp[1][1] = a[1][1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if ((i != 1) || (j != 1)){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            }
        }
    }
    cout << dp[n][m] << endl;
    int i = n, j = m;
    //cout << i << " " << j << endl;
    char ch[113][113];
    memset(ch, '#', sizeof(ch));
    ch[i][j] = '+';
    while (i != 1 || j != 1){
        if (dp[i - 1][j] > dp[i][j - 1]){
            j--;
            //cout << i << " " << j << endl;
            ch[i][j] = '+';
        }
        else {
            i--;
            ch[i][j] = '+';
            //cout << i << " " << j << endl;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << ch[i][j];
        }
        cout << endl;
    }
}

