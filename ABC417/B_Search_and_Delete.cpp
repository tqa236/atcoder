#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++)
    {
        int B;
        cin >> B;

        auto it = find(A.begin(), A.end(), B);
        if (it != A.end())
        {
            A.erase(it);
        }
    }

    for (int i = 0; i < A.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << A[i];
    }
    if (!A.empty())
        cout << endl;

    return 0;
}