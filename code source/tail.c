#include "tail.h"
int compter(FILE *fichier)
{
	int count = 0;
	char mot[200];
	while(!feof(fichier))
	{
		fgets(mot, 200, fichier);
		count ++;
	}
	return count;
}
FILE *ouverture(char argv[100])
{
	FILE *fichier = NULL;
	fichier = fopen(argv, "r+");
	if(fichier == NULL)
	{
		printf("Consulter Tail --help\n");
		exit (-1);
	}
	return (fichier);
}
void afficher(FILE *fichier, int count, int retour)
{
	int i;
	char mot[200];
	for(i = 0; feof(fichier) != 1; i++)
	{
		fgets(mot, 200, fichier);
		if(i >= count -  (retour + 1) && i < count - 1)
		{
				printf("%s", mot);
		}
	}
}
void fermeture(FILE *fichier)
{
	if(fichier != NULL)
	{
		fclose(fichier);
	}
}
FILE *option(int argc, char *argv[])
{
	FILE *fichier = NULL;
	if(argv[1] == NULL)
	{
		printf("Consulter Tail --help\n");
		exit(0);
	}
	else if(strcmp(argv[1],"-n")==0)
	{
		option_n(argv);
	}
	else if(strcmp(argv[1],"-f")==0)
	{
		option_f(argv);
	}
	else if(strcmp(argv[1],"--version")==0)
	{
		printf("tail 24.7.12 ecrit par Johnson de MIT\n");
		exit (0);
	}
	else if(strcmp(argv[1],"--help")==0)
	{
		option_help();
	}
	else if(strcmp(argv[1]," ")==0)
	{
		printf("Consulter tail --help");
		exit (0);
	}
	else if(argv[1]==NULL)
	{
		printf("Consulter tail --help");
		exit(0);
	}
	else if(strcmp(argv[1],"-v")==0)
	{
		option_sans(argv);
		printf("Nom du fichier: %s\n",argv[2]);
	}
	else if(strcmp(argv[1],"-q")==0)
	{
		option_q(argv);
	}
	else if(strcmp(argv[1],"-c")==0)
	{
		option_c(argv);
	}
	else
	{
		fichier = option_sans(argv);
	}
	return (fichier);
}
FILE *option_q(char *argv[])
{
	int count;
	int result = 10;
	FILE *fichier = NULL;
	fichier = ouverture(argv[2]);
	count = compter(fichier);
	rewind(fichier);
	afficher(fichier, count, result);
	return (fichier);
}
FILE *option_f(char *argv[])
{
	FILE *fichier = NULL;
	char mot[200];
	int i;
	int count;
	int nombre;
	int result = 10;
	fichier = ouverture(argv[2]);
	count = compter(fichier);
	rewind(fichier);
	afficher(fichier, count, result);
	nombre = count;
	rewind(fichier);
	while(true)
	{
		fichier = ouverture(argv[2]);
		count = compter(fichier);
		if(count > nombre )
		{
			rewind(fichier);
			for(i = 0; feof(fichier) != 1; i++)
			{
				fgets(mot, 200, fichier);
				if(i < count - 1)
				{
						printf("%s", mot);
				}
			}
			nombre = count;
		}
		else if(count < nombre)
		{
			rewind(fichier);
			for(i = 0; feof(fichier) != 1; i++)
			{
				fgets(mot, 200, fichier);
				if(i < nombre - 1)
				{
					printf("%s", mot);
				}
			}
			nombre = count;
		}
		rewind(fichier);
		fclose(fichier);
	}
	return (fichier);
}	
void option_help()
{
	printf("tail est une commande qui permet d'afficher les 10 derniers lignes d'un fichier par defaut.\n");
		printf("Voici les options pour tail:\n");
		printf("--version : pour les versions\n");
		printf("--help : afficher ce menu\n");
		printf("-f : afficher en permanance le fichier\n");
		printf("-n [line]: afficher le nombre de ligne a partir de line\n");
		printf("-q : par defaut\n");
		printf("-v : nom du fichier\n");
		printf("-c : nombre de bytes\n");
		exit(0);
}
FILE *option_c(char *argv[])
{
	FILE *fichier = NULL;
	int longueur;
	int result;
	int i;
	int j;
	char mot[200];
	fichier = ouverture(argv[3]);
	result = atoi(argv[2]);
	//afficher(fichier, nombre, count);
	for(i = 0; feof(fichier) != 1; i++)					
	{
		fgets(mot, 200, fichier);
		if(i < result - 1)
		{
			//printf("%s", mot);
		}
		longueur = (int)strlen(mot);
	}
	for (j = longueur - result; j < longueur; j++)
	{
		printf("%c", mot[j]);
	}
	return (fichier);
}
FILE *option_sans(char *argv[])
{
	FILE *fichier = NULL;
	int count;
	int result = 10;
	fichier = ouverture(argv[1]);
	count = compter(fichier);
	rewind(fichier);
	afficher(fichier, count, result);
	return (fichier);
}
FILE *option_n(char *argv[])
{
	FILE *fichier = NULL;
	int result;
	int count;
	result = atoi(argv[2]);
	fichier = ouverture(argv[3]);
	count = compter(fichier);
	rewind(fichier);
	afficher(fichier, count, result);
	return (fichier);
}
