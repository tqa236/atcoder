#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

using ll = long long;

struct Present
{
    int P, A, B;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Present> presents(N);
    int maxP = 0;

    for (int i = 0; i < N; ++i)
    {
        cin >> presents[i].P >> presents[i].A >> presents[i].B;
        maxP = max(maxP, presents[i].P);
    }

    const int MAX_PRECOMPUTE = 1e7;
    vector<ll> precomputed(MAX_PRECOMPUTE + 1);

    for (int mood0 = 0; mood0 <= MAX_PRECOMPUTE; ++mood0)
    {
        ll mood = mood0;
        for (const auto &p : presents)
        {
            if (p.P >= mood)
            {
                mood += p.A;
            }
            else
            {
                mood = max(0LL, mood - p.B);
            }
        }
        precomputed[mood0] = mood;
    }

    unordered_map<ll, ll> cache_large;

    int Q;
    cin >> Q;
    while (Q--)
    {
        ll mood;
        cin >> mood;

        if (mood <= MAX_PRECOMPUTE)
        {
            cout << precomputed[mood] << '\n';
        }
        else if (cache_large.count(mood))
        {
            cout << cache_large[mood] << '\n';
        }
        else
        {
            ll start_mood = mood;
            for (const auto &p : presents)
            {
                if (p.P >= mood)
                {
                    mood += p.A;
                }
                else
                {
                    mood = max(0LL, mood - p.B);
                }
            }
            cache_large[start_mood] = mood;
            cout << mood << '\n';
        }
    }

    return 0;
}
