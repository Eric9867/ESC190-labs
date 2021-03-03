#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "autocomplete.h"

int main(void)
{
  struct term* terms;
  int n_terms;
  // read_in_terms(&terms, &n_terms, "../src/Project 1/cities.txt");
  read_in_terms(&terms, &n_terms, "C:\\Users\\Eric\\OneDrive - University of Toronto\\Classes\\Year 1 Winter\\ESC190\\Assignments\\Labs\\src\\Project 1\\cities.txt");

  // lowest_match(terms, nterms, "Tor");
  // highest_match(terms, nterms, "Tor");

  // struct term *answer;
  // int n_answer;
  // autocomplete(&answer, &n_answer, terms, int nterms, "Tor");

  //free allocated blocks here -- not required for the project, but good practice

  struct term* answers;
  int n_answers;

  autocomplete(&answers, &n_answers, terms, n_terms, "Ver");

  // printf("# TERMS: %d,  # ANSWERS: %d\n", n_terms, n_answers);

  for (int i = 0; i < n_answers; i++)
    printf("%lf,\t%s\n", answers[i].weight, answers[i].term);


  // printf("\nSTART\n");
  // printf("%s\n", answers[0].term);
  // for (int i = 0; answers[0].term[i]; i++)
  //   printf("%c\n", answers[0].term[i]);


  if (n_terms != 0)
  {
    free(terms);
    if (n_answers != 0)
      free(answers);
  }
  return 0;
}

