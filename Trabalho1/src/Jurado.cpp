#include "Jurado.h"

class telemovel_exception: public exception {
	virtual const char* what() const throw()
	{
		return "Número de Telemóvel Inválido.";
    }
} tele_ex;


Jurado::Jurado(int id, string nome, string morada, int telemovel, string genero) : Pessoa(id, nome, morada, genero) {
	this->telemovel = telemovel;

}


int Jurado::getTelemovel() const {
	return telemovel;
}

void Jurado::setTelemovel(int telemovel){
	if ((telemovel < 900000000) || (telemovel > 999999999)) {
		throw tele_ex;
	}
	else {
		this->telemovel=telemovel;
	}
}

Jurado::~Jurado() {

}

ostream& operator<<(ostream& out, const Jurado &j1) {
	out << "ID: " << j1.getId() << endl;
	out << "Nome: " << j1.getNome() << endl;
	out << "Morada: " << j1.getMorada() << endl;
	out << "Telemovel: " << j1.getTelemovel() << endl;
	out << "Genero de Arte: " << j1.getGenero() << endl;

	return out;


}

bool Jurado::operator<(const Jurado &j2)
{
	return this->getId() < j2.getId();
}


