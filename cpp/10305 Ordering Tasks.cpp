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
#include<queue>
#include <list>
#include <string>
#include <functional>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

vector<int> adj[1005];
vector<int> ans;
int vis[1005];

void dfs(int x) {
    if (vis[x])
        return;

    vis[x] = 1;
    for (int i = 0; i < adj[x].size(); i++)
        if (!vis[adj[x][i]])
            dfs(adj[x][i]);

    ans.push_back(x);
}

int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    int n, m, x, y;
    while (cin >> n >> m && n != 0) {
        memset(adj, 0, sizeof(adj));
        memset(vis, 0, sizeof(vis));
        ans.clear();

        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
        }

        for (int i = 1; i <= n; i++)
            if (!vis[i])
                dfs(i);

        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " \n"[i == ans.size() - 1];
    }

    return 0;
}
