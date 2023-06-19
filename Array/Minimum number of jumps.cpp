#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:

    int minJumps(int arr[], int n)
    {
        if (n <= 1)
        {
            return 0;
        }

        if (arr[0] == 0 && n > 1)
        {
            return -1;
        }

        int total_jumps = 1, steps = arr[0], max_index_reached = arr[0];
        for (int i = 1; i < n; i++)
        {
            if(i==n-1){
                return total_jumps;
            }

            steps--;
            max_index_reached = max(max_index_reached , i + arr[i]); // we want to jump maximum, So select that i who have max jump range
            if(steps == 0){
                total_jumps++;
                if( i >= max_index_reached){
                    return -1;
                }
                steps = max_index_reached - i;
            }

        }
        return -1;
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.minJumps(arr, n);
    return 0;
}