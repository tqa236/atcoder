
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
    int tc = 1;
    int curr, count;
    count = 0;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        cin >> curr;
        if (curr > 10)
        {
            count += (curr - 10);
        }
    }
    cout << count;
}