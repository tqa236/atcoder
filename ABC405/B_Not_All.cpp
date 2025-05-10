#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    bool containsAll = true;
    for (int i = 1; i <= M; ++i)
    {
        if (find(A.begin(), A.end(), i) == A.end())
        {
            containsAll = false;
            break;
        }
    }

    if (!containsAll)
    {
        cout << 0 << endl;
        return;
    }

    int operations = 0;
    while (!A.empty())
    {
        A.pop_back();
        operations++;

        containsAll = true;
        for (int i = 1; i <= M; ++i)
        {
            if (find(A.begin(), A.end(), i) == A.end())
            {
                containsAll = false;
                break;
            }
        }

        if (!containsAll)
        {
            cout << operations << endl;
            return;
        }
    }

    cout << operations << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
