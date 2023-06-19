#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        vector<char> v;
        unordered_map<char, int> mp;
        string ans;

        for (char ch : A)
        {
            if (mp.find(ch) == mp.end())
            { // any new character visited for
              // the first time
                v.push_back(ch);
                mp[ch] = 1;
            }
            else
            {
                // any repeated character visited
                int index = find(v.begin(), v.end(), ch) - v.begin();
                // for any repeated character encountered more
                // than twice the index will be equal to
                // v.size()
                if (index < v.size())
                    v.erase(v.begin() + index);
            }
            ans += (v.empty() ? '#' : v.front());
        }

        return ans;
    }
};

int main()
{
    string input;
    cin >> input;
    Solution sol;
    cout << sol.FirstNonRepeating(input);
    return 0;
}