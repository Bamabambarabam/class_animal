// Copyright 2024 HSE NN
// Author: Lev Pestov

#pragma once

#include <string>
#include <cstdint>
#include <typeinfo>
#include <iostream>
#include <cctype>
#include <cstring>
#include <random>

#ifndef CLASS_ANIMAL_INCLUDE_ANIMAL_H_
#define CLASS_ANIMAL_INCLUDE_ANIMAL_H_



class Animal{

 protected:
  float mass;
  char* sex;
  char* color;
  int64_t age;
 public:
  Animal();
  Animal(float _mass, const char* _sex, const char* _color, int64_t _age);
  Animal(const Animal& other);
  Animal(Animal&& other) noexcept;
  virtual ~Animal();
  float GetMass() const;
  char* GetSex() const;
  uint64_t GetAge() const;
  char* GetColor() const;


  void SetMass(const float& mass);
  void SetSex(const char* sex);
  void SetAge(const int64_t& age);
  void SetColor(const char* color);
  virtual const char* WhatDoesSay() const = 0;

  Animal& operator=(const Animal& other);

  Animal& operator=(Animal&& other) noexcept;
};

enum class Breed {
  Labrador,
  GermanShepherd,
  Bulldog,
  Beagle,
  Poodle,
  Rottweiler,
  YorkshireTerrier,
  Boxer,
  Dachshund,
  SiberianHusky
};


class Dog : public Animal {
 private:
  char* name;
  Breed race;
 public:
  Dog();
  Dog(const char* _name, Breed _race, float _mass, const char* _sex, const char* _color, int64_t _age);
  Dog(const Dog& other);
  Dog(Dog&& other) noexcept;
  ~Dog();


  char* GetName() const;
  Breed GetRace() const;

  void SetName(const char* _name);
  void SetRace(Breed _race);


  Dog& operator=(const Dog& other);
  Dog& operator=(Dog&& other) noexcept;

  const char* WhatDoesSay() const override;
};








#endif //CLASS_ANIMAL_INCLUDE_ANIMAL_H_
