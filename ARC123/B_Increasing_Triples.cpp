
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
    cin >> n;
    vector<int> as;
    vector<int> bs;
    vector<int> cs;
    int a, b, c;
    for (int t = 1; t <= n; t++)
    {
        cin >> a;
        as.push_back(a);
    }
    for (int t = 1; t <= n; t++)
    {
        cin >> b;
        bs.push_back(b);
    }

    for (int t = 1; t <= n; t++)
    {
        cin >> c;
        cs.push_back(c);
    }
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    sort(cs.begin(), cs.end());
    int bi = 0;
    int ci = 0;
    int count = 0;

    for (int ai = 0; ai < n; ai++)
    {
        // cout << ai << " " << bi << " " << ci << endl;
        while ((as[ai] >= bs[bi]) || (bs[bi] >= cs[ci]))
        {
            if (as[ai] >= bs[bi])
            {
                bi += 1;
            }
            if (bs[bi] >= cs[ci])
            {
                ci += 1;
            }
            if ((bi >= n) || (ci >= n))
            {
                cout << count;
                exit(0);
            }
        }
        count += 1;
        bi += 1;
        ci += 1;
        if ((bi >= n) || (ci >= n))
        {
            cout << count;
            exit(0);
        }
    }
    cout << count;
}