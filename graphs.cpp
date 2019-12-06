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
    int n, m;
    cin >> n >> m;
    /*vector < vector<int> > gr(n + 13, vector<int>(n + 13, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> gr[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << gr[i][j] << " ";
        }
        cout << endl;
    }*/
    /*vector < pair<int, int> > gr(m);
    for(int i = 0; i < m; i++){
        cin >> gr[i].first >> gr[i].second;
    }*/
    vector < vector<int> > gr(n + 13);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < gr[i].size(); j++){
            cout << gr[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 1; i <= n; i++){
        for(auto j: gr[i]){
            cout << j << " ";
        }
        cout << endl;
    }
    // если нужно упорядочивать вершины
    /*vector < set<int> > gr(n + 13);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        gr[u].insert(v);
        gr[v].insert(u);
    }*/
}
