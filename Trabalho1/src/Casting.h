/** @defgroup Casting Casting
 * @{
 *
 *	Criacao de classe para o Casting
 *
 */
#include "Utils.h"
#include "Candidato.h"
#include "Jurado.h"
#include "Sessao.h"
#include "Classificacao.h"

using namespace std;

class Casting {
public:

	string fichCandidatos, fichJurados, fichSessoes, fichClassificacaoes;

	vector<Candidato *> candidatos;
	vector<Jurado *> jurados;
	vector<Sessao *> sessoes;
	vector<Classificacao *> classificacoes;
	unsigned int maxId = 0;

	/**
	 * @brief Construtor de Casting
	 *
	 */
	Casting();
	/** @brief Destrutor de Casting
	 *
	 */
	virtual ~Casting();

	void atualizaMaxID(int n);
	/**@brief Numero de Candidatos
	 *
	 * Tamanho do vetor candidatos
	 */
	int numCandidatos() const;

	/**@brief Numero de Jurados
	 *
	 * Tamanho do vetor jurados
	 */
	int numJurados() const;

	/**@brief Numero de Sessoes
	 *
	 * Tamanho do vetor sessoes
	 */
	int numSessoes() const;

	/**@brief Procura Candidato
	 *
	 * procura candidato no vetor candidatos pedindo o id ao utilizador
	 */
	void searchCandidatoById();

	/**@brief Procura Jurado
	 *
	 * procura jurado no vetor jurados pedindo o id ao utilizador
	 */
	void searchJuradoById();

	/**@brief Novo Candidato
	 *
	 * Acrescenta um candidao ao ficheiro candidatos.txt
	 *
	 */
	void criaCandidato();

	/**@brief Novo Jurado
	 *
	 * Acrescenta um jurado ao ficheiro jurados.txt
	 *
	 */
	void criaJurado();

	/**@brief Nova Sessao
	 *
	 * Acrescenta uma sessao ao ficheiro sessoes.txt
	 *
	 */
	void criaSessao();

	/**@brief Nova classificacao
	 *
	 * Acrescenta uma classificacao ao ficheiro classificacoes.txt
	 *
	 */
	void criaClassificacao();

	/**@brief Novo Candidato
	 *
	 * Acrescenta o candidato passado como argumento ao vector candidatos
	 *
	 * @param c1 Apontador para Candidato
	 */
	void addCandidatoSessao(Candidato* c1);

	/**@brief Novo Jurado
	 *
	 * Acrescenta o Jurado passado como argumento ao vector jurados
	 *
	 * @param j1 Apontador para Jurado
	 */
	void addJuradoSessao(Jurado* j1);

	/**@brief Mostra candidatos
	 *
	 *Lista todos os candidatos existentes no vetor candidatos
	 *
	 */
	void showAllCandidatos();
	/**@brief Mostra candidatos
	 *
	 *Lista todos os candidatos existentes no vetor candidatos ordenados pelo nome
	 *
	 */
	void showAllCandidatosOrderByName();

	/**@brief Mostra jurados
	 *
	 *Lista todos os jurados existentes no vetor jurados
	 *
	 */
	void showAllJurados();

	/**@brief Mostra sessoes
	 *
	 *Lista todos as sessoes existentes no vetor sessoes ordenadas por genero de arte
	 *
	 */
	void showAllSessoes();

	/**@brief Mostra sessoes
	 *
	 *Lista todos as sessoes existentes no vetor sessoes ordenadas por id
	 *
	 */
	void showAllSessoesSortById();

	/**@brief Escreve Candidatos
	 *
	 * Abre o ficheiro candidatos.txt e, percorrendo o vector candidatos, escreve os candidatos do
	 * vector e seus atributos no ficheiro.
	 */
	void guardaCandidatos();

	/**@brief Escreve Jurados
	 *
	 * Abre o ficheiro jurados.txt e, percorrendo o vector jurados, escreve os jurados do
	 * vector e seus atributos no ficheiro.
	 */
	void guardaJurados();

	/**@brief Escreve Sessoes
	 *
	 * Abre o ficheiro sessoes.txt e, percorrendo o vector sessoes, escreve as sessoes do
	 * vector e seus atributos no ficheiro.
	 */
	void guardaSessoes();

	/**@brief Escreve Classificacoes
	 *
	 * Abre o ficheiro classificacoes.txt e, percorrendo o vector classificacoes, escreve as sessoes do
	 * vector e seus atributos no ficheiro.
	 */
	void guardaClassificacoes();

	/**@brief Altera os atributos dos candidatos
	 *
	 *Para alterar uma caracteristica de um determinado candidato.
	 */
	void editaCandidato();

	/**@brief Altera os atributos dos jurados
	 *
	 *Para alterar uma caracteristica de um determinado jurado.
	 */
	void editaJurado();

	/**@brief Remove Candidatos
	 * Elimina o candidato correspondente ao indice passado como argumento do vector candidatos
	 * @param i Indica a posicao do candidato que se deseja remover no vector candidatos
	 */
	void removeCandidato(unsigned int i);

	/**@brief Remove Jurados
	 * Elimina o jurado correspondente ao indice passado como argumento do vector jurados
	 * @param i Indica a posicao do jurado que se deseja remover no vector jurados
	 */
	void removeJurado(unsigned int i);

	/**@brief Remover Candidato
	 *
	 * Opcao do menu que permite remover o candidato que o utilizador pretender.
	 */
	void apagaCandidato();

	/**@brief Remover Jurado
	 *
	 * Opcao do menu que permite remover o jurado que o utilizador pretender.
	 */
	void apagaJurado();

	/**@brief Mostra Classificacaoes
	 *
	 *Lista todos as classificacoes da primeira fase
	 *
	 */
	void showClassificacoes();


	/**@brief Mostra Classificacaoes
	 *
	 *Lista todos as classificacoes da segunda fase
	 *
	 */
	void showClassificacoesSegundaFase();


};
