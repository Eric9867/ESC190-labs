#include "autocomplete.h"
#include <stdio.h>


void read_in_terms(struct Term **terms, int *pnterms, char *filename)
{
    FILE* handle;
    if(fopen_s(handle, filename, "r"))
        abort(); /* Better error handling is recommended */
    

    /* Read number of lines (first line of file) */
    int number_of_lines;
    fscanf( handle, " %d\n", &number_of_lines );
    
    *terms = (struct Term*)malloc(number_of_lines * sizeof(struct Term)); 
    /* loop through the file, creating one term per line */
    /* Examples
      14608512	Shanghai, China
    5627187200	the
     */
    
    for(int i = 0; )   
    fscanf_s( 
        handle, 
        " %lf\t%[^\n]\n", 
        &((*terms)[i].weight), sizeof(double),
        (*terms)[i].term, sizeof(TERM_LENGTH)
    );
};

int lowest_match(struct term *terms, int nterms, char *substr)
{

};

int highest_match(struct term *terms, int nterms, char *substr)
{

};

void autocomplete(struct term **answer, int *n_answer, struct term *terms, int nterms, char *substr)
{

};
