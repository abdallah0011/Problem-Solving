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

long double p, r, q, s, t, u;

double calc(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}
double BS() {
    long double s = 0.0, e = 1.0, md=0.0;
    while (fabs(s - e) > 1e-7) {
        md = (s + e) / 2.0;
        if (calc(md) * calc(s) <= 0)
            e = md;
        else
            s = md;
    }
    return md;
}
int main()
{
    ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
    while (cin >> p >> q >> r >> s >> t >> u) {
        if (calc(0) * calc(1) > 0)
            cout << "No solution" << endl;
        else
            cout << fixed << setprecision(4) << BS() << endl;
    }
    return 0;
}