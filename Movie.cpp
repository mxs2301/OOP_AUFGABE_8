#include "Movie.h"
#include "personen.h"
#include <vector>

cinema::Movie::Movie(const std::string &Title, const std::string &Regissuer,
                     const int &Duration)
    : Title(Title), Regissuer(Regissuer), Duration(Duration), scores(),
      length(0) {}

cinema::Movie::Movie(const std::string &Title, const int &Duration,
                     const hfu::Person &director, const int *scores,
                     const int length)
    : Title(Title), Duration(Duration), length(length), director(director),
      scores(createArr(scores, length)) {}

cinema::Movie::Movie(const Movie &copy)
    : Title(copy.Title), Duration(copy.Duration), length(copy.length),
      director(copy.director), scores(copy.scores) {}

cinema::Movie::Movie(const std::string &Title, const int Duration,
                     const hfu::Person &director)
    : Title(Title), Duration(Duration), director(director), scores(),
      length(0) {}

std::vector<int> cinema::Movie::createArr(const int *scores,
                                          const int &arrSize) {
  std::vector<int> vec;

  for (int i = 0; i < arrSize; i++) {
    this->scores.push_back(scores[i]);
  }
  return vec;
}

std::string cinema::Movie::getTitle() { return Title; }

std::string cinema::Movie::getRegissuer() { return Regissuer; }

int cinema::Movie::getDuration() { return Duration; }

int cinema::Movie::getScore(int input) { 
    
    return this->scores.at(input);

 }

int cinema::Movie::getScoreCount() { return length; }

void cinema::Movie::setScore(int index, int score) {

  this->scores[index] = score;
}

hfu::Person cinema::Movie::getDirector() { return director; }

bool cinema::Movie::operator==(const Movie &input) {
    return !(*this != input);
}

bool cinema::Movie::operator!=(const Movie &input) {
  if (Title != input.Title || Regissuer != input.Regissuer ||
      Duration != input.Duration || length != input.length ||
      scores != input.scores)
    return true;
  else
    return false;
}
