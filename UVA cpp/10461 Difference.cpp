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

ll arr[501];
vector<ll> adj1[501];
vector<ll> adj2[501];
bool vis1[501];
bool vis2[501];

int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    int v, e, t = 1;
    while (cin >> v >> e) {
        if (v == 0 && e == 0)
            break;

        ll sum = 0;
        for (int i = 1; i <= v; i++)
            cin >> arr[i], sum += arr[i];

        while (e--) {
            int x, y;
            cin >> x >> y;
            adj1[x].push_back(y);
            adj2[y].push_back(x);
        }

        int q;
        cin >> q;

        cout << "Case #" << t++ << ":" << endl;

        while (q--) {
            int x;
            cin >> x;

            memset(vis1, false, sizeof(vis1));
            memset(vis2, false, sizeof(vis1));
            
            ll min = -arr[x];
            queue<ll> q1;
            vis1[x] = 1;
            q1.push(x);

            while (!q1.empty()) {
                ll p = q1.front();
                q1.pop();
                min += arr[p];

                for (auto i : adj1[p])
                    if (!vis1[i]) {
                        q1.push(i);
                        vis1[i] = 1;
                    }
            }

            ll max = sum;
            queue<ll> q2;
            q2.push(x);
            vis2[x] = 1;
            
            while (!q2.empty()) {
                ll p = q2.front();
                q2.pop();
                max -= arr[p];

                for (auto i : adj2[p])
                    if (!vis2[i]) {
                        vis2[i] = 1;
                        q2.push(i);
                    }
            }

            cout << max - min << endl;
        }
        cout << endl;
        for (int i = 1; i <= v; i++)
            adj1[i].clear(), adj2[i].clear();
    }

    return 0;
}
