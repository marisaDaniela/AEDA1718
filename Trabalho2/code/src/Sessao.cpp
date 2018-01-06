#include "Sessao.hpp"

Sessao::Sessao(int id, string Genero_Arte, string Data) {
    this->id=id;
    this->Genero_Arte=Genero_Arte;
    this->Data=Data;
}

void Sessao::setData(int Data) {
    this->Data=Data;
}

int Sessao::getId() const {
    return id;
}

string Sessao::getData() const {
    return this->Data;
}

void Sessao::setGenero_Arte(string Genero_Arte) {
    this->Genero_Arte=Genero_Arte;
}

string Sessao::getGenero_Arte() const {
    return this->Genero_Arte;
}

void Sessao::Compute_PrimeiraFase(void) {
    for (int i = 0; i < this->classificacao_1fase.size(); i++) {
        this->classificacao_1fase[i].Compute_PrimeiraFase();
    }
}

void Sessao::Compute_SegundaFase(void) {
    this->Ordenar_Classificacoes_PrimeiraFase();
    
    for(int i=this->classificacao_1fase.size()-1; i<classificacao_1fase.size()-6; i--) {
        this->classificacao_2fase.push_back(this->classificacao_1fase[i]);
    }
    
    for (int i=0; i < this->classificacao_2fase.size(); i++) {
        this->classificacao_2fase[i].Compute_SegundaFase(this->id_JuradoResponsavel);
    }
}

void Sessao::Ordenar_Classificacoes_PrimeiraFase(void) {
    vector<Classificacao> Classificacoes_PrimeiraFase_Ordenado;
    
    sort(this->classificacao_1fase.begin(), this->classificacao_1fase.end());
}

ostream& operator<<(ostream& out, const Sessao &s) {
    out << "ID: " << s.getId() << endl;
    out << "Genero de Arte: " << s.getGenero_Arte() << endl;
    out << "Data: " << s.getData() << endl;
    
    return out;
}
