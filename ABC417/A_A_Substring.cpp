#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N, A, B;
    string S;
    cin >> N >> A >> B;
    cin >> S;

    string result = S.substr(A, N - A - B);

    cout << result << endl;

    return 0;
}