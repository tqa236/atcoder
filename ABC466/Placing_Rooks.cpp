#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> r(m), c(m);
    for (int i = 0; i < m; i++)
    {
        cin >> r[i] >> c[i];
    }

    vector<bool> seen_row(n + 1, false);
    vector<bool> seen_col(n + 1, false);

    int ans = 0;

    for (int i = m - 1; i >= 0; i--)
    {
        if (!seen_row[r[i]] && !seen_col[c[i]])
        {
            ans++;
        }

        seen_row[r[i]] = true;
        seen_col[c[i]] = true;
    }

    cout << ans << "\n";
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

    return 0;
}