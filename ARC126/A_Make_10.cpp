
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
    int tc;
    cin >> tc;
    ll a, b, c, tmp;
    ll count;
    for (int t = 1; t <= tc; t++)
    {
        cin >> a >> b >> c;
        count = 0;
        if (b >= 2 * c)
            tmp = c;
        else
            tmp = b / 2;
        count += tmp;
        b -= 2 * tmp;
        c -= tmp;

        if (2 * c >= a)
            tmp = a;
        else
            tmp = c / 2;
        count += tmp;
        c -= 2 * tmp;
        a -= tmp;

        if (b >= a)
            tmp = a / 2;
        else
            tmp = b / 2;
        count += tmp;
        b -= 2 * tmp;
        a -= 2 * tmp;

        if (3 * c >= a)
            tmp = a / 3;
        else
            tmp = c;
        count += tmp;
        a -= 3 * tmp;
        c -= tmp;

        count += a / 5;

        cout << count << endl;
    }
}