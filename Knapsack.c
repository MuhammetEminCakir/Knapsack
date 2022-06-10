#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int K[2][W + 1];

	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i % 2][w] = 0;
			else if (wt[i - 1] <= w)
				K[i % 2][w] = max(
					val[i - 1]
						+ K[(i - 1) % 2][w - wt[i - 1]],
					K[(i - 1) % 2][w]);
			else
				K[i % 2][w] = K[(i - 1) % 2][w];
		}
	}
	return K[n % 2][W];
}

int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	char stringA[11] = "ks_4_0";
	char stringB[100000] = "ks_100_0";
	char stringC[1000000] = "ks_10000_0";

	printf("%f", knapSack(W, wt, val, n));

	return 0;
}