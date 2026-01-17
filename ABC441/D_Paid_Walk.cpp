#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int N, M, L;
ll S, T;
vector<pair<int, int>> adj[MAX_N];
bool valid_dest[MAX_N];

void dfs(int u, int depth, ll cost)
{
    if (cost > T)
        return;

    if (depth == L)
    {
        if (cost >= S)
        {
            valid_dest[u] = true;
        }
        return;
    }

    for (auto &edge : adj[u])
    {
        int v = edge.first;
        int w = edge.second;
        dfs(v, depth + 1, cost + w);
    }
}

void solve()
{
    cin >> N >> M >> L >> S >> T;

    for (int i = 0; i <= N; i++)
    {
        adj[i].clear();
        valid_dest[i] = false;
    }

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dfs(1, 0, 0);

    bool first = true;
    for (int i = 1; i <= N; i++)
    {
        if (valid_dest[i])
        {
            if (!first)
                cout << " ";
            cout << i;
            first = false;
        }
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}