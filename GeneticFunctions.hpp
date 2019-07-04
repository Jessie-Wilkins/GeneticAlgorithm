#pragma once
#ifndef GeneticFunctions_h
#define GeneticFunctions_h
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class GeneticFunctions {
    public:
        string getInitialSet(string gene_set, int len);
        void setFitGoal(string goal);
        string getFitGoal();
        int getFitScore(string init_set);
        bool containsSub(string initSet, string GeneSet);
        string* pickFittestParents(string initSets[], int len);
        string mate(string initSets[], int rand_num);
        string mutate(string offspring, int index, char rand_char);
        string* newGeneration(string initSets[], string offspring, int len);
        int pickUnfitIndex(string initSets[], int len);
        
    private:
        string goal;
};

#endif