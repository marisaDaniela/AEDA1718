#ifndef CANDIDATO_H_
#define CANDIDATO_H_

/** @defgroup Candidato Candidato
 * @{
 *	Criacao de classe para objecto Candidato e respectivas funcoes
 */
#include "Utils.h"
#include "Pessoa.h"


/**@{
 *
 * Classe para criacao do objecto Candidato
 */
class Candidato: public Pessoa
{
	string dataNascimento;
	string genero;
	vector<int> id_Sessoes;

public:
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
	Candidato(int id, string nome, string morada, string dataNascimento,string genero);
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

	/**@brief Overload do operador <
	 *
	 *@param c2 Endereco de Candidato
	 */
	bool operator<(const Candidato &c2);

	/**@brief Overload do operador <<
	 *
	 *@param out Endereco de ostream
	 *@param c1 Endereco de Candidato
	 */
	friend ostream& operator<<(ostream& out, const Candidato &c1);

};

#endif /* CANDIDATO_H_ */

