//Coin change problem using Memoization

#include <iostream>
#include <climits>
using namespace std;

// Function to find the minimum number of coins required
// to get total of N from set S
int findMinCoins(int S[], int n, int N)
{
	// T[i] stores minimum number of coins needed to get total of i
	int T[N + 1];
	T[0] = 0;	// 0 coins are needed to get total of i

	for (int i = 1; i <= N; i++)
	{
		// initialize minimum number of coins needed to infinity
		T[i] = INT_MAX;
		int res = INT_MAX;

		// do for each coin
		for (int c = 0; c < n; c++)
		{
			// check if index doesn't become negative by including
			// current coin c
			if (i - S[c] >= 0)
				res = T[i - S[c]];

			// if total can be reached by including current coin c,
			// update minimum number of coins needed T[i]
			if (res != INT_MAX)
				T[i] = min(T[i], res + 1);
		}
	}

	// T[N] stores the minimum number of coins needed to get total of N
	return T[N];
}

// main function
int main()
{
	// n coins of given denominations
	int S[] = { 1, 2, 3, 4 };
	int n = sizeof(S) / sizeof(S[0]);

	// Total Change required
	int N = 15;

	cout << "Minimum number of coins required to get desired change is "
			<< findMinCoins(S, n, N);

	return 0;
}
