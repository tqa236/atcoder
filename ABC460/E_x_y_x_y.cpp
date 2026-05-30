#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const ll MOD = 998244353;
ll power10[19];

void precompute()
{
    power10[0] = 1;
    for (int i = 1; i <= 18; i++)
        power10[i] = power10[i - 1] * 10;
}

void solve()
{
    ll N, M;
    cin >> N >> M;

    ll ans = 0;
    ll pow10d_mod = 1;

    for (int d = 1; d <= 19; d++)
    {
        pow10d_mod = pow10d_mod * 10 % M;

        ll lo = (d == 1) ? 1LL : power10[d - 1];
        if (lo > N)
            break;

        ll hi = (d <= 18) ? min(N, power10[d] - 1) : N;

        ll count_y = hi - lo + 1;

        ll k = (pow10d_mod - 1 + M) % M;
        ll g = gcd(k, M);
        ll p = M / g;

        ll count_x = N / p;

        ans = (ans + (count_y % MOD) * (count_x % MOD)) % MOD;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precompute();

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}