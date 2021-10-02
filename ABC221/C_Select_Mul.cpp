
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

struct greaterthan
{
    template <class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<int> digits;
    while (n > 0)
    {
        int digit = n % 10;
        n /= 10;
        digits.push_back(digit);
    }
    sort(digits.begin(), digits.end(), greaterthan());
    ll first = digits[0];
    ll second = digits[1];
    for (int i = 2; i < digits.size(); i++)
    {
        if (first < second)
        {
            first = 10 * first + digits[i];
        }
        else
        {
            second = 10 * second + digits[i];
        }
    }
    cout << first * second;
}