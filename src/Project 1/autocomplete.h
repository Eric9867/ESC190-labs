#ifndef AUTOCOMPLETE_H_
#define AUTOCOMPLETE_H_

#define TERM_LENGTH 100

struct Term{
    char term[TERM_LENGTH]; // *******changed to 100, watch out for related errors******* assume terms are not longer than 200
    double weight;
};

void read_in_terms(struct term **terms, int *pnterms, char *filename);
int lowest_match(struct term *terms, int nterms, char *substr);
int highest_match(struct term *terms, int nterms, char *substr);
void autocomplete(struct term **answer, int *n_answer, struct term *terms, int nterms, char *substr);

#endif
