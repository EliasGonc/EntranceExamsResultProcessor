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
 * @param n Um menos o número de candidatos que já foram cadastrados.
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
 * @param n Um menos o número de candidatos que já foram cadastrados.
 */
void printResults(Candidate *candidates, int n);

/**
 * Verifica se a resposta do candidato é a mesma do gabarito para certa questão.
 *
 * @param answer A resposta da questão.
 * @param question Qual a questão.
 *
 * @return 1 se answer for igual ao gabarito (CORRECT_ANSWERS[question]), e 0
 *     caso contrário.
 */
short int isCorrectAnswer(char answer, short int question);

/**
 * Pega as respostas dos candidatos do vestibular de um arquivo de texto,
 * retornando o número de candidatos.
 *
 * @param candidatesPtr Um ponteiro para o vetor de candidatos.
 *
 * @return O número de candidatos do vestibular.
 */
int getAnswersFromFile(Candidate **candidatesPtr);

/**
 * Pede o nome do arquivo com as respostas dos candidatos do vestibular para o
 * usuário.
 *
 * @param fileName A string onde será guardado do arquivo por referência.
 *
 * @return Também retorna uma string com o nome do arquivo.
 */
char* getFileName(char *fileName);

/**
 * Lê o número de matrícula e as respostas dos candidatos do vestibular de um
 * arquivo aberto. O arquivo deve estar no formato:
 *     CCCCC abcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcde
 * onde CCCCC é o número da matrícula do candidato e o resto as respotsas para
 * cada uma das questões do vestibular.
 *
 * @param fp Um ponteiro para um arquivo aberto.
 * @param candidatesPtr Um ponteiro para o vetor de candidatos.
 *
 * @return Também retorna uma string com o nome do arquivo.
 */
int getFileData(FILE **fp, Candidate **candidatesPtr);

/**
 * Processa uma linha do arquivo de respostas, salvando os valores no vetor de
 * candidatos.
 *
 * @param candidatesPtr Um ponteiro para o vetor de candidatos.
 * @param id O número de matrícula do candidato
 * @param answers A string com as respostas do candidato.
 * @param n O número de candidatos já cadastrados.
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
 * usuário.
 *
 * @param candidatesPtr Um ponteiro para o vetor de candidatos.
 * @param n Um ponteiro para o número de candidatos já cadastrados.
 *
 * @return 1 se o último candidato cadastrado foi o último, 0 caso contrário.
 */
void getNewCandidateFromUser(Candidate **candidatesPtr, int *n);

/**
 * Pede para o usuário digitar o número de matrícula do candidato ou um número
 * negativo para encerrar.
 *
 * @param n O número de candidatos já cadastrados.
 *
 * @return O número de matrícula digitado pelo usuário
 * 0 caso contrário.
 */
int getIdFromUser(Candidate *candidates, int n);

/**
 * Pede para o usuário digitar as respostas do candidato.
 *
 * @return n Uma string contendo todas as respostas do candidato.
 */
char* getAnswersFromUser();

/**
 * Pergunta para o usuário se deseja cadastrar um novo candidato ou não.
 *
 * @returns 1 se o usuário deseja parar, 0 caso contrário.
 */
short int queryRegistrationEnd();

/**
 * Verifica se uma matrícula pertence a algum candidato já cadastrado.
 *
 * @param candidates O vetor de candidatos cadastrados.
 * @param n O número de candidatos já cadastrados.
 * @param id Um número de matrícula
 *
 * @return 1 se já existe um candidato com o número de matrícula informado, 0
 * caso contrário.
 */
short int checkIfIdExist(Candidate *candidates, int n, int id);

#endif // VESTIBULAR_H_INCLUDED
