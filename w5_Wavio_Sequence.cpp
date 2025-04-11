#include<iostream>
#include <vector>
using namespace std;

vector<int> lis(vector<int> &sq,int n)
{
    vector<int> lis_lens(n,1);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(sq[i]<sq[j])
            {
                lis_lens[j]=max(lis_lens[j],lis_lens[i]+1);
            }
        }
    }
    return lis_lens;
}

vector<int> lds(vector<int> &sq,int n)
{
    vector<int> lds_lens(n,1);
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(sq[i]<sq[j])
            {
                lds_lens[j]=max(lds_lens[j],lds_lens[i]+1);
            }
        }
    }
    return lds_lens;
}

int main()
{
    ios_base::sync_with_stdio(false);
    vector<int> sq;
    int n;
    int ele;
    while(cin>>n)
    {
        
        for(int i=0;i<n;i++)
        {
            cin>>ele;
            sq.push_back(ele);
        }
        vector<int> lds_list=lds(sq,n),lis_list=lis(sq,n);
        int ans=0;
        for (int j=0;j<n;j++) 
        {
            ans = max(ans, min(lis_list[j], lds_list[j])*2-1);
        }
        cout << ans << endl;
        sq.clear();
    }
    return 0;
}