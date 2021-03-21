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
char arr[10][10];
bool visited[10][10];
vector<string> ans;
int n, m;

int dx[] = { 0 ,0 ,-1 };
int dy[] = { 1 ,-1 ,0 };

void print() {
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << ans[i];
            cout << endl;
        }
        else
            cout << ans[i] << " ";
    }
    return;
}

bool valid1(int x, int y) {
    return x >= 0 && y >= 0 && x < m && y < n;
}

bool valid2(int x, int y) {
    return arr[x][y] == 'I' || arr[x][y] == 'E' || arr[x][y] == 'O' ||
        arr[x][y] == 'V' || arr[x][y] == 'A' || arr[x][y] == '#' || arr[x][y] == 'H';
}

void dfs(int x, int y) {
    if (arr[x][y] == '#') {
        print();
        return;
    }

    visited[x][y] = true;
    for (int i = 0; i < 3; i++) {
        int xx = dx[i] + x;
        int yy = dy[i] + y;

        if (valid1(xx, yy) && valid2(xx, yy) && !visited[xx][yy]) {
            if (dx[i] == 0 && dy[i] == 1)
                ans.push_back("right");
            if (dx[i] == 0 && dy[i] == -1)
                ans.push_back("left");
            if (dx[i] == -1 && dy[i] == 0)
                ans.push_back("forth");

            dfs(xx, yy);
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n;

        int startx = 0, starty = 0;
        memset(visited, 0, sizeof(visited));
        ans.clear();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == '@')
                    startx = i, starty = j;
            }
        dfs(startx, starty);
    }
    return 0;
}