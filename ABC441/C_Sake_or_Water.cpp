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
    ll x;
    cin >> n >> k >> x;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    ll current_sum = 0;

    for (int i = n - k; i < n; i++)
    {
        current_sum += a[i];

        if (current_sum >= x)
        {
            cout << i + 1 << "\n";
            return;
        }
    }

    cout << -1 << "\n";
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