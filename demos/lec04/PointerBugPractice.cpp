#include <iostream>

using namespace std;

int* bigger(int* x, int *y) {
  int* result{nullptr};

  if (*x > *y)
    result = x;
  else if (*y > *x)
    result = y;
else 
    result = x;
    
  return result;
}
  
int main() {
  int a{4};
  int b{4};
  int *biggest = bigger(&a, &b);
  cout << "the biggest num is " << *biggest << "\n";
}