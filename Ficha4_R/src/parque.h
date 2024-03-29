#ifndef PARQUE_H_
#define PARQUE_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class InfoCartao {
public:
	string nome;
	bool presente;
	int frequencia;
	bool operator == (const InfoCartao &ic1) const;
	bool operator < (const InfoCartao &ic1) const;
};

class ParqueEstacionamento {
	unsigned int vagas;
	const unsigned int lotacao;
	unsigned int numClientes;
	const unsigned int numMaximoClientes;
public:
	vector<InfoCartao> clientes; // na f mudei isto para aqui por causa da visibility (nao tava a dar)

	ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli);
	~ParqueEstacionamento();
	vector<InfoCartao> getClientes() const;
	bool adicionaCliente(const string & nome);
	bool retiraCliente(const string & nome);
	bool entrar(const string & nome);
	bool sair(const string & nome);
	unsigned int getNumLugares() const;
	unsigned int getNumLugaresOcupados() const;
	int posicaoCliente(const string & nome) const;
	friend ostream & operator<<(ostream & os, const ParqueEstacionamento & pe);
	int getFrequencia(const string &nome) const;
	InfoCartao getClienteAtPos(vector<InfoCartao>::size_type p) const;
	void ordenaClientesPorFrequencia();
	void ordenaClientesPorNome();
	vector<string> clientesGamaUso(int n1, int n2);
};


/////
//b)

class ClienteNaoExistente{
	string nome;
public:
	ClienteNaoExistente(string nm): nome(nm) {}
	string getNome() const { return nome; }
};


/////
//f)
class PosicaoNaoExistente{
	int valor;
public:
	PosicaoNaoExistente(int val): valor(val) {}
	int getValor() const { return valor; }
};

#endif /*PARQUE_H_*/
