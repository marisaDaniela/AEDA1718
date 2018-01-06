#include "Sessao.h"

Sessao::Sessao(int id, string Genero_Arte, string Data){
	this->id=id;
	this->Genero_Arte=Genero_Arte;
	this->Data=Data;
}

void Sessao::setData(int Data){
	this->Data=Data;
}

int Sessao::getId() const{
	return id;
}

string Sessao::getData() const{
	return this->Data;
}

void Sessao::setGenero_Arte(string Genero_Arte){
	this->Genero_Arte=Genero_Arte;
}

string Sessao::getGenero_Arte() const{
	return this->Genero_Arte;
}

void Sessao::Compute_PrimeiraFase(void){
	for (int i = 0; i < this->classificacao_1fase.size(); i++) {
		this->classificacao_1fase[i].Compute_PrimeiraFase();
	}

}

void Sessao::Compute_SegundaFase(void){
	this->Ordenar_Classificacoes_PrimeiraFase();
	vector<Classificacao> Classificacao_1Fase_5Melhores;
	for (vector<Classificacao>::iterator it = classificacao_1fase.end() ; it != classificacao_1fase.end()-5; --it){
		Classificacao_1Fase_5Melhores.push_back(*it);
	}
	for (int i=0; i < Classificacao_1Fase_5Melhores.size(); i++){
		Classificacao_1Fase_5Melhores[i].Compute_SegundaFase(this->id_JuradoResponsavel);
	}

}

void Sessao::Ordenar_Classificacoes_PrimeiraFase(void){
	vector<Classificacao> Classificacoes_PrimeiraFase_Ordenado;

	sort(this->classificacao_1fase.begin(), this->classificacao_1fase.end());
}

ostream& operator<<(ostream& out, const Sessao &s)
{
	out << "ID: " << s.getId() << endl;
	out << "Genero de Arte: " << s.getGenero_Arte() << endl;
	out << "Data: " << s.getData() << endl;

	return out;
}

