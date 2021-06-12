
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc;
    cin >> tc;
    ll a = 0;
    ll pos_sum = 0;
    ll neg_sum = 0;
    ll pos_count = 0;
    ll neg_count = 0;
    ll tmp_sum = 0;
    ll tmp_count = 0;
    for (ll t = 1; t <= tc; t++)
    {
        cin >> a;
        if (t == 1)
        {
            pos_sum = a;
            pos_count = 1;
        }
        else
        {
            tmp_sum = ((pos_sum - a * pos_count) % MOD + MOD) % MOD;
            tmp_count = pos_count;
            pos_sum = (((pos_sum + neg_sum) % MOD + (a * (pos_count + neg_count)) % MOD) % MOD + MOD) % MOD;
            pos_count = (pos_count + neg_count) % MOD;
            neg_sum = tmp_sum;
            neg_count = tmp_count;
        }
        // cout << ((-4) % 3) << endl;
        // cout << a << " " << pos_sum << " " << pos_count << " " << neg_sum << " " << neg_count << " " << pos_count + neg_count << endl;
    }
    cout << ((pos_sum + neg_sum) % MOD + MOD) % MOD;
}