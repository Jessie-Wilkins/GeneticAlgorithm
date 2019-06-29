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
    return result;
}
