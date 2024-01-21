#include<bits/stdc++.h>
using namespace std; 

class Object {
public:
    string ID, DIRECTION;
    int x, y, LX, LY, r, SPEED;
    Object(string _ID, int _x, int _y, int _LX, int _LY, string _DIRECTION, int _SPEED) : ID(_ID), x(_x), y(_y), LX(_LX), LY(_LY), DIRECTION(_DIRECTION), SPEED(_SPEED) {}
    Object(string _ID, int _x, int _y, int _r, string _DIRECTION, int _SPEED) : ID(_ID), x(_x), y(_y), r(_r), DIRECTION(_DIRECTION), SPEED(_SPEED) {}
    Object(){}
};

unordered_map<string, Object> objects;
void changeDirection(string id, string direction, int speed) {
    Object object = objects[id];
    object.DIRECTION = direction;
    object.SPEED = speed;
}
void viewPosition(string id) {
    Object object = objects[id];
    cout << object.x << " " << object.y << endl;
}
bool checkCollisiton(string id) {
    Object object1 = objects[id];
    for (auto& pair : objects) {
        if (pair.first != id) {
            
        }
    }
    return true;
}
void move() {
    vector<Object> canMove;
    for (auto& pair : objects) {
        if (checkCollisiton(pair.first)) {
            canMove.push_back(pair.second);
        }
    }
    for (auto& object : canMove) {
        string direction = object.DIRECTION;
        if (direction == "U") {
            object.y += object.SPEED;
        } else if (direction == "D") {
            object.y -= object.SPEED;
        } else if (direction == "L") {
            object.x -= object.SPEED;
        } else {
            object.x += object.SPEED;
        }
    }
}


int  main() {
    string query;
    string nameQuery;
    string nameShape;
    string id;
    int x, y;
    int LX, LY, r;
    string direction;
    int speed;
    
    getline(cin, query);
    while (query != "#") {
        stringstream ss(query);
        ss >> nameQuery;
        cout << nameQuery << endl;
        if (nameQuery == "create") {
            ss >> nameShape;
            if (nameShape == "RETANGLE") {
                ss >> id >> x >> y >> LX >> LY >> direction >> speed;
                objects[id] = Object(id, x, y, LX, LY, direction, speed);
            } else {
                ss >> id >> x >> y >> r >> direction >> speed;
                objects[id] = Object(id, x, y, r, direction, speed);
            }
        } else if (nameQuery == "change_direction") {
            ss >> id >> direction >> speed;
            changeDirection(id, direction, speed);
        } else if (nameQuery == "view_position") {
            ss >> id;
            viewPosition(id);
        } else if (nameQuery == "move") {

        }
        getline(cin, query);
        cout <<"query la : " << query << endl;
    }
}