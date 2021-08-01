#include<bits/stdc++.h>

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

ll power(ll b, ll e) {
    if (e == 0) return 1;
    ll sq = power(b, e / 2);
    sq *= sq;

    if (e & 1)
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

int x, y, x1, x2, ans;

int solve(int i) {
    if (i == 1) {
        return ans++;
    }

    if (i & 1) {
        ans++;
        return solve(3 * i + 1);
    }
    else {
        ans++;
        return solve(i / 2);
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    int n;
    cin >> n;
    cout << solve(n);

    return 0;
}