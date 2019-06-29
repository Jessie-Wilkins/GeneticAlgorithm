#include "GeneticFunctionsTest.hpp"
#include <iostream>
TEST_CASE("GeneticFunctionsTest") {
    GeneticFunctions gf;
    GeneticFunctionsTest gt;
    
    SECTION("Test If Random Initial Parent Is Subset Of Entire Gene Set"){
        string GeneSet = "abcdefghijklmnopqrstuvwxyz";
        string initSet = gf.getInitialSet(GeneSet);
        
        bool part_of_subset = gt.containsSub(initSet, GeneSet);
        
        REQUIRE(part_of_subset == true);
    }

    SECTION("Test If Multiple Subsets Are Different"){
        string GeneSet = "abcdefghijklmnopqrstuvwxyz";
        string initSet1 = gf.getInitialSet(GeneSet);
        string initSet2 = gf.getInitialSet(GeneSet);
        
        REQUIRE(initSet1 != initSet2);
    }
    
    
}

bool GeneticFunctionsTest::containsSub(string initSet, string GeneSet) {
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