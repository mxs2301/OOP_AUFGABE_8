#ifndef _MOVIE_H_
#define _MOVIE_H_
#include<iostream>
#include <vector>
#include"personen.h"
#include"vector"

namespace cinema{
    class Movie{

    private:
        std::string Title;
        std::string Regissuer;
        int Duration;
        int length = scores.size();
        hfu::Person director;
        



    public:
        Movie(const std::string& Title, const int& Duration, const hfu::Person& director,const int *scores, const int length);
        Movie(const std::string& Title,const std::string& Regissuer,const int& Duration);
        Movie(const std::string& Title, const int Duration, const hfu::Person& director);
        Movie(const Movie& copy);

        std::string getTitle();
        std::string getRegissuer();

        int getDuration();
        int getScore(int input);
        int getScoreCount();
        hfu::Person getDirector();


        void setScore(int index, int score);
        std::vector<int> createArr(const int *scores, const int &arrSize);


        bool operator == (const Movie& input);
        bool operator != (const Movie& input);

        std::vector<int> scores;
    };
};

#endif
