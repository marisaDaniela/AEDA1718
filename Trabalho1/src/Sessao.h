#ifndef SESSAO_H_
#define SESSAO_H_

/** @defgroup Sessao Sessao
 * @{
 *	Criacao de classe para objecto Sessao e respectivas funcoes
 */
#include "Utils.h"
#include "Classificacao.h"

/**@{
 *
 * Classe para criacao do objecto Sessao
 */
class Sessao {
private:
	int id;
	string Genero_Arte;
	string Data;

public:
	int id_Jurados[3];
	int id_JuradoResponsavel;
	vector<Classificacao> classificacao_1fase;
	vector<Classificacao> classificacao_2fase;

	/**
	 * @brief Alterar a data da Sessao
	 *
	 * Permite alterar o atributo privado "Data" da classe Sessao
	 *
	 * @param int com o novo valor de Data o para alterar .
	 */
	void setData(int);
	/**
	 * @brief Obter a Data da Sessao
	 *
	 * Permite aceder ao atributo privado "Data" da classe Sessao
	 *
	 * @return string com o valor do atributo privado "Data".
	 */
	string getData() const;

	/**
	 * @brief Obter o ID da Sessao
	 *
	 * Permite aceder ao atributo privado "id" da classe Sessao
	 *
	 * @return int com o valor do atributo privado "id".
	 */
	int getId() const;
	/**
	 * @brief Alterar o genero de arte da Sessao
	 *
	 * Permite alterar o atributo privado "Genero_Arte" da classe Sessao
	 *
	 * @param string com o novo valor de Genero_Arte o para alterar .
	 */
	void setGenero_Arte(string);
	/**
	 * @brief Obter o Genero de Arte da Sessao
	 *
	 * Permite aceder ao atributo privado "Genero_Arte" da classe Sessao
	 *
	 * @return string com o valor do atributo privado "Genero_Arte".
	 */
	string getGenero_Arte() const;


	/**
	 * @brief Classificacaoes da primeira fase
	 *
	 * Permite computar as classificacoes da primeira fase
	 *
	 */
	void Compute_SegundaFase(void);

	/**
	 * @brief Classificacaoes da segunda fase
	 *
	 * Permite computar as classificacoes da segunda fase
	 */

	void Compute_PrimeiraFase(void);

	/**
	 * @brief Ordenar classificacoes da primeira fase
	 *
	 * Permite ordenar as classificacoes da primeira fase
	 */

	void Ordenar_Classificacoes_PrimeiraFase(void);

	/**
	 * @brief Construtor de Sessao
	 */
	Sessao();
	/**
	 * @brief Construtor de Sessao
	 *
	 * Cria um objecto Sessao com um conjunto de atributos
	 *
	 * @param id ID da Sessao a ser criado
	 * @param Genero_Arte Genero de arte da Sessao a ser criado
	 * @param Data Data de nascimento da Sessao a ser criado

	 */
	Sessao(int id, string Genero_Arte, string Data); // Construtor

	/**@brief Overload do operador <<
	 *
	 *@param out Endereco de ostream
	 *@param s Endereco de Sessao
	 */
	friend ostream& operator<<(ostream& out, const Sessao &s);


};

#endif /* SESSAO_H_ */
