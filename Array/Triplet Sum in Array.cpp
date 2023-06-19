#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool find3Numbers(int A[], int n, int X)
    {
        // int max = INT_MIN;
        // for (int i = 0; i < n; i++)
        // {
        //     if (max < A[i])
        //     {
        //         max = A[i];
        //     }
        // }
        // int hash[max + 1]={0};
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++)
        {
            hash[A[i]]++;
        }

        for (int i = 0; i < n - 2; i++)
        {
            int new_X = X - A[i];
            for (int j = i + 1; j < n; j++)
            {
                if ((hash[new_X - A[j]] > 0 && new_X - A[j] != A[j]) || (hash[new_X - A[j]] > 1 && new_X - A[j] == A[j]))
                {
                    // cout<<new_X - A[j]<<" + "<<A[j]<<" + "<<A[i]<<" ";
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    int n, X;
    cin >> n >> X;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    Solution sol;
    cout<<sol.find3Numbers(A, n, X);
    return 0;
}