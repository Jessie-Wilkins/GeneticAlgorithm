#include "GeneticFunctions.hpp"

string GeneticFunctions::getInitialSet(string gene_set) {
    int len = rand() % gene_set.size();
    string init_set = "";
    for(int i = 0; i<len; i++) {
        int index = rand() % len;
        init_set += gene_set.at(index);
    }
    return init_set;
}