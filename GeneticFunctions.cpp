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
                
        if (getFitGoal().at(i) == init_set.at(i))
        {
            score +=1;
                    
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

string GeneticFunctions::mate(string initSets[], int rand_num) {
    string offspring = "";
    for(int i = 0; i<initSets[0].size(); i++) {
        int rand_gen = rand()%rand_num;
        if(rand_gen <50) {
            offspring += initSets[0].at(i);
            //return initSets[0].substr(0,(initSets[0].size()-1)/2)+initSets[1].substr((initSets[1].size()-1)/2,initSets[1].size()-1);
        }
        else{
            offspring += initSets[1].at(i);
            //return initSets[1].substr(0,(initSets[1].size()-1)/2)+initSets[0].substr((initSets[0].size()-1)/2,initSets[0].size()-1);
        }
    }
    return offspring;
    
}

string GeneticFunctions::mutate(string offspring, int index, char rand_char) {
    offspring.at(index) = rand_char;
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

string* GeneticFunctions::orderArray(string initSets[], int len) {
    for(int i = 0; i<len; i++) {
        for(int j = i; j<len; j++) {
            if(getFitScore(initSets[i])<getFitScore(initSets[j])) {
                string temp = initSets[i];
                initSets[i]=initSets[j];
                initSets[j]=temp;
            }
        }
    }
    return initSets;
}