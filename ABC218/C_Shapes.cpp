
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
vector<pair<int, int>> get_shape(vector<vector<char>> SS, int N)
{
    vector<pair<int, int>> SS_shape;
    int x, y;
    bool first = true;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (SS[i][j] == '#')
            {
                if (first)
                {
                    x = i;
                    y = j;
                    first = false;
                }
                else
                {
                    SS_shape.push_back(make_pair(i - x, j - y));
                }
            }

    return SS_shape;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<vector<char>> S(N, vector<char>(N)), T(N, vector<char>(N)), T_left(N, vector<char>(N)), T_right(N, vector<char>(N)), T_down(N, vector<char>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> S[i][j];
        }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {

            cin >> T[i][j];
            T_left[j][N - 1 - i] = T[i][j];
            T_right[N - 1 - j][i] = T[i][j];
            T_down[N - 1 - i][N - 1 - j] = T[i][j];
        }
    vector<pair<int, int>> S_shape = get_shape(S, N);
    vector<pair<int, int>> T_shape = get_shape(T, N);
    if (S_shape.size() != T_shape.size())
    {
        cout << "No";
        exit(0);
    }

    if (S_shape == T_shape)
    {
        cout << "Yes";
        exit(0);
    }

    vector<pair<int, int>> T_left_shape = get_shape(T_left, N);
    if (S_shape == T_left_shape)
    {
        cout << "Yes";
        exit(0);
    }

    vector<pair<int, int>> T_right_shape = get_shape(T_right, N);
    if (S_shape == T_right_shape)
    {
        cout << "Yes";
        exit(0);
    }

    vector<pair<int, int>> T_down_shape = get_shape(T_down, N);
    if (S_shape == T_down_shape)
    {
        cout << "Yes";
        exit(0);
    }
    cout << "No";
}