// стандартная шапка

#include <iostream>
using namespace std;
int main(){
}

========================
  
// программа нахождения суммы двух чисел
#include <iostream>
using namespace std;
int main(){
  int a, b;
  cin >> a >> b;
  int c = a + b;
  cout << c;
}

#include <iostream>
using namespace std;

int main(){
    long long a, b;
    cin >> a >> b;
    long long c = a + b;
    cout << c << " ";
    c = a * b;
    cout << c;
}

================================================
  
#include <iostream>
using namespace std;

int main(){
    int a;
    cin >> a;
    int a3, a2, a1;
    a3 = a % 10;
    a2 = (a / 10) % 10; // 1. 123 / 10 = 12; 2. 12 ? 10 = 2
    a1 = a / 100;
    int b = a3 * 100 + a2 * 10 + a1;
    cout << a3 + a2 + a1 << " " << a3 << a2 << a1 << " " << b;
    // 123
}
