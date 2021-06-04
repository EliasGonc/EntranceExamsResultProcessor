#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "vestibular.h"

int main() {
	setlocale(LC_ALL, "Portuguese");
	short int option;
    int n = 0;
	Candidate *candidates = NULL;

    do {
		printMenu();
		scanf("%hd", &option);
		switch(option) {
		case 1:
			n = getAnswersFromFile(&candidates);
			break;
		case 2:
			do {
				getNewCandidateFromUser(&candidates, &n);
			} while(queryRegistrationEnd() == 0);
			break;
		case 3:
			break;
		default:
			printf("Opção inválida. Aperte qualquer tecla para continuar.\n");
			system("pause>nul");
		}
    } while(option < 1 || option > 3);
    printResults(candidates, n);
    free(candidates);
	return 0;
}

