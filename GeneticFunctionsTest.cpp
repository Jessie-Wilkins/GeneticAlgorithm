#include "GeneticFunctionsTest.hpp"
#include <iostream>
TEST_CASE("GeneticFunctionsTest") {
    GeneticFunctions gf;
    GeneticFunctionsTest gt;
    SECTION("Test If Random Initial Parent Is Subset Of Entire Gene Set"){
        string GeneSet = "abcdefghijklmnopqrstuvwxyz";

        int len = 4;

        string initSet = gf.getInitialSet(GeneSet, len);
        
        bool part_of_subset = gf.containsSub(initSet, GeneSet);
        
        REQUIRE(part_of_subset == true);
    }

    SECTION("Test If Multiple Subsets Are Different"){
        string GeneSet = "abcdefghijklmnopqrstuvwxyz";

        int len = 4;

        string initSet1 = gf.getInitialSet(GeneSet, len);
        string initSet2 = gf.getInitialSet(GeneSet, len);
        
        REQUIRE(initSet1 != initSet2);
    }

    SECTION("Test If Fitness Caclulator Can Accurately Detect Fitness Score") {
        string initSet = "bdft";
        gf.setFitGoal("bald");
        int fit_score = gf.getFitScore(initSet);
        REQUIRE(fit_score == 1);
    }

    SECTION("Test If Fitness Caclulator Can Accurately Detect Fitness Score For Multiple Sets") {
        string initSet1 = "bdft";
        string initSet2 = "labf";
        gf.setFitGoal("bald");
        int fit_score1 = gf.getFitScore(initSet1);
        int fit_score2 = gf.getFitScore(initSet2);
        REQUIRE(fit_score1 == 1);
        REQUIRE(fit_score2 == 1);
    }
    
    SECTION("Test If Fittest Parents Mate") {
        
        gf.setFitGoal("bald");
        string* initSets;
        initSets = gt.r_array("bdft", "labf", "bady");
        string *chosenSets;
        chosenSets = gf.pickFittestParents(initSets, 3);
        REQUIRE(chosenSets[0] == "bady");
        REQUIRE(chosenSets[1] == "bdft");
    }

    SECTION("Test If Crossbreeding Occurs Through Switching First Three chromosomes Of Fittest Parents"){

        gf.setFitGoal("bald");
        string* initSets;
        initSets = gt.r_array("labf", "bady","bdft");
        string *chosenSets;
        chosenSets = gf.pickFittestParents(initSets, 3);
        string offspring = gf.mate(chosenSets, 49);
        REQUIRE(offspring == "bady");
    }

    SECTION("Test If Mutation Will Change One Chromosome"){
        
        gf.setFitGoal("bald");
        string* initSets;
        initSets = gt.r_array("labf", "bady","bdft");
        string *chosenSets;
        chosenSets = gf.pickFittestParents(initSets, 3);
        string offspring = gf.mate(chosenSets, 49);
        int index = 0;
        offspring = gf.mutate(offspring, index, 'c');
        REQUIRE(offspring.compare("bady") == 1);
    }

    SECTION("Test If Offspring will be added and least fit Deleted") {
        gf.setFitGoal("bald");
        string* initSets;
        initSets = gt.r_array("labf", "bady","bdft");
        string *chosenSets;
        chosenSets = gf.pickFittestParents(initSets, 3);
        string offspring = gf.mate(chosenSets, 49);
        int index = 0;
        offspring = gf.mutate(offspring, index, 'c');

        string* newSet;
        newSet = gf.newGeneration(initSets, offspring, 3);
        REQUIRE(newSet[2] == "bdft");
    }
    
    SECTION("Test If initSets Can Be Ordered by Fittest") {
        gf.setFitGoal("bald");
        string* initSets;
        initSets = gt.r_array("labf", "bady","bdft");
        initSets = gf.orderArray(initSets, 3);
        REQUIRE(initSets[0] == "bady");
    }

    SECTION("Test If Top 50% Can Be Chosen From initSets") {
        gf.setFitGoal("bald");
        string* initSets;
        initSets = gt.r_array("labf", "bady","bdft","balt");
        initSets = gf.orderArray(initSets, 4);
        string* eliteSet;
        eliteSet = gf.chooseElite(initSets, 4);
        REQUIRE(eliteSet[0] == "balt");
        REQUIRE(eliteSet[1] == "bady");
        REQUIRE(eliteSet[2] != "bdft");
    }
}

string* GeneticFunctionsTest::r_array(string initSet1,string initSet2,string initSet3) {
        static string initSets [3];
        initSets[0] = initSet1;
        initSets[1] = initSet2;
        initSets[2] = initSet3;
        return initSets;
}

string* GeneticFunctionsTest::r_array(string initSet1,string initSet2,string initSet3, string initSet4) {
        static string initSets [4];
        initSets[0] = initSet1;
        initSets[1] = initSet2;
        initSets[2] = initSet3;
        initSets[3] = initSet4;
        return initSets;
}
