#include "Pessoa.h"

Pessoa::Pessoa(int id, string nome, string morada, string genero) {
	this->id = id;
	this->nome = nome;
	this->morada = morada;
	this->genero = genero;

}

string Pessoa::getGenero() const {
	return genero;
}

void Pessoa::setGenero(const string genero) {
	this->genero = genero;
}

Pessoa::~Pessoa() {

}

int Pessoa::getId() const
{
	return id;
}
void Pessoa::setId(const int id)
{
	this->id = id;
}

string Pessoa::getMorada() const {
	return morada;
}

void Pessoa::setMorada(const string morada) {
	this->morada = morada;
}

string Pessoa::getNome() const {
	return nome;
}

void Pessoa::setNome(const string nome) {
	this->nome = nome;
}



