
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
    int n, a, x, y;
    cin >> n >> a >> x >> y;
    int result;
    if (n > a)
    {
        result = a * x + (n - a) * y;
    }
    else
    {
        result = n * x;
    }
    cout << result;
}