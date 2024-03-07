// Copyright 2024 HSE NN
// Author: Lev Pestov


#include "animal.h"

// конструктор по-умолчанию
Animal::Animal() : mass(0.0), sex(nullptr), color(nullptr), age(0) {}

// конструктор инциализации
Animal::Animal(const float _mass, const char *_sex, const char *_color, const int64_t _age) : mass(_mass), age(_age) {
  sex = new char[strlen(_sex) + 1];
  snprintf(sex, strlen(_sex) + 1, "%s", _sex);
  color = new char[strlen(_color) + 1];
  snprintf(color, strlen(_color) + 1, "%s", _color);
}

// конструктор копирования
Animal::Animal(const Animal &other) : mass(other.mass), age(other.age) {
  sex = new char[strlen(other.sex) + 1];
  snprintf(sex, strlen(other.sex) + 1, "%s", other.sex);
  color = new char[strlen(other.color) + 1];
  snprintf(color, strlen(other.color) + 1, "%s", other.color);
}

// конструктор перемещения
Animal::Animal(Animal &&other) noexcept: mass(std::move(other.mass)), sex(std::move(other.sex)),
                                         color(std::move(other.color)), age(std::move(other.age)) {
  other.mass = 0.0;
  other.sex = nullptr;
  other.color = nullptr;
  other.age = 0;
}

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
// оператор присваивания
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

// оператор перемещения
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

// конструктор по-умолчанию (Присваиваем породу в зависимости от сгенерированного числа)
Dog::Dog() : Animal(), name(nullptr) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, 9);
  int random_number = distrib(gen);
  race = static_cast<Breed>(random_number);
}

// конструктор инициализации
Dog::Dog(const char* _name, Breed _race, float _mass, const char* _sex, const char* _color, int64_t _age)
    : Animal(_mass, _sex, _color, _age), race(_race) {
  name = new char[strlen(_name) + 1];
  snprintf(name, strlen(_name) + 1, "%s", _name);
}

// конструктор копирования
Dog::Dog(const Dog& other) : Animal(other), race(other.race) {
  name = new char[strlen(other.name) + 1];
  snprintf(name, strlen(other.name) + 1, "%s", other.name);
}

// конструктор перемещения
Dog::Dog(Dog&& other) noexcept : Animal(std::move(other)), name(std::move(other.name)), race(std::move(other.race)) {
  other.name = nullptr;
}

// деструктор
Dog::~Dog() {
  delete[] name;
}

// оператор присваивания
Dog& Dog::operator=(const Dog& other) {
  if (this == &other) {
    return *this;
  } else {
    Animal::operator=(other);
    SetName(other.name);
    race = other.race;
    return *this;
  }
}

// оператор перемещения
Dog& Dog::operator=(Dog&& other) noexcept {
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


char* Dog::GetName() const {
  return name;
}

Breed Dog::GetRace() const {
  return race;
}

void Dog::SetName(const char* _name) {
  delete[] name;
  name = new char[strlen(_name) + 1];
  snprintf(name, strlen(_name) + 1, "%s", _name);
}

void Dog::SetRace(Breed _race) {
  race = _race;
}

const char* Dog::WhatDoesSay() const {
  return "WOOOF!!!";
}


