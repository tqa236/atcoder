
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int score(char first, char second)
{
    if ((first == 'G') && (second == 'C'))
        return 1;
    if ((first == 'C') && (second == 'P'))
        return 1;
    if ((first == 'P') && (second == 'G'))
        return 1;
    return 0;
}

template <typename T>
vector<size_t> sort_indexes(const vector<T> &v)
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
                { return v[i1] < v[i2] || (v[i1] == v[i2] && i1 >= i2); });

    return idx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> hands;
    string hand;
    vector<int> scores;
    vector<size_t> ranks;
    int result;
    for (int t = 1; t <= 2 * n; t++)
    {
        cin >> hand;
        hands.push_back(hand);
        scores.push_back(0);
    }
    for (int t = 0; t < m; t++)
    {
        ranks = sort_indexes(scores);
        for (int i = 0; i < n; i++)
        {
            result = score(hands[ranks[2 * i]][t], hands[ranks[2 * i + 1]][t]);
            scores[ranks[2 * i]] += result;
            result = score(hands[ranks[2 * i + 1]][t], hands[ranks[2 * i]][t]);
            scores[ranks[2 * i + 1]] += result;
        }
        // for (auto i : sort_indexes(scores))
        // {
        //     cout << i + 1 << endl;
        // }
        // cout << endl;
    }
    ranks = sort_indexes(scores);
    for (int i = 0; i < 2 * n; i++)
    {
        cout << ranks[2 * n - 1 - i] + 1 << endl;
    }
}