class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>m;
        vector<int>re={0,0};
        int n=nums.size();
        int t=0;
        for(int i=0;i<n;i++){
            if(m[nums[i]]==0){
                t+=nums[i];
                m[nums[i]]=1;
            }
            else{
                re[0]=nums[i];
            }
        }
        re[1]=n*(n+1)/2-t;
        return re;
    }
};
//645. 错误的集合：利用数组是1~n的条件，map找出重复的数字，求和后和1~n的和求差得出覆盖的数字。简单题，直接过。
