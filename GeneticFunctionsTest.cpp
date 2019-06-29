#include "GeneticFunctionsTest.hpp"
#include <iostream>
TEST_CASE("GeneticFunctionsTest") {
    GeneticFunctions gf;
    GeneticFunctionsTest gt;
    SECTION("Test If Random Initial Parent Is Subset Of Entire Gene Set"){
        string GeneSet = "abcdefghijklmnopqrstuvwxyz";
        string initSet = gf.getInitialSet(GeneSet);
        
        bool part_of_subset = gf.containsSub(initSet, GeneSet);
        
        REQUIRE(part_of_subset == true);
    }

    SECTION("Test If Multiple Subsets Are Different"){
        string GeneSet = "abcdefghijklmnopqrstuvwxyz";
        string initSet1 = gf.getInitialSet(GeneSet);
        string initSet2 = gf.getInitialSet(GeneSet);
        
        REQUIRE(initSet1 != initSet2);
    }

    SECTION("Test If Fitness Caclulator Can Accurately Detect Fitness Score") {
        string initSet = "bdft";
        gf.setFitGoal("bald");
        int fit_score = gf.getFitScore(initSet);
        REQUIRE(fit_score == 2);
    }

    SECTION("Test If Fitness Caclulator Can Accurately Detect Fitness Score For Multiple Sets") {
        string initSet1 = "bdft";
        string initSet2 = "labf";
        gf.setFitGoal("bald");
        int fit_score1 = gf.getFitScore(initSet1);
        int fit_score2 = gf.getFitScore(initSet2);
        REQUIRE(fit_score1 == 2);
        REQUIRE(fit_score2 == 3);
    }
    
    SECTION("Test If Fittest Parents Mate") {
        
        cout<<"Not At GeneticFunctionsTest.cpp:48"<<endl;
        gf.setFitGoal("bald");
        string* initSets;
        initSets = gt.r_array("bdft", "labf", "bady");
        string *chosenSets;
        chosenSets = gf.pickFittestParents(initSets);
        REQUIRE(chosenSets[0] == "labf");
        REQUIRE(chosenSets[1] == "bady");
    }

    SECTION("Test If Crossbreeding Occurs Through Switching First Three chromosomes Of Fittest Parents"){

        gf.setFitGoal("bald");
        string* initSets;
        initSets = gt.r_array("labf", "bady","bdft");
        string *chosenSets;
        chosenSets = gf.pickFittestParents(initSets);
        string offspring = gf.mate(chosenSets);
        REQUIRE(offspring == "laby");
    }
    
}

string* GeneticFunctionsTest::r_array(string initSet1,string initSet2,string initSet3) {
        static string initSets [3];
        initSets[0] = initSet1;
        initSets[1] = initSet2;
        initSets[2] = initSet3;
        return initSets;
}
