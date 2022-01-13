#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<math.h>
#include<algorithm>
#include<time.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<deque>
#include<fstream>
#include<unordered_map>
#include<bitset>
#include<cstdio>


using namespace std;

struct edge {
	long long v, to, f, c;
	edge(long long v, long long to, long long f, long long c)
	{
		this->v = v;
		this->to = to;
		this->f = f;
		this->c = c;
	}
};

const int maxn = 2e5;
vector<edge> Egr;
vector<int> Vgr[maxn];
int lvl[maxn];
int counti[maxn];

bool bfs(int s, int t, int n)
{
	for (int i = 0; i <= n; i++)
		lvl[i] = -1, counti[i] = 0;
	queue<int> st;
	st.push(s);
	lvl[s] = 1;
	while (st.size())
	{
		int v = st.front();
		st.pop();
		for (int i = 0; i < Vgr[v].size(); i++)
		{
			edge r = Egr[Vgr[v][i]];
			if (r.f < r.c && lvl[r.to] == -1)
			{
				lvl[r.to] = lvl[v] + 1;
				st.push(r.to);
			}
		}
	}
	return lvl[t] != -1;
}

long long dfs(int v, int t, long long f)
{
	if (f == 0)
		return 0;
	if (v == t)
		return f;
	for (; counti[v] < Vgr[v].size(); counti[v]++)
	{
		edge r = Egr[Vgr[v][counti[v]]];
		if (lvl[r.to] == lvl[v] + 1)
		{
			long long newans = dfs(r.to, t, min(f, r.c - r.f));
			if (newans)
			{
				Egr[Vgr[v][counti[v]]].f += newans;
				Egr[Vgr[v][counti[v]] ^ 1].f -= newans;
				return newans;
			}
		}
	}
	return 0;
}

long long dinic(int s, int t, int n)
{
	long long ans = 0;
	while (bfs(s, t, n))
	{
		while (true)
		{
			long long newans = dfs(s, t, 1e15 + 113);
			if (!newans)
				break;
			ans += newans;
		}
	}
	return ans;
}

void updedge(int a, int b, long long c)
{
	edge r1(a, b, 0, c);
	edge r2(b, a, 0, 0);
	Vgr[a].push_back(Egr.size());
	Egr.push_back(r1);
	Vgr[b].push_back(Egr.size());
	Egr.push_back(r2);
}

int color[maxn];

int main() {
	//freopen("cooling.in", "r", stdin);
	//freopen("cooling.out", "w", stdout);
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.setf(ios::fixed);
	//cout.precision(4);
	int n, k;
	cin >> n >> k;
	int s = n + 1, t = n + 2;
	for (int i = 1; i <= n; i++)
	{
		int colorv, c;
		cin >> colorv >> c;
		color[i] = colorv;
		if (!color[i])
			updedge(s, i, c);
		else
			updedge(i, t, c);
	}
	for (int i = 1; i <= k; i++)
	{
		int a, b;
		cin >> a >> b;
		if (color[a] != color[b])
		{
			if (color[a])
				swap(a, b);
			updedge(a, b, 1e9 + 113);
		}
	}
	cout << dinic(s, t, t + 1);
	//system("pause");
}
