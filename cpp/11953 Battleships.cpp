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
int n;
char arr[101][101];
bool visited[101][101];

int dx[] = { 0 ,0 ,-1 ,1 };
int dy[] = { 1 ,-1 ,0 ,0 };

bool valid(int x , int y) {
    return x >= 0 && y >= 0 && y < n && x < n;
}

void dfs(int x, int y) {
    if (arr[x][y] == '.' || visited[x][y])
        return;

    visited[x][y] = true;
    
    for (int i = 0; i < 4; i++) {
        int xx = dx[i] + x;
        int yy = dy[i] + y;
        
        if (valid(xx, yy) && !visited[xx][yy])
            dfs(xx, yy);
    }
}
int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    int t, tcase = 1;
    cin >> t;
    while (t--) {
        memset(visited, 0, sizeof(visited));
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && arr[i][j] == 'x') {
                    ans++;
                    dfs(i, j);
                }
            }
        cout << "Case " << tcase++ << ": " << ans << endl;
    }

    return 0;
}