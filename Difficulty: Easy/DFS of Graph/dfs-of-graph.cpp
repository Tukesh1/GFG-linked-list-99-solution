//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     void dfs(unordered_map<int,vector<int>>&adj,vector<bool>&visited, vector<int>&ans, int sr){
        if(visited[sr])return;
         visited[sr] = true;
         ans.push_back(sr);
         for(auto &it:adj[sr]){
             if(!visited[it]){
                 dfs(adj,visited,ans,it);
             }
         }
     }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> graph[]) {
        // Code here
        unordered_map<int, vector<int>>adj;
        for(int v =0 ;v<V;v++){
            for(auto &u:graph[v]){
                adj[v].push_back(u);
            }
        }
        vector<int>ans;
        vector<bool>visited(V,false);
        dfs(adj,visited,ans,0);
        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends