#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define n 15
class Solution{
public:
    vector<vector<int>>a;
    vector<vector<int>>b;
    vector<string>names;
    Solution()
    {
        a.assign(n,vector<int>(n,0));
        b.assign(n,vector<int>(n,0));
        names.assign(n,"-");
    }
    Solution(int s)
    {
        a.assign(s,vector<int>(s,0));
        b.assign(s,vector<int>(s,0));
        names.assign(s,"-");
    }

    void add_edge(int u,int v,int w)
    {
        a[u][v] = w;
        a[v][u] = w;
    }

    void input(int ver,int e)
    {
        int u,v,w;
        string n1,n2;
        cout<<"\nEnter cities = \n";
        for(int i=0;i<ver;i++)
        {
            cin>>names[i];
        }
        cout<<"\nEnter start,dest,weight = \n";
        for(int i=0;i<e;i++)
        {
            cin>>n1>>n2>>w;
            for(int j=0;j<ver;j++)
            {
                if(names[j]==n1)
                {
                    u=j;
                    break;
                }
            }
            for(int j=0;j<ver;j++)
            {
                if(names[j]==n2)
                {
                    v=j;
                    break;
                }
            }
            add_edge(u,v,w);
        }
    }

    void print()
    {
        cout<<"\n";
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[i].size();j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void print1()
    {
        cout<<"\n";
        for(int i=0;i<b.size();i++)
        {
            for(int j=0;j<b[i].size();j++)
            {
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void prims(int ver,int e)
    {
        print();
        int ne = 0;
        int s;
        vector<bool>selected(ver,false);
        cout<<"\nEnter start vertex = ";
        cin>>s;
        selected[s]=true;
        int cost = 0;
        while(ne<ver-1)
        {
            int x = 0,y = 0;
            int mini= 1e9;
            for(int i=0;i<ver;i++)
            {
                if(selected[i])
                {
                    for(int j=0;j<ver;j++)
                    {
                        if(!selected[j]&&a[i][j])
                        {
                            if(mini>a[i][j])
                            {
                                mini = a[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }
            cout<<"\n"<<names[x]<<" - "<<names[y]<<" : "<<a[x][y];
            b[x][y] = a[x][y];
            b[y][x] = a[x][y];
            selected[y]=true;
            cost+=a[x][y];
            ne++;
        }
        print1();
    }

};

int main()
{
    
    int ver,edges;
    cout<<"\nEnter no of ver = ";
    cin>>ver;
    cout<<"\nEnter no of edges = ";
    cin>>edges;
    Solution s(ver);
    s.input(ver,edges);
    s.prims(ver,edges);
}