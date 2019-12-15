#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
void bfs(const vector <vector <int> > &gr, int s, vector<char> &used, vector <int> &d){
    // used[i] = 0, если вершина i не была посещена
    // used[i] = 1, если вершину i посетили
    queue <int> q;
    used[s] = 1;
    q.push(s);
    d[s] = 0;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for(int to: gr[v]){
            if (!used[to]){
                d[to] = d[v] + 1;
                used[to] = 1;
                q.push(to);
            }
        }
    }
}
void dfs(const vector <vector <int> > &gr, int s, vector<char> &used, vector <int> &d){
    // used[i] = 0, если вершина i не была посещена
    // used[i] = 1, если вершину i посетили
    stack <int> q;
    used[s] = 1;
    q.push(s);
    d[s] = 0;
    while (!q.empty()){
        int v = q.top();
        q.pop();
        for(int to: gr[v]){
            if (!used[to]){
                d[to] = d[v] + 1;
                used[to] = 1;
                q.push(to);
            }
        }
    }
}
int main () {
    int n, m;
    std::ios::sync_with_stdio(false);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector <vector <int> > gr(n + 13);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    vector <char> used(n + 13, 0);
    vector <int> d(n + 13, n);
    //bfs(gr, 1, used, d);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if (!used[i]){
            bfs(gr, i, used, d);
            cnt++;
        }
        /*if (used[i]){
            cout << i << " ";
        }*/
        //cout << d[i] << " ";
    }
    cout << cnt;
}
