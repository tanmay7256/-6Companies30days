// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    vector <vi> dp;
    vi ans;
    int find(int n, vector<int> &arr,int idx)
    {
        if(n<=0 || idx>11)
          return 0;
        int a=find(n,arr,idx+1),b=find(n-arr[idx]+1,arr,idx+1);
        if(a<b)
          ans[idx]=arr[idx]+1;
        // dp[idx]=max(a,b);
        return max(a,b);
    }
    vector<int> maximumBobPoints(int n, vector<int> &arr)
    {
        dp=vector<vi> (12,vi(n+1));
        ans=vi(12,0);
        int a =find(n,arr,0);
        return ans;
    }
};
int main()
{

    return 0;
}
