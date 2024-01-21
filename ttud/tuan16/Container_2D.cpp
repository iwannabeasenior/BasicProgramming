#include<bits/stdc++.h>
using namespace std;
const int M = 10000000;


struct Item {
    int w;
    int l;
    int rotation;
    int x, y, truck;
};
struct Truck {
    int W;
    int L;
    int c;
    vector<vector<bool>> usedSpace;
};
struct Best {
    int x, y, truck, rotation;
    Best(int _rotation) : rotation(_rotation){}
};

int N, K;
vector<Item> items;
vector<Best> bests;
vector<Truck> trucks;

int minCost = M;

void input() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        Item item = Item();
        cin >> item.w >> item.l; item.rotation = 0; item.truck = -1;
        items.push_back(item);
        Best best = Best(0);
        bests.push_back(best);
    }
    for (int i = 1; i <= K; i++) {
        Truck truck = Truck();
        cin >> truck.W >> truck.L >> truck.c;
        truck.usedSpace.resize(truck.W , vector<bool>(truck.L , false));
        trucks.push_back(truck);
    }
}

bool sortByAreaDesc(const Item& a, const Item& b) {
    return a.w*a.l > b.w*b.l;
}
bool sortTruck(const Truck& a, const Truck& b) {
    return (double)(a.W * a.L) / a.c > (double) (b.W * b.L) / b.c; 
}

bool canPlaceItem(Item& item, Truck& truck, int currentItem, int truckSelect) {                                                                                                                               

    for (int i = 0; i < truck.W; i++) {
        for (int j = 0; j < truck.L; j++) {
            if (i + item.w < truck.W && j + item.l < truck.L) {
                bool canPlace = true;
                for (int x = i; x < item.w + i; x++) {
                    for (int y = j; y < item.l + j; y++) {
                        if (truck.usedSpace[x][y]) {
                            canPlace = false;
                            break;
                        }
                    }
                    if (!canPlace) {
                        break;
                    }
                }
                if (canPlace) {
                    for (int x = i; x < item.w + i; x++) {
                        for (int y = j; y < item.l + j; y++) {
                            truck.usedSpace[x][y] = true;
                        }
                    }
                    item.x = i;
                    item.y = j;
                    item.truck = truckSelect;
                    item.rotation = 0;
                    return true;
                }
            }
        }
    }
    return false;
}


bool canPlaceItem2(Item& item, Truck& truck, int currentItem, int truckSelect) {                                                                                                                               
    for (int i = 0; i < truck.W; i++) {
        for (int j = 0; j < truck.L; j++) {
            if (i + item.l < truck.W && j + item.w < truck.L) {
                bool canPlace = true;
                for (int x = i; x < item.l + i; x++) {
                    for (int y = j; y < item.w + j; y++) {
                        if (truck.usedSpace[x][y]) {
                            canPlace = false;
                            break;
                        }
                    }
                    if (!canPlace) {
                        break;
                    }
                }
                if (canPlace) {
                    for (int x = i; x < item.l + i; x++) {
                        for (int y = j; y < item.w + j; y++) {
                            truck.usedSpace[x][y] = true;
                        }
                    }
                    item.x = i;
                    item.y = j;
                    item.truck = truckSelect;
                    item.rotation = 1;
                    return true;
                }
            }
        }
    }
    return false;
}

void removeItem(Item& item, Truck& truck) {

}

void loadItems(int currentItem, vector<int>& loadTrucks) {
    if (currentItem == items.size()) {
        int totalCost = 0;
        set<int> setLoadTrucks;
        for (auto truck : loadTrucks) {
            setLoadTrucks.insert(truck);
        }
        for (auto& truck : setLoadTrucks) {
            totalCost += trucks[truck].c;
        }
        if (totalCost < minCost) {
            minCost = totalCost;
            // cap nhat best
            for (int i = 0; i < items.size(); i++) {
                bests[i].x = items[i].x;
                bests[i].y = items[i].y;
                bests[i].rotation = items[i].rotation;
                bests[i].truck = items[i].truck;
            }
        }
        return;
    }
    int truckSelect = 0;
    for (auto& truck : trucks) {
        if (canPlaceItem(items[currentItem], truck, currentItem, truckSelect)) {\
            loadTrucks.push_back(truckSelect);
            loadItems(currentItem + 1, loadTrucks);
            // recover
            Item item  = items[currentItem];
            if (item.rotation = 0) {
                for (int i = item.x; i < item.w + item.x; i++) {
                    for (int j = item.y; j < item.l + item.y; j++) {
                        truck.usedSpace[i][j] = false;
                    }   
                }
            }
            
            item.rotation = 0;
            loadTrucks.pop_back();
        }
        else if (canPlaceItem2(items[currentItem], truck, currentItem, truckSelect)) {
            loadTrucks.push_back(truckSelect);
            loadItems(currentItem + 1, loadTrucks);
            // recover
            Item item  = items[currentItem];
            if (item.rotation = 1) {
                for (int i = item.x; i < item.l + item.x; i++) {
                    for (int j = item.y; j < item.w + item.y; j++) {
                        truck.usedSpace[i][j] = false;
                    }   
                }
            }
            
            item.rotation = 0;
            loadTrucks.pop_back();
        } 
        truckSelect++;
    }
}
int main() {
    input();
    vector<int> loadTrucks;
    // sort(items.begin(), items.end(), sortByAreaDesc);
    // sort(trucks.begin(), trucks.end(), sortTruck);
    loadItems(0, loadTrucks);
    int i = 1;
    for (auto& best : bests) {
        cout << i << " " <<  best.truck + 1 << " " << best.x << " " << best.y << " " << best.rotation << endl;
        i++;
    }
}