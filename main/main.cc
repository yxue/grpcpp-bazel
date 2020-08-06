#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;
  for (int i = 0; i < 10; ++i) {
    vec.push_back(i);
  }

  std::for_each(vec.begin(), vec.end(),
                [](const int x) { std::cout << x << std::endl; });

  return 0;
}
