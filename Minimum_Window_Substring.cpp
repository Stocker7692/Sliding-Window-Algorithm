#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hash;
        
        //O(n) step
        for(char i: t)
            hash[i] += 1;
        int count = hash.size();
        
        int i=0,j=0;
        pair<int,int> ans; // {starting index, size} to store best result for which we need to do substr only once
        int counter = INT_MAX; //to maintain current min sized window 
        
        //O(m) step
        while(j<s.size())
        {
            //Calculation of arr[j]
            if(hash.find(s[j]) != hash.end())
            {
                hash[s[j]] --;
                if(hash[s[j]]==0)
                    count--;
            }
            
            if(count > 0) 
                j++;
            
            else if(count == 0)
            {
                //we have a candidate answer and we will also try to optimise the string by removing useless characters
                while(count==0)
                {
                    if(j-i+1 < counter)
                    {
                        counter = j-i+1;
                        ans = {i,counter};
                    }
                    
                    if(hash.find(s[i]) != hash.end())
                    {
                        hash[s[i]] ++;
                        if(hash[s[i]]==1)
                            count++;
                    }
                    i++;
                }
                j++;
            } 
        }
        return (counter==INT_MAX) ? "" : s.substr(ans.first,ans.second);
    }
};