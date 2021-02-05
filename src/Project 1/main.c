#include <stdlib.h>
#include <stdio.h>
#include "autocomplete.h"

int main(void)
{
    struct Term *terms;
    int n_terms;
    read_in_terms(&terms, &n_terms, "../src/Project 1/cities.txt");

    // lowest_match(terms, nterms, "Tor");
    // highest_match(terms, nterms, "Tor");
    
    // struct term *answer;
    // int n_answer;
    // autocomplete(&answer, &n_answer, terms, int nterms, "Tor");

    //free allocated blocks here -- not required for the project, but good practice
    qsort(terms, n_terms, sizeof(struct Term), term_comparison);
    
    int idx_match = lowest_match(terms, n_terms, " ");
    printf("\n%d\n", idx_match);
    printf("%s\n", terms[idx_match].term);
    printf("%s\n", terms[idx_match + 1].term);

    free(terms);
    return 0;
}

