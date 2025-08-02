#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> result;
bool found;

void dfs(int current, int target, vector<vector<int>> &adj, set<int> &visited, vector<int> &path)
{
    if (found)
        return;

    if (current == target)
    {
        result = path;
        found = true;
        return;
    }

    for (int neighbor : adj[current])
    {
        if (visited.find(neighbor) == visited.end())
        {
            visited.insert(neighbor);
            path.push_back(neighbor);
            dfs(neighbor, target, adj, visited, path);
            if (found)
                return;
            path.pop_back();
            visited.erase(neighbor);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int N, M, X, Y;
        cin >> N >> M >> X >> Y;

        vector<vector<int>> adj(N + 1);

        for (int i = 0; i < M; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= N; i++)
        {
            sort(adj[i].begin(), adj[i].end());
        }

        result.clear();
        found = false;

        set<int> visited;
        vector<int> path;

        visited.insert(X);
        path.push_back(X);
        dfs(X, Y, adj, visited, path);

        for (int i = 0; i < result.size(); i++)
        {
            if (i > 0)
                cout << " ";
            cout << result[i];
        }
        cout << "\n";
    }

    return 0;
}