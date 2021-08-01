#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

/* light bulb has 2 states ON =1 or OFF = 0
so if we turn off and on a bulb 3 times we have  ==>  1 0 1  then the final state is ON
if we tried 4 times we get ==> 1 0 1 0 then the final state is  OFF

In this problem we search for how many factors for the given number
if the number is odd we print YES if it's not we print NO

EX: 8 we have 4 factors ==> (1 * 8) , (2 , 4)
EX: 5 we have 2 factors ==> (1 * 5)

So we always get Even number of factors unless the given number has a Square_Root 
EX: 9 we have 3  factors ==> (1 * 9) , (3 , 3)

so the final problem is about finding out if the given number has a Square_Root Or Not 
*/

int main()
{
	ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
	
	ll n;
	while (cin >> n, n != 0) {
		ll sq = (ll)sqrt(n);

		cout << (sq * sq == n ? "yes\n" : "no\n");
	}

	return 0;
}