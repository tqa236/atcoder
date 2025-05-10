#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int R, X;
    cin >> R >> X;

    if (X == 1)
    {
        if (R >= 1600 && R <= 2999)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else if (X == 2)
    {
        if (R >= 1200 && R <= 2399)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else
    {
        cout << "No" << endl;
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
