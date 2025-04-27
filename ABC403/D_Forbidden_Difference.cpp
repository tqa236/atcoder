#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve()
{
    int N, D;
    cin >> N >> D;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<vector<int>> graph(N);

    set<pair<int, int>> edges;

    map<int, vector<int>> value_map;
    for (int i = 0; i < N; i++)
    {
        value_map[A[i]].push_back(i);
    }

    for (int i = 0; i < N; i++)
    {
        if (value_map.count(A[i] + D))
        {
            for (int j : value_map[A[i] + D])
            {
                if (i != j)
                {
                    int u = min(i, j);
                    int v = max(i, j);
                    edges.insert({u, v});
                }
            }
        }

        if (value_map.count(A[i] - D))
        {
            for (int j : value_map[A[i] - D])
            {
                if (i != j)
                {
                    int u = min(i, j);
                    int v = max(i, j);
                    edges.insert({u, v});
                }
            }
        }
    }

    for (auto [u, v] : edges)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> color(N, -1);
    int max_independent_set = 0;

    for (int i = 0; i < N; i++)
    {
        if (color[i] != -1)
            continue;

        vector<int> color_count(2, 0);

        queue<int> q;
        q.push(i);
        color[i] = 0;
        color_count[0]++;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node])
            {
                if (color[neighbor] == -1)
                {
                    color[neighbor] = 1 - color[node];
                    color_count[color[neighbor]]++;
                    q.push(neighbor);
                }
            }
        }

        max_independent_set += max(color_count[0], color_count[1]);
    }

    cout << N - max_independent_set << endl;
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