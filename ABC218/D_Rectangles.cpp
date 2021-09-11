
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
const ll MAX_N = 1e5 + 1;
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
    ll N, x, y;
    cin >> N;
    map<ll, set<ll>> my_map;
    for (ll t = 1; t <= N; t++)
    {
        cin >> x >> y;
        my_map[x].insert(y);
    }
    ll size;
    ll count = 0;
    for (auto element1 = my_map.begin(); element1 != my_map.end(); ++element1)
    {
        for (auto element2 = next(element1); element2 != my_map.end(); ++element2)
        {
            set<ll> intersect;

            set_intersection(element1->second.begin(), element1->second.end(), element2->second.begin(), element2->second.end(), inserter(intersect, intersect.begin()));
            size = intersect.size();
            if (size >= 2)
                count += size * (size - 1) / 2;
        }
    }
    cout << count;
}