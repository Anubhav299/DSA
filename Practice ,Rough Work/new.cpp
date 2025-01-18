#include <bits/stdc++.h>
using namespace std;

// Function to calculate Manhattan distance
int manhattanDist(vector<int>& a, vector<int>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int solution(vector<vector<int>>& points) {
    int n = points.size();
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // Start with the first point
    pq.push({0, 0}); // {cost, point_index}
    int totalCost = 0;
    int edgesUsed = 0;

    while (edgesUsed < n) {
        // Extract the edge with the smallest cost
        pair<int, int> topElement = pq.top();
        pq.pop();
        int cost = topElement.first;
        int current = topElement.second;

        // Skip if already visited
        if (visited[current]) continue;

        // Add cost to the total and mark as visited
        totalCost += cost;
        visited[current] = true;
        edgesUsed++;

        // Add all unvisited neighbors to the priority queue
        for (int next = 0; next < n; next++) {
            if (!visited[next]) {
                int dist = manhattanDist(points[current], points[next]);
                pq.push({dist, next});
            }
        }
    }

    return totalCost;
}

// Example Usage
int main() {
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << solution(points) << endl; // Output: 18
    return 0;
}
