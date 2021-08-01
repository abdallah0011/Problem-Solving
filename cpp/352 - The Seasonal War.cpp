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

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
int MAX = -1e16;
int MIN = 1e16;

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
char arr[26][26];
bool visited[26][26];
int n;

int dx[] = { 0 ,0 ,-1 ,1 ,-1 ,1 ,-1 ,1 };   // 8 dimensions that we check 
int dy[] = { 1 ,-1 ,0 ,0 ,1 ,1 ,-1 ,-1 };  

bool valid(int x, int y) {      // ensure that the position we do dfs on is valid 
    return x >= 0 && y < n && x < n && y >= 0;
}

void dfs(int x , int y) {
    if (visited[x][y])
        return;

    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {   // looping on the 8 adjacent dimensions
        int xx = dx[i] + x;
        int yy = dy[i] + y;

        if (!visited[xx][yy] && valid(xx, yy) && arr[xx][yy] == '1')
            dfs(xx, yy);
    }
}
int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    int tcase = 1;
    while (cin >> n) {
        for (int i = 0; i < n; i++)     // we read strings
            cin >> arr[i];
        
        memset(visited, 0, sizeof(visited));

        int ans = 0;
        for (int i = 0; i < n; i++)     // loop on the strings to dfs on each unvisited '1' and find its connectors
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && arr[i][j] == '1')     // we ensure that the '1' is not visited in the previous dfs
                    dfs(i, j), ans++;
            }
        cout << "Image number " << tcase++ << " contains " << ans << " war eagles." << endl;
    }

    return 0;
}