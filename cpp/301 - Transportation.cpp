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

// at the first the train will take 1 passenger from 0 station then take 7 passengers;
// from station 1 then free 8 places on station 2 then he will be able to take 10 passengers;
// from the station 2 to station 3 so the solution is;
// (0 2 1) ==> (1 2 7) ===> (2 3 10);
// ((2-0)*1) + ((2-1)*7) + ((3-2)*10) = 19;

int freePlaces, final, n, maxProfit, profit, pos;
int depart[MAX];

struct order {
    int st, en, cap;
}arr[MAX];


void solve(int idx) {
    if (idx == n) {
        maxProfit = max(maxProfit, profit);
        return;
    }

    int oldpos = pos;
    int oldcap = freePlaces;

    for (int j = pos + 1; j <= arr[idx].st; j++)
        freePlaces += depart[j];

    pos = arr[idx].st;


    if (freePlaces >= arr[idx].cap) {   // take value

        freePlaces -= arr[idx].cap;
        profit += (arr[idx].en - arr[idx].st) * arr[idx].cap;
        depart[arr[idx].en] += arr[idx].cap;    // we increment free places when passengers leave at the end destination

        solve(idx + 1);

        freePlaces += arr[idx].cap;
        profit -= (arr[idx].en - arr[idx].st) * arr[idx].cap;
        depart[arr[idx].en] -= arr[idx].cap;

    }

    solve(idx + 1); // leave value

    pos = oldpos;	// return to the old position after backtracking	
    freePlaces = oldcap;	// return the old capacity after backtracking
}

int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    while (cin >> freePlaces >> final >> n , n || final || freePlaces) {
        memset(depart, 0, sizeof depart);

        for (int i = 0; i < n; i++)
            cin >> arr[i].st >> arr[i].en >> arr[i].cap;

        sort(arr, arr + n, [](order a, order b) {return a.st < b.st; });
        maxProfit = pos = 0;
        solve(0);
        
        cout << maxProfit << endl;
    }
        
    return 0;
}