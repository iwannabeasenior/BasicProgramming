#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX_N = 10000;

int n, K, Q;
vector<int> demand(MAX_N, 0);
vector<vector<int>> distanceMatrix(MAX_N + 1, vector<int>(MAX_N + 1, 0));
vector<vector<int>> bestRoutes;
vector<int> currentRoute;
vector<bool> visited(MAX_N + 1, false);
int bestDistance = INT_MAX;

void backtrack(int truck, int currentDistance, int currentLoad) {
    if (truck == K) {
        // All trucks have been assigned a route
        if (currentDistance < bestDistance) {
            bestDistance = currentDistance;
            bestRoutes.push_back(currentRoute);
        }
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            // Customer i is not visited in the current route
            int newDistance = currentDistance + distanceMatrix[currentRoute.back()][i];
            int newLoad = currentLoad + demand[i];

            if (newDistance <= Q && newLoad <= Q) {
                currentRoute.push_back(i);
                visited[i] = true;
                backtrack(truck, newDistance, newLoad);
                currentRoute.pop_back();
                visited[i] = false;
            }
        }
    }

    // Move to the next truck
    currentRoute.push_back(0); // Adding the depot to separate routes
    backtrack(truck + 1, currentDistance, 0);
    currentRoute.pop_back(); // Removing the depot for backtracking
}

int main() {
    // Read input
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; ++i) {
        cin >> demand[i];
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cin >> distanceMatrix[i][j];
        }
    }

    // Start the backtracking algorithm
    backtrack(0, 0, 0);

    // Display the result
    cout << "Minimal total travel distance: " << bestDistance << endl;
    cout << "Best Routes:\n";
    // for (const vector<int>& route : bestRoutes) {
    //     for (int i : route) {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
