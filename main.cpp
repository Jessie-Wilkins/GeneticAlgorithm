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


string* getArrayOfSets(string GeneSet, int str_len, int arr_len);

int main(int argc, const char * argv[]) {
    int result = Catch::Session().run( argc, argv );


    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;

    srand(time(NULL));

    GeneticFunctions gf;
    

    string GeneSet = "abcdefghijklmnopqrstuvwxyz";

    int str_len = 4;

    int arr_len = 8;

    string* initSets;

    initSets = getArrayOfSets(GeneSet, str_len, arr_len);

    cout<<"Initial Sets:"<<endl;

    for(int i = 0; i<arr_len; i++) {
        cout<<initSets[i]<<endl;
    }

    cout<<endl;

    string goal = "bald";

    gf.setFitGoal(goal);

    cout<<"Goal: "<<gf.getFitGoal()<<endl<<endl;

    for(int i = 0; i<50; i++) {

        cout<<"Generation "<<i<<endl;

        for(int i = 0; i<arr_len; i++) {
            cout<<initSets[i]<<endl;
        }

        cout<<endl;

        string* chosenSets;

        chosenSets = gf.pickFittestParents(initSets, arr_len);

        cout<<"Chosen Mates: "<<chosenSets[0]<<"; "<<chosenSets[1]<<endl<<endl;

        string offspring = gf.mate(chosenSets);

        cout<<"Offspring: "<<offspring<<endl<<endl<<endl;

        string* newSets;

        if(rand()%2 == 0) {
            int index = rand() % offspring.length();
            offspring = gf.mutate(offspring, index);
        }

        newSets = gf.newGeneration(initSets, offspring, arr_len);

        *initSets = *newSets;

        
    }




    return result;
}

string* getArrayOfSets(string GeneSet, int str_len, int arr_len) {

    GeneticFunctions gf;

    string* initSets = new string [arr_len];
    for(int i  = 0; i<arr_len; i++) {
        initSets[i] = gf.getInitialSet(GeneSet, str_len);
    
    }

    return initSets;
}