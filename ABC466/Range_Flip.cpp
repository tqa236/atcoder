#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve()
{
    int n, k;
    cin >> n >> k;

    int max_j = 2 * k;
    vector<ll> dp(max_j + 1, 0);

    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;

        vector<ll> new_dp(max_j + 1, 0);
        ll max_prev = 0;

        for (int j = 0; j <= max_j; j++)
        {
            max_prev = max(max_prev, dp[j]);

            ll val = (j % 2 == 0) ? a : b;
            new_dp[j] = max_prev + val;
        }
        dp = move(new_dp);
    }

    ll ans = 0;
    for (int j = 0; j <= max_j; j++)
    {
        ans = max(ans, dp[j]);
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