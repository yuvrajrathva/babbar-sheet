#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        sort(arr,arr+n);
        int ans = arr[n-1] - arr[0];
        int prev_min = arr[0] + k;
        int prev_max = arr[n-1] - k;

        for(int i=0;i<n;i++){
            

        }


    }
};

int main()
{
    int k, n;
    cin >> k >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.getMinDiff(arr, n, k);
    return 0;
}