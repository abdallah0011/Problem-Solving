#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long long ll;


/*
gdc Greatest Common Devisor
أكبر رقم بيتقسم عليه الرقمين بكام لو هما ال2 بيتقسمو على 5 هيبقى باد على 7 على 2 على 3 
هكذا فهو بيشوف لو مبيتقسموش على حاجةمنهم يعني هو الواحد يبقى خلاص جود*/

int gcd(int a, int b) {
	int R;
	while ((a % b > 0)) {
		R = a % b;
		a = b;
		b = R;
	}
	return b;
}

int main()
{
	ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
	int mod, step;
	
	while (cin >> step >> mod) {
		if(gcd(step , mod) == 1)
			cout << setw(10) << step <<setw(10) << mod << "    " << "Good Choice\n\n";
		else
			cout << setw(10) << step << setw(10) << mod << "    " << "Bad Choice\n\n";
	}

	return 0;
}

========================================================================================================================================

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(NULL), cout.tie(NULL), cin.tie(NULL);
	int mod, step;
	int index = 0;

	while (cin >> step >> mod) {
		bool vis[100000] = { 0 };
		bool bad = false;
		
		for (int i = 0; i < mod; i++) {
			int generated = (index + step) % mod;
			
			if (vis[generated] == 1){	// if the number repeated ==> break  and this Bad
				bad = true;
				break;
			}

			vis[generated] = 1;		// make sure I visited the number
			index = generated;		// to start from where I end
		}
		cout << setw(10) << step << setw(10) << mod << "    ";
		bad ? cout << "Bad Choice\n\n" : cout << "Good Choice\n\n";
	}

	return 0;
}

