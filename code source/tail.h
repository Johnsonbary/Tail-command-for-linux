#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

FILE *ouverture(char argv[100]);
int compter(FILE *fichier);
void afficher(FILE *fichier, int count, int retour);
void fermeture(FILE *fichier);
FILE *option(int argc, char *argv[]);
FILE *option_q(char *argv[]);
FILE *option_f(char *argv[]);
void option_help();
FILE *option_c(char *argv[]);
FILE *option_sans(char *argv[]);
FILE *option_n(char *argv[]);
