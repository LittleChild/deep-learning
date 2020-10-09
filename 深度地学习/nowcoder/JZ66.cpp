#include<iostream>
using namespace std;

class Solution {
public:
    int count=0;
    int movingCount(int threshold, int rows, int cols)
    {
        int *pass=new int[rows*cols];
        Count(threshold, rows,cols,0,0,pass);
        return count;
    }
    void Count(int threshold, int rows, int cols,int i, int j,int *pass){
        int index=i*cols+j;
        if(i<0||j<0||i>=rows||j>=cols||pass[index]==1)
            return ;
        if(bitsum(i,j)<threshold){
            count++;
            pass[index]=1;
        }
        else{
            //pass[index]=0;
            return;
        }
        Count(threshold, rows,cols,i-1,j,pass);
        Count(threshold, rows,cols,i+1,j,pass);
        Count(threshold, rows,cols,i,j-1,pass);
        Count(threshold, rows,cols,i,j+1,pass);
    }
    int bitsum(int i,int j){
        int sum=0;
        while(i>0){
            sum+=i%10;
            i/=10;
        }
        while(j>0){
            sum+=j%10;
            j/=10;
        }
        return sum;
    }
};

int main(){
    Solution s;
    int re=s.movingCount(5,10,10);
    cout<<re;
    // int sum[10]= { 0 };
    // for(int i=0;i<10;i++)
    //     cout<<sum[i]<<' ';
    // cout<<endl;
    // int *sum2=new int[10];
    // for(int i=0;i<10;i++)
    //     cout<<sum2[i]<<' ';
    // cout<<endl;
    return 0;
}