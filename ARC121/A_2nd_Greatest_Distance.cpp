
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll int

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
    int tc = 1;
    cin >> tc;
    // vector<pair<ll, ll>> points;
    ll a, b;
    ll big1 = 0;
    ll big2 = 0;
    ll val;
    ll minx1, minx2, maxx1, maxx2, miny1, miny2, maxy1, maxy2;
    ll minix1, minix2, maxix1, maxix2, miniy1, miniy2, maxiy1, maxiy2;
    for (int t = 1; t <= tc; t++)
    {
        cin >> a;
        cin >> b;
        if (t == 1)
        {
            minx1 = a;
            maxx1 = a;
            miny1 = b;
            maxy1 = b;

            minix1 = t;
            maxix1 = t;
            miniy1 = t;
            maxiy1 = t;
        }
        else if (t == 2)
        {
            if (a > minx1)
            {
                minx2 = a;
                maxx2 = maxx1;
                maxx1 = a;
                minix2 = t;
                maxix2 = maxix1;
                maxix1 = t;
            }
            else
            {
                minx2 = minx1;
                minix2 = minix1;
                minx1 = a;
                maxx2 = a;
                minix1 = t;
                maxix2 = t;
            }
            if (b > miny1)
            {
                miny2 = b;
                miniy2 = t;
                maxy2 = maxy1;
                maxiy2 = maxiy1;
                maxy1 = b;
                maxiy1 = t;
            }
            else
            {
                miny2 = miny1;
                miniy2 = miniy1;
                miny1 = b;
                maxy2 = b;
                miniy1 = t;
                maxiy2 = t;
            }
        }
        else
        {
            if (a < minx1)
            {
                minx2 = minx1;
                minx1 = a;
                minix2 = minix1;
                minix1 = t;
            }
            else if (a < minx2)
            {
                minx2 = a;
                minix2 = t;
            }
            if (a > maxx1)
            {
                maxx2 = maxx1;
                maxx1 = a;
                maxix2 = maxix1;
                maxix1 = t;
            }
            else if (a > maxx2)
            {
                maxx2 = a;
                maxix2 = t;
            }

            if (b < miny1)
            {
                miny2 = miny1;
                miny1 = b;
                miniy2 = miniy1;
                miniy1 = t;
            }
            else if (b < miny2)
            {
                miny2 = b;
                miniy2 = t;
            }
            if (b > maxy1)
            {
                maxy2 = maxy1;
                maxy1 = b;
                maxiy2 = maxiy1;
                maxiy1 = t;
            }
            else if (b > maxy2)
            {
                maxy2 = b;
                maxiy2 = t;
            }
        }
        // cout << a << " " << b << endl;
        // cout << maxx1 << " " << maxx2 << " " << minx2 << " " << minx1 << endl;
        // points.push_back(make_pair(a, b));
    }
    // cout << maxx1 << " " << maxx2 << " " << minx2 << " " << minx1 << endl;
    // cout << maxy1 << " " << maxy2 << " " << miny2 << " " << miny1 << endl;
    vector<int> distance = {abs(maxx1 - minx1), abs(maxx1 - minx2), abs(maxx2 - minx1), abs(maxy1 - miny1), abs(maxy1 - miny2), abs(maxy2 - miny1)};
    sort(distance.begin(), distance.end(), greater<int>());
    if ((maxix1 == maxiy1) && (minix1 == miniy1))
    {
        cout << distance.at(2);
    }
    else if ((maxix1 == miniy1) && (minix1 == maxiy1))
    {
        cout << distance.at(2);
    }
    else
    {
        cout << distance.at(1);
    }
}