#include <iostream>
#include <cstddef>

int main() {
  int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
  std::cout << ia[0][0] << std::endl;
  size_t cnt = 0;
  for (auto &row : ia) 
    for (auto &col : row) {
      std::cout << "before: "<< col;
      col = cnt;
      ++cnt;
      std::cout << ", after: " << col << std::endl;
    }
  
  for (const auto &row : ia) {
    for (auto col : row) {
      std::cout << col << ",";
    }
  }
  std::cout << std::endl;
  for (auto &row : ia) {
    for (auto col : row) {
      std::cout << col << std::endl;
    }
  }
  return (0);
}
