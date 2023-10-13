#include <algorithm>
#include <map>
#include<iostream>
using namespace std;
int main() {
  // Create a map.
  std::map<int, std::string> mymap = {
    {1, "a"},
    {2, "b"},
    {3, "c"}
  };

  // Create a comparator function.
  auto cmp = [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
    return a.second < b.second;
  };

  // Sort the map by value.
  std::sort(mymap.begin(), mymap.end(), cmp);

  // Print the sorted map.
  for (auto it = mymap.begin(); it != mymap.end(); it++) {
   cout << it->first << ": " << it->second << endl;
  }

  return 0;
}