#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return;
        }
        if (nums.size() == 2)
        {
            reverse(nums.begin(), nums.end());
        }
        else{
        queue<int> q;
        int stop, index=-1, removed;
        for (int i = nums.size() - 1; i > 0; i--)
        {
            q.push(nums[i]);
            if (nums[i] > nums[i - 1])
            {
                index = i - 1;
                removed = nums[i - 1];
                break;
            }
        }
        int counter =1;
        if(index != -1){
        for (int i = index + 1; i < nums.size(); i++)
        {
            if (removed < q.front() && counter > 0)
            {
                nums[index] = q.front();
                q.pop();
                nums[i] = removed;
                counter--;
            }
            else
            {
                nums[i] = q.front();
                q.pop();
            }
        }}else{
            reverse(nums.begin(),nums.end());
        }
        }
        for (auto it = nums.begin(); it != nums.end(); it++)
            cout << *it << " ";

    }
};

int main()
{
    vector<int> input = {1,2};

    Solution sol;
    sol.nextPermutation(input);
    return 0;
}