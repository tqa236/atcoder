
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
    int n;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (string(1, s[i]) == "1")
        {
            if (i % 2 == 0)
            {
                cout << "Takahashi";
                break;
            }
            else
            {
                cout << "Aoki";
                break;
            }
        }
    }
}