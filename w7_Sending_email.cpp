#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int T,n,m,s,t,from,to,w;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for(int ts=1;ts<=T;ts++)
    {
        cin>>n>>m>>s>>t;
        vector<vector<pair<int,int>>> graph(n,vector<pair<int,int>>());
        for(int i=0;i<m;i++)
        {
            cin>>from>>to>>w;
            graph[from].push_back({w,to});
            graph[to].push_back({w,from});
        }
        vector<int> dist(n,200000000);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        dist[s]=0;
        pq.push({0,s});
        while (!pq.empty())
        {
            auto p=pq.top();
            if(p.second==t)
                break;
            pq.pop();
            if(dist[p.second]>=p.first)
            {
                for(auto path:graph[p.second])
                {
                    if(path.first+dist[p.second]<dist[path.second])
                    {
                        dist[path.second]=path.first+dist[p.second];
                        pq.push({dist[path.second],path.second});
                    }
                }
            }
        }
        if(dist[t]<200000000)
            cout<<"Case #"<<ts<<": "<<dist[t]<<endl;
        else
            cout<<"Case #"<<ts<<": unreachable"<<endl;
    }
    return 0;
}