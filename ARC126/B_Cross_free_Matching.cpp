
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

bool SortAscending(const std::pair<int, int> &p1, const std::pair<int, int> &p2)
{
    return std::tie(p1.first, p1.second) < std::tie(p2.first, p2.second);
}

bool CompareAscending(const std::pair<int, int> &p1, const std::pair<int, int> &p2)
{
    return p1.second < p2.second;
    return p1.first < p2.first and p1.second < p2.second;
}

// //Approach 2: Time Complexity = O(n * log(n))
// int lengthOfLIS(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> v;
//     int max_1 = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         if (i == 0)
//             v.push_back(nums[i]);
//         else
//         {
//             auto x = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
//             if (x >= v.size())
//                 v.push_back(nums[i]);
//             else
//                 v[x] = nums[i];
//         }
//     }
//     return v.size();
// }

//Approach 2: Time Complexity = O(n * log(n))
int lengthOfLISPair(vector<pair<int, int>> &nums)
{
    int n = nums.size();
    vector<pair<int, int>> v;
    int max_1 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            v.push_back(nums[i]);
        else
        {
            auto x = lower_bound(v.begin(), v.end(), nums[i], SortAscending) - v.begin();
            if (x >= v.size())
                v.push_back(nums[i]);
            else
                v[x] = nums[i];
        }
    }
    std::cout << "\n\nAscending: \n";
    for (auto &p : v)
        std::cout << p.first << " " << p.second << "\n";
    return v.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    int a, b;
    cin >> n >> m;
    vector<pair<int, int>> segments;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        segments.push_back(make_pair(a, b));
    }

    std::sort(segments.begin(), segments.end(), SortAscending);
    // std::cout << "\n\nAscending: \n";
    // for (auto &p : segments)
    //     std::cout << p.first << " " << p.second << "\n";
    // vector<int> segments;
    // for (int i = 0; i < n; i++)
    // {
    //     segments.push_back(n);
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a >> b;
    //     segments[a - 1] = min(b - 1, segments[a - 1]);
    // }
    // vector<int> clean_segments;
    // for (auto &p : clean_segments)
    //     std::cout << p << "\n";
    // for (int i = 0; i < n; i++)
    // {
    //     if (segments[i] < n)
    //         clean_segments.push_back(segments[i]);
    // }
    // int K = lengthOfLIS(clean_segments);

    int K = lengthOfLISPair(segments);
    cout << K;
}