
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
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b)
    {
        cout << c;
    }
    else if (a == c)
    {
        cout << b;
    }
    else if (b == c)
    {
        cout << a;
    }
    else
    {
        cout << 0;
    }
}