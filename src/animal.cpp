// Copyright 2024 HSE NN
// Author: Lev Pestov


#include "animal.h"

// default constructor
Animal::Animal() : mass(0.0), sex(nullptr), color(nullptr), age(0) {}

// initialization constructor
Animal::Animal(const float _mass, const char *_sex, const char *_color, const int64_t _age) : mass(_mass), age(_age) {
  sex = new char[strlen(_sex) + 1];
  snprintf(sex, strlen(_sex) + 1, "%s", _sex);
  color = new char[strlen(_color) + 1];
  snprintf(color, strlen(_color) + 1, "%s", _color);
}

// copy constructor
Animal::Animal(const Animal &other) : mass(other.mass), age(other.age) {
  sex = new char[strlen(other.sex) + 1];
  snprintf(sex, strlen(other.sex) + 1, "%s", other.sex);
  color = new char[strlen(other.color) + 1];
  snprintf(color, strlen(other.color) + 1, "%s", other.color);
}

// move constructor
Animal::Animal(Animal &&other) noexcept: mass(std::move(other.mass)), sex(std::move(other.sex)),
                                         color(std::move(other.color)), age(std::move(other.age)) {
  other.mass = 0.0;
  other.sex = nullptr;
  other.color = nullptr;
  other.age = 0;
}

// destructor
Animal::~Animal() {
  delete[] sex;
  delete[] color;
}
float Animal::GetMass() const {
  return mass;
}
char *Animal::GetSex() const {
  return sex;
}
uint64_t Animal::GetAge() const {
  return age;
}

char *Animal::GetColor() const {
  return color;
}

void Animal::SetMass(const float &_mass) {
  mass = _mass;
}
void Animal::SetSex(const char *_sex) {
  if (sex != nullptr) {
    delete[] sex;
  }
  sex = new char[strlen(_sex) + 1];
  snprintf(sex, strlen(_sex) + 1, "%s", _sex);
}
void Animal::SetAge(const int64_t &_age) {
  age = _age;
}

void Animal::SetColor(const char *_color) {
  delete[] color;
  color = new char[strlen(_color) + 1];
  snprintf(color, strlen(_color) + 1, "%s", _color);
}
// assignment operator
Animal &Animal::operator=(const Animal &other) {
  if (this == &other) {
    return *this;
  } else {
    mass = other.mass;
    age = other.age;
    SetColor(other.color);
    SetSex(other.sex);
    return *this;
  }
}

// move operator
Animal &Animal::operator=(Animal &&other) noexcept {
  if (this == &other) {
    return *this;
  } else {
    mass = std::move(other.mass);
    age = std::move(other.age);
    color = std::move(other.color);
    sex = std::move(other.sex);
    other.mass = 0.0;
    other.age = 0;
    other.color = nullptr;
    other.sex = nullptr;
    return *this;
  }
}

// default constructor (Assign the type depending on the generated number)
Dog::Dog() : Animal(), name(nullptr) {
  int64_t random_number = rand() % 9;
  race = static_cast<Breed>(random_number);
}

// initialization constructor
Dog::Dog(const char *_name, Breed _race, float _mass, const char *_sex, const char *_color, int64_t _age)
    : Animal(_mass, _sex, _color, _age), race(_race) {
  name = new char[strlen(_name) + 1];
  snprintf(name, strlen(_name) + 1, "%s", _name);
}

// copy constructor
Dog::Dog(const Dog &other) : Animal(other), race(other.race) {
  name = new char[strlen(other.name) + 1];
  snprintf(name, strlen(other.name) + 1, "%s", other.name);
}

// move constructor
Dog::Dog(Dog &&other) noexcept: Animal(std::move(other)), name(std::move(other.name)),
                                race(std::move(other.race)) {
  other.name = nullptr;
}

// destructor
Dog::~Dog() {
  delete[] name;
}

char *Dog::GetName() const {
  return name;
}

Breed Dog::GetRace() const {
  return race;
}

void Dog::SetName(const char *_name) {
  delete[] name;
  name = new char[strlen(_name) + 1];
  snprintf(name, strlen(_name) + 1, "%s", _name);
}

void Dog::SetRace(Breed _race) {
  race = _race;
}

// assignment operator
Dog &Dog::operator=(const Dog &other) {
  if (this == &other) {
    return *this;
  } else {
    Animal::operator=(other);
    SetName(other.name);
    race = other.race;
    return *this;
  }
}

// move operator
Dog &Dog::operator=(Dog &&other) noexcept {
  if (this == &other) {
    return *this;
  } else {
    Animal::operator=(std::move(other));
    name = std::move(other.name);
    race = std::move(other.race);
    other.name = nullptr;
    return *this;
  }
}

const char *Dog::WhatDoesSay() const {
  return "WOOOF!!!";
}

// default constructor (Assign the type depending on the generated number)
Fox::Fox() : Animal(), name(nullptr), numberRabbitsEaten(0) {
  int64_t random_number = rand() % 9;
  type = static_cast<TypeFox>(random_number);
}

// initialization constructor
Fox::Fox(const char *_name, TypeFox _type, float _mass, const char *_sex, const char *_color, int64_t _age)
    : Animal(_mass, _sex, _color, _age), type(_type), numberRabbitsEaten(0) {
  name = new char[strlen(_name) + 1];
  snprintf(name, strlen(_name) + 1, "%s", _name);
}

// copy constructor
Fox::Fox(const Fox &other) : Animal(other), type(other.type), numberRabbitsEaten(other.numberRabbitsEaten) {
  name = new char[strlen(other.name) + 1];
  snprintf(name, strlen(other.name) + 1, "%s", other.name);
}

// move constructor
Fox::Fox(Fox &&other) noexcept: Animal(std::move(other)), name(std::move(other.name)),
                                type(std::move(other.type)), numberRabbitsEaten(std::move(other.numberRabbitsEaten)) {
  other.name = nullptr;
}

// destructor
Fox::~Fox() {
  delete[] name;
}

char *Fox::GetName() const {
  return name;
}

TypeFox Fox::GetType() const {
  return type;
}

int64_t Fox::GetNumberRabbitsEaten() const {
  return numberRabbitsEaten;
}

void Fox::SetName(const char *_name) {
  delete[] name;
  name = new char[strlen(_name) + 1];
  snprintf(name, strlen(_name) + 1, "%s", _name);
}

void Fox::SetType(TypeFox _type) {
  type = _type;
}

void Fox::SetNumberRabbitsEaten(int64_t _numberRabbitsEaten) {
  numberRabbitsEaten = _numberRabbitsEaten;
}

void Fox::Eat() {
  numberRabbitsEaten++;
}

// assignment operator
Fox &Fox::operator=(const Fox &other) {
  if (this == &other) {
    return *this;
  } else {
    Animal::operator=(other);
    SetName(other.name);
    type = other.type;
    numberRabbitsEaten = other.numberRabbitsEaten;
    return *this;
  }
}

// move operator
Fox &Fox::operator=(Fox &&other) noexcept {
  if (this == &other) {
    return *this;
  } else {
    Animal::operator=(std::move(other));
    name = std::move(other.name);
    type = std::move(other.type);
    numberRabbitsEaten = std::move(other.numberRabbitsEaten);
    other.numberRabbitsEaten = 0;
    other.name = nullptr;
    return *this;
  }
}

const char *Fox::WhatDoesSay() const {
  switch (type) {
    case TypeFox::FennecFox:
      return "Ring-ding-ding-ding-dingeringeding!\n"
             "Gering-ding-ding-ding-dingeringeding!\n"
             "Gering-ding-ding-ding-dingeringeding!";
    case TypeFox::ArcticFox:
      return "Wa-pa-pa-pa-pa-pa-pow!\n"
             "Wa-pa-pa-pa-pa-pa-pow!\n"
             "Wa-pa-pa-pa-pa-pa-pow!";
    case TypeFox::RedFox:
      return "Hatee-hatee-hatee-ho!\n"
             "Hatee-hatee-hatee-ho!\n"
             "Hatee-hatee-hatee-ho!";
    case TypeFox::GrayFox:
      return "Joff-tchoff-tchoffo-tchoffo-tchoff!\n"
             "Tchoff-tchoff-tchoffo-tchoffo-tchoff!\n"
             "Joff-tchoff-tchoffo-tchoffo-tchoff!";
    case TypeFox::SwiftFox:
      return "Jacha-chacha-chacha-chow!\n"
             "Chacha-chacha-chacha-chow!\n"
             "Chacha-chacha-chacha-chow!";
  }
}

// overloading the output operator for dog::breed
std::ostream &operator<<(std::ostream &os, const Breed &breed) {
  switch (breed) {
    case Breed::Labrador: os << "Labrador";
      break;
    case Breed::GermanShepherd: os << "German Shepherd";
      break;
    case Breed::Bulldog: os << "Bulldog";
      break;
    case Breed::Beagle: os << "Beagle";
      break;
    case Breed::Poodle: os << "Poodle";
      break;
    case Breed::Rottweiler: os << "Rottweiler";
      break;
    case Breed::YorkshireTerrier: os << "Yorkshire Terrier";
      break;
    case Breed::Boxer: os << "Boxer";
      break;
    case Breed::Dachshund: os << "Dachshund";
      break;
    case Breed::SiberianHusky: os << "Siberian Husky";
      break;
    default: os << "Unknown Breed";
      break;
  }
  return os;
}

// overloading the output operator for fox::type
std::ostream &operator<<(std::ostream &os, const TypeFox &type) {
  switch (type) {
    case TypeFox::FennecFox: os << "Fennec Fox";
      break;
    case TypeFox::ArcticFox: os << "Arctic Fox";
      break;
    case TypeFox::RedFox: os << "Red Fox";
      break;
    case TypeFox::GrayFox: os << "Gray Fox";
      break;
    case TypeFox::SwiftFox: os << "Swift Fox";
      break;
    default: os << "Unknown Fox Type";
      break;
  }
  return os;
}