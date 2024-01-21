#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
int result = 0;
int n;
int distances[10000][10000];
// Hàm in ma trận

// Hàm greedy TSP
std::vector<int> greedyTSP() {
    std::vector<int> tour;
    std::vector<bool> visited(n+1, false);

    // Bắt đầu từ đỉnh 0
    int currentVertex = 1;
    tour.push_back(currentVertex);
    visited[currentVertex] = true;

    // Du lịch các đỉnh còn lại
    for (int i = 2; i <= n; ++i) {
        int nextVertex = -1;
        int minDistance = std::numeric_limits<int>::max();

        // Tìm đỉnh chưa được thăm gần nhất
        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && distances[currentVertex][j] < minDistance) {
                minDistance = distances[currentVertex][j];
                nextVertex = j;
            }
        }

        // Di chuyển đến đỉnh chưa được thăm gần nhất
        currentVertex = nextVertex;
        tour.push_back(currentVertex);
        visited[currentVertex] = true;
    }

    return tour;
}

int main() {
    int n;
    std :: cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std :: cin >> distances[i][j];
        }
    }
    // Ma trận khoảng cách giữa các đỉnh
 
    std::vector<int> tour = greedyTSP();

    for (int vertex : tour) {
        std::cout << vertex << " ";
    }
    std::cout << "\n";

    return 0;
}
