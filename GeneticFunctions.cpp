#include "GeneticFunctions.hpp"

string GeneticFunctions::getInitialSet(string gene_set, int len) {
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

string * GeneticFunctions::pickFittestParents(string initSets[], int len) {
    static string chosenSets[2];

    string fit1 = "";
    string fit2 = "";
    for(int i = 0; i<len; i++){

        if(fit1 == "") {
            fit1 = initSets[i];

        }
        else if(getFitScore(initSets[i]) > getFitScore(fit1)) {
            fit2 = fit1;
            fit1 = initSets[i];

        }
        else if(getFitScore(initSets[i])>getFitScore(fit2)) {
            fit2 = initSets[i];

        }
        
    }

    chosenSets[0] = fit1;
    chosenSets[1] = fit2;

    return chosenSets;
}

string GeneticFunctions::mate(string initSets[]) {
    return initSets[0].substr(0,3)+initSets[1].substr(3,initSets[1].size()-1);
}

string GeneticFunctions::mutate(string offspring, int index) {
    int change_amount = 1;
    offspring.at(index) = offspring.at(index)+change_amount;
    return offspring;
}

string* GeneticFunctions::newGeneration(string initSets[], string offspring, int len){ 
    int unfit_index = pickUnfitIndex(initSets, len);

    initSets[unfit_index] = offspring;

    return initSets;
}

int GeneticFunctions::pickUnfitIndex(string initSets[], int len) {

    int unfit_index = 0;
    for(int i = 0; i<len; i++){
        if(getFitScore(initSets[i]) < getFitScore(initSets[unfit_index])) {
            unfit_index = i;
        }
    }
    return unfit_index;
}