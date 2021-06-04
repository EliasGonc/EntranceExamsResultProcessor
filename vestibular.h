#ifndef VESTIBULAR_H_INCLUDED
#define VESTIBULAR_H_INCLUDED

#define FILE_NAME_LENGTH 50
#define ID_MAX_LENGTH 5
#define N_QUESTIONS 50
#define CORRENT_ANSWERS "ecacececeaedaaddeabadabaaadecbcedabbecdcadabeddaab"

typedef struct Candidate {
	short int correctAnswersCount;
	int id;
	char answers[N_QUESTIONS+1];
} Candidate;

/**
 * Adiciona um novo candidato num vetor de candidatos (Candidate).
 *
 * @param candidatesPtr Um ponteiro para o vetor de candidatos.
 * @param n Um menos o n�mero de candidatos que j� foram cadastrados.
 */
void createNewCandidate(Candidate **candidatesPtr, int n);

/**
 * Imprime o menu inicial do programa.
 */
void printMenu();

/**
 * Imprime os resultados do vestibular.
 *
 * @param candidates O vetor de candidatos.
 * @param n Um menos o n�mero de candidatos que j� foram cadastrados.
 */
void printResults(Candidate *candidates, int n);

/**
 * Verifica se a resposta do candidato � a mesma do gabarito para certa quest�o.
 *
 * @param answer A resposta da quest�o.
 * @param question Qual a quest�o.
 *
 * @return 1 se answer for igual ao gabarito (CORRECT_ANSWERS[question]), e 0
 *     caso contr�rio.
 */
short int isCorrectAnswer(char answer, short int question);

/**
 * Pega as respostas dos candidatos do vestibular de um arquivo de texto,
 * retornando o n�mero de candidatos.
 *
 * @param candidatesPtr Um ponteiro para o vetor de candidatos.
 *
 * @return O n�mero de candidatos do vestibular.
 */
int getAnswersFromFile(Candidate **candidatesPtr);

/**
 * Pede o nome do arquivo com as respostas dos candidatos do vestibular para o
 * usu�rio.
 *
 * @param fileName A string onde ser� guardado do arquivo por refer�ncia.
 *
 * @return Tamb�m retorna uma string com o nome do arquivo.
 */
char* getFileName(char *fileName);

/**
 * L� o n�mero de matr�cula e as respostas dos candidatos do vestibular de um
 * arquivo aberto. O arquivo deve estar no formato:
 *     CCCCC abcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcde
 * onde CCCCC � o n�mero da matr�cula do candidato e o resto as respotsas para
 * cada uma das quest�es do vestibular.
 *
 * @param fp Um ponteiro para um arquivo aberto.
 * @param candidatesPtr Um ponteiro para o vetor de candidatos.
 *
 * @return Tamb�m retorna uma string com o nome do arquivo.
 */
int getFileData(FILE **fp, Candidate **candidatesPtr);

/**
 * Processa uma linha do arquivo de respostas, salvando os valores no vetor de
 * candidatos.
 *
 * @param candidatesPtr Um ponteiro para o vetor de candidatos.
 * @param id O n�mero de matr�cula do candidato
 * @param answers A string com as respostas do candidato.
 * @param n O n�mero de candidatos j� cadastrados.
 */
void processFileLine(Candidate **candidatesPtr, char *id, char *answers, int n);

/**
 * Calcula quantas respostas o candidato acertou.
 *
 * @param answers A string com as respostas do candidato.
 *
 * @return A quantidade de respostas que o candidato acertou.
 */
int checkCandidateAnswers(char *answers);

/**
 * Adiciona um novo candidato do vestibular de acordo com dados digitados pelo
 * usu�rio.
 *
 * @param candidatesPtr Um ponteiro para o vetor de candidatos.
 * @param n Um ponteiro para o n�mero de candidatos j� cadastrados.
 *
 * @return 1 se o �ltimo candidato cadastrado foi o �ltimo, 0 caso contr�rio.
 */
void getNewCandidateFromUser(Candidate **candidatesPtr, int *n);

/**
 * Pede para o usu�rio digitar o n�mero de matr�cula do candidato ou um n�mero
 * negativo para encerrar.
 *
 * @param n O n�mero de candidatos j� cadastrados.
 *
 * @return O n�mero de matr�cula digitado pelo usu�rio
 * 0 caso contr�rio.
 */
int getIdFromUser(Candidate *candidates, int n);

/**
 * Pede para o usu�rio digitar as respostas do candidato.
 *
 * @return n Uma string contendo todas as respostas do candidato.
 */
char* getAnswersFromUser();

/**
 * Pergunta para o usu�rio se deseja cadastrar um novo candidato ou n�o.
 *
 * @returns 1 se o usu�rio deseja parar, 0 caso contr�rio.
 */
short int queryRegistrationEnd();

/**
 * Verifica se uma matr�cula pertence a algum candidato j� cadastrado.
 *
 * @param candidates O vetor de candidatos cadastrados.
 * @param n O n�mero de candidatos j� cadastrados.
 * @param id Um n�mero de matr�cula
 *
 * @return 1 se j� existe um candidato com o n�mero de matr�cula informado, 0
 * caso contr�rio.
 */
short int checkIfIdExist(Candidate *candidates, int n, int id);

#endif // VESTIBULAR_H_INCLUDED
