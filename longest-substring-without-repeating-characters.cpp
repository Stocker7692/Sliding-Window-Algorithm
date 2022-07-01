#include<bits/stdc++.h>
using namespace std;

// map

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int>m;
        int res=0;
        int curr=0;
        for(int i=0;i<s.size();i++){
            res = max(res,i-curr);
            if(m.find(s[i])!=m.end() && m[s[i]]>=curr){
                curr = m[s[i]]+1;
            }
            m[s[i]]=i;
        }
        if(res<s.size()-curr) return s.size()-curr;
        return res;
        
    }
};
// sliding window

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int>m;
        int res=0;
        int i=0,j=0;
        while(j<s.size()){
            m[s[j]]++;
            if(m.size()==j-i+1){
                res=max(res,j-i+1);
            }
            else if(m.size()<j-i+1){
                while(m.size()<j-i+1){
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return res;
        
    }
};