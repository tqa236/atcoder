
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 998244353;
const ll INF = 1e9;

template <typename T>
vector<size_t> sort_indexes(vector<T> v)
{

    // initialize original index locations
    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);

    // sort indexes based on comparing values in v
    // using std::stable_sort instead of std::sort
    // to avoid unnecessary index re-orderings
    // when v contains elements of equal values
    stable_sort(idx.begin(), idx.end(),
                [&v](size_t i1, size_t i2)
                { return v[i1] < v[i2]; });

    return idx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    vector<int> numbers;
    int number;
    int count;
    ll total = 0;

    for (int t = 1; t <= tc; t++)
    {
        cin >> number;
        numbers.push_back(number);
    }
    vector<size_t> indices = sort_indexes(numbers);
    // for (int t = 0; t < tc; t++)
    // {
    //     cout << indices[t] << endl;
    // }
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            if (numbers[j] >= numbers[i])
            {
                total += (ll)pow(2, j - i - 1);
                total = total % MOD;
            }
        }

        // cout << i << " " << count << " " << total << " " << numbers[i] << endl;
    }
    cout
        << total;
}