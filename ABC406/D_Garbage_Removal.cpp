#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 2e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve()
{
    int H, W, N;
    cin >> H >> W >> N;

    vector<set<int>> row_trash(H + 1);
    vector<set<int>> col_trash(W + 1);

    for (int i = 0; i < N; i++)
    {
        int X, Y;
        cin >> X >> Y;
        row_trash[X].insert(Y);
        col_trash[Y].insert(X);
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++)
    {
        int type, pos;
        cin >> type >> pos;

        if (type == 1)
        {
            cout << row_trash[pos].size() << "\n";

            for (int col : row_trash[pos])
            {
                col_trash[col].erase(pos);
            }
            row_trash[pos].clear();
        }
        else
        {
            cout << col_trash[pos].size() << "\n";

            for (int row : col_trash[pos])
            {
                row_trash[row].erase(pos);
            }
            col_trash[pos].clear();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}