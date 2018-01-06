#ifndef PESSOA_H_
#define PESSOA_H_

/** @defgroup Pessoa Pessoa
 * @{
 *	Criacao de classe para objecto Pessoa e respectivas funcoes
 */
#include "Utils.hpp"

/**@{
 *
 * Classe para criacao do objecto Pessoa
 */
class Pessoa {
    int id;
    string nome;
    string morada;
   string genero;

public:
    /**
     * @brief Construtor de Pessoa
     */
    Pessoa();

    /**
     * @brief Construtor de Pessoa
     *
     * Cria um objecto Candidato com um conjunto de atributos (id, nome, morada, genero)
     *
     * @param id ID da Pessoa a ser criada
     * @param nome Nome da Pessoa a ser criada
     * @param morada  Morada da Pessoa a ser criada
     * @param genero Genero do casting ds Pessoa a ser criada
     */
    Pessoa(int id, string nome, string morada, string genero);
    
    /**
     * @brief Destrutor de Pessoa
     */
    virtual ~Pessoa();
    
    /**
     * @brief Obter o ID da Pessoa
     *
     * Permite aceder ao atributo privado "id" da classe Pessoa
     *
     * @return int com o valor do atributo privado "id".
     */
    int getId() const;
    
    /**
     * @brief Alterar o id da Pessoa
     *
     * Permite alterar o atributo privado "id" da classe Pessoa
     *
     * @param id string com o novo valor de id para alterar .
     */
    void setId(const int id);
    
    /**
     * @brief Obter a morada da Pessoa
     *
     * Permite aceder ao atributo privado "morada" da classe Pessoa
     *
     * @return string com o valor do atributo privado "morada".
     */
    string getMorada() const;
    
    /**
     * @brief Alterar a morada da Pessoa
     *
     * Permite alterar o atributo privado "morada" da classe Pessoa
     *
     * @param morada string com o novo valor de morada para alterar .
     */
    void setMorada(const string morada);
    
    /**
     * @brief Obter o nome da Pessoa
     *
     * Permite aceder ao atributo privado "nome" da classe Pessoa
     *
     * @return string com o valor do atributo privado "nome".
     */
    string getNome() const;
    
    /**
     * @brief Alterar a nome da Pessoa
     *
     * Permite alterar o atributo privado "nome" da classe Pessoa
     *
     * @param nome string com o novo valor de nome para alterar .
     */
    void setNome(const string nome);
    
    /**
     * @brief Obter o genero de arte da Pessoa
     *
     * Permite aceder ao atributo privado "genero" da classe Pessoa
     *
     * @return string com o valor do atributo privado "genero".
     */
    string getGenero() const;
    
    /**
     * @brief Alterar o genero de arte da Pessoa
     *
     * Permite alterar o atributo privado "genero" da classe Pessoa
     *
     * @param genero string com o novo valor de genero para alterar .
     */
    void setGenero(string genero);
};

#endif
