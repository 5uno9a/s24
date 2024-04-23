#include <iostream>
#include <vector>

using namespace std;

class Coord {
  int x=-1, y=-1;

public:
  Coord() {
    //cout << "Construct Coord!\n";
  }

  Coord(int x, int y) : x(x), y(y) {
    //cout << "Construct Coord!\n";
  }

  // Coord(const Coord& other) = delete;  
  Coord(const Coord& other) : x(other.x), y(other.y) {
    cout << "Copy Constructor!\n";
  }

  ~Coord() {
    //cout << "Destruct Coord!\n";
  }
  
  friend ostream& operator<<(ostream& os, const Coord& coord);
};

ostream& operator<<(ostream& os, const Coord& coord) {
  os << "Coord(" << coord.x << "," << coord.y << ")";
  return os;
}

int main() {
  vector<Coord> items;
  items.reserve(3);
  cout << items.size() << " " << items.capacity() << " " << &items[0] << "\n";
  items.emplace_back(1,2);
  items.emplace_back(3,4);
  items.emplace_back(4,5);
  cout << items.size() << " " << items.capacity() << " " << &items[0] << "\n";
}
