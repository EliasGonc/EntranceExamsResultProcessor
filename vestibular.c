#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "vestibular.h"

void createNewCandidate(Candidate **candidatesPtr, int n) {
	if(n == 0) {
		*candidatesPtr = malloc(sizeof(Candidate));
	} else {
		*candidatesPtr = realloc(*candidatesPtr, (n+1) * sizeof(Candidate));
	}
}

void printMenu() {
	system("cls");
	printf("Selecione uma opção abaixo:\n");
	printf("1. Pegar dados dos candidatos de um arquivo.\n");
	printf("2. Digitar dados manualmente.\n");
	printf("3. Sair.\n");
	printf("Opção: ");
}

void printResults(Candidate *candidates, int n) {
    system("cls");
    if(n > 0) {
		printf("Resultado do vestibular:\n\n");
		printf("MATR. NOTA\n");
		for(short int i = 0; i < n; i++) {
			printf("%05d  %02hd\n", candidates[i].id, candidates[i].correctAnswersCount);
		}
    }
}

short int isCorrectAnswer(char answer, short int question) {
	answer = tolower(answer);
	if(answer == CORRENT_ANSWERS[question]) {
		return 1;
	}
	return 0;
}

int getAnswersFromFile(Candidate **candidatesPtr) {
	char fileName[FILE_NAME_LENGTH];
	int n = 0;
	FILE *fp = NULL;

	while(1) {
		if(strcmp(getFileName(fileName), "/") != 0) {
			fp = fopen(fileName, "r");
			if(fp == NULL) {
				printf("Arquivo não encontrado.\n");
			} else {
				n = getFileData(&fp, candidatesPtr);
				fclose(fp);
				break;
			}
		} else {
			break;
		}
	}
	return n;
}

char* getFileName(char* fileName) {
	printf("Digite o nome do arquivo e sua extensão ou / para cancelar: ");
	scanf("%s", fileName);
	fflush(stdin);
	return fileName;
}

int getFileData(FILE **fp, Candidate **candidatesPtr) {
	char id[ID_MAX_LENGTH], answers[N_QUESTIONS];
	int n = 0;
	while((fscanf(*fp, "%s %s", id, answers)) != EOF) {
		createNewCandidate(candidatesPtr, n);
		processFileLine(candidatesPtr, id, answers, n);
		n++;
	}
	return n;
}

void processFileLine(Candidate **candidatesPtr, char *id, char *answers, int n){
	(*candidatesPtr)[n].id = atoi(id);
	strcpy((*candidatesPtr)[n].answers, answers);
	(*candidatesPtr)[n].correctAnswersCount = checkCandidateAnswers(answers);
}

int checkCandidateAnswers(char *answers) {
	int correctCount = 0;
	for(short int i = 0; i < N_QUESTIONS; i++) {
		if(answers[i] == CORRENT_ANSWERS[i]) {
			correctCount++;
		}
	}
	return correctCount;
}

void getNewCandidateFromUser(Candidate **candidatesPtr, int *n) {
	createNewCandidate(candidatesPtr, *n);
	(*candidatesPtr)[*n].id = getIdFromUser(*candidatesPtr, *n);
	strcpy((*candidatesPtr)[*n].answers, getAnswersFromUser());
	(*candidatesPtr)[*n].correctAnswersCount = checkCandidateAnswers((*candidatesPtr)[*n].answers);
	(*n)++;
}

int getIdFromUser(Candidate *candidates, int n) {
	int id;
	while(1) {
		system("cls");
		printf("Digite o número da matrícula do %d° candidato (até 5 dígitos) "
				"ou um número negativo para sair.\n", n+1);
		printf("Matrícula: ");
		fflush(stdin);
		scanf("%d", &id);
		fflush(stdin);
		if(id <= 0 || id > 99999) {
			printf("Número de matrícula inválido. Pressione qualquer tecla "
					"para continuar.\n");
			system("pause>nul");
		} else if(checkIfIdExist(candidates, n, id) == 1) {
			printf("Já existe um candidato com esse número de matrículal. "
				   "Pressione qualquer tecla para continuar.\n");
			system("pause>nul");
		} else {
			break;
		}
	}
	return id;
}

char* getAnswersFromUser() {
	char *answers = malloc((N_QUESTIONS+1) * sizeof(char));
	printf("Digite as respostas do candidato para todas as %d questões do "
			"vestibular (a, b, c, d ou e)\n", N_QUESTIONS);
	printf("Respostas: ");
	for(short int i = 0; i < N_QUESTIONS; i++) {
		scanf(" %c", &answers[i]);
	}
	return answers;
}

short int queryRegistrationEnd() {
	char getAnotherUser;
	while(1) {
		printf("Deseja cadastrar outro candidato (S/N)? ");
		fflush(stdin);
		scanf("%c", &getAnotherUser);
		fflush(stdin);
		switch(getAnotherUser) {
		case 'n':
		case 'N':
			return 1;
		case 's':
		case 'S':
			return 0;
		default:
			printf("Opção inválida. Pressione qualquer tecla para continuar.\n");
			system("pause>nul");
		}
	}
}

short int checkIfIdExist(Candidate *candidates, int n, int id) {
	for(int i = 0; i < n; i++) {
		if(candidates[i].id == id) {
			return 1;
		}
	}
	return 0;
}
