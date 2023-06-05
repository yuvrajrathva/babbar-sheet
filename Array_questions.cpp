#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &price)
    {
        int min1 = price[0];
        int max_diff1 = 0, max_diff2 = 0;
        int start = 0, end = 0;
        int n = price.size();
        for (int i = 1; i < n; i++)
        {
            int diff = 0;
            if (price[i] < min1)
            {
                min1 = price[i];
                start = i;
            }
            else if (start != 0 && i<n-2)
            {
                diff = price[i] - min1;
                if (diff > max_diff1)
                {
                    max_diff1 = diff;
                    end = i;
                }
            }
        }

        if (start != 0)
        {
            int min2 = price[0];
            for (int i = 0; i < start; i++)
            {
                int diff = 0;
                if (price[i] < min2)
                {
                    min2 = price[i];
                }
                else
                {
                    diff = price[i] - min2;
                    if (diff > max_diff2)
                    {
                        max_diff2 = diff;
                    }
                }
            }
        }
        if (end + 1 != n)
        {

            int min2 = price[end + 1];
            for (int i = 0; i < start; i++)
            {
                int diff = 0;
                if (price[i] < min2)
                {
                    min2 = price[i];
                }
                else
                {
                    diff = price[i] - min2;
                    if (diff > max_diff2)
                    {
                        max_diff2 = diff;
                    }
                }
            }
        }
        // cout << max_diff1 << " " << max_diff2;
        return max_diff1 + max_diff2;
    }
};

int main()
{
    vector<int> price;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        price.push_back(input);
    }
    Solution sol;
    cout << sol.maxProfit(price);

    return 0;
}