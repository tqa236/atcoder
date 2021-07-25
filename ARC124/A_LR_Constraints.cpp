
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
    int n, k;
    ll c;
    cin >> n >> k;
    string op_type;
    vector<vector<ll>> good(n, vector<ll>(k, 1));
    vector<bool> fill(n, false);
    for (int i = 0; i < k; i++)
    {
        cin >> op_type;
        cin >> c;

        fill[c - 1] = true;
        if (op_type == "L")
        {
            for (int j = 0; j < c - 1; j++)
            {
                good[j][i] = 0;
            }
        }
        else
        {
            for (int j = c; j < n; j++)
            {
                good[j][i] = 0;
            }
        }
    }
    ll count = 1;
    ll count_row;
    for (int i = 0; i < n; i++)
    {
        if (not fill[i])
        {
            count_row = accumulate(good[i].begin(), good[i].end(), 0);
            // cout << i << " " << count_row << endl;
            count *= count_row;
            count = count % 998244353;
        }
    }
    count = count % 998244353;
    cout << count;
}