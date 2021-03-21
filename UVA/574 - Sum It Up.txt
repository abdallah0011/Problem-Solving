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
const int MAX = 1e5 + 7;


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

int n, required, sum;
bool print;

int freq[MAX];
vector<int> ans;

void solve(int v) {

    if (v == 0) {
        if (sum == required) {
            print = 1;

            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << "+\n"[i + 1 == ans.size()];
        }
        return;
    }

    if (sum + v <= required && freq[v] > 0) {
        sum += v;
        freq[v]--;
        ans.push_back(v);

        solve(v);   // we check if we can take more of the value if we have more frequencies left

        sum -= v;   // undo
        freq[v]++;
        ans.pop_back();
    }

    solve(v - 1);   // we move to the next value as we have no frequency left or the sum is bigger
}

int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    while (cin >> required >> n ,n) {
       
        memset(freq, 0, sizeof freq);
        print = 0;
        ans.clear();

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ++freq[x];
        }

        cout << "Sums of " << required << ":\n";
        solve(1000);

        if (!print)
            cout << "NONE\n";
    }


    return 0;
}