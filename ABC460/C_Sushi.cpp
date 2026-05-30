
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
    int N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < M; i++)
        cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int i = 0, j = 0, count = 0;
    while (i < N && j < M)
    {
        if (B[j] <= 2 * A[i])
        {
            count++;
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    cout << count << endl;
}