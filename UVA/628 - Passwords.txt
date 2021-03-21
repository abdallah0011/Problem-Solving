#include <iostream>
#include <vector>
#include<iomanip>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <numeric>
#include <set>
#include <map>
#include <assert.h> 
#include <stack>
#include <list>
#include <string>
#include <functional>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int MAX = 1e5+10;


vector<string> dic;
string pattern, s;

void solve(int idx) {
    if (idx == pattern.size()) {
        cout << s << endl;
        return;
    }
    if (pattern[idx] == '#') {
        for (string i : dic) {
            s += i;     // faster than s + i;
            solve(idx + 1);
            s.resize(s.size() - i.size());  // backtrack ==> delete the last word;
        }
    }
    else {
        for (char c = '0'; c <= '9'; c++) {
            s += c;     // faster than s + c;
            solve(idx + 1);
            s.pop_back();   // backtrack ==> delete the last char;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    int n;
    while (cin >> n) {
        dic.resize(n);
        for (int i = 0; i < n; i++)
            cin >> dic[i];

        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> pattern;
            cout << "--" << endl;
            solve(0);
        }

    }
    return 0;
}

====================================================================================================================================================================================

#include <iostream>
#include <vector>
#include<iomanip>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <numeric>
#include <set>
#include <map>
#include <assert.h> 
#include <stack>
#include <list>
#include <string>
#include <functional>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int MAX = 1e5+10;


vector<string> dic;
string pattern;

void solve(int idx, string s) {
    if (idx == pattern.size()) {
        cout << s << endl;
        return;
    }
    if (pattern[idx] == '#') {
        for (string i : dic)
            solve(idx + 1, s + i);
    }
    else {
        for (char c = '0'; c <= '9'; c++)
            solve(idx + 1, s + c);
    }

}

int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    int n;
    while (cin >> n) {
        dic.resize(n);
        for (int i = 0; i < n; i++)
            cin >> dic[i];

        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> pattern;
            cout << "--" << endl;
            solve(0, "");
        }

    }
    return 0;
}
