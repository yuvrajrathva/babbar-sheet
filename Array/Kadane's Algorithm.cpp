// Largest Sum Contiguous Subarray

#include <iostream>
using namespace std;

class Solution
{
public:
    long long function(int array[], int n)
    {
        long long max = INT16_MIN, sum_till_now = 0;

        for (int i = 0; i < n; i++)
        {
            sum_till_now += array[i];
            
            if(sum_till_now > max){
                max = sum_till_now;
            }

            if(sum_till_now<0){
                sum_till_now = 0;
            }
        }
        return max;
    }
};

int main()
{
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    Solution sol;
    cout << sol.function(array, n);
    return 0;
}