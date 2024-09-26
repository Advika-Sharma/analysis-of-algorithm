#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

// Function to solve the 0/1 Knapsack problem

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {

// Create a 1D DP array to store the maximum value at each weight limit

vector<int> dp(W+1, 0);

// Loop through each item

for (int i=0; i < n; i++){

// Traverse the DP array from right to left

for (int w = W; w>= weights[1]; w--) {

dp[w]=max(dp[w], dp[w weights[i]] + values[i]);

}}
return dp[W];}

// The last element will hold the maximum value for weight limit W return dp[W];

int main(){

// Example usage

Int W 11; // Maximum weight

vector<int> weights (2,3,3); // Weights of the items vertor<int> values (1,2,4); // Values of the items

intin values size(); // Humber of items

int maxValue knapsack(W, weights, values, n);

cout << "Maximum value in the knapsack"<< maxValue << endl;

return 0;
}
