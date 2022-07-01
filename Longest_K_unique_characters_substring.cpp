#include<bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k) {
    // your code here
    int res=-1;
    map<char,int>m;
    int i=0,j=0;
    while(j<s.size()){
        m[s[j]]++;
        if(m.size()>k){
            while(m.size()>k){
                m[s[i]]--;
            if(m[s[i]]==0){
                m.erase(s[i]);
            }
            i++;
            }
            
            
        }
        else if(m.size()==k){
            res=max(res,j-i+1);
           
            
        }
        j++;
    }
    return res;
    }