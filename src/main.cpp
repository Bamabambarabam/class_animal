// Copyright 2024 HSE NN
// Author: Lev Pestov

#include <iostream>
#include "animal.h"

int main() {
  // Test Dog class
  std::cout << "--< test 1 >--\n";
  Dog dog_1("Max", Breed::Labrador, 30.0f, "Male", "Yellow", 5);
  std::cout << "Dog's Name: " << dog_1.GetName() << std::endl;
  std::cout << "Dog's Race: " << dog_1.GetRace() << std::endl;
  std::cout << "Dog's Mass: " << dog_1.GetMass() << std::endl;
  std::cout << "Dog's Sex: " << dog_1.GetSex() << std::endl;
  std::cout << "Dog's Age: " << dog_1.GetAge() << std::endl;
  std::cout << "Dog's Color: " << dog_1.GetColor() << std::endl;
  std::cout << "Dog says: " << dog_1.WhatDoesSay() << std::endl;

  std::cout << "--< add another dog >--\n";

  Dog dog_2("Buddy", Breed::Beagle, 25.0f, "Female", "Black", 4);
  std::cout << "Dog's Name: " << dog_2.GetName() << std::endl;
  std::cout << "Dog's Race: " << dog_2.GetRace() << std::endl;
  std::cout << "Dog's Mass: " << dog_2.GetMass() << std::endl;
  std::cout << "Dog's Sex: " << dog_2.GetSex() << std::endl;
  std::cout << "Dog's Age: " << dog_2.GetAge() << std::endl;
  std::cout << "Dog's Color: " << dog_1.GetColor() << std::endl;
  std::cout << "Dog says: " << dog_2.WhatDoesSay() << std::endl;

  // Test Fox class
  std::cout << "--< test 2 >--\n";
  Fox fox_1("Foxy", TypeFox::FennecFox, 20.0f, "Male", "Red", 3);
  std::cout << "Fox's Name: " << fox_1.GetName() << std::endl;
  std::cout << "Fox's Type: " << fox_1.GetType() << std::endl;
  std::cout << "Fox's Mass: " << fox_1.GetMass() << std::endl;
  std::cout << "Fox's Sex: " << fox_1.GetSex() << std::endl;
  std::cout << "Fox's Age: " << fox_1.GetAge() << std::endl;
  std::cout << "Fox's Color: " << fox_1.GetColor() << std::endl;
  std::cout << "Fox says: " << fox_1.WhatDoesSay() << std::endl;

  std::cout << "--< add another fox >--\n";

  Fox fox_2("Swift", TypeFox::SwiftFox, 15.0f, "Female", "White", 2);
  std::cout << "Fox's Name: " << fox_2.GetName() << std::endl;
  std::cout << "Fox's Type: " << fox_2.GetType() << std::endl;
  std::cout << "Fox's Mass: " << fox_2.GetMass() << std::endl;
  std::cout << "Fox's Sex: " << fox_2.GetSex() << std::endl;
  std::cout << "Fox's Age: " << fox_2.GetAge() << std::endl;
  std::cout << "Fox's Color: " << fox_2.GetColor() << std::endl;
  std::cout << "Fox says: " << fox_2.WhatDoesSay() << std::endl;


  // Test eating behavior
  std::cout << "--< test 3 >--\n";
  for (int i = 0; i < 5; ++i) {
    fox_1.Eat();
  }

  for (int i = 0; i < 10; ++i) {
    fox_2.Eat();
  }
  std::cout << "fox_1 has eaten " << fox_1.GetNumberRabbitsEaten() << " rabbit(s)" << std::endl;
  std::cout << "fox_2 has eaten " << fox_2.GetNumberRabbitsEaten() << " rabbit(s)" << std::endl;

  // Test setters for Dog class
  std::cout << "--< test 4 >--\n";
  dog_1.SetName("Charlie");
  dog_1.SetRace(Breed::Bulldog);
  dog_1.SetMass(35.0f);
  dog_1.SetSex("Male");
  dog_1.SetColor("Black");
  dog_1.SetAge(6);
  std::cout << "After setters, Dog's Name: " << dog_1.GetName() << std::endl;
  std::cout << "After setters, Dog's Race: " << dog_1.GetRace() << std::endl;
  std::cout << "After setters, Dog's Mass: " << dog_1.GetMass() << std::endl;
  std::cout << "After setters, Dog's Sex: " << dog_1.GetSex() << std::endl;
  std::cout << "After setters, Dog's Age: " << dog_1.GetAge() << std::endl;
  std::cout << "After setters, Dog's Color: " << dog_1.GetColor() << std::endl;

  // Test setters for Fox class
  std::cout << "--< test 5 >--\n";
  fox_1.SetName("Snowy");
  fox_1.SetType(TypeFox::ArcticFox);
  fox_1.SetMass(25.0f);
  fox_1.SetSex("Female");
  fox_1.SetColor("White");
  fox_1.SetAge(4);
  fox_1.SetNumberRabbitsEaten(10);
  std::cout << "After setters, Fox's Name: " << fox_1.GetName() << std::endl;
  std::cout << "After setters, Fox's Type: " << fox_1.GetType() << std::endl;
  std::cout << "After setters, Fox's Mass: " << fox_1.GetMass() << std::endl;
  std::cout << "After setters, Fox's Sex: " << fox_1.GetSex() << std::endl;
  std::cout << "After setters, Fox's Age: " << fox_1.GetAge() << std::endl;
  std::cout << "After setters, Fox's Color: " << fox_1.GetColor() << std::endl;
  std::cout << "After setters, Fox's Number of Rabbits Eaten: " << fox_1.GetNumberRabbitsEaten() << std::endl;

  // Test constructors and operators for Dog class
  std::cout << "--< test 6 >--\n";
  Dog dog_3("Max", Breed::Labrador, 30.0f, "Male", "Yellow", 5);
  std::cout << "After initialization, Dog's Name: " << dog_3.GetName() << std::endl;
  Dog dog_4(dog_3); // Copy constructor
  std::cout << "After copy, Dog's Name: " << dog_4.GetName() << std::endl;
  Dog dog_5(std::move(dog_4)); // Move constructor
  std::cout << "After move, Dog's Name: " << dog_5.GetName() << std::endl;
  Dog dog_6 = dog_3; // Copy assignment operator
  std::cout << "After copy assignment, Dog's Name: " << dog_6.GetName() << std::endl;
  Dog dog_7 = std::move(dog_6); // Move assignment operator
  std::cout << "After move assignment, Dog's Name: " << dog_7.GetName() << std::endl;

  // Test constructors and operators for Fox class
  std::cout << "--< test 7 >--\n";
  Fox fox_3("Foxy", TypeFox::RedFox, 20.0f, "Female", "Red", 3);
  std::cout << "After initialization, Fox's Name: " << fox_3.GetName() << std::endl;
  Fox fox_4(fox_3); // Copy constructor
  std::cout << "After copy, Fox's Name: " << fox_4.GetName() << std::endl;
  Fox fox_5(std::move(fox_4)); // Move constructor
  std::cout << "After move, Fox's Name: " << fox_5.GetName() << std::endl;
  Fox fox_6 = fox_3; // Copy assignment operator
  std::cout << "After copy assignment, Fox's Name: " << fox_6.GetName() << std::endl;
  Fox fox_7 = std::move(fox_6); // Move assignment operator
  std::cout << "After move assignment, Fox's Name: " << fox_7.GetName() << std::endl;
  return 0;
}
