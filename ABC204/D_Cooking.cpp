
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

// Returns the minimum value of the difference of the two sets.
int findMin(int arr[], int n)
{
    // Calculate sum of all elements
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // Create an array to store results of subproblems
    bool dp[n + 1][sum + 1];

    // Initialize first column as true. 0 sum is possible
    // with all elements.
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    // Fill the partition table in bottom up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // If i'th element is excluded
            dp[i][j] = dp[i - 1][j];

            // If i'th element is included
            if (arr[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
        }
    }

    // Initialize difference of two sums.
    int diff = INT_MAX;

    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j = sum / 2; j >= 0; j--)
    {
        // Find the
        if (dp[n][j] == true)
        {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    int dishes[tc];
    int dish, sum;
    sum = 0;
    for (int t = 0; t < tc; t++)
    {
        cin >> dish;
        dishes[t] = dish;
        sum += dish;
    }
    int diff;
    diff = findMin(dishes, tc);
    int val = (sum + diff) / 2;
    cout << val;
}