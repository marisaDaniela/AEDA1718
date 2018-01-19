#include "Parque.h"
#include <vector>

using namespace std;

///////////
//a)
ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):lotacao(lot), numMaximoClientes(nMaxCli)
{
	this->vagas = lot;
}

unsigned int ParqueEstacionamento::getNumLugares() const {
	return lotacao;
}

unsigned int ParqueEstacionamento::getNumMaximoClientes() const {
	return numMaximoClientes;
}

///////////
//b)
int ParqueEstacionamento::posicaoCliente(const string & nome) const {
	for(int i = 0; i < clientes.size(); i++) {
		if(clientes[i].nome == nome)
			return i;
	}
	return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string & nome) {
	InfoCartao info;
	if(clientes.size() == numMaximoClientes)
		return false;
	if(posicaoCliente(nome) == -1)
	{
		info.nome = nome;
		info.presente = false;
		clientes.push_back(info);
		return true;
	}

	return false;
}

///////////
//c)
bool ParqueEstacionamento::entrar(const string & nome){
	int pos = posicaoCliente(nome);
	if(pos == -1)
		return false;
	if(vagas == 0)
		return false;

	if(clientes[pos].presente)
		return false;

	clientes[pos].presente = true;
	vagas--;
	return true;

}


///////////
//d)
bool ParqueEstacionamento::retiraCliente(const string & nome) {
	vector<InfoCartao>::iterator it;
	for(it = clientes.begin(); it != clientes.end(); it++)
	{
		if((*it).nome == nome){
			if((*it).presente == false)
			{
				clientes.erase(it);
				return true;
			}
		}

	}
	return false;
}

///////////
//e)
bool ParqueEstacionamento::sair(const string & nome) {
	int pos = posicaoCliente(nome);
	if(pos == -1)
		return false; // nao esta registado

	if(!clientes[pos].presente)
		return false;

	clientes[pos].presente = false;
	vagas++;
	return true;
}

///////////
//f)
unsigned int ParqueEstacionamento::getNumLugaresOcupados() const {
	return lotacao - vagas;
}

unsigned int ParqueEstacionamento::getNumClientesAtuais() const {
	return clientes.size();
}

///////////
//g)

const ParqueEstacionamento & ParqueEstacionamento::operator += (const ParqueEstacionamento & p2) {
	vector <InfoCartao>::const_iterator it;
	for(it = p2.clientes.begin(); it != p2.clientes.end(); it++)
	{
		adicionaCliente(it->nome);
		if(clientes.size() == numMaximoClientes)
			break;

	}
	return *this;
}

