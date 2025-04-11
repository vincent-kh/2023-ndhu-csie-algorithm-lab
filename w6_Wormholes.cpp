#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int a,b,d;
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,N;
    cin>>N;
    while(N--)
    {
        cin>>n>>m;
        vector<Edge> edges(m);
        vector<int> dis(n,1001);
        for(int i=0;i<m;i++)
        {
            cin>>edges[i].a>>edges[i].b>>edges[i].d;
        }
        
        for(int i=0;i<n-1;i++)
        {
            for(Edge ele:edges)
            {
                dis[ele.b]=min(dis[ele.a]+ele.d,dis[ele.b]);
            }
        }

        bool nag_cycle=0;
        for(Edge ele:edges)
        {
            if(dis[ele.a]+ele.d<dis[ele.b])
            {
                nag_cycle=1;
                break;
            }
        }

        if(nag_cycle)
            cout<<"possible"<<endl;
        else
            cout<<"not possible"<<endl;
        
        edges.clear();
        dis.clear();
    }
}
