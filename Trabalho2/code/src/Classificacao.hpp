#ifndef CLASSIFICACAO_H_
#define CLASSIFICACAO_H_

/** @defgroup Classificacao Classificacao
 * @{
 *	Criacao de classe para objecto Classificacao e respectivas funcoes
 */
#include "Utils.hpp"

/**@{
 *
 * Classe para criacao do objecto Classificacao
 */
class Classificacao{
    
public:
    int id_Candidato;
    int notas[3];
    int id_sessao;
    float Media_PrimeiraFase;
    float Media_SegundaFase;
    friend bool operator< (const Classificacao &C1, const Classificacao &C2);
    
    /**
     * @brief Classificacaoes da primeira fase
     *
     * Permite computar as classificacoes da primeira fase
     *
     */
    void Compute_PrimeiraFase(void);
    
    /**
     * @brief Classificacaoes da segunda fase
     *
     * Permite computar as classificacoes da segunda fase
     *@param Jurado_Responsavel int com o id do jurado responsavel para saber qual das notas na classificacao terá um maior peso
     */
    void Compute_SegundaFase(int Jurado_Resposavel);
    
    /**
     * @brief Destrutor de Classificacao
     */
    virtual ~Classificacao(){};
    
    /**
     * @brief Construtor de Classificacao
     */
    Classificacao(); // Construtor
    
    /**
     * @brief Construtor de Classificacao
     *
     * Cria um objecto Classificacao com um conjunto de atributos
     *
     * @param id ID do Candidato
     * @param id_Sessao ID da sessao
     * @param nota_0  Nota atribuida por um juri
     * @param nota_1 Nota atribuida por um juri
     * @param nota_2 Nota atribuida por um juri
     */
    Classificacao(int id_Candidato, int id_Sessao, int nota_0, int nota_1, int nota_2);
    
    /**@brief Overload do operador <<
     *
     *@param out Endereco de ostream
     *@param c1 Endereco de Classificacao
     */
    friend ostream& operator<<(ostream& out, const Classificacao &s);
};

#endif /* CLASSIFICACAO_H_ */
