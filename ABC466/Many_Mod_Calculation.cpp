#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 2e18;

void solve()
{
    int n;
    ll x;
    cin >> n >> x;

    vector<ll> B;
    ll current_min = INF;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        if (a < current_min)
        {
            B.push_back(a);
            current_min = a;
        }
    }

    int m = B.size();
    vector<ll> W(m, 0);

    auto eval_C = [&](ll v, int idx) -> ll
    {
        ll res = 0;
        while (true)
        {
            auto it = lower_bound(B.begin() + idx, B.end(), v, greater<ll>());
            int j = it - B.begin();

            if (j == m)
            {
                res += 1;
                break;
            }

            if (j == m - 1)
            {
                res += v / B[j] + 1;
                break;
            }

            res += (v / B[j]) * W[j];
            v %= B[j];
            idx = j + 1;
        }
        return res;
    };

    for (int i = m - 2; i >= 0; i--)
    {
        W[i] = eval_C(B[i] - 1, i + 1);
    }

    ll ans = eval_C(x, 0) - 1;
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}