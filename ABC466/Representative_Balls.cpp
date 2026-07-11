#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;

    vector<int> maxSizes(M + 1, -1);

    for (int i = 0; i < N; ++i)
    {
        int C, S;
        cin >> C >> S;
        if (S > maxSizes[C])
        {
            maxSizes[C] = S;
        }
    }

    for (int k = 1; k <= M; ++k)
    {
        cout << maxSizes[k];
        if (k < M)
        {
            cout << " ";
        }
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; ++t)
    {
        solve();
    }
    return 0;
}