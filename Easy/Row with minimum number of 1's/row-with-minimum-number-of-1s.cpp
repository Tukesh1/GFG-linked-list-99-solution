//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> matrix) {
        // code here
        // tranverse in row and maintain no of ones 
    int minOnes = INT_MAX;
    int minOnesRow = -1;
    
    for (int i = 0; i < matrix.size(); ++i) {
        int onesCount = 0;
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == 1) {
                ++onesCount;
            }
        }
        if (onesCount < minOnes) {
            minOnes = onesCount;
            minOnesRow = i;
        }
    }
    
    return minOnesRow+1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
// } Driver Code Ends