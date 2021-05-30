
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
    int n, k;
    cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
        {
            sum += 100 * i + j;
        }
    cout << sum;
}