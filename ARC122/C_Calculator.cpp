
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
    ll tc;
    cin >> tc;
    vector<ll> values;
    while (tc > 0)
    {
        // cout << tc << endl;
        if (tc % 2 == 0)
        {
            values.push_back(4);
            values.push_back(3);
            tc = tc / 2;
        }
        else
        {
            values.push_back(2);
            values.push_back(1);
            tc = tc - 1;
        }
    }
    // cout << "Result" << endl;
    cout << values.size() - 1 << endl;
    for (int i = values.size() - 1; i > 0; i--)
    {
        cout << values[i] << endl;
    }
}