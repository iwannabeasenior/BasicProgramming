#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

// Hàm in ma trận
void printMatrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double distance : row) {
            std::cout << distance << "\t";
        }
        std::cout << std::endl;
    }
}

// Hàm greedy TSP
std::vector<int> greedyTSP(const std::vector<std::vector<double>>& distances) {
    int n = distances.size();
    std::vector<int> tour;
    std::vector<bool> visited(n, false);

    // Bắt đầu từ đỉnh 0
    int currentVertex = 0;
    tour.push_back(currentVertex);
    visited[currentVertex] = true;

    // Du lịch các đỉnh còn lại
    for (int i = 1; i < n; ++i) {
        int nextVertex = -1;
        double minDistance = std::numeric_limits<double>::max();

        // Tìm đỉnh chưa được thăm gần nhất
        for (int j = 0; j < n; ++j) {
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
    // Ma trận khoảng cách giữa các đỉnh
    std::vector<std::vector<double>> distanceMatrix = {
        {0, 2, 9, 10},
        {1, 0, 6, 4},
        {15, 7, 0, 8},
        {6, 3, 12, 0}
    };

    std::cout << "Distance Matrix:" << std::endl;
    printMatrix(distanceMatrix);

    std::vector<int> tour = greedyTSP(distanceMatrix);

    std::cout << "\nGreedy TSP Tour: ";
    for (int vertex : tour) {
        std::cout << vertex << " ";
    }
    std::cout << "\n";

    return 0;
}
