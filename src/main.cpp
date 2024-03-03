// Copyright 2024 HSE NN
// Author: Lev Pestov

#include <iostream>
#include "animal.h"


int main() {
  std::cout << "Hello, World!" << std::endl;
  Animal dog(6.6, "male", "brown", 5);
  Animal dog2(8, "female", "white", 3);
  dog = std::move(dog2);
  std::cout << dog.GetSex() << std::endl;
  return 0;
}
