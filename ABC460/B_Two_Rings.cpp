#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    ll x1, y1, r1, x2, y2, r2;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t  << ": ";
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        ll distance_squared = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        if (distance_squared > (r1 + r2) * (r1 + r2) || distance_squared < (r1 - r2) * (r1 - r2))
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
        solve();
    }
}