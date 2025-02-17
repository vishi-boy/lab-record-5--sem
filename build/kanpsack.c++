
#include <bits/stdc++.h>
using namespace std;


int knapSack(int W, int wt[], int val[], int n)
{

    if (n == 0 || W == 0)
        return 0;

    
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);


    else
        return max(knapSack(W, wt, val, n - 1), 
         val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1));
}

// Driver code
int main()
{
    int profit[] = { 350, 12, 167 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << knapSack(W, weight, profit, n);
    return 0;
}