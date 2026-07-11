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

    int R = 1;
    ll ans = 0;

    for (int i = 1; i <= N - 1; i++)
    {
        R = max(R, i);

        while (R < N)
        {
            cout << "? " << i << " " << R + 1 << "\n";
            cout.flush();

            string res;
            cin >> res;

            if (res == "Yes")
            {
                R++;
            }
            else
            {
                break;
            }
        }

        ans += (R - i);
    }

    cout << "! " << ans << "\n";
    cout.flush();
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

    return 0;
}