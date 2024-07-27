//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    // arr: input array
    int equilibriumPoint(vector<long long> &arr) {
        int sum =0 ;
        for(int i =0 ;i<arr.size();i++){
            sum+= arr[i];
        }
        int leftSum=0;
        // find eue pont
        for (int i = 0; i < arr.size(); ++i) {
        // If the left sum equals the sum on the right side
        if (leftSum == sum - leftSum - arr[i]) {
            return i + 1; // Return the equilibrium point (1-based indexing)
        }
        leftSum += arr[i]; // Update the left sum
    }
        
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<long long> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.equilibriumPoint(arr) << endl;
    }
}
// } Driver Code Ends