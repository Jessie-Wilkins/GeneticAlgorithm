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
    
    cout<<"Choose Gene Set:"<<endl;

    
    cout<<1<<": abcdefghijklmnopqrstuvwxyz"<<endl;
    cout<<2<<": 0123456789"<<endl;
    cout<<3<<": abcdefghijklmnopqrstuvwxyz(space_char)"<<endl;
    cout<<4<<": abcdefghijklmnopqrstuvwxyz(space_char);:!().,/][}{"<<endl;
    cout<<5<<": abcdefghijklmnopqrstuvwxyz(space_char);:!().,/][}{0123456789"<<endl;
    
    int gene_set_choice = 0;

    cin>>gene_set_choice;

    string GeneSet = "abcdefghijklmnopqrstuvwxyz";

    if(gene_set_choice==1) {
        GeneSet = "abcdefghijklmnopqrstuvwxyz";
    }
    else if(gene_set_choice==2) {
        GeneSet = "0123456789";
    }
    else if(gene_set_choice==3) {
        GeneSet = "abcdefghijklmnopqrstuvwxyz ";
    }
    else if(gene_set_choice==4) {
        GeneSet = "abcdefghijklmnopqrstuvwxyz ;:!().,/][}{";
    }
    else if(gene_set_choice==5) {
        GeneSet = "abcdefghijklmnopqrstuvwxyz ;:!().,/][}{0123456789";
    }
    

    cout<<"Please Enter the Length of the Strings: ";

    int str_len = 4;

    cin>>str_len;

    cout<<"Please Enter the Number of the Strings: ";

    int arr_len = 8;

    cin>>arr_len;

    string* initSets;

    initSets = getArrayOfSets(GeneSet, str_len, arr_len);

    //cout<<"Initial Sets:"<<endl;

    /*for(int i = 0; i<arr_len; i++) {
        cout<<initSets[i]<<endl;
    }*/

    cout<<endl;

    cout<<"Please Enter the Goal String: ";

    string goal = "bald";

    cin>>goal;

    int chance_to_mutate = 0;

    cout<<"Please Enter the Probability of Mutation: ";

    cin>>chance_to_mutate;

    gf.setFitGoal(goal);

    cout<<"Goal: "<<gf.getFitGoal()<<endl<<endl;

    for(int i = 0; true; i++) {

        cout<<"Generation "<<i<<endl;

        /*for(int i = 0; i<arr_len; i++) {
            cout<<initSets[i]<<endl;
        }*/

        cout<<endl;

        string* chosenSets;

        initSets = gf.orderArray(initSets, arr_len);



        //chosenSets = gf.pickFittestParents(initSets, arr_len);
        chosenSets = gf.chooseElite(initSets, arr_len);

        //cout<<"Chosen Mates: "<<chosenSets[0]<<"; "<<chosenSets[1]<<endl<<endl;

        int rand_num = 100;

        //string offspring = gf.mate(chosenSets, rand_num);

        string* offSpringSet;
        offSpringSet = gf.mateElite(chosenSets, arr_len/2, true,rand_num);

        string* newSets;
        for(int i = 0; i<arr_len/2; i++) {
            if((rand()%100)/chance_to_mutate == 0) {
                //cout<<"Mutation!!!"<<endl<<endl;
                int index1 = rand() % offSpringSet[i].length();
                int index2 = rand() % GeneSet.length();
                offSpringSet[i] = gf.mutate(offSpringSet[i], index1, GeneSet[index2]);
            }
        }
        

        //cout<<"Offspring: "<<offspring<<endl<<endl<<endl;


        newSets = gf.newGeneration(initSets, offSpringSet, arr_len);

        *initSets = *newSets;

        bool do_break = false;
        for(int i = 0; i<arr_len/2; i++) {
            if(offSpringSet[i] == goal) {
                do_break = true;
            }
        }

        if(do_break) {
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