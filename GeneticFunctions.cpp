#include "GeneticFunctions.hpp"

string GeneticFunctions::getInitialSet(string gene_set) {
    int len = rand() % gene_set.size();
    string init_set = "";
    for(int i = 0; i<len; i++) {
        int index = rand() % len;
        init_set += gene_set.at(index);
    }
    return init_set;
}

void GeneticFunctions::setFitGoal(string goal) {
    this->goal = goal;
}

string GeneticFunctions::getFitGoal(){
    return GeneticFunctions::goal;
}

int GeneticFunctions::getFitScore(string init_set) {
    int score =0;
    for (int i = 0; i < init_set.size(); i++)
        {
            for (int j = 0; j < getFitGoal().size(); j++)
            {
                if (getFitGoal().at(j) == init_set.at(i))
                {
                    score +=1;
                    break;
                }
            }
           
        }
    
    return score;
}

bool GeneticFunctions::containsSub(string initSet, string GeneSet) {
    bool part_of_subset = false;
    for (int i = 0; i < initSet.size(); i++)
        {
            part_of_subset = false;
            for (int j = 0; j < GeneSet.size(); j++)
            {
                if (GeneSet.at(j) == initSet.at(i))
                {
                    part_of_subset = true;
                    break;
                }
            }
            if(!part_of_subset) {
                break;
            }
        }
    return part_of_subset;
}

string * GeneticFunctions::pickFittestParents(string initSets[]) {
    static string chosenSets[2];
    chosenSets[0] = initSets[1];
    chosenSets[1] = initSets[2];
    cout<<"Not At GeneticFunctions.cpp:63"<<endl;
    return chosenSets;
}