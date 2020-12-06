#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int>p={1};
        vector<vector<int>>re;
        if(numRows==0)
            return re;
        re.push_back(p);
        if(numRows==1)
            return re;
        p.push_back(1);
        re.push_back(p);
        if(numRows==2)
            return re;
        vector<int>t;
        for(int i=1;i<numRows-1;i++){
            t.push_back(1);
            for(int j=0;j<i;j++){
                t.push_back(p[j]+p[j+1]);
            }
            t.push_back(1);
            re.push_back(t);
            p=t;
            t.clear();
        }
        return re;
    }
};
int main(){
    vector<int>A={2,2};
    Solution s;
    vector<vector<int>>re=s.generate(5);
    return 0;
}