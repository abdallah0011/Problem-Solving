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
    //auto start = std::chrono::high_resolution_clock::now();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string units[11] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    string ele[11] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                      "eighteen", "nineteen"};
    string tens[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    int ans = 0;
    for (int i = 1; i < 1000; i++) {
        string s = to_string(i);
        if (i <= 10) {  // 1 - 10;
            ans += (int) units[i].length();
        } else if (i > 10 && i < 20) {  // 11 - 19;
            ans += (int) ele[s[1] - '0'].length();
        } else if (i >= 20 && i < 100) {    // 20 - 100;
            ans += (int) tens[s[0] - '0'].length();
            if (s[1] - '0' != 0)
                ans += (int) units[s[1] - '0'].length();
        } else {    // 100 - 999
            ans += (int) units[s[0] - '0'].length() + 7; // 7 ==> hundred;
            if (s[1] - '0' > 1 && s[2] - '0' != 0) { // ex: 125;
                ans += 3; // 3 ==> and;
                ans += (int) tens[s[1] - '0'].length();
                ans += (int) units[s[2] - '0'].length();
            } else if (s[1] - '0' == 1 && s[2] - '0' >= 1) {    // ex: 115;
                ans += 3; // 3 ==> and;
                ans += (int) ele[s[2] - '0'].length();
            } else if (s[1] - '0' == 0 && s[2] - '0' != 0) {    // ex: 105;
                ans += 3; // 3 ==> and;
                ans += (int) units[s[2] - '0'].length();
            } else if (s[1] - '0' > 1 && s[2] - '0' == 0) {    // ex: 120;
                ans += 3; // 3 ==> and;
                ans += (int) tens[s[1] - '0'].length();
            } else if (s[1] - '0' == 1 && s[2] - '0' == 0) {    // ex: 110;
                ans += 3; // 3 ==> and;
                ans += (int) units[10].length();
            }
        }
    }

    cout << ans + 11; // 11 ==> one thousand
    //Time(start);
    return 0;
}