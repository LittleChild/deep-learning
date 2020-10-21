#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int i=1;
        vector<vector<int> >re;
        vector<int>t;
        int s=sum;
        int b=i;
        while(i<sum){
            t.push_back(i);
            s-=i;
            i++;
            if(s==0){
                re.push_back(t);
                t.clear();
                if(s==b)
                    break;
                b++;
                i=b;
                s=sum;   
            }
            if(s<i){
                t.clear();
                b++;
                i=b;
                s=sum;
            }
           
        }
        return re;


        // int i=1;
        // vector<vector<int> >re;
        // vector<int>t;
        // int s=sum;
        // int b=i;
        // map<vector<int>,int>m;
        // while(i<sum){
        //     t.push_back(i);
        //     s-=i;
        //     i++;
        //     if(s<0){
        //         t.clear();
        //         b++;
        //         i=b;
        //         s=sum;
        //     }
        //     if(s<b){
        //         // int ii=t.back();
        //         // t.pop_back();
        //         // t.push_back(ii+s);
        //         if(s!=0)
        //             t.insert(t.begin(),s);
        //         m[t]++;
        //         if(m[t]<=1)
        //             re.push_back(t);
        //         t.clear();
        //         if(s==b)
        //             break;
        //         b++;
        //         i=b;
        //         s=sum;   
        //     }
            
        // }
        // return re;
    }
};

int main(){
    Solution s;
    vector<vector<int>>re=s.FindContinuousSequence(10);
    for(int i=0;i<re.size();i++){
        for(int j=0;j<re[i].size();j++){
            cout<<re[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}