
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e15;

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<ll> cutenesses;
    vector<string> colors;
    ll cute;
    string last_color = "U";
    string color;
    int red = 0, blue = 0, green = 0;
    bool rb = false, rg = false, bg = false;
    ll min_rb = INF, min_rg = INF, min_bg = INF;
    for (int t = 1; t <= 2 * N; t++)
    {
        cin >> cute;
        cin >> color;

        cutenesses.push_back(cute);
        colors.push_back(color);
        if (color.compare("R") == 0)
        {
            red += 1;
        }
        else if (color.compare("B") == 0)
        {
            blue += 1;
        }
        else
        {
            green += 1;
        }
        // cout << cute << " " << color << endl;
        // solve();
    }
    if ((red % 2 == 0) && (blue % 2 == 0) && (green % 2 == 0))
    {
        cout << 0;
    }
    else
    {

        vector<size_t> idx(cutenesses.size());
        iota(idx.begin(), idx.end(), 0);

        // sort indexes based on comparing values in v
        // using std::stable_sort instead of std::sort
        // to avoid unnecessary index re-orderings
        // when v contains elements of equal values
        stable_sort(idx.begin(), idx.end(),
                    [&cutenesses](size_t i1, size_t i2)
                    { return cutenesses[i1] < cutenesses[i2]; });
        for (int i = 0; i < 2 * N - 1; i++)
        {
            // cout << idx[i] << " " << idx[i + 1] << endl;
            // cout << colors[idx[i]] << " " << colors[idx[i + 1]] << endl;
            if (((colors[idx[i]].compare("R") == 0) && ((colors[idx[i + 1]].compare("B") == 0))) || (((colors[idx[i]].compare("B") == 0) && ((colors[idx[i + 1]].compare("R") == 0)))))
            {
                rb = true;
                min_rb = min(min_rb, abs(cutenesses[idx[i]] - cutenesses[idx[i + 1]]));
            }
            else if (((colors[idx[i]].compare("R") == 0) && ((colors[idx[i + 1]].compare("G") == 0))) || (((colors[idx[i]].compare("G") == 0) && ((colors[idx[i + 1]].compare("R") == 0)))))
            {
                rg = true;
                min_rg = min(min_rg, abs(cutenesses[idx[i]] - cutenesses[idx[i + 1]]));
            }
            else if (((colors[idx[i]].compare("G") == 0) && ((colors[idx[i + 1]].compare("B") == 0))) || (((colors[idx[i]].compare("B") == 0) && ((colors[idx[i + 1]].compare("G") == 0)))))
            {
                bg = true;
                min_bg = min(min_bg, abs(cutenesses[idx[i]] - cutenesses[idx[i + 1]]));
            }
        }
        // cout << red << " " << blue << " " << green << endl;
        // cout << rb << " " << rg << " " << bg << endl;
        // cout << min_rb << " " << min_rg << " " << min_bg << endl;
        if (red % 2 == 0)
        {
            cout << min(min_bg, min_rg + min_rb);
        }
        else if (blue % 2 == 0)
        {
            cout << min(min_rg, min_rb + min_bg);
        }
        else
        {
            cout << min(min_rb, min_rg + min_bg);
        }
    }
}