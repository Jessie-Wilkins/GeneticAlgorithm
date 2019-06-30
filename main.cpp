//
//  main.cpp
//  GeneticFunctions
//
//  Created by Jessie Wilkins on 6/29/19.
//  Copyright © 2019 Jessie Wilkins. All rights reserved.
//


#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "GeneticFunctions.hpp"
#include "catch.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    int result = Catch::Session().run( argc, argv );


    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;

    GeneticFunctions gf;
    

    string GeneSet = "abcdefghijklmnopqrstuvwxyz";

    int len = 4;

    string initSet1 = gf.getInitialSet(GeneSet, len);
    string initSet2 = gf.getInitialSet(GeneSet, len);
    string initSet3 = gf.getInitialSet(GeneSet, len);
    string initSet4 = gf.getInitialSet(GeneSet, len);

    string initSets [4];
    initSets[0] = initSet1;
    initSets[1] = initSet2;
    initSets[2] = initSet3;
    initSets[3] = initSet4;

    cout<<"Initial Sets:"<<endl<<initSets[0]<<endl<<initSets[1]<<endl<<initSets[2]<<endl<<initSets[3]<<endl<<endl;

    string goal = "bald";

    gf.setFitGoal(goal);

    cout<<"Goal: "<<gf.getFitGoal()<<endl<<endl;

    string* chosenSets;

    chosenSets = gf.pickFittestParents(initSets, len);

    cout<<"Chosen Mates: "<<chosenSets[0]<<"; "<<chosenSets[1]<<endl<<endl;

    string offspring = gf.mate(chosenSets);

    cout<<"Offspring: "<<offspring<<endl<<endl<<endl;

    string* newSets;

    newSets = gf.newGeneration(initSets, offspring, len);

    cout<<"New Generation:"<<endl<<newSets[0]<<endl<<newSets[1]<<endl<<newSets[2]<<endl<<newSets[3]<<endl<<endl;



    int index = rand() % offspring.length();
    offspring = gf.mutate(offspring, index);


    return result;
}
