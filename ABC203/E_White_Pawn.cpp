
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

bool sortbyfirst(const pair<int, int> &a,
                 const pair<int, int> &b)
{
    return (a.first < b.first);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> blacks;
    vector<bool> available(2 * n);
    int x, y;
    for (int t = 1; t <= m; t++)
    {
        cin >> x >> y;
        available[x] = true;
        blacks.push_back(make_pair(x, y));
    }
    int min_x = 0;
    int max_x = 2 * n;
    for (int t = n; t >= 0; t--)
    {
        if (!available[t])
        {
            min_x = t + 1;
            break;
        }
    }
    for (int t = n; t <= 2 * n; t++)
    {
        if (!available[t])
        {
            max_x = t - 1;
            break;
        }
    }

    deque<pair<int, int>> pawns;
    for (int i = 0; i < m; i++)
    {
        if ((blacks[i].first >= min_x) && (blacks[i].first <= max_x))
        {
            pawns.push_back(blacks[i]);
        }
    }
    sort(pawns.begin(), pawns.end(), sortbyfirst);

    // for (int i = 0; i < pawns.size(); i++)
    // {
    //     cout << pawns[i].first << " " << pawns[i].second << endl;
    // }

    vector<bool> can_reach(max_x - min_x - 1);
    deque<pair<int, int>> to_visit;
    pair<int, int> node, pawn;
    to_visit.push_back(make_pair(0, n));
    bool advance;
    std::set<pair<int, int>> visited;
    int count = 0;
    while (!to_visit.empty())
    {
        // cout << "New" << endl;
        // for (int i = 0; i < to_visit.size(); i++)
        // {
        //     cout << to_visit[i].first << " " << to_visit[i].second << endl;
        // }

        node = to_visit.front();
        // cout << "visited size" << visited.size() << endl;

        while ((!visited.empty()) && (visited.find(node) != visited.end()))
        {
            to_visit.pop_front();
            if (to_visit.empty())
            {
                cout << 0;
                return 0;
            }
            node = to_visit.front();
        }

        if (node.first == 2 * n)
        {
            cout << "True" << endl;

            for (int i = 0; i < to_visit.size(); i++)
            {
                cout << to_visit[i].first << " " << to_visit[i].second << endl;
            }

            for (int i = 0; i < to_visit.size(); i++)
            {
                // cout << to_visit[i].first - min_x << endl;
                if (!can_reach[to_visit[i].first - min_x])
                {
                    // cout << "can reach" << endl;
                    can_reach[to_visit[i].first - min_x] = true;
                    count += 1;
                }
            }
            cout << count;
            return 0;
        }
        else
        {
            to_visit.pop_front();
            visited.insert(node);
            advance = true;
            for (int j = 0; j < pawns.size(); j++)
            {
                pawn = pawns.front();
                if (pawn.first <= node.first)
                {
                    pawns.pop_front();
                }
                else if (pawn.first == node.first + 1)
                {
                    if (abs(pawn.second - node.second) == 1)
                    {
                        to_visit.push_back(pawn);
                    }
                    else if (pawn.second == node.second)
                    {
                        advance = false;
                    }
                }
                else
                    break;
            }
            if (advance)
            {
                to_visit.push_back(make_pair(node.first + 1, node.second));
            }
        }
    }
    cout << 0;
}