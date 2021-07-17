
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
    int n, k, color, best;
    int curr = 0;
    best = 0;
    cin >> n >> k;
    vector<int> colors;
    map<int, int> counter;
    for (int i = 0; i < n; i++)
    {
        cin >> color;
        colors.push_back(color);
        if (i >= k)
        {
            counter[colors[i - k]] -= 1;
            if (counter[colors[i - k]] == 0)
            {
                counter.erase(colors[i - k]);
                curr -= 1;
            }
        }

        if (counter.find(color) == counter.end())
        {
            curr += 1;
            counter[color] = 1;
        }
        else
        {
            counter[color] += 1;
        }
        best = max(curr, best);
    }
    cout << best;
}