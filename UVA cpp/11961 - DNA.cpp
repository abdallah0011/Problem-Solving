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
const int MAX = 1e5+7;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

string s, pattern = "ACGT";
int n, k, changes;
vector<string> ans;


void solve(int idx) {

    if (idx == n) {
        ans.push_back(s);
        return;
    }

    char backup = s[idx];

    for (int i = 0; i < 4; i++) {
        if (pattern[i] != backup)
            changes++;

        s[idx] = pattern[i];

        if (changes <= k) solve(idx + 1);

        if (pattern[i] != backup)
            changes--;
    }
    
    s[idx] = backup;    // undo 
}
int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ans.clear();
        
        cin >> n >> k >> s;
        solve(0);

        cout << ans.size() << endl;
        for (auto& i : ans)
            cout << i << endl;

    }

    return 0;
}