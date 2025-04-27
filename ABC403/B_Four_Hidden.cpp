#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

bool make_substring(const std::string &T, const std::string &U)
{
    int T_len = T.length();
    int U_len = U.length();

    if (U_len > T_len)
    {
        return false;
    }

    for (int start = 0; start <= T_len - U_len; start++)
    {
        bool possible = true;
        int question_marks_needed = 0;

        for (int i = 0; i < U_len; i++)
        {
            if (T[start + i] != '?' && T[start + i] != U[i])
            {
                possible = false;
                break;
            }
            if (T[start + i] == '?')
            {
                question_marks_needed++;
            }
        }

        if (possible)
        {
            int remaining_question_marks = 4 - question_marks_needed;

            if (question_marks_needed > 4)
            {
                continue;
            }

            int available_outside = 0;
            for (int i = 0; i < start; i++)
            {
                if (T[i] == '?')
                {
                    available_outside++;
                }
            }
            for (int i = start + U_len; i < T_len; i++)
            {
                if (T[i] == '?')
                {
                    available_outside++;
                }
            }

            if (available_outside >= remaining_question_marks)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    std::string T, U;
    std::cin >> T >> U;

    if (make_substring(T, U))
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}