#ifndef AUTOCOMPLETE_H_
#define AUTOCOMPLETE_H_

#define TERM_SIZE 200

struct Term{
    char term[TERM_SIZE]; // *******changed to 100, watch out for related errors******* assume terms are not longer than 200
    double weight;
};

void read_in_terms(struct Term **terms, int *pnterms, char *filename);
int term_comparison(const void*, const void*);
int term_weight_comparison(const void*, const void*);
int lowest_match(struct Term *terms, int n_terms, char *substr);
int highest_match(struct Term *terms, int n_terms, char *substr);
void autocomplete(struct Term **answer, int *n_answer, struct Term *terms, int n_terms, char *substr);

#endif
