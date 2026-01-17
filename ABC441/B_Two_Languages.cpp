#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    unordered_set<char> takahashi, aoki;
    for (char c : S)
        takahashi.insert(c);
    for (char c : T)
        aoki.insert(c);

    int Q;
    cin >> Q;
    while (Q--)
    {
        string w;
        cin >> w;
        bool is_takahashi = true, is_aoki = true;

        for (char c : w)
        {
            if (takahashi.find(c) == takahashi.end())
                is_takahashi = false;
            if (aoki.find(c) == aoki.end())
                is_aoki = false;
        }

        if (is_takahashi && !is_aoki)
            cout << "Takahashi\n";
        else if (is_aoki && !is_takahashi)
            cout << "Aoki\n";
        else
            cout << "Unknown\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
