#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve()
{
    int n, k;
    cin >> n >> k;

    ll displayed_number = 1;
    ll limit = 1;
    for (int i = 0; i < k; ++i)
        limit *= 10;

    for (int i = 0; i < n; ++i)
    {
        ll a;
        cin >> a;
        if (displayed_number > limit / a)
        {
            displayed_number = 1;
        }
        else
        {
            displayed_number *= a;
            if (displayed_number >= limit)
                displayed_number = 1;
        }
    }

    cout << displayed_number << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}