#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(string pat, string txt)
    {
        // code here
        int i, j, count;
        i = j = count = 0;
        int n = txt.size();
        int k = pat.size();
        vector<int> v(26);
        vector<int> real(26);
        for (int x = 0; x < k; x++)
        {
            real[pat[x] - 'a']++;
        }
        while (j < n)
        {
            if (j - i + 1 <= k)
            {
                v[txt[j] - 'a']++;
            }
            if (j - i + 1 == k)
            {
                if (v == real)
                    count++;
                v[txt[i] - 'a']--;
                i++;
            }
            j++;
        }
        return count;
    }
};