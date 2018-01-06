#ifndef CANDIDATO_H_
#define CANDIDATO_H_

/** @defgroup Candidato Candidato
 * @{
 *	Criacao de classe para objecto Candidato e respectivas funcoes
 */
#include "Utils.hpp"
#include "Pessoa.hpp"

/**@{
 *
 * Classe para criacao do objecto Candidato
 */
class Candidato: public Pessoa {
	string dataNascimento;
	string genero;
	vector<int> id_Sessoes;
	int idade;

	// HashTables
	string periodoDeIndisponibilidade;
	string razao;

public:
	/**
	 * @brief Construtor de Candidato
	 */
	Candidato();

	/**
	 * @brief Construtor de Candidato
	 *
	 * Cria um objecto Candidato com um conjunto de atributos (id, nome, morada, dataNascimento, genero).
	 * Invoca o construtor da classe Pessoa(classe mae).
	 *
	 * @param id ID do Candidato a ser criado
	 * @param nome Nome do Candidato a ser criado
	 * @param morada  Morada do Candidato a ser criado
	 * @param dataNascimento Data de nascimento do Candidato a ser criado
	 * @param genero Genero do casting do Candidato a ser criado
	 */
	Candidato(int id, string nome, string morada, string dataNascimento,string genero, int idade, string periodoDeIndisponibilidade, string razao);

	/**
	 * @brief Destrutor de Candidato
	 */
	virtual ~Candidato();

	/**
	 * @brief Obter a Data de Nascimento do Candidato
	 *
	 * Permite aceder ao atributo privado "dataNascimento" da classe Candidato
	 *
	 * @return string com o valor do atributo privado "dataNascimento".
	 */
	string getDataNascimento() const;

	/**
	 * @brief Alterar a data de Nascimento do Candidato
	 *
	 * Permite alterar o atributo privado "dataNascimento" da classe Candidato
	 *
	 * @param dataNascimento string com o novo valor de dataNascimento para alterar .
	 */
	void setDataNascimento(string dataNascimento);

	/**
	 * @brief Obter a idade do Candidato
	 *
	 * Permite alterar o atributo privado "idade" da classe Candidato
	 *
	 * @return idade int
	 */
	int getIdade() const;

	/**
	 * @brief Alterar idade do Candidato
	 *
	 * Permite alterar o atributo privado "idade" da classe Candidato
	 *
	 * @param idade int com o novo valor de idade para alterar .
	 */
	void setIdade(int idade);

	/**@brief Overload do operador <
	 *
	 *@param c2 Endereco de Candidato
	 */
	bool operator<(const Candidato &c2) const;

	/**@brief Overload do operador <<
	 *
	 *@param out Endereco de ostream
	 *@param c1 Endereco de Candidato
	 */
	friend ostream& operator<<(ostream& out, const Candidato &c1);

	/**
	 * @brief Obter o periodo de indisponibilidade do Candidato
	 * Permite aceder ao atributo privado "periodoDeIndisponibilidade" da classe Candidato
	 * @return string com o valor do atributo privado "periodoDeIndisponibilidade".
	 */
	string getPeriodoDeIndisponibilidade() const;


	/**
	 * @brief Alterar o periodo de indisponibilidade do Candidato
	 * Permite alterar o atributo privado "periodoDeIndisponibilidade" da classe Candidato
	 * @param periodoDeIndisponibilidade string com o novo valor de periodoDeIndisponibilidade para alterar .
	 */
	void setPeriodoDeIndisponibilidade(string periodoDeIndisponibilidade);

	/**
	 * @brief Obter a razao da indisponibilidade do Candidato
	 * Permite aceder ao atributo privado "razao" da classe Candidato
	 * @return string com o valor do atributo privado "razao".
	 */
	string getRazao() const;

	/**
	 * @brief Alterar a razao de indisponibilidade do Candidato
	 * Permite alterar o atributo privado "razao" da classe Candidato
	 * @param raazao string com o novo valor de razao para alterar .
	 */
	void setRazao(string razao);

	/**
	 * @brief Alterar o Candidato
	 * Permite alterar os atributos da classe Candidato
	 * @param BSTCandidatos arvore binaria com os candidatos
	 */
	void alteraCandidato(BST<Candidato> BSTCandidatos);

};

#endif /* CANDIDATO_H_ */
