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

    cout<<"Please enter the length of the strings: ";

    int str_len = 4;

    cin>>str_len;

    cout<<"Please enter the number of the strings: ";

    int arr_len = 8;

    cin>>arr_len;

    string* initSets;

    initSets = getArrayOfSets(GeneSet, str_len, arr_len);

    cout<<"Initial Sets:"<<endl;

    for(int i = 0; i<arr_len; i++) {
        cout<<initSets[i]<<endl;
    }

    cout<<endl;

    cout<<"Please Enter the Goal String: ";

    string goal = "bald";

    cin>>goal;

    gf.setFitGoal(goal);

    cout<<"Goal: "<<gf.getFitGoal()<<endl<<endl;

    for(int i = 0; true; i++) {

        cout<<"Generation "<<i<<endl;

        for(int i = 0; i<arr_len; i++) {
            cout<<initSets[i]<<endl;
        }

        cout<<endl;

        string* chosenSets;

        chosenSets = gf.pickFittestParents(initSets, arr_len);

        cout<<"Chosen Mates: "<<chosenSets[0]<<"; "<<chosenSets[1]<<endl<<endl;

        int rand_num = rand()%100;

        string offspring = gf.mate(chosenSets, rand_num);

        string* newSets;

        if(rand()%1 == 0) {
            cout<<"Mutation!!!"<<endl<<endl;
            int index1 = rand() % offspring.length();
            int index2 = rand() % GeneSet.length();
            offspring = gf.mutate(offspring, index1, GeneSet[index2]);
        }

        cout<<"Offspring: "<<offspring<<endl<<endl<<endl;


        newSets = gf.newGeneration(initSets, offspring, arr_len);

        *initSets = *newSets;

        if(offspring == goal) {
            cout<<"offspring: "<<offspring<<" goal: "<<goal<<endl<<endl;
            break;
        }
        
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