
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve()
{
    int N;
    cin >> N;
    bool all_negative = true;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (x >= 0)
        {
            all_negative = false;
        }
    }
    cout << (all_negative ? "Yes" : "No") << '\n';
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