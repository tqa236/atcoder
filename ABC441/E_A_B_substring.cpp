#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
const int MAX_N = 5e5 + 5;
const int BIT_SIZE = 2 * MAX_N + 10;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int bit[BIT_SIZE];
int n;
string s;

void update(int i, int val)
{
    for (; i < BIT_SIZE; i += i & -i)
        bit[i] += val;
}

int query(int i)
{
    int res = 0;
    for (; i > 0; i -= i & -i)
        res += bit[i];
    return res;
}

void solve()
{
    cin >> n;
    cin >> s;

    for (int i = 0; i <= 2 * n + 5; i++)
    {
        bit[i] = 0;
    }

    int offset = n + 1;

    ll ans = 0;
    int current_prefix = 0;

    update(0 + offset, 1);

    for (char c : s)
    {
        if (c == 'A')
        {
            current_prefix++;
        }
        else if (c == 'B')
        {
            current_prefix--;
        }
        ans += query(current_prefix + offset - 1);

        update(current_prefix + offset, 1);
    }

    cout << ans << "\n";
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