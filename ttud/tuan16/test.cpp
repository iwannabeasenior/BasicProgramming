#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int id;
    int width;
    int height;
    int rotation;  // 0 for no rotation, 1 for 90-degree rotation

    Item(int i, int w, int h, int r) : id(i), width(w), height(h), rotation(r) {}
};

struct Truck {
    int id;
    int width;
    int height;
    int cost;

    Truck(int i, int w, int h, int c) : id(i), width(w), height(h), cost(c) {}
};

bool sortByAreaDesc(const Item& a, const Item& b) {
    return a.width * a.height > b.width * b.height;
}

bool canPlaceItem(const Item& item, const Truck& truck, const std::vector<std::vector<bool>>& usedSpace) {
    for (int i = 0; i < truck.width; ++i) {
        for (int j = 0; j < truck.height; ++j) {
            if (i + item.width <= truck.width && j + item.height <= truck.height) {
                bool canPlace = true;
                for (int x = i; x < i + item.width; ++x) {
                    for (int y = j; y < j + item.height; ++y) {
                        if (usedSpace[x][y]) {
                            canPlace = false;
                            break;
                        }
                    }
                    if (!canPlace) break;
                }
                if (canPlace) {
                    return true;
                }
            }
        }
    }
    return false;
}

void placeItem(const Item& item, const Truck& truck, std::vector<std::vector<bool>>& usedSpace) {
    for (int i = 0; i < item.width; ++i) {
        for (int j = 0; j < item.height; ++j) {
            usedSpace[i][j] = true;
        }
    }
}

void removeItem(const Item& item, std::vector<std::vector<bool>>& usedSpace) {
    for (int i = 0; i < item.width; ++i) {
        for (int j = 0; j < item.height; ++j) {
            usedSpace[i][j] = false;
        }
    }
}

void loadItems(int currentItem, std::vector<Item>& items, std::vector<Truck>& trucks,
               std::vector<std::vector<bool>>& usedSpace, int& minCost, std::vector<int>& bestAssignment) {
    if (currentItem == items.size()) {
        // Calculate total cost
        int totalCost = 0;
        for (const auto& truck : trucks) {
            totalCost += truck.cost;
        }

        // Update the minimum cost and best assignment
        if (totalCost < minCost) {
            minCost = totalCost;
            bestAssignment.resize(items.size());
            for (size_t i = 0; i < items.size(); ++i) {
                bestAssignment[i] = items[i].rotation;
            }
        }

        return;
    }

    for (const auto& truck : trucks) {
        if (canPlaceItem(items[currentItem], truck, usedSpace)) {
            placeItem(items[currentItem], truck, usedSpace);
            truck.cost += truck.id;  // Adjust the cost based on the truck id
            loadItems(currentItem + 1, items, trucks, usedSpace, minCost, bestAssignment);
            truck.cost -= truck.id;  // Backtrack the cost adjustment
            removeItem(items[currentItem], usedSpace);
        }
    }
}

int main() {
    // Example data
    std::vector<Item> items = {{1, 3, 5, 0}, {2, 4, 6, 0}, {3, 2, 3, 0}, {4, 5, 4, 0}};
    std::vector<Truck> trucks = {{1, 8, 8, 0}, {2, 6, 6, 0}};

    // Sort items by area in descending order
    std::sort(items.begin(), items.end(), sortByAreaDesc);

    // Create a matrix to represent used space
    std::vector<std::vector<bool>> usedSpace(trucks[0].width, std::vector<bool>(trucks[0].height, false));

    // Variables to store the best assignment
    int minCost = std::numeric_limits<int>::max();
    std::vector<int> bestAssignment;

    // Load items into trucks
    loadItems(0, items, trucks, usedSpace, minCost, bestAssignment);

    // Output the results
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << "Item " << items[i].id << " (Rotation: " << bestAssignment[i] << ") is loaded in Truck " << trucks[i].id << std::endl;
    }

    return 0;
}
