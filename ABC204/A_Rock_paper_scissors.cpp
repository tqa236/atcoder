
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
    int x, y, z;
    cin >> x >> y;
    if (x == y)
    {
        cout << x;
    }
    else
    {
        if ((x != 0) && (y != 0))
        {
            cout << 0;
        }
        else if ((x != 1) && (y != 1))
        {
            cout << 1;
        }
        else
            cout << 2;
    }
}