
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    vector<ll> values;
    ll a;
    ll total = INF;
    ll curr = 0;
    for (int t = 1; t <= tc; t++)
    {
        cin >> a;
        values.push_back(a);
        // cout << a << endl;
    }
    sort(values.begin(), values.end(), greater<ll>());
    for (int i = 0; i < tc; i++)
    {
        curr += values[i];
        total = min(total, 2 * curr + values[i] * (tc - 2 * (i + 1)));
        // cout << curr << " " << total << endl;
    }
    // cout << total << endl;
    double val = total * 1.0 / (2 * tc);
    cout.precision(17);
    cout << val;
}