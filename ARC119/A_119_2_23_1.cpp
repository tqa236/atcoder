
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

int main()
{
    long long N;
    cin >> N;

    long long Answer = (1LL << 60);
    for (int i = 0; i <= 60; i++)
    {
        long long a = N / (1LL << i);
        long long b = i;
        long long c = N - a * (1LL << i);
        Answer = min(Answer, a + b + c);
    }

    cout << Answer << endl;
    return 0;
}