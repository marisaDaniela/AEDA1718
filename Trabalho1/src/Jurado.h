#ifndef JURADO_H_
#define JURADO_H_
/** @defgroup Jurado Jurado
 * @{
 *	Criacao de classe para objecto Jurado e respectivas funcoes
 */

#include "Pessoa.h"


/**@{
 *
 * Classe para criacao do objecto Jurado
 */
class Jurado: public Pessoa {
	int telemovel;
	string genero;
public:
	/**
	 * @brief Construtor de Jurado
	 *
	 * Cria um objecto Jurado com um conjunto de atributos
	 * Invoca o construtor da classe Pessoa(classe mae).
	 *
	 * @param id ID do Jurado a ser criado
	 * @param nome Nome do Jurado a ser criado
	 * @param morada  Morada do Jurado a ser criado
	 * @param telemovel Telemovel do Jurado a ser criado
	 * @param genero Genero do casting do Jurado a ser criado
	 */
	Jurado(int id, string nome, string morada,int telemovel, string genero);

	/**
	 * @brief Destrutor de Candidato
	 */
	virtual ~Jurado();

	/**
	 * @brief Obter o telemovel do Jurado
	 *
	 * Permite aceder ao atributo privado "telemovel" da classe Jurado
	 *
	 * @return int com o valor do atributo privado "telemovel".
	 */
	int getTelemovel() const;

	/**
	 * @brief Alterar o telemovel do Jurado
	 *
	 * Permite alterar o atributo privado "telemovel" da classe Jurado
	 *
	 * @param telemovel int com o novo valor de telemovel para alterar .
	 */
	void setTelemovel(int telemovel);

	/**@brief Overload do operador <
	 *
	 *@param j2 Endereco de Jurado
	 */
	bool operator<(const Jurado &j2);

	/**@brief Overload do operador <<
	 *
	 *@param out Endereco de ostream
	 *@param j1 Endereco de jurado
	 */
	friend ostream& operator<<(ostream& out, const Jurado &j1);
};

#endif /* JURADO_H_ */
