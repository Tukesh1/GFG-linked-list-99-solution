//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    void bfs(vector<int> adj[],vector<bool>&visited,
        vector<int>&result, int src){
            
            queue<int>q;
            q.push(src);
            result.push_back(src);
             visited[src]= true;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto &v:adj[u]){
                    if(visited[v]==false){
                        q.push(v);
                         visited[v]= true;
                        result.push_back(v);
                    }
                }
            }
            
        }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // bfs here
        vector<bool>visited(V,false);
        vector<int>result;
         bfs(adj,visited,result,0);
        return result;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends