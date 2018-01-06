#include "Classificacao.h"

Classificacao::Classificacao(int id_Candidato,int id_Sessao, int nota_0, int nota_1, int nota_2){
    this->id_Candidato=id_Candidato;
    this->id_sessao = id_Sessao;
    this->notas[0] = nota_0;
    this->notas[1] = nota_1;
    this->notas[2] = nota_2;
}

void Classificacao::Compute_PrimeiraFase(void){
    this->Media_PrimeiraFase=((this->notas[0] + this->notas[1] + this->notas[2]) / 3);
};

bool operator<(const Classificacao &C1, const Classificacao &C2)
{
    if (C1.Media_PrimeiraFase <  C2.Media_PrimeiraFase) {
        return true;
    }
    else {
        return false;
    }
}

void Classificacao::Compute_SegundaFase(int Jurado_Responsavel){
    this->Media_SegundaFase=((this->notas[0] + this->notas[1] + this->notas[2] + this->notas[Jurado_Responsavel]) / 4);
}


ostream& operator<<(ostream& out, const Classificacao &c1) {
	out << "ID do Candidato: " << c1.id_Candidato << endl;
	out << "ID da Sessao: " << c1.id_sessao << endl;
	out << "Nota 1: " << c1.notas[0] << endl;
	out << "Nota 2: " << c1.notas[1] << endl;
	out << "Nota 3: " << c1.notas[2] << endl;
	return out;


}
