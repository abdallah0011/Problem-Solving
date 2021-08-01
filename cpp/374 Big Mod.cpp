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
const int MAX = 1e5+7;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

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
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

ll power(ll b, ll p) {
    if (p == 0) return 1;
    ll sq = power(b, p / 2);
    sq *= sq;

    if (p & 1)
        sq *= b;

    return sq;
}

int good, bad;
int maxVal, val, Month[MAX];

void solve(int m) {

    if (m >= 5) {   // check last five months
        int lastM = 0;
        for (int i = m - 5; i < m; i++)
            lastM += Month[i];

        if (lastM >= 0)
            return;
    }

    if (m == 12) {  // base case
        maxVal = max(maxVal, val);
        return;
    }

    val += good;    // take surplus
    Month[m] = good;
    solve(m + 1);
    Month[m] = 0;   // undo
    val -= good;    // undo

    
    val -= bad;     // take deficit
    Month[m] -= bad;
    solve(m + 1);
    Month[m] = 0;   // undo 
    val += bad;     // undo 

}


int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    while (cin >> good >> bad) {
        
        maxVal = -1e9;
        memset(Month, 0, sizeof Month);

        solve(0);

        if (maxVal < 0)
            cout << "Deficit" << endl;
        else
            cout << maxVal << endl;
    }
    return 0;
}