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

const int sz = 1e6;
int arr[sz];

int main() {
    start();
    //auto start = std::chrono::high_resolution_clock::now();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    arr[1] = 1;
    ll num = 0, mx = 0;
    for (ll i = 2; i < sz; i++) {
        ll cnt = 0, j = i;
        while (j != 1 && j >= i) {
            if (j & 1) j = j * 3 + 1;
            else j /= 2;
            cnt++;
        }
        arr[i] = cnt + arr[j];
        if (arr[i] > mx)
            mx = arr[i], num = i;
    }

    cout << num;
    //Time(start);
    return 0;
}