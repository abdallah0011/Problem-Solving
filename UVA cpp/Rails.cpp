#include <iostream>
#include <vector>
#include<iomanip>
#include <stdio.h>
#include <string.h>
#include <math.h>
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

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

bool prime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

ll pow(ll b, ll p) {
    if (p == 0) return 1;
    ll sq = pow(b, p / 2);
    sq *= sq;

    if (p & 1)
        sq *= b;

    return sq;
}

int n, c;
stack<int> s;

void solve() {
    while (true) {
        while (!s.empty())
            s.pop();

        int j = 0;
        for (int i = 0; i < n; i++) {
            cin >> c;
            if (c == 0)
                return;

            while (j < n && j != c) {
                if (!s.empty() && s.top() == c)
                    break;
                j++;
                s.push(j);
            }
            if (c == s.top())
                s.pop();
        }
        if (s.empty())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    while (cin >> n && n != 0) {
        solve();
        cout << endl;
    }
    return 0;
}