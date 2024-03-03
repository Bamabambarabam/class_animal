// Copyright 2024 HSE NN
// Author: Lev Pestov

#pragma once

#include <string>
#include <cstdint>
#include <typeinfo>
#include <iostream>
#include <cctype>
#include <cstring>

#ifndef CLASS_ANIMAL_INCLUDE_ANIMAL_H_
#define CLASS_ANIMAL_INCLUDE_ANIMAL_H_



class Animal{

 protected:
  float mass;
  char* sex;
  char* color;
  int age;
 public:
  Animal();
  Animal(float _mass, const char* _sex, const char* _color, int _age);
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
  //virtual const char* WhatDoesSay() const = 0;

  Animal& operator=(const Animal& other);

  Animal& operator=(Animal&& other) noexcept;
};









#endif //CLASS_ANIMAL_INCLUDE_ANIMAL_H_
