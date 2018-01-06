#include "Candidato.h"

Candidato::	Candidato(int id, string nome, string morada, string dataNascimento,string genero): Pessoa(id, nome, morada, genero) {
	this->dataNascimento = dataNascimento;
	this->genero=genero;
}

Candidato::~Candidato() {
}

string Candidato::getDataNascimento() const
{
	return dataNascimento;
}

void Candidato::setDataNascimento(string dataNascimento) {
	this->dataNascimento = dataNascimento;
}

ostream& operator<<(ostream& out, const Candidato &c1) {
	out << "ID: " << c1.getId() << endl;
	out << "Nome: " << c1.getNome() << endl;
	out << "Morada: " << c1.getMorada() << endl;
	out << "Data Nascimento: " << c1.getDataNascimento() << endl;
	out << "Genero de Arte: " << c1.getGenero() << endl;

	return out;


}

bool Candidato::operator<(const Candidato &c2)
{
	return this->getId() < c2.getId();
}






