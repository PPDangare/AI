#include<bits/stdc++.h>
using namespace std;


class Graph
{
    public:
    vector<vector<int>>graph;
    int n;

    Graph()
    {
        n=0;
    }

    void createGraph();
    void printGraph();
    void dfs();
    void dfs_rec(int n,vector<int>&viisted,int level);
    void dfs_nonrec();
    void bfs_nonrec();
    void bfs();
    void bfs_rec(vector<int>&visited,queue<int>&q,vector<int>&level);


};

void Graph::createGraph()
{
    cout<<"Enter number of vertices : ";
    cin>>n;

    graph.resize(n);  // to resize graph

    int u,v;
    cout<<"Enter Starting vertex and end vertex  of edges : "<<endl;

    while(1)
    {
        cin>>u>>v;
        if(u==-1 || v==-1)
        {
            break;
        }
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}


void Graph::printGraph()
{

    cout<<"\nGraphhh :: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<" --> ";
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Graph::dfs()
{
    vector<int>visited(n,0);

    int x;
    cout<<"\nEnter Starting vertex for dfs Traversal : ";
    cin>>x;

    cout<<"DFS Recursive traversal : ";
    dfs_rec(x,visited,0);
    
}

void Graph::dfs_rec(int x,vector<int>&visited,int level)
{
    cout<<"{"<<x<<","<<level<<"}";

    visited[x]=1;

    for(int i=0;i<graph[x].size();i++)
    {
        if(visited[graph[x][i]]==0)
        {
            dfs_rec(graph[x][i],visited,level+1);
        }
    }
}

void Graph::dfs_nonrec()
{
    vector<int>visited(n,0);
    int v;
    cout<<"\n\nEnter starting vertex for dfs traversal :  ";
    cin>>v;

    stack<pair<int,int>>st;
    st.push({v,0});
    visited[v]=1;
    cout<<"DFS nonrecursive travresalv : ";

    while(!st.empty())
    {
        auto v=st.top();
        st.pop();

        cout<<"{"<<v.first<<","<<v.second<<"}";


        for(int i=0;i<graph[v.first].size();i++)
        {
            if(visited[graph[v.first][i]]==0)
            {
                st.push({graph[v.first][i],v.second+1});
                visited[graph[v.first][i]]=1;
            }
        }
    }
}

void Graph::bfs_nonrec()
{
    vector<int>visited(n,0);
    cout<<"\n\nEnter starting vertex for bfs traversal : ";
    int v;
    cin>>v;

    queue<pair<int,int>>q;
    q.push({v,0});
    visited[v]=1;

    cout<<"Non recursive BFS Traversal : ";

    while(!q.empty())
    {
        auto v=q.front();
        q.pop();

        cout<<"{"<<v.first<<","<<v.second<<"}";

        for(int i=0;i<graph[v.first].size();i++)
        {
            if(visited[graph[v.first][i]]==0)
            {
                visited[graph[v.first][i]]=1;
                q.push({graph[v.first][i],v.second+1});
            }
        }
    }
}


void Graph::bfs()
{
    vector<int>visited(n,0);

    int x;
    cout<<"\nEnter Starting vertex for bfs Traversal : ";
    cin>>x;
    visited[x]=1;
    
    queue<int>q;
    q.push(x);
   
   cout<<"BFS recursive traversal : ";
   vector<int>level(n,0);
    bfs_rec(visited,q,level);
}

void Graph::bfs_rec(vector<int>&visited,queue<int>&q,vector<int>&level)
{
    if(q.empty())
    {
        return;
    }

    int v=q.front();
    q.pop();
    cout<<"{"<<v<<","<<level[v]<<"}";

    for(int x:graph[v])
    {
        if(!visited[x])
        {
            visited[x]=1;
            q.push(x);
            level[x]=level[v]+1;
        }
    }

    bfs_rec(visited,q,level);

}


int main()
{
    Graph g;
    g.createGraph();
    g.printGraph();
    g.dfs();
    g.dfs_nonrec();
    g.bfs_nonrec();
    g.bfs();

}
