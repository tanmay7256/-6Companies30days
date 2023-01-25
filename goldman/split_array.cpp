// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> umap;
        vector<int> v;
        int c=0,mx=0,ans=1;
        for (int i = 0; i < n; i++)
            umap[v[i]]++;
        auto it=umap.begin();
        auto temp=umap.end();
        int pre=(*it).first-1;
        while(it!=umap.end())
        {
            auto p=*it;
            if(p.first!=(pre+1))
            {
                if(c<3)
                  return 0;
                mx=max(mx,c);
                c=0;
                it=temp;
                continue;
                ans++;
            }
            if(p.second>1 && temp==umap.end())
                temp=it;
            umap[p.first]--;
            c++;
            pre=p.first;
            it++;
        }
        if(ans==1 && mx<6)
          return 0;
           
        return 1;
        
    }
};
int main()
{

    return 0;
}
