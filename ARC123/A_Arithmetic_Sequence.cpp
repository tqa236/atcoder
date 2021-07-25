
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
    ll a, b, c;
    cin >> a >> b >> c;
    ll goal = a + c;
    ll count = 0;
    if (goal % 2 == 1)
    {
        count += 1;
        goal += 1;
    }
    if (goal > 2 * b)
    {
        count += (goal - 2 * b) / 2;
    }
    else if (goal < 2 * b)
    {
        count += 2 * b - goal;
    }
    cout << count;
}