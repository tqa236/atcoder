#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve()
{
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<set<int>> user_permissions(N + 1);

    vector<bool> has_full_access(N + 1, false);

    for (int q = 0; q < Q; ++q)
    {
        int query_type;
        cin >> query_type;

        if (query_type == 1)
        {
            int X, Y;
            cin >> X >> Y;
            user_permissions[X].insert(Y);
        }
        else if (query_type == 2)
        {
            int X;
            cin >> X;
            has_full_access[X] = true;
        }
        else if (query_type == 3)
        {
            int X, Y;
            cin >> X >> Y;

            if (has_full_access[X] || user_permissions[X].count(Y) > 0)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
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