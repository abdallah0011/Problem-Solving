//Binomical Coffecients

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



ll arr[21][21];

ll solve(ll x, ll y) {
    if (x == 0 || y == 0) return 1;
    if (arr[x][y] != -1) return arr[x][y];

    arr[x][y] = solve(x - 1, y) + solve(x, y - 1);
    return arr[x][y];
}

int main() {
    start();
    //auto start = std::chrono::high_resolution_clock::now();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    memset(arr, -1, sizeof arr);
    cout << solve(20, 20);
    
    //Time(start);
    return 0;
}

========================================================================================================================================================================================================================================================================
//Dynamic Programming

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

const int sz = 21;
ll grid[sz][sz];

int main() {
    start();
    //auto start = std::chrono::high_resolution_clock::now();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < sz; i++) {
        grid[0][i] = 1;
        grid[i][0] = 1;
    }

    for (int i = 1; i < sz; i++) {
        for (int j = 1; j < sz; j++) {
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
        }
    }
    cout << grid[20][20];
    
    //Time(start);
    return 0;
}