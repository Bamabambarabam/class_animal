// Copyright 2024 HSE NN
// Author: Lev Pestov

#include <iostream>
#include "animal.h"


int main() {
  // Create a Dog object
  Dog myDog("Max", Breed::Labrador, 30.0f, "Male", "Yellow", 5);

  // Display the dog's name and breed
  std::cout << "Dog's Name: " << myDog.GetName() << std::endl;
  std::cout << "Dog's Breed: ";

  switch(myDog.GetRace()) {
    case Breed::Labrador: std::cout << "Labrador"; break;
    case Breed::GermanShepherd: std::cout << "German Shepherd"; break;
    case Breed::Bulldog: std::cout << "Bulldog"; break;
    case Breed::Beagle: std::cout << "Beagle"; break;
    case Breed::Poodle: std::cout << "Poodle"; break;
    case Breed::Rottweiler: std::cout << "Rottweiler"; break;
    case Breed::YorkshireTerrier: std::cout << "Yorkshire Terrier"; break;
    case Breed::Boxer: std::cout << "Boxer"; break;
    case Breed::Dachshund: std::cout << "Dachshund"; break;
    case Breed::SiberianHusky: std::cout << "Siberian Husky"; break;
  }

  std::cout << std::endl;

  // Call the WhatDoesSay method
  std::cout << "Dog says: " << myDog.WhatDoesSay() << std::endl;

  // Change the dog's name and breed
  myDog.SetName("Buddy");
  myDog.SetRace(Breed::Beagle);

  // Display the updated dog's name and breed
  std::cout << "Updated Dog's Name: " << myDog.GetName() << std::endl;
  std::cout << "Updated Dog's Breed: ";

  switch(myDog.GetRace()) {
    case Breed::Labrador: std::cout << "Labrador"; break;
    case Breed::GermanShepherd: std::cout << "German Shepherd"; break;
    case Breed::Bulldog: std::cout << "Bulldog"; break;
    case Breed::Beagle: std::cout << "Beagle"; break;
    case Breed::Poodle: std::cout << "Poodle"; break;
    case Breed::Rottweiler: std::cout << "Rottweiler"; break;
    case Breed::YorkshireTerrier: std::cout << "Yorkshire Terrier"; break;
    case Breed::Boxer: std::cout << "Boxer"; break;
    case Breed::Dachshund: std::cout << "Dachshund"; break;
    case Breed::SiberianHusky: std::cout << "Siberian Husky"; break;
  }

  std::cout << std::endl;
  return 0;
}
