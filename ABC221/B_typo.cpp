
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
    string s, t;
    cin >> s;
    cin >> t;
    bool swap = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != t[i])
        {
            if (i == s.length() - 1)
            {
                cout << " No";
                exit(0);
            }
            if (swap)
            {
                cout << "No";
                exit(0);
            }
            if ((s[i] == t[i + 1]) && (s[i + 1] == t[i]))
            {
                swap = true;
                i++;
            }
            else
            {
                cout << "No";
                exit(0);
            }
        }
    }
    cout << "Yes";
}