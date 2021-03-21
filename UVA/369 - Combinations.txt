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

ll pow(ll b, ll p) {
    if (p == 0) return 1;
    ll sq = pow(b, p / 2);
    sq *= sq;

    if (p & 1)
        sq *= b;

    return sq;
}

ll ncr(ll n, ll r) {

    ll ans = 1;

    if (n - r < r)  // Since C(n, r) = C(n, n-r) as nCr = 0 wwhen n < r;
        r = n - r;

    // Calculate value of 
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
    for (ll i = 0; i < r; i++) {
        ans *= n - i;
        ans /= i + 1;
    }

    return ans;
}

int dx[] = { 0 ,0 ,-1 ,1 ,-1 ,1 ,-1 ,1 };
int dy[] = { 1 ,-1 ,0 ,0 ,1 ,1 ,-1 ,-1 };


int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0) {
        cout << n << " things taken " << m << " at a time is " << ncr(n, m) << " exactly." << endl;
    }
    return 0;
}