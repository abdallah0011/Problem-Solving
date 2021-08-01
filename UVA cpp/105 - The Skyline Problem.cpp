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

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll g = extended_gcd(b, a % b, y, x);
    y -= (a / b) * x;

    return g;
}

bool isPrime(ll n) {
    if (n < 2) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

ll binPow(ll b, ll p) {
    if (p == 0) return 1;
    ll sq = binPow(b, p / 2);
    sq *= sq;

    if (p & 1)
        sq *= b;

    return sq;
}

void Time(chrono::high_resolution_clock::time_point &start) {
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "Time taken : " << ((long double) duration.count()) / ((long double) 1e9) << "s " << endl;
}


int heights[10005];

int main() {
    start();
    //chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int l, h, r, end = 0;
    for (int i = 0; i < 8; i++) {
        cin >> l >> h >> r;
        if (end < r)
            end = r;

        for (int i = l; i < r; i++) {
            if (heights[i] < h)
                heights[i] = h;
        }
    }

    int mx = heights[1];
    cout << "1 " << mx;

    for (int i = 2; i < end; i++) {
        if (mx != heights[i]) {
            cout << " " << i << " " << heights[i];
            mx = heights[i];
        }
    }
    cout << " " << end << " 0\n";
//Time(start);
    return 0;
}
