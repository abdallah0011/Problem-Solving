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

int dx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };
int d[10][10];

bool valid(int r, int c) {
    return r >= 0 && c >= 0 && r < 8 && c < 8;
}
int bfs(int sr , int sc , int tr , int tc){
    memset(d, -1, sizeof(d));
    queue<pair<int,int> >q;
    d[sr][sc] = 0;

    q.push({ sr,sc });
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (r == tr && c == tc)
            return d[r][c];

        for (int i = 0; i < 8; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (valid(nr, nc)) {
                if (d[nr][nc] == -1)
                    d[nr][nc] = d[r][c] + 1;    // add previous cost to the new cost
                q.push({ nr,nc });
            }

            
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    string s1, s2;
    while (cin >> s1 >> s2) {
        int ans = bfs(s1[1] - '1', s1[0] - 'a', s2[1] - '1', s2[0] - 'a');
       cout << "To get from " << s1 << " to " << s2 << " takes " << ans << " knight moves." << endl;
    }
    return 0;
}
