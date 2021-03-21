#include <iostream>
#include <vector>
#include<iomanip>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
#include <assert.h> 
#include <stack>
#include <list>
#include <string>
#include <queue>
#include <functional>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n, arr[500001], q;

ll BSF(ll x) {     // FFFTTT Search for the first true
    int s = 0, e = n - 1;

    while (s < e) {
        int md = s + (e - s) / 2;
        if (arr[md] > x)
            e = md;
        else
            s = md + 1;
    }
    if (arr[s] > x)
        return arr[s];
    else
        return -1;
}


ll BSL(ll x) {      // FFFTTT Search for the last false
    int s = 0, e = n - 1;

    while (s < e) {
        int md = s + (e - s + 1) / 2;
        if (arr[md] < x)
            s = md;
        else
            e = md - 1;
    }
    if (arr[s] < x)
        return arr[s];
    else
        return -1;
}


int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        (BSL(x) == -1) ? cout << "X" : cout << BSL(x);
        (BSF(x) == -1) ? cout << " X" << endl : cout << " " << BSF(x) << endl;
    }
    return 0;
}