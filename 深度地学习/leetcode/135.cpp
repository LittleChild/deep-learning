#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int re=ratings.size();
        int *l=new int[re];
        int *r=new int[re];
        if(re<=1) 
            return re;
        for(int i=0;i<ratings.size();i++){
            if(i>0 &&ratings[i]>ratings[i-1]){
                l[i]=l[i-1]+1;
            }else
            {
                l[i]=1;
            }
        }
        re=0;
        for(int i=ratings.size()-1;i>=0;i--){
            if(i<ratings.size()-1 &&ratings[i]>ratings[i+1]){
                r[i]=r[i+1]+1;
            }else
            {
                r[i]=1;
            }
            re+=max(l[i],r[i]);
        }
        return re;
    }
};

int main(){
    vector<int>r={1,0,2};
    Solution s;
    cout<<s.candy(r);
    return 0;
}