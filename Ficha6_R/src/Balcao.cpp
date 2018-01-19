#include <queue>
#include <cstdlib>
#include "Balcao.h"
#include "exceptions.h"

using namespace std;


Cliente::Cliente() {
	numPresentes = rand() % 6; // random entre 1 e 5
}


int Cliente::getNumPresentes() const {
	return numPresentes;
}


Balcao::Balcao(int te): tempo_embrulho(te) {
	tempo_atual = 0;
	prox_chegada = (rand() % 20) + 1;
	prox_saida = 0;
	clientes_atendidos = 0;
}      


void Balcao:: proximoEvento()
{
	if(clientes.empty()==false){
		if(prox_chegada < prox_saida) {
			tempo_atual = prox_chegada;
			chegada();
		}
		else {
			tempo_atual = prox_saida;
			saida();
		}
	}
	else {
		tempo_atual = prox_chegada;
		chegada();
	}
}


void Balcao::chegada()
{
	cout << "tempo= " << tempo_atual<< endl;

	Cliente c1;
	if (clientes.empty())
		prox_saida=tempo_atual+c1.getNumPresentes()*tempo_embrulho;
	clientes.push(c1);
	cout << "chegou novo cliente com " << c1.getNumPresentes() << " presentes" << endl;
	prox_chegada=tempo_atual+(rand()%20)+1;
}   


void Balcao::saida()
{
	cout << "tempo= " << tempo_atual << endl;
	Cliente c1;

	try {
		c1 = getProxCliente();
	}
	catch(FilaVazia &e) {
		cout << e.getMsg() << endl;
		return;
	}

	clientes.pop();
	cout << "cliente atendido: " << c1.getNumPresentes() << " presentes" << endl;
	clientes_atendidos++;
	if(clientes.empty() != false)
		prox_saida = tempo_atual + clientes.front().getNumPresentes() * tempo_embrulho;
}


int Balcao::getTempoAtual() const { return tempo_atual; }


int Balcao::getProxChegada() const { return prox_chegada; }


ostream & operator << (ostream & out, const Balcao & b1)
{
	// a alterar
	return out;
}


int Balcao::getTempoEmbrulho() const {
	return tempo_embrulho;
}


int Balcao::getProxSaida() const {
	return prox_saida;
}


int Balcao::getClientesAtendidos() const {
	return clientes_atendidos;
}


Cliente & Balcao::getProxCliente() {
	if (clientes.empty()) throw FilaVazia();
	return clientes.front();
}


