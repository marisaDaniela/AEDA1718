/** @defgroup Casting Casting
 * @{
 *
 *	Criacao de classe para o Casting
 *
 */
#include "Utils.hpp"
#include "Candidato.hpp"
#include "Jurado.hpp"
#include "Sessao.hpp"
#include "Classificacao.hpp"
#include "BST.hpp"
#include <unordered_set>

using namespace std;

/**
 * Priority Queue
 */

class compCandidato {
public:
	compCandidato(){};
	bool operator()(Candidato * c1, Candidato * c2) const{
		return lessThan(c1->getDataNascimento(), c2->getDataNascimento());
	}
};

typedef priority_queue<Candidato*, vector<Candidato*>, compCandidato> candidatosFila;


/**
 * Hash table
 */

struct hashCandidato {
	// funcao de igualdade
	bool operator() (const Candidato &c1, const Candidato &c2) const {
		return c1.getId() == c2.getId();
	}
	// funcao de hash
	int operator() (const Candidato &c1) const {
		return c1.getId();
	}
};

typedef unordered_set <Candidato, hashCandidato, hashCandidato> hashCandidatosIndisponiveis;

class Casting {

public:
	string fichCandidatos, fichJurados, fichSessoes, fichClassificacaoes;

	vector<Candidato *> candidatos;
	vector<Jurado *> jurados;
	vector<Sessao *> sessoes;
	vector<Classificacao *> classificacoes;
	unsigned int maxId = 0;

	// Priority queues
	vector<candidatosFila> candidatosOrdenados;
	//candidatosFila objs;

	// HashTables
	unordered_set <Candidato *> hashIndisponiveis;

	//Vetor usado para guardar pointers para os objetos da classe Candidato
	BST<Candidato> BSTCandidatos = BST<Candidato>(Candidato());

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

	/**@brief Mostra candidatos por genero de arte
	 *
	 *Lista todos os candidatos por genero de arte existentes na BST
	 *
	 */
	void showAllCandidatosGeneroArte();

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

	/**
	 * Metodo que serve para escolher um candidato do vetor candidatos
	 *
	 * @return pointer para o candidato escolhido
	 */
	Candidato* escolher_candidato();

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
	void showClassificacoesSegundaFase(int id_sessao);

	/**@brief Altera Candidato
	 * Altera os atributos do candidato
	 */
	void alteraCandidato();

	/**
	 * @brief Adiciona candidato a fila
	 * Metodo para adicionar um candidato à fila de prioridade de acordo com o seu genero de arte
	 * @param c1 Candidato que vai ser adicionado à fila de prioridade
	 */
	void addCandidatoFilaPorGenero(Candidato * c1);

	/**
	 * @brief Adiciona candidato a fila
	 * Metodo para adicionar um candidato à fila de prioridade
	 */
	void addCandidatosFilaDePrioridade();

	/**
	 * @brief Atualiza Candidato Fila
	 * Metodo para atualizar as informações de um candidato que já existe numa determinada fila do vetor de listas de prioridades
	 * @param c1 Candidato que vai ser alterado na fila de prioridade
	 */
	void atualizaCandidatoFila(Candidato c1);

	/**
	 * @brief Fila de prioridade
	 * Retorna uma fila de prioridades de uma certa arte
	 * @param generoArte string com o genero que se pretende retornar
	 */
	candidatosFila getFilaGenero(string genertoArte);

	/**
	 * @brief imprimeConteudoFila
	 * @return Retorna o conteudo de uma fila de prioridades
	 */
	string imprimeConteudoFila() const;


	/**
	 * @brief get Candidatos Indisponiveis
	 * Metodo para aceder aos candidatos indisponiveis presentes na tabela de dispersao
	 */
	unordered_set <Candidato *> getCandidatosIndisponiveisHash() const ;

	/**
	 * @brief Adiciona Candidato Indisponivel
	 * Adiciona um candidato indisponivel à tabela de dispersão
	 * @param c1 Candidato para ser adicionado
	 */
	void addCandidatoIndisponivel(Candidato * c1);

	/**
	 * @brief Apaga candidato
	 * Apaga candidato da tabela de dispersao
	 */
	void apagaCandidatoHash();

	/**
	 * @brief Remove candidato
	 * Apaga candidato da tabela de dispersao e do ficheiro respetivo
	 * @param id id do candidato indisponivel para ser removido
	 * @return true or false
	 */
	bool removeCandidatoHash(int id);

	/**
	 * @brief get Candidato
	 * Acede ao candidato da tabela de dispersão através do id do candidato
	 * @param id int com o id do candidato para aceder
	 * @return Candidato
	 */
	Candidato* getCandidatoHashById(int id) const;

	/**
	 * @brief Mostra candidatos
	 * Mostra todos os candidatos indisponiveis presentes no ficheiro e na tabela de dispersao
	 */
	void showAllCandidatosIndisponiveis();

	/**
	 * @brief Procura candidato
	 * Procura candidato indisponivel na tabela de dispersao
	 */
	void searchCandidatoIndisponivel();

	/**
	 * @brief Guarda candidato
	 * Guarda os candidatos indisponiveis no ficheiro de texto "candidatosIndisponiveis.txt"
	 */
	void guardaCandidatosIndisponiveis();


	/**
	 * @brief Examina candidato
	 * Mostra as informações de um candidato indisponivel
	 */
	void examinarCandidatoIndisponivel();



};
