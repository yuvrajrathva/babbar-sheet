#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestSubWithSum(int arr[], int n, int x)
    {
        int start = 0;
        int end = 0;
        int current_sum = arr[0];
        int min;
        for (int i = 0; i < n; i++)
        {
            if (current_sum > x)
            {
                while (current_sum > x)
                {
                    current_sum -= arr[start];
                    start++;
                    end = i;
                }
                start--;
                current_sum = -(arr[start] + arr[start + 1]);
                if (min > end - start + 1)
                {
                    min = end - start + 1;
                }
            }
            else
            {
                current_sum += arr[i];
            }
        }
    }
};

int main()
{
    int n, x;
    cin >> n >> x;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution sol;
    cout << sol.smallestSubWithSum(arr, n, x);

    return 0;
}