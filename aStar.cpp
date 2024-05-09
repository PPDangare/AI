#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define n 3

class state{
public:
    int board[n][n];
    int g,f;
    state *parent;
    state()
    {
        g=0;
        f=0;
        parent=NULL;
    }

    static int heuristic(state from,state to)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(from.board[i][j] && from.board[i][j]!=to.board[i][j])
                    cnt++;
            }
        }
        return cnt;
        
    }

    bool operator==(state a)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(this->board[i][j]!=a.board[i][j])
                    return false;
            }
        }
        return true;
        
    }
    void print()
    {
        cout<<"\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<"\ng = "<<g<<"  |  f = "<<f;
    }
};
vector<state>output;

bool lowerF(state a,state b)
{
    return a.f<b.f;
}

bool checkSolvable(state curr)
{
    int arr[9];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i*3+j] = curr.board[i][j];
        }
    }
    int inv = 0;
    for(int i=0;i<9-1;i++)
    {
        for(int j=i+1;j<9;j++)
        {
            if(arr[i]&&arr[j]&&arr[i]>arr[j])
                inv++;
        }
    }
    if(inv%2!=0)
        return false;
    return true;
}

bool printPath(state curr,vector<state>&output)
{
    state*temp = &curr;
    while(temp!=NULL)
    {
        output.push_back(*temp);
        temp = temp->parent;
    }
    return true;

}

bool isinset(state &a,vector<state>&b)
{
    for(int i=0;i<b.size();i++)
    {
        if(a==b[i])
            return true;
    }
    return false;
}

void add_neighbour(int newi,int newj,int posi,int posj,state curr,state goal,vector<state>&openset,vector<state>&closedset)
{
    state newState = curr;
    swap(newState.board[newi][newj],newState.board[posi][posj]);
    if(!isinset(newState,openset)&&!isinset(newState,closedset))
    {
        newState.g = curr.g+1;
        newState.f = newState.g + state::heuristic(newState,goal);
        state* temp = new state();
        *temp = curr;
        newState.parent = temp;
        openset.push_back(newState);
    }
}

void neighbours(state curr,state goal,vector<state>&openset,vector<state>&closedset)
{
    int i,j,posi,posj;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(curr.board[i][j]==0)
            {
                posi=i;
                posj=j;
            }
        }
    }
    i=posi;
    j=posj;
    if(i-1>=0)
        add_neighbour(i-1,j,posi,posj,curr,goal,openset,closedset);
    if(j-1>=0)
        add_neighbour(i,j-1,posi,posj,curr,goal,openset,closedset);
    if(i+1<n)
        add_neighbour(i+1,j,posi,posj,curr,goal,openset,closedset);
    if(j+1<n)
        add_neighbour(i,j+1,posi,posj,curr,goal,openset,closedset);
}

bool astar(state start,state goal)
{
    vector<state>openset;
    vector<state>closedset;
    start.g = 0;
    start.f = start.g+state::heuristic(start,goal);
    openset.push_back(start);
    state curr;
    while(!openset.empty())
    {
        sort(openset.begin(),openset.end(),lowerF);
        curr = openset[0];
        
        if(goal==curr)
            return printPath(curr,output);
        openset.erase(openset.begin());
        closedset.push_back(curr);
        neighbours(curr,goal,openset,closedset);
    }
    return false;
}

int main()
{
    state start,goal;
    cout<<"\nEnter start mat = \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>start.board[i][j];
        }
    }
    cout<<"\nEnter goal mat = \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>goal.board[i][j];
        }
    }

    if(!checkSolvable(start))
    {
        cout<<"\nUnsolvable";
        return 0;
    }
    if(astar(start,goal))
    {
        for(int i=output.size()-1;i>=0;i--)
        {
            output[i].print();
        }
        cout<<"\nSuccess ";
    }
    else
        cout<<"\nFail";
    return 0;
        
}