#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

vector< pair<long long int,long long int> > g[101000];
long long int n,m;
vector<long long int> dist;
vector <long long int> vis;

void dijkstra(long long int source,long long int l)
{
    dist.clear();
    long long int i,j,k;
    for(i=0;i<n;i++)
    {
        dist.push_back(INT_MAX);
        vis.push_back(0);
    }
    dist[source] = 0;
    set< pair<long long int,long long int> > s; // pair is dist, node_number
    set< pair<long long int,long long int> >::iterator it;

    for(i=0;i<n;i++)
        s.insert(mp(dist[i],i));

    while(!s.empty())
    {
        it = s.begin();
        pair<long long int,long long int> temp = *it;
        s.erase(temp); // remove minimum val node
        long long int cur = temp.sd;
        long long int val = temp.ft;

        if(val == INT_MAX)
            return;
        for(i=0;i<g[cur].size();i++)
        {
            long long int nb = g[cur][i].ft;
            if(!vis[nb] && dist[nb] > val + g[cur][i].sd)
            {
                s.erase(mp(dist[nb],nb)); // erase old val
                dist[nb] = val + g[cur][i].sd;
                s.insert(mp(dist[nb],nb));
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;

}
int main()
{
    long long int i,j,k;

        dist.clear();
        vis.clear();

        long long int x,y,z;
        cin>>n>>m;
        for(i=0;i<m;i++)
            g[i].clear();

        for(i=0;i<m;i++)
        {
            cin>>x>>y>>z;
            x--;    y--;

            g[x].push_back(mp(y,z));
            g[y].push_back(mp(x,z));
        }
        dijkstra(0,n-1);

        return 0;
}