#pragma once
#ifndef GeneticFunctions_h
#define GeneticFunctions_h
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class GeneticFunctions {
    public:
        string getInitialSet(string gene_set);
        void setFitGoal(string goal);
        string getFitGoal();
        int getFitScore(string init_set);
        bool containsSub(string initSet, string GeneSet);
        string* pickFittestParents(string initSets[]);
        string mate(string initSets[]);
        string mutate(string offspring, int index);
        string* newGeneration(string initSets[], string offspring);
        int pickUnfitIndex(string initSets[]);
        
    private:
        string goal;
};

#endif