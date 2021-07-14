#include "boost/circular_buffer.hpp"

#include <cstdlib>
#include <iostream>

#define EXPECT_EQ(actual, expected)                                  \
  do {                                                               \
    if ((actual) != (expected)) {                                    \
      std::cerr << "Expected=" << (expected) << ", Got=" << (actual) \
                << std::endl;                                        \
      exit(1);                                                       \
    }                                                                \
  } while (0)

int main() {
  constexpr int kSize = 3;
  boost::circular_buffer<int> cb(kSize);
  EXPECT_EQ(cb.capacity(), kSize);
  cb.push_back(1);
  EXPECT_EQ(cb.size(), 1);
  cb.push_back(2);
  cb.push_back(3);
  EXPECT_EQ(cb.size(), kSize);
  cb.push_back(4);
  cb.push_back(5);
  EXPECT_EQ(cb.size(), kSize);
  EXPECT_EQ(cb.capacity(), kSize);
  EXPECT_EQ(cb[0], 3);
  EXPECT_EQ(cb[2], 5);
  cb.pop_back();
  EXPECT_EQ(cb.size(), kSize - 1);
  cb.pop_front();
  EXPECT_EQ(cb.size(), kSize - 2);
  EXPECT_EQ(cb[0], 4);
  return 0;
}
