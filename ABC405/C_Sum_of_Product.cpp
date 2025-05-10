#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int N;
    cin >> N;

    vector<int> A(N);
    long long sum = 0;
    long long sumOfSquares = 0;

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        sum += A[i];
        sumOfSquares += static_cast<long long>(A[i]) * A[i];
    }

    long long result = (sum * sum - sumOfSquares) / 2;
    cout << result << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
