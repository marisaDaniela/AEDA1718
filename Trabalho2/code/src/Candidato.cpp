#include "Candidato.hpp"

Candidato::Candidato(): Pessoa(){
	this->dataNascimento = " ";
	this->genero=" ";
}

Candidato::Candidato(int id, string nome, string morada, string dataNascimento,string genero, int idade,string periodoDeIndisponibilidade, string razao): Pessoa(id, nome, morada, genero) {
	this->dataNascimento = dataNascimento;
	this->genero = genero;
	this->idade = idade;
	this->periodoDeIndisponibilidade = periodoDeIndisponibilidade;
	this->razao = razao;
}

Candidato::~Candidato() {
}

string Candidato::getDataNascimento() const {
	return dataNascimento;
}

void Candidato::setDataNascimento(string dataNascimento) {
	this->dataNascimento = dataNascimento;
}

int Candidato::getIdade() const {
	return idade;
}

void Candidato::setIdade(int idade) {
	this->idade = idade;
}

string Candidato::getPeriodoDeIndisponibilidade() const {
	return periodoDeIndisponibilidade;
}

void Candidato::setPeriodoDeIndisponibilidade(string periodoDeIndisponibilidade) {
	this->periodoDeIndisponibilidade = periodoDeIndisponibilidade;
}

string Candidato::getRazao() const {
	return razao;
}

void Candidato::setRazao(string razao) {
	this->razao = razao;
}

ostream& operator<<(ostream& out, const Candidato &c1) {
	out << "ID: " << c1.getId() << endl;
	out << "Nome: " << c1.getNome() << endl;
	out << "Morada: " << c1.getMorada() << endl;
	out << "Data Nascimento: " << c1.getDataNascimento() << endl;
	out << "Genero de Arte: " << c1.getGenero() << endl;
	out << "Idade: " << c1.getIdade() << endl;

	return out;
}

bool Candidato::operator<(const Candidato &c2) const {
	return this->getIdade() < c2.getIdade();
}

void Candidato::alteraCandidato(BST<Candidato> BSTCandidatos){
	int opcao, idade;
	string nome, morada, dataNascimento, genero;

	do{
		cout << "Qual elemento deseja alterar?" << endl;
		cout << "\nO que pretende alterar?" << endl;
		cout << "1. Nome." << endl;
		cout << "2. Morada." << endl;
		cout << "3. Data de Nascimento." << endl;
		cout << "4. Género de Arte." << endl;
		cout << "5. Back" << endl;

		cin >> opcao;


		if (opcao > 5) {
			cout << "Opção inválida. Prima enter para tentar novamente.\n";

			continue;
		}

		cout << endl;
		switch (opcao)
		{
		case 1:
		{
			cout << "Introduza o novo nome do candidato : ";

			cin >> nome;

			setNome(nome);
		}
		break;

		case 2:
		{
			cout << "Introduza a nova morada: ";

			cin >> morada;

			setMorada(morada);
		}
		break;

		case 3:
		{

			cout << "Insira a nova data de nascimento do candidato (DD/MM/AA): ";

			cin >> dataNascimento;

			setDataNascimento(dataNascimento);

			cout << "Insira a idade correspondente: ";

			cin >> idade;

			setIdade(idade);


		}
		break;
		case 4:
		{
			cout << "Insira o novo género: ";

			cin >> genero;

			setGenero(genero);
		}
		break;
		case 5:
			break;


		}
	}while (opcao != 5);
}
