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

bool prime[20000005];
int ans[20000005];

void pre() {
    for (int i = 4; i <= 20000000; i += 2)
        prime[i] = 0;

    for (int i = 3; i * i <= 20000000; i += 2) {
        if (prime[i]) {
            for (int j = i * i; j <= 20000000; j += i)
                prime[j] = 0;
        }
    }
}

void solve() {
    int j = 1;
    for (int i = 3; i <= 20000000; i++) {
        if (prime[i] && prime[i + 2])
            ans[j++] = i;
    }
}

int main() {
    start();
    //chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(prime, 1, sizeof prime);
    pre();
    solve();
    int n;
    while (cin >> n) {
        cout << "(" << ans[n] << ", " << ans[n] + 2 << ")" << '\n'; 
    }

    //Time(start);
    return 0;
}
