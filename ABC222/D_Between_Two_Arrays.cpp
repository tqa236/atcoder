
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 998244353;
const ll INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    vector<ll> a;
    vector<ll> b;
    ll num;
    for (ll t = 1; t <= n; t++)
    {
        cin >> num;
        a.push_back(num + 1);
    }
    for (ll t = 1; t <= n; t++)
    {
        cin >> num;
        b.push_back(num + 1);
    }
    ll dp[n][b[n - 1] + 1];
    memset(dp, 0, sizeof(dp));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = a[i]; j <= b[i]; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 1 + dp[i][j - 1];
                dp[i][j] = dp[i][j] % MOD;
                // cout << i << " " << j << " " << dp[i][j] << endl;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] = dp[i][j] % MOD;
                // cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        for (ll j = b[i] + 1; j <= b[n - 1]; j++)
        {
            dp[i][j] = dp[i][j - 1];
            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[n - 1][b[n - 1]];
}