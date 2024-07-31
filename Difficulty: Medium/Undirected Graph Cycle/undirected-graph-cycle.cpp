//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool isCycleBFS( vector<bool>&visited, vector<int>adj[],int u){
      visited[u] = true;
        queue<pair<int, int>> que;
        que.push({u, -1});
        while (!que.empty())
        {
            pair<int, int> p = que.front();
            que.pop();
            int src = p.first;
            int parent = p.second;
            // check each neighbor of source
            for (auto &v : adj[src])
            {
                if (visited[v] == false)
                {
                    // good to go ahed
                    visited[v] = true;
                    que.push({v, src});
                }
                else if (v != parent)
                {
                    // if the neighbor is already visited and it is not the parent of the source then there is a cycle
                    return true;
                }
            }
        }
        return false;
    }
  
    
    bool isCycle(int V, vector<int> adj[]) {
    
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i] && isCycleBFS(visited,adj,i))return true;
    }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends