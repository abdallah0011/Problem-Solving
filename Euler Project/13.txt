#include<bits//stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef ll ll;
const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 7;
const int mxN = 1e6 + 7;
const int eps = -1e9;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}


void Time(chrono::high_resolution_clock::time_point &start) {
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "Time taken : " << ((long double) duration.count()) / ((long double) 1e9) << "s " << endl;
}


int main() {
    start();
    //chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s1, s2;
    cin >> s1;
    s2 = s1;
    for (int i = 0; i < 99; i++) {
        cin >> s1;
        int carry = 0, n1 = s1.size(), n2 = s2.size(), diff = n2 - n1;
        string tmp;
        for (int j = n1 - 1; j >= 0; j--) {
            int sum = (s1[j] - '0') + (s2[j + diff] - '0') + carry;
            tmp.push_back(sum % 10 + '0'), carry = sum / 10;
        }
        for (int k = n2 - n1 - 1; k >= 0; k--) {
            int sum = s2[k] - '0' + carry;
            tmp.push_back(sum % 10 + '0'), carry = sum / 10;
        }
        if (carry)
            tmp.push_back(carry + '0');
        reverse(tmp.begin(), tmp.end());
        s2 = tmp;
    }

    for (int i = 0; i < 10; i++)
        cout << s2[i];
    //Time(start);
    return 0;
}
