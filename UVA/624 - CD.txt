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
const int INF = 0x3f3f3f3f;
const int MAX = 1e5+10;

int m, n;
vector<int> v, taken, ans;
ll mx = 0;

void solve(int idx , int sum) {
    if (idx == n) {
        if (sum > mx) {
            mx = sum;
            ans = taken;
        }
        return;
    }

    if (sum + v[idx] <= m) {
        sum += v[idx];
        taken.push_back(v[idx]);
        solve(idx + 1, sum);
        sum -= v[idx];
        taken.pop_back();
    }
    solve(idx + 1, sum);
}

int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    while (cin >> m >> n) {
        v.resize(n);
        for (auto &i : v)
            cin >> i;
        
        mx = 0;
        solve(0, 0);

        for (auto i : ans)
            cout << i << " ";
        cout << "sum:" << mx << endl;
    }
    return 0;
}

============================================================================================================================================================

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
const int INF = 0x3f3f3f3f;
const int MAX = 1e5+10;


int m, n;
vector<int> v, taken, ans;
ll mx = 0;

void solve(int idx , int sum) {
    if (idx == n) {
        if (sum > mx&& sum <= m) {
            mx = sum;
            ans = taken;
        }
        return;
    }
    taken.push_back(v[idx]);
    solve(idx + 1, sum + v[idx]);
    taken.pop_back();
    solve(idx + 1, sum);
}

int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    while (cin >> m >> n) {
        v.resize(n);
        for (auto &i : v)
            cin >> i;
        
        mx = 0;
        solve(0, 0);

        for (auto i : ans)
            cout << i << " ";
        cout << "sum:" << mx << endl;
    }
    return 0;
}