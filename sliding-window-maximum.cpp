#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0;
        vector<int>ans;
        deque<int>q;
        int n = nums.size();
        while(j<n){
            while(q.size()>0 && q.back()<nums[j]){
                q.pop_back();
            }
            q.push_back(nums[j]);
            
            if(j-i+1<k){
                j++;
            }
            
            else{
                ans.push_back(q.front());
                if(nums[i]==q.front()){
                    q.pop_front();
                }
                i++;
                j++;
            }
            
        }
        return ans;
        
    }
};