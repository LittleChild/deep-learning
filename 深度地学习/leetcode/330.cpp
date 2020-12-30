#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long int miss=1;
        int idx=0;
        int re=0;
        while(miss<=n){
            if(idx<nums.size() && nums[idx]<=miss){
                miss+=nums[idx];
                idx+=1;
            }
            else{
                miss+=miss;
                re+=1;
            }
        }
        return re;
    }
};

int main(){
    vector<int>nums={1,3};
    Solution s;
    cout<<s.minPatches(nums,6);
    return 0;
}