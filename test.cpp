#include "test.h"
#include "Movie.h"
#include "Wordsequence.h"
#include "personen.h"
#include <cassert>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>

void test_1() {
  std::string Firstname = "Max";
  std::string Lastname = "Schopf";
  hfu::Person A(Firstname, Lastname);

  hfu::Person B(A);

  Firstname = "Michael";
  assert(A.getFirstname() == B.getFirstname());
  // std::cout << "Copy success:\t" << A.getFirstname() <<" == " <<
  // B.getFirstname() << "\n";
}

void test_2() {
  hfu::Person director("Donald", "Duck");
  int scores[] = {4, 7, 1, 1};
  cinema::Movie scored_movie("Modern Times", 90, director, scores, 4);
  scored_movie.setScore(3, 42);
  assert(scored_movie.getScore(3) == 42);
}

void test_3() {
  hfu::Person director("Donald", "Duck");
  int scores[] = {4, 7, 1, 1};
  cinema::Movie scored_movie("Modern Times", 90, director, scores, 4);
  auto copy = scored_movie;
  scored_movie.setScore(3, 42);
  // std::cout << copy.getScore(3);
  assert(copy.getScore(3) == 1);
}

// Test für Aufgabenblatt 7

hfu::Person *createArr() {
  hfu::Person *result = new hfu::Person[4];
  result[0] = hfu::Person("Minnie", "Maus");
  result[1] = hfu::Person("Daisy", "Duck");
  result[2] = hfu::Person("Donald", "Duck");
  result[3] = hfu::Person("Micky", "Maus");
  return result;
}

void test_4() {
  int size = 4;
  hfu::Person *persons = createArr();
  hfu::sort(persons, size);
  assert((persons[0]).getFirstname() == "Daisy");
  assert((persons[1]).getFirstname() == "Donald");
  assert((persons[2]).getFirstname() == "Micky");
  assert((persons[3]).getFirstname() == "Minnie");

  delete[] persons;
}

void test_5() {
  int size = 4;

  std::string Arr[] = {"Go", "Kotlin", "Rust", "Julia"};
  hfu::sort(Arr, size);
  assert(Arr[0] == "Rust");
  assert(Arr[1] == "Kotlin");
  assert(Arr[2] == "Julia");
  assert(Arr[3] == "Go");

  int Ar[4] = {2, 3, 1, 4};
  hfu::sort(Ar, 4);
}

// Was ist gemeint mit ganzzahligen Arrays????

void test_6() {

  hfu::Person *persons = createArr();
  SimpleVector list(persons, 3);
  assert(list.getSize() == 3);
  assert(list[2].getFirstname() == "Donald");
  assert(list[2].getLastname() == "Duck");
  list[2] = persons[3];
  assert(list[2].getFirstname() == "Micky");
  assert(list[2].getLastname() == "Maus");
  SimpleVector copy;

  assert(copy.getSize() == 0);
  copy = list;
  assert(copy[2].getFirstname() == "Micky");
  assert(copy[2].getLastname() == "Maus");
  list[2] = persons[2];
  assert(copy[2].getFirstname() == "Micky");
  assert(copy[2].getLastname() == "Maus");
  copy = copy;
  assert(copy[2].getFirstname() == "Micky");
  assert(copy[2].getLastname() == "Maus");
  delete[] persons;
}

void test_7(){
    hfu::Person director("Donald", "Duck");
    int scores[] = {4, 7, 1, 1};
    cinema::Movie scored_movie("Modern Times", 90, director, scores, 4);
    auto copy = cinema::Movie("Modern Times", 90, director);
    copy = scored_movie;
    scored_movie.setScore(3, 42);
    assert(copy.getScore(3)==1);
}


void test_8(){
    hfu::Person director("Max", "Schopf");
    int arr[] = {2, 3, 0, 1};
    cinema::Movie obj("Der Informatiker", 180, director);

    auto copy = cinema::Movie(obj);

    copy.setScore(0, 1);

    assert(copy != obj);
    
}


void runing() {

  test_1();
  test_2();
  test_3();
  test_4();
  test_5();
  test_6();
  test_7();
  test_8();
}
