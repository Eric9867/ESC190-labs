#include <stdlib.h>
#include <stdio.h>
#include "autocomplete.h"

int main(void)
{
    struct Term *terms;
    int n_terms;
    read_in_terms(&terms, &n_terms, "../src/Project 1/wiktionary.txt");

    // lowest_match(terms, nterms, "Tor");
    // highest_match(terms, nterms, "Tor");
    
    // struct term *answer;
    // int n_answer;
    // autocomplete(&answer, &n_answer, terms, int nterms, "Tor");

    //free allocated blocks here -- not required for the project, but good practice
    qsort(terms, n_terms, sizeof(struct Term), term_comparison);
    
    struct Term *answers;
    int n_answers;

    autocomplete(&answers, &n_answers, terms, n_terms, "the");


    for( int i = 0; i < n_answers; i++ )
        printf("%lf, %s\n", answers[i].weight, answers[i].term);

    free(answers);
    free(terms);
    return 0;
}

