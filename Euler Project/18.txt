//Dynamic Programming (BOTTOM-UP approach)

#include<bits//stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef ll ll;
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 7;
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

const int sz = 15;
int arr[sz][sz];

int main() {
    start();
    //auto start = std::chrono::high_resolution_clock::now();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int x;
    for (int i = 1; i <= sz; i++) {
        for (int j = 0; j < i; j++) {
            cin >> x;
            arr[i - 1][j] = x;
        }
    }

    for (int i = sz - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            arr[i][j] += max(arr[i + 1][j], arr[i + 1][j + 1]);
        }
    }

    for (int i = 1; i <= sz; i++) {
        for (int j = 0; j < i; j++) {
            cout << arr[i - 1][j] << " ";
        }
        cout << '\n';
    }

    cout << arr[0][0];

    //Time(start);
    return 0;
}

========================================================================================================================
//Dynamic Programming (TOP-DOWN approach)

#include<bits//stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef ll ll;
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 7;
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

const int sz = 15;
int arr[sz][sz];

int main() {
    start();
    //auto start = std::chrono::high_resolution_clock::now();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int x;
    for (int i = 1; i <= sz; i++) {
        for (int j = 0; j < i; j++) {
            cin >> x;
            arr[i - 1][j] = x;
        }
    }

    for (int i = 1; i < sz; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                arr[i][j] += arr[i - 1][j];
            else if (j == i)
                arr[i][j] += arr[i - 1][j - 1];
            else
                arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);
        }
    }

    for (int i = 1; i <= sz; i++) {
        for (int j = 0; j < i; j++) {
            cout << arr[i - 1][j] << " ";
        }
        cout << '\n';
    }

    int ans = 0;
    for (int i = 0; i < 15; i++)
        ans = max(ans, arr[14][i]);

    cout << '\n' << ans;
    //Time(start);
    return 0;
}