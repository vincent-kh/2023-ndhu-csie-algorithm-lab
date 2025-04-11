#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t,n,max_w,p,w,member,anser;
    long mx;
    cin>>t;
    while(t--)
    {
        vector<pair<int,int>> products;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>p>>w;
            products.push_back(make_pair(p,w));
        }
        cin>>member;
        anser=0;
        while(member--)
        {
            mx=0;
            cin>>max_w;
            vector<long> dp(max_w+1,0);
            for(int i=0;i<n;i++)
            {
                for(int j=max_w;j>=products[i].second;j--)
                {
                    dp[j]=max(dp[j],dp[j-products[i].second]+products[i].first);
                }
            }
            mx=dp[max_w];
            anser+=mx;
        }
        cout<<anser<<endl;
    }
}