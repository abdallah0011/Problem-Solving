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
#include <climits>
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

int arr[5];
bool ret = false;
bool solve(int idx, int cur) {

    if (idx == 5)
        return cur == 23;

    bool ret = false;
    ret |= solve(idx + 1, cur + arr[idx]);	// we do bitwise or to save the solution anytime we find it
    ret |= solve(idx + 1, cur - arr[idx]);
    ret |= solve(idx + 1, cur * arr[idx]);

    return ret;
}


int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    while (true) 
    {
        for (int i = 0, sum = 0; i < 5; i++) {
            cin >> arr[i];
            sum += arr[i];

            if (sum == 0 && i == 4)
                return 0;
        }

        sort(arr, arr + 5);
        bool can = false;

        do {
            can = solve(1, arr[0]);
            if (can)
                break;
        } while (next_permutation(arr, arr + 5));

        if (can)
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }

    return 0;
}

========================================================================================================================================

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
#include <climits>
#include <stack>
#include <list>
#include <string>
#include <functional>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int dx[] = { 0 ,0 ,-1 ,1 ,-1 ,1 ,-1 ,1 };
int dy[] = { 1 ,-1 ,0 ,0 ,1 ,1 ,-1 ,-1 };

int arr[5];
bool ret = false;
bool solve(int idx, int cur) {
    if (ret)
        return true;

    if (idx == 5)
        return cur == 23;

    bool ret = false;
    ret = solve(idx + 1, cur + arr[idx]);
    if (ret)	//if we catch a solution we return true and stop backtracking
        return true;
    ret = solve(idx + 1, cur - arr[idx]);
    if (ret)
        return true;
    ret = solve(idx + 1, cur * arr[idx]);
    if (ret)
        return true;
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    while (true) 
    {
        for (int i = 0, sum = 0; i < 5; i++) {
            cin >> arr[i];
            sum += arr[i];

            if (sum == 0 && i == 4)
                return 0;
        }

        sort(arr, arr + 5);
        bool can = false;

        do {
            can = solve(1, arr[0]);
            if (can)
                break;
        } while (next_permutation(arr, arr + 5));

        if (can)
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }

    return 0;
}