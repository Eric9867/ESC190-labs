#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "autocomplete.h"


void read_in_terms(struct Term **terms, int *pnterms, char *filename)
{
    FILE* handle;
    if(fopen_s(&handle, filename, "r"))
        abort(); /* Better error handling is recommended */
    
    /* Read number of lines (first line of file) */
    fscanf_s( handle, " %d ", pnterms, sizeof(int) );
    
    *terms = (struct Term*)malloc(*pnterms * sizeof(struct Term)); 
    /* loop through the file, creating one term per line */
    /* Examples
      14608512	Shanghai, China
    5627187200	the
     */
    for(
        int i = 0;    
        fscanf_s( 
            handle, 
            "%lf %[^\n] ", 
            &(*terms)[i].weight,
            (*terms)[i].term, TERM_SIZE
        ) > 0;
        i++
    ); /* {printf("%s\n", (*terms)[i].term);} */

    fclose(handle);
};

int term_comparison(const void* term_1, const void* term_2)
{
    return strcmp(((struct Term*)term_1)->term, ((struct Term*)term_2)->term);
}


int lowest_match(struct Term *terms, int n_terms, char *substr)
{
    /**
     * Looking for the lower boundary (in terms of alphabetical 
     * ordering) on strings that match the substring
     */
    int idx_lower = 0;
    int idx_upper = n_terms;
    int mid, comparison;

    while(idx_upper - idx_lower > 1){
        mid = (idx_lower + idx_upper)/2;
        comparison = strcmp(substr, terms[mid].term);
        if(comparison < 0) // substr is in first half
        {
            idx_upper = mid;
        } else {
            idx_lower = mid;
        }
    }
    return idx_upper;
};

/*
int highest_match(struct Term *terms, int n_terms, char *substr)
{

};

void autocomplete(struct Term **answer, int *n_answer, struct term *terms, int nterms, char *substr)
{

};
*/