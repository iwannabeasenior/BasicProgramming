#include <iostream>
#include <vector>
#include <algorithm>

// Function to calculate the total distance of a tour
double calculateTotalDistance(const std::vector<int>& tour, const std::vector<std::vector<double>>& distances) {
    double totalDistance = 0.0;
    for (size_t i = 0; i < tour.size() - 1; ++i) {
        totalDistance += distances[tour[i]][tour[i + 1]];
    }
    totalDistance += distances[tour.back()][tour.front()]; // Return to the starting city
    return totalDistance;
}

// 2-opt algorithm to optimize a TSP tour
std::vector<int> twoOpt(const std::vector<int>& initialTour, const std::vector<std::vector<double>>& distances) {
    std::vector<int> improvedTour = initialTour;
    bool improvement = true;

    while (improvement) {
        improvement = false;

        for (size_t i = 1; i < improvedTour.size() - 1; ++i) {
            for (size_t j = i + 1; j < improvedTour.size(); ++j) {
                std::vector<int> newTour = improvedTour;
                std::reverse(newTour.begin() + i, newTour.begin() + j);

                double initialDistance = calculateTotalDistance(improvedTour, distances);
                double newDistance = calculateTotalDistance(newTour, distances);

                if (newDistance < initialDistance) {
                    improvedTour = newTour;
                    improvement = true;
                }
            }
        }
    }

    return improvedTour;
}

int main() {
    // Example distance matrix
    std::vector<std::vector<double>> distanceMatrix = {
        {0, 2, 9, 10},
        {1, 0, 6, 4},
        {15, 7, 0, 8},
        {6, 3, 12, 0}
    };

    // Initial tour (greedy, for example)
    std::vector<int> initialTour = {0, 1, 2, 3};

    // Optimize the tour using 2-opt
    std::vector<int> optimizedTour = twoOpt(initialTour, distanceMatrix);

    // Print the optimized tour
    std::cout << "Optimized TSP Tour: ";
    for (int vertex : optimizedTour) {
        std::cout << vertex << " ";
    }
    std::cout << "\n";

    return 0;
}
