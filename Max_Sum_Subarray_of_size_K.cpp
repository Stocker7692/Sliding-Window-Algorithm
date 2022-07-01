
#include <bits/stdc++.h>
using namespace std;

long maximumSumSubarray(int K, vector<int> &Arr, int N)
{
    // code here
    if (N < K)
        return -1;

    int windstart = 0;
    long maxsum = INT_MIN;
    long windsum = 0;

    for (int i = 0; i < N; ++i)
    {
        windsum += Arr[i];

        if (i + 1 >= K)
        {
            maxsum = max(maxsum, windsum);
            windsum -= Arr[windstart];
            windstart++;
        }
    }
    return maxsum;
}