class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int re=0;
        int t=0;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[t]++;
            t+=nums[i];
            re+=m[t-goal];
        }
        return re;

    }
};
