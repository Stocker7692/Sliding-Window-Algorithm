#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int i = 0, j = 0;
        int res = 0;
        unordered_map<int, int> m;
        while (j < fruits.size())
        {
            m[fruits[j]]++;
            if (m.size() <= 2)
            {
                res = max(res, j - i + 1);
                j++;
            }
            else if (m.size() > 2)
            {
                while (m.size() > 2)
                {
                    // cout<<i<<m.size()<<endl;
                    m[fruits[i]]--;
                    if (m[fruits[i]] == 0)
                    {
                        m.erase(fruits[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return res;
    }
};