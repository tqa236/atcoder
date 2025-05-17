#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < c)
    {
        cout << "No\n";
    }
    else if (a > c)
    {
        cout << "Yes\n";
    }
    else
    {
        if (b < d)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}