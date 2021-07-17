
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e9 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int flipgame(vector<int> &f, vector<int> &b)
{
    unordered_set<int> same;
    same.insert(MOD);
    for (int i = 0; i < f.size(); ++i)
        if (f[i] == b[i])
            same.insert(f[i]);
    int res = MAX_N;
    bool flag;
    for (int &i : f)
    {
        flag = true;
        for (auto val : same)
        {
            if (__gcd(val, i) > 1)
                flag = false;
            break;
        }
        if (flag)
        {

            res = min(res, i);
        }

        cout << res << endl;
    }

    for (int &i : b)
    {
        flag = true;
        for (auto val : same)
        {
            if (__gcd(val, i) > 1)
                flag = false;
            break;
        }
        if (flag)
        {
            res = min(res, i);
        }
        cout << res << endl;
    }
    cout << res << endl;
    return res % MAX_N;
}

vector<int> SieveOfEratosthenes(int n)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    vector<int> result;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            result.push_back(p);
    return result;
}

set<int> find_factors(int a, vector<int> &primes)
{
    set<int> factors;
    for (auto prime : primes)
    {
        while (a % prime == 0)
        {
            factors.insert(prime);
            a /= prime;
        }
        if (a < prime)
            break;
    }
    if (a > 1)
    {
        factors.insert(a);
    }
    return factors;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    set<int> factors1;
    set<int> factors2;
    vector<int> primes = SieveOfEratosthenes(2000);
    set<int> curr1;
    set<int> curr2;
    cin >> n;
    int a, b;
    vector<int> front;
    vector<int> back;
    for (int t = 1; t <= n; t++)
    {
        cin >> a >> b;
        front.push_back(a);
        back.push_back(b);
    }
    int result = flipgame(front, back);
    if (result > 0)
    {
        cout << "Yes";
    }
    else
        cout << "No";
}