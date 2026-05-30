#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve()
{
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    bool has_b = false, has_w = false;

    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == '#')
                has_b = true;
            if (s[i][j] == '.')
                has_w = true;
        }
    }

    if (!has_b || !has_w)
    {
        for (int i = 0; i < h; i++)
        {
            cout << string(w, '.') << "\n";
        }
        return;
    }

    vector<int> dist(h * w, -1);
    queue<int> q;

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == '.')
            {
                bool adj_b = false;
                for (int k = 0; k < 8; k++)
                {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < h && nj >= 0 && nj < w)
                    {
                        if (s[ni][nj] == '#')
                        {
                            adj_b = true;
                            break;
                        }
                    }
                }
                if (adj_b)
                {
                    dist[i * w + j] = 0;
                    q.push(i * w + j);
                }
            }
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        int r = u / w;
        int c = u % w;

        for (int k = 0; k < 8; k++)
        {
            int nr = r + dx[k];
            int nc = c + dy[k];

            if (nr >= 0 && nr < h && nc >= 0 && nc < w)
            {
                int v = nr * w + nc;
                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        string ans(w, '.');
        for (int j = 0; j < w; j++)
        {
            if (dist[i * w + j] % 2 != 0)
            {
                ans[j] = '#';
            }
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}