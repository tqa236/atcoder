
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    vector<int> prefix_sum1((n + 1) / 2);
    vector<int> prefix_sum2(n / 2);
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            sum1 += w[i];
            prefix_sum1[i / 2] = sum1;
        }
        else
        {
            sum2 += w[i];
            prefix_sum2[i / 2] = sum2;
        }
    }
    // for (int i = 0; i < (n + 1) / 2; i++)
    //     cout << prefix_sum1[i] << " ";
    // cout << endl;
    // for (int i = 0; i < (n) / 2; i++)
    //     cout << prefix_sum2[i] << " ";
    // cout << endl;
    int count = 0;
    for (int j = 1; j < n; j++)
        for (int i = 0; i < j; i++)
        {
            sum1 = 0;
            sum2 = 0;
            if (i >= 2)
            {
                sum1 = prefix_sum1[(i + 1) / 2 - 1];
                sum2 = prefix_sum2[i / 2 - 1];
            }
            else if (i >= 1)
            {
                sum1 = prefix_sum1[(i + 1) / 2 - 1];
            }
            // cout << i << " " << j << endl;
            // cout << sum1 << " " << prefix_sum1[j / 2] << " " << sum2 << " " << prefix_sum2[(j - 1) / 2] << endl;
            if (prefix_sum1[j / 2] - sum1 == prefix_sum2[(j - 1) / 2] - sum2)
            {
                // cout << "Good" << endl;
                count += 1;
            }
        }
    cout << count << endl;
}
