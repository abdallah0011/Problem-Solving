#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
	int n, m, c;

	while (cin >> n >> m >> c && !n) {
		cout << ((n - 7) * (m - 7) + c) / 2 << endl;
	}
	return 0;
}