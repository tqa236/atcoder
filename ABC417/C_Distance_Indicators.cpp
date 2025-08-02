#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    long long count = 0;
    unordered_map<int, int> freq;

    for (int j = 1; j <= N; j++)
    {
        int target = j - A[j];

        if (freq.find(target) != freq.end())
        {
            count += freq[target];
        }

        freq[j + A[j]]++;
    }

    cout << count << endl;

    return 0;
}