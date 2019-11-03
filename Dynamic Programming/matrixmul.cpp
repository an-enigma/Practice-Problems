#include <iostream>
#include <climits>
using namespace std;

#define MAX 10

// lookup table to store the solution to already computed
// sub-problems
int lookup[MAX][MAX];

// Function to find the most efficient way to multiply
// given sequence of matrices
int MatrixChainMultiplication(int dims[], int i, int j)
{
	// base case: one matrix
	if (j <= i + 1)
		return 0;

	// stores minimum number of scalar multiplications (i.e., cost)
	// needed to compute the matrix M[i+1]...M[j] = M[i..j]
	int min = INT_MAX;

	// if sub-problem is seen for the first time, solve it and
	// store its result in a lookup table
	if (lookup[i][j] == 0)
	{
		// take the minimum over each possible position at which the
		// sequence of matrices can be split

		/*
			(M[i+1]) x (M[i+2]..................M[j])
			(M[i+1]M[i+2]) x (M[i+3.............M[j])
			...
			...
			(M[i+1]M[i+2]............M[j-1]) x (M[j])
		*/

		for (int k = i + 1; k <= j - 1; k++)
		{
			// recur for M[i+1]..M[k] to get a i x k matrix
			int cost = MatrixChainMultiplication(dims, i, k);

			// recur for M[k+1]..M[j] to get a k x j matrix
			cost += MatrixChainMultiplication(dims, k, j);

			// cost to multiply two (i x k) and (k x j) matrix
			cost +=	dims[i] * dims[k] * dims[j];

			if (cost < min)
				min = cost;
		}
		lookup[i][j] = min;
	}

	// return min cost to multiply M[j+1]..M[j]
	return lookup[i][j];
}

// Matrix Chain Multiplication Problem
int main()
{
	// Matrix M[i] has dimension dims[i-1] x dims[i] for i = 1..n
	// input is 10 x 30 matrix, 30 x 5 matrix, 5 x 60 matrix
	int dims[] = { 10, 30, 5, 60 };
	int n = sizeof(dims) / sizeof(dims[0]);

	cout << "Minimum cost is " << MatrixChainMultiplication(dims, 0, n - 1);

	return 0;
}
