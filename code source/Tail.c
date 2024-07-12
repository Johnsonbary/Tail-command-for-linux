#include "tail.h"

int main(int argc, char *argv[])
{
	FILE *fichier = NULL;
	fichier = option(argc, argv);
	fermeture(fichier);
	return 0;
}
