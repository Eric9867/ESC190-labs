#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "autocomplete.h"

#define TERM_SIZE 200

void read_in_terms(struct term **terms, int *pnterms, char *filename)
{
    FILE* handle;
    if(fopen_s(&handle, filename, "r"))
        abort(); /* Better error handling is recommended */
    
    /* Read number of lines (first line of file) */
    fscanf_s( handle, " %d ", pnterms, sizeof(int) );
    
    *terms = (struct term*)malloc(*pnterms * sizeof(struct term)); 
    /* loop through the file, creating one term per line */
    /** Examples
     *    14608512	Shanghai, China
     *  5627187200	the
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
    ); // {printf("%s\n", (*terms)[i].term);}

    fclose(handle);
};

int term_weight_comparison(const void *term_1, const void *term_2)
{
    double arg1 = ((struct term*)term_1)->weight;
    double arg2 = ((struct term*)term_2)->weight;
    if (arg1 > arg2) return -1;
    else if (arg1 < arg2) return 1;
    else return 0;
}


/**
 * Looking for the lower boundary (in terms of alphabetical 
 * ordering) on strings that begin with the substring
 */
int lowest_match(struct term *terms, int n_terms, char *substr)
{
    int idx_lower = 0;
    int idx_upper = n_terms;
    int mid = idx_upper / 2;
    size_t substr_len = strlen(substr);
    int comparison = strncmp(substr, terms[mid].term, substr_len);

    while(idx_upper - idx_lower > 1){
        if(comparison <= 0) // substr is in first half
            idx_upper = mid;
        else
            idx_lower = mid;
            
        mid = (idx_lower + idx_upper) / 2;
        comparison = strncmp(substr, terms[mid].term, substr_len);
    }
    
    comparison = strncmp(substr, terms[idx_lower].term, substr_len);
    if(comparison == 0)
        return idx_lower;

    comparison = strncmp(substr, terms[idx_upper].term, substr_len);
    if(comparison == 0)
        return idx_upper;
    
    else
        return -1;
    /**
     * TODO: What is a suitable return value if no match was found??
     */ 
};

/**
Part 2(b)
=========
Write a function with the signature
int highest_match(struct term *terms, int nterms, char *substr);

The function returns the index in terms of the last term in lexicographic order that matches the string substr.

This function must run in O(log(nterms)) time, where nterms is the number of terms in terms.

You can assume that terms is sorted in ascending lexicographic ordering.
*/
int highest_match(struct term *terms, int n_terms, char *substr)
{
    int idx_lower = 0;
    int idx_upper = n_terms;
    int mid = idx_upper / 2;
    size_t substr_len = strlen(substr);
    int comparison = strncmp(substr, terms[mid].term, substr_len);

    while(idx_upper - idx_lower > 1){
        if(comparison < 0) // substr is in first half
            idx_upper = mid;
        else 
            idx_lower = mid;
            
        mid = (idx_lower + idx_upper) / 2;
        comparison = strncmp(substr, terms[mid].term, substr_len);
    }

    comparison = strncmp(substr, terms[idx_upper].term, substr_len);
    if(comparison == 0)
        return idx_upper;
    
    comparison = strncmp(substr, terms[idx_lower].term, substr_len);
    if(comparison == 0)
        return idx_lower;
    
    else
        return -1;
}

/**
Part 3
======
Write a function with the signature 

void autocomplete(struct term **answer, int *n_answer, struct term *terms, int nterms, char *substr);

The function takes terms (assume it is sorted), the number of terms nterms, and the query string substr, and places the 
answers in answer, with *n_answer being the number of answers.
*/

void autocomplete(struct term **answer, int *n_answer, struct term *terms, int n_terms, char *substr)
{
    int idx_lower = lowest_match(terms, n_terms, substr);
    int idx_upper = highest_match(terms, n_terms, substr);
    *n_answer = idx_upper - idx_lower + 1;    
    *answer = (struct term*) malloc((*n_answer) * sizeof(struct term));
    
    for(int i = 0; i < *n_answer; i++)
    {
        (*answer)[i] = terms[idx_lower + i]; 
    }

    qsort(*answer, *n_answer, sizeof(struct term), term_weight_comparison);
}