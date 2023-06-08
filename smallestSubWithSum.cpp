#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestSubWithSum(int arr[], int n, int x)
    {
        int sum = 0, start = 0, min = n;
        for (int i = 0; i < n; i++)
        {
            int flag = 0;
            sum += arr[i];
            while (sum > x && start <= i)
            {
                sum -= arr[start];
                start++;
                flag = 1;
            }
            if (flag == 1 && min > i - start + 1 + 1)
            {
                min = i - start + 1 + 1;
            }
        }

        sum = 0;
        start = n-1;
        for (int i = n - 1; i >= 0; i--)
        {
            int flag = 0;
            sum += arr[i];
            while (sum > x && start >= i)
            {
                sum -= arr[start];
                start--;
                flag = 1;
            }
            if (flag == 1 && min >  start + 1 - i + 1)
            {
                min = start + 1 - i + 1;
            }
        }

        return min;
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