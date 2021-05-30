
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

bool sortbyfirst(const pair<ll, ll> &a,
                 const pair<ll, ll> &b)
{
    return (a.first < b.first);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    ll pos = 0;
    ll a, b;
    bool stop = false;
    vector<pair<ll, ll>> villages;
    for (ll t = 1; t <= n; t++)
    {
        cin >> a >> b;
        villages.push_back(make_pair(a, b));
    }
    sort(villages.begin(), villages.end(), sortbyfirst);
    for (ll t = 0; t < n; t++)
    {
        a = villages[t].first;
        b = villages[t].second;
        // cout << a << " " << b << endl;
        if (pos + k >= a)
        {
            k -= a - pos;
            k += b;
            pos = a;
            // cout << pos << " " << k << " " << a << " " << b << endl;
        }
        else
        {
            // cout << "Why" << endl;
            // cout << pos << " " << k << " " << a << " " << b << endl;
            stop = true;
            cout << pos + k;
            break;
            // cout << "Here" << endl;
        }
    }
    if (not stop)
    {
        cout << pos + k;
    }
}