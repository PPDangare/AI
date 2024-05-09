#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> dij(vector<vector<pair<int, int>>> &adj, int ver, int s, vector<int> &parent)
    {
        set<pair<int, int>> st;
        vector<int> dist(ver, 1e9);
        st.insert({0, s}); // Insert the node with its distance into the set
        dist[s] = 0;       // Set distance of start node to zero

        while (!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            for (const auto &edge : adj[node])
            {
                int adjnode = edge.first;
                int weight = edge.second;

                if (dis + weight < dist[adjnode])
                {
                    if (dist[adjnode] != 1e9)
                    {
                        st.erase({dist[adjnode], adjnode});
                    }
                    dist[adjnode] = dis + weight;
                    parent[adjnode] = node; // Store the parent
                    st.insert({dist[adjnode], adjnode});
                }
            }
        }
        return dist;
    }
};

int main()
{
    int ver, e;
    string s;

    cout << "Enter the number of vertices: ";
    cin >> ver;
    cout << "Enter the number of edges: ";
    cin >> e;
    cout << "Enter the start vertex: ";
    cin.ignore();
    getline(cin, s);

    map<string, int> cityIndices;
    map<int, string> reverseCityIndices; // Map for index to city name
    vector<vector<pair<int, int>>> adj(ver);
    string u, v;
    int w;
    int index = 0;

    cout << "Enter the edges (u, v, weight):" << endl;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        if (cityIndices.find(u) == cityIndices.end())
        {
            cityIndices[u] = index;
            reverseCityIndices[index] = u;
            index++;
        }
        if (cityIndices.find(v) == cityIndices.end())
        {
            cityIndices[v] = index;
            reverseCityIndices[index] = v;
            index++;
        }
        adj[cityIndices[u]].push_back({cityIndices[v], w});
        adj[cityIndices[v]].push_back({cityIndices[u], w});
    }

    Solution sol;
    int start_index = cityIndices[s];
    vector<int> parent(ver, -1); // Initialize parent array with -1
    vector<int> res = sol.dij(adj, ver, start_index, parent);

    cout << "Shortest distances from " << s << ":" << endl;
    for (const auto &it : cityIndices)
    {
        string city = it.first;
        int index = it.second;
        cout << "Distance from " << s << " to " << city << " is: " << res[index] << endl;

        // Print the shortest path from the start to each city
        cout << "Shortest path from " << s << " to " << city << ": ";
        stack<int> path;
        int current = index;

        while (current != -1)
        {
            path.push(current);
            current = parent[current];
        }

        while (!path.empty())
        {
            cout << reverseCityIndices[path.top()] << " "; // Print city names
            path.pop();
        }

        cout << endl;
    }

    return 0;
}