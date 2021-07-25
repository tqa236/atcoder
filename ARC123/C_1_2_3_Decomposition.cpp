
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int countDigit(ll n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

ll make_number(int digit, int length)
{
    ll result = 0;
    for (int i = 0; i < length; i++)
    {
        result = result * 10 + 1;
    }
    result = result * digit;
    return result;
}

vector<int> get_digits(ll n)
{
    vector<int> result;
    int digit;
    while (n > 0)
    {
        digit = n % 10;
        result.push_back(digit);
        n /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

void solve()
{
    ll n;
    cin >> n;
    int count = 0;
    ll tmp;
    bool flag;
    // int counter = 0;
    int length, tmp_length;
    int last;
    vector<int> digits;
    vector<int> tmp_num;
    while (n > 0)
    {

        length = countDigit(n);
        digits = get_digits(n);
        tmp = make_number(1, length);
        // cout << n << " " << length << " " << tmp << endl;
        // for (auto i = digits.begin(); i != digits.end(); ++i)
        //     std::cout << *i << ' ';
        // cout << endl;

        if (n < tmp)
        {
            tmp = make_number(3, length - 1);
        }
        else
        {
            tmp = 0;
            tmp_num.clear();
            flag = false;
            for (auto i = 0; i < digits.size(); i++)
            {
                if ((digits[i] > 3) || flag)
                {
                    tmp_num.push_back(3);
                    flag = true;
                }
                else
                {
                    if (digits[i] > 0)
                    {
                        tmp_num.push_back(min(digits[i], 3));
                    }
                    if (digits[i] > 1)
                    {
                        last = i;
                    }
                    if (digits[i] == 0)
                    {
                        tmp_num[last] -= 1;
                        for (int j = last + 1; j < tmp_num.size(); j++)
                        {
                            tmp_num[j] = 3;
                        }
                        tmp_length = tmp_num.size();
                        for (auto j = tmp_length; j < digits.size(); j++)
                        {
                            tmp_num.push_back(3);
                        }
                        break;
                    }
                }
            }

            // for (auto i = tmp_num.begin(); i != tmp_num.end(); ++i)
            //     std::cout << *i << ' ';
            // cout << endl;

            for (int j = 0; j < tmp_num.size(); j++)
            {
                tmp = tmp * 10 + tmp_num[j];
            }
        }
        n -= tmp;
        count += 1;
        // cout << n << " " << tmp << endl;

        // counter += 1;
        // if (counter > 10)
        //     break;
    }
    cout << count << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}