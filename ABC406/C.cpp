#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];

    vector<int> feat;
    for (int i = 1; i + 1 < n; ++i)
    {
        if ((p[i - 1] < p[i] && p[i] > p[i + 1]) || (p[i - 1] > p[i] && p[i] < p[i + 1]))
            feat.push_back(i);
    }
    if (p[0] < p[1])
        feat.insert(feat.begin(), 0);
    if (p[n - 2] < p[n - 1])
        feat.push_back(n - 1);

    long long ans = 0;

    for (int i = 0; i + 3 < feat.size(); i = i + 2)
    {

        ans += (long long)(feat[i + 1] - feat[i]) * (feat[i + 3] - feat[i + 2]);
        // cout << i << " " << ans << endl;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}