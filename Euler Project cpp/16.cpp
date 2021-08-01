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


int main() {
    start();
    auto start = std::chrono::high_resolution_clock::now();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    double num = pow(2, 1000);
    string s = to_string(num);
    cout << s << '\n';

    int sum = 0;
    for (auto &i: s) {
	if (isdigit(s[i])) {
            sum += s[i] - '0';
        }
    }

    cout << sum;
    //Time(start);
    return 0;
}



====================================================================================================================================
//Using array to calculate the whole number

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

const int exponenet = 1000, dig = 500;
int arr[dig];

int main() {
    start();
    //auto start = std::chrono::high_resolution_clock::now();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(arr, 0, sizeof arr);
    arr[0] = 1;
    for (int i = 0; i < exponenet; i++) {
        int carry = 0;
        for (int j = 0; j < dig; j++) {
            int tmp = arr[j] * 2 + carry;
            if (tmp > 9)
                arr[j] = tmp % 10, carry = tmp / 10;
            else
                carry = 0, arr[j] = tmp;
        }
    }

    int sum = 0;
    for (auto &i:arr) {
        //cout << i; ==> print the whole array
        sum += i;
    }

    int i = dig - 1;
    while (arr[i] == 0)
        i--;

    cout << "Number of digits: " << i + 1 << '\n';
    for (; i >= 0; i--)
        cout << arr[i];

    cout << '\n' << sum;
    //Time(start);
    return 0;
}

====================================================================================================================================

#include<iostream> 
 
using namespace std; 
 
int main() 
{ 
	int ar[500]; 
	int sum =0; 
	ar[0]=1; 
	for(int j=1;j<500;j++) 
		ar[j]=0; 
	for(int i=1;i<1001;i++) 
	{ 
		ar[0]=2*ar[0]; 
		for(int k=1;k<500;k++) 
			ar[k]=2*ar[k] + ar[k-1]/10; 
		for(int j=0;j<500;j++) 
                        ar[j]=ar[j]%10; 
	} 
	for(int i=0;i<500;i++) 
	sum = sum + ar[i]; 
	cout<<sum; 
} 