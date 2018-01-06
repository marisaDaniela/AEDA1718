#include "Menus.hpp"
#include "Utils.hpp"

using namespace std;

unsigned int maxId = 1;

void Casting::atualizaMaxID(int n)
{
	if (n > maxId)
		maxId = n + 1;
}

//Exceção - Se for introduzida uma frase muito grande, dá erro
class CandidatoOFB{};
class Overflow : public CandidatoOFB{
	virtual const char* what() const throw() {
		return "Frase muito grande!\n";
	}
};

Casting::Casting() {

	ifstream ficheiroJurados, ficheiroCandidatos, ficheiroSessoes, fichClassificacoes, fichCandidatosIndis;
	string line_e;

	ficheiroJurados.open("jurados.txt");

	if (!ficheiroJurados.is_open()) {
		cerr << "Ficheiro <jurados.txt> não encontrado. Tente de novo. \n";
	}

	while (getline(ficheiroJurados, line_e)) {
		istringstream i1;
		string idS, nome, morada, telS, generoArte;
		int id, tel;
		i1.str(line_e);
		getline(i1, idS, ';'); trim(idS); id = stoi(idS);
		getline(i1, nome, ';'); trim(nome);
		getline(i1, morada, ';'); trim(morada);
		getline(i1, telS, ';'); trim(telS); tel = stoi(telS);
		getline(i1, generoArte, ';'); trim(generoArte);

		atualizaMaxID(id);
		Jurado *j1 = new Jurado(id, nome, morada, tel, generoArte);

		jurados.push_back(j1);
	}

	ficheiroCandidatos.open("candidatos.txt");

	if (!ficheiroCandidatos.is_open())
	{
		cerr << "Ficheiro <candidatos.txt> não encontrado. Tente de novo. \n";
	}

	while (getline(ficheiroCandidatos, line_e)) {

		istringstream i1;
		string idS, nome, morada, dataNasc, generoArte, idadeS, periodo, razao;
		int id, idade;
		i1.str(line_e);
		getline(i1, idS, ';'); trim(idS); id = stoi(idS);
		getline(i1, nome, ';'); trim(nome);
		getline(i1, morada, ';'); trim(morada);
		getline(i1, dataNasc, ';'); trim(dataNasc);
		getline(i1, generoArte, ';'); trim(generoArte);
		getline(i1, idadeS, ';'); trim(idadeS); idade = stoi(idadeS);
		getline(i1, periodo, ';'); trim(periodo);
		getline(i1, razao, ';'); trim(razao);

		atualizaMaxID(id);

		BSTCandidatos.insert(Candidato(id, nome, morada, dataNasc, generoArte, idade, periodo, razao));
	}

	ficheiroSessoes.open("sessoes.txt");

	if (!ficheiroSessoes.is_open()) {
		cerr << "Ficheiro <sessoes.txt> não encontrado. Tente de novo. \n";
	}

	while (getline(ficheiroSessoes, line_e)) {
		istringstream i1;
		string idS, generoArte, data;
		int id;
		i1.str(line_e);
		getline(i1, idS, ';'); trim(idS); id = stoi(idS);
		getline(i1, generoArte, ';'); trim(generoArte);
		getline(i1, data, ';'); trim(data);

		atualizaMaxID(id);

		Sessao *s1 = new Sessao(id,generoArte, data);

		sessoes.push_back(s1);
	}

	fichClassificacoes.open("classificacoes.txt");

	if (!fichClassificacoes.is_open()) {
		cerr << "Ficheiro <classificacoes.txt> não encontrado. Tente de novo. \n";
	}

	while (getline(fichClassificacoes, line_e)) {
		istringstream i1;
		string idS, idSessaoS, nota1S, nota2S, nota3S;
		int id, idSessao, nota1, nota2, nota3 = 0;
		i1.str(line_e);

		getline(i1, idS, ';'); trim(idS); id = stoi(idS);
		getline(i1, idSessaoS, ';'); trim(idSessaoS); idSessao = stoi(idSessaoS);
		getline(i1, nota1S, ';'); trim(nota1S); nota1 = stoi(nota1S);
		getline(i1, nota2S, ';'); trim(nota2S); nota2 = stoi(nota2S);
		getline(i1, nota3S, ';'); trim(nota3S); nota3 = stoi(nota2S);

		Classificacao *cl1 = new Classificacao(id, idSessao, nota1, nota2, nota3);

		classificacoes.push_back(cl1);
	}

	fichCandidatosIndis.open("candidatosIndisponiveis.txt");

	if (!fichCandidatosIndis.is_open())
	{
		cerr << "Ficheiro <candidatosIndisponiveis.txt> nao encontrado! Tente de novo. \n";

	}

	while (getline(fichCandidatosIndis, line_e)) {
		istringstream i1;
		string idS, nome,morada, dataNasc, generoArte, idadeS, periodo, razao;
		int id, idade;
		i1.str(line_e);
		getline(i1, idS, ';'); trim(idS); id = stoi(idS);
		getline(i1, nome, ';'); trim(nome);
		getline(i1, morada, ';'); trim(morada);
		getline(i1, dataNasc, ';'); trim(dataNasc);
		getline(i1, generoArte, ';'); trim(generoArte);
		getline(i1, idadeS, ';'); trim(idadeS); idade = stoi(idadeS);
		getline(i1, periodo, ';'); trim(periodo);
		getline(i1, razao, ';'); trim(razao);

		atualizaMaxID(id);

		Candidato *c1 = new Candidato(id, nome, morada, dataNasc, generoArte, idade, periodo, razao);
		addCandidatoIndisponivel(c1);
	}
}

Casting::~Casting() {
}

int Casting::numCandidatos() const {
	return candidatos.size();
}

int Casting::numJurados() const {
	return jurados.size();
}

int Casting::numSessoes() const {
	return sessoes.size();
}

void Casting:: searchCandidatoById() {
	int idi;
	bool a = true;

	cout << "ID do Candidato: ";
	cin >> idi;

	for (unsigned int i = 0; i < candidatos.size(); i++) {
		if (candidatos[i]->getId() == idi) {
			cout << endl << *(candidatos[i]) << endl;
			a = false;
		}
	}

	if (a)
		cout << "Candidato com id: " << idi << " não encontrado!\n";
}

void Casting::searchJuradoById() {
	int idi;
	bool a = true;

	cout << "ID do Jurado: ";
	cin >> idi;

	for (unsigned int i = 0; i < jurados.size(); i++) {
		if (jurados[i]->getId() == idi) {
			a = false;
			cout << endl << *(jurados[i]);
		}
	}

	if (a) cout << "Jurado com id: " << idi << " não encontrado!\n";
}

bool sortCandidatosByID(Candidato *lhs, Candidato *rhs) {
	return lhs->getId() < rhs->getId();
}

void Casting::showAllCandidatos() {
	BSTCandidatos.printTree();
}

void Casting::showAllCandidatosGeneroArte() {
	cin.ignore();

	unsigned int option;

	cout << "\nQuer visualizar os candidatos de que género de arte?\n1" << endl;
	cout << "1. Música" << endl;
	cout << "2. Dança" << endl;
	cout << "3. Teatro" << endl;
	cout << "4. Pintura" << endl;
	cout << "5. Cinema" << endl;
	cout << "0. Back" << endl;
	cout << "Escolha um número [0-5]: ";
	cin >> option;

	if (option > 5) {
		cout << "Opção Inválida. Tente novamente.\n";

		pause();
	}

	switch (option) {
	case 1:
	{
		BSTItrIn<Candidato> it(BSTCandidatos);
		bool existe = false;

		while(!it.isAtEnd())
		{
			if (it.retrieve().getGenero() == "musica")
			{
				cout << it.retrieve().getId() << endl;
				cout << it.retrieve().getNome() << endl;
				cout << it.retrieve().getMorada() << endl;
				cout << it.retrieve().getDataNascimento() << endl;
				cout << it.retrieve().getGenero() << endl;
				cout << it.retrieve().getIdade() << endl;
				cout << endl;
				existe = true;
			}
			it.advance();
		}
		if(!existe){
			cout << "Não existe nenhum candidato inscrito em Música." << endl;
		}
	}
	break;

	case 2:
	{
		BSTItrIn<Candidato> it(BSTCandidatos);
		bool existe = false;

		while(!it.isAtEnd())
		{
			if (it.retrieve().getGenero() == "danca")
			{
				cout << it.retrieve().getId() << endl;
				cout << it.retrieve().getNome() << endl;
				cout << it.retrieve().getMorada() << endl;
				cout << it.retrieve().getDataNascimento() << endl;
				cout << it.retrieve().getGenero() << endl;
				cout << it.retrieve().getIdade() << endl;
				cout << endl;
				existe = true;
			}
			it.advance();
		}
		if(!existe){
			cout << "Não existe nenhum candidato inscrito em Dança.";
		}
	}
	break;

	case 3:
	{
		BSTItrIn<Candidato> it(BSTCandidatos);
		bool existe = false;

		while(!it.isAtEnd())
		{
			if (it.retrieve().getGenero() == "teatro")
			{
				cout << it.retrieve().getId() << endl;
				cout << it.retrieve().getNome() << endl;
				cout << it.retrieve().getMorada() << endl;
				cout << it.retrieve().getDataNascimento() << endl;
				cout << it.retrieve().getGenero() << endl;
				cout << it.retrieve().getIdade() << endl;
				cout << endl;
				existe = true;
			}
			it.advance();
		}

		if(!existe){
			cout << "Não existe nenhum candidato inscrito em Teatro.";
		}

	}
	break;

	case 4:
	{
		BSTItrIn<Candidato> it(BSTCandidatos);
		bool existe = false;

		while(!it.isAtEnd())
		{
			if (it.retrieve().getGenero() == "pintura")
			{
				cout << it.retrieve().getId() << endl;
				cout << it.retrieve().getNome() << endl;
				cout << it.retrieve().getMorada() << endl;
				cout << it.retrieve().getDataNascimento() << endl;
				cout << it.retrieve().getGenero() << endl;
				cout << it.retrieve().getIdade() << endl;
				cout << endl;
				existe = true;
			}
			it.advance();
		}
		if(!existe){
			cout << "Não existe nenhum candidato inscrito em Pintura.";
		}
	}

	break;
	case 5:
	{
		BSTItrIn<Candidato> it(BSTCandidatos);
		bool existe = false;

		while(!it.isAtEnd())
		{
			if (it.retrieve().getGenero() == "cinema")
			{
				cout << endl;
				cout << it.retrieve().getId() << endl;
				cout << it.retrieve().getNome() << endl;
				cout << it.retrieve().getMorada() << endl;
				cout << it.retrieve().getDataNascimento() << endl;
				cout << it.retrieve().getGenero() << endl;
				cout << it.retrieve().getIdade() << endl;
				cout << endl;
				existe = true;
			}
			it.advance();
		}

		if(!existe){
			cout << "Não existe nenhum candidato inscrito em Cinema.";
		}
	}

	break;

	case 0:
	{
		exit(1);
	}
	break;
	}

}


bool sortJuradosByID(Jurado *lhs, Jurado *rhs) {
	return lhs->getId() < rhs->getId();
}

void Casting::showAllJurados() {

	vector<Jurado *> t = jurados;

	sort(t.begin(), t.end(), sortJuradosByID);

	cout << "ID:     Nome:\n";

	for (int i = 0; i < t.size(); i++) {
		cout << t[i]->getId() <<" -   " << t[i]->getNome() << endl;
	}
}

bool sortSessoesByGenero(Sessao *lhs, Sessao *rhs) {
	return lhs->getGenero_Arte() < rhs->getGenero_Arte();
}

void Casting::showAllSessoes() {

	sort(sessoes.begin(), sessoes.end(), sortSessoesByGenero);

	for (int i = 0; i < sessoes.size(); i++) {
		cout << *(sessoes[i]) << endl;
	}
}

bool sortSessoesByID(Sessao *lhs, Sessao *rhs) {
	return lhs->getId() < rhs->getId();
}

void Casting::showAllSessoesSortById() {

	sort(sessoes.begin(), sessoes.end(), sortSessoesByID);

	for (int i = 0; i < sessoes.size(); i++) {
		cout << *(sessoes[i]) << endl;
	}
}

void Casting::criaCandidato() {

	cin.ignore();

	unsigned int conf;
	int id = maxId++;
	int idade;

	atualizaMaxID(id);

	string nome, morada, generoArte, confS, dataNascimento, dia, mes, ano, periodoDeIndisponibilidade, razao;

	cout << "Insira o nome: ";

	getline(cin, nome);

	if(nome.size() > SIZETEXTO) {
		throw Overflow();
	}

	cout << "Insira a morada: ";
	getline(cin, morada);
	cout << "Insira a dataNascimento do candidato\nDia: ";
	getline(cin, dia);
	cout << "Mês: ";
	getline(cin, mes);
	cout << "Ano: ";
	getline(cin, ano);

	dataNascimento = dia + "/" + mes + "/" + ano;

	idade = 2018 - stoi(ano);

	cout << "Insira o Género da Arte: ";
	getline(cin, generoArte);

	cout << "Insira o Periodo de Indisponibilidade: ";
	getline(cin, periodoDeIndisponibilidade);
	if(periodoDeIndisponibilidade != "0") {

		cout << "Insira a razao de Indisponibilidade: ";
		getline(cin, razao);
	}
	else
		razao = "0";
	cout << "Confirmar?\n1. Sim            0. Não" << endl;
	getline(cin, confS);
	conf = stoi(confS);

	if (conf > 1) {
		cout << "Opção Inválida.";
	}

	if (conf == 1) {
		if(periodoDeIndisponibilidade != "0")
		{
			Candidato* c1 = new Candidato(id, nome, morada, dataNascimento, generoArte, idade,periodoDeIndisponibilidade, razao);
			addCandidatoIndisponivel(c1);
			guardaCandidatosIndisponiveis();
		}
		else
		{
			BSTCandidatos.insert(Candidato(id, nome, morada, dataNascimento, generoArte, idade,periodoDeIndisponibilidade, razao));
			addCandidatoFilaPorGenero(new Candidato(id, nome, morada, dataNascimento, generoArte, idade,periodoDeIndisponibilidade, razao));
			guardaCandidatos();
		}


	}
	cout << "Candidato adicionado com sucesso.\n";


}

void Casting::criaJurado() {

	string confs;
	unsigned int conf;
	int telemovel;
	string nome, morada, telemovelS, generoArte;
	int id = maxId++;

	atualizaMaxID(id);

	cin.ignore();

	cout << "Insira o nome do Jurado: ";
	getline(cin, nome);
	if(nome.size() > SIZETEXTO) {
		throw Overflow();
	}

	cout << "Insira a morada do Jurado: ";
	getline(cin, morada);

	cout << "Insira o número de telemóvel do Jurado: ";
	getline(cin, telemovelS); telemovel = stoi(telemovelS);

	cout << "Insira o género de arte que o Jurado vai avaliar: ";
	getline(cin, generoArte);

	Jurado* j1 = new Jurado(id, nome, morada, telemovel, generoArte);
	cout << *j1 << endl;

	cout << "Confirmar?\n1. Sim            0. Não" << endl;
	getline(cin, confs);
	conf = stoi(confs);

	if (conf > 1) {
		cout << "Opção Inválida.\n";
	}

	if (conf == 1) {

		jurados.push_back(j1);

		guardaJurados();

		cout << "Jurado adicionado com sucesso.\n";
	}
}

void Casting::criaSessao() {

	string generoArte, data, dia, mes, ano;
	string confs;
	unsigned int conf;
	int id = maxId++;

	atualizaMaxID(id);

	cin.ignore();

	cout << "Género de arte da sessão: ";
	getline(cin, generoArte);

	if(generoArte.size() > SIZETEXTO) {
		throw Overflow();
	}

	cout << "Insira a data da sessão:\nDia: ";
	getline(cin, dia);
	cout << "Mês: ";
	getline(cin, mes);
	cout << "Ano: ";
	getline(cin, ano);

	data = dia + "/" + mes + "/" + ano;

	Sessao * s1 = new Sessao(id, generoArte, data);

	cout << * s1 << endl;

	cout << "Confirmar?\n1. Sim            0. Não" << endl;
	getline(cin, confs);
	conf = stoi(confs);

	if (conf >1) {
		cout << "Opção Inválida.\n";
	}

	if (conf == 1) {

		sessoes.push_back(s1);

		guardaSessoes();

		cout << "Sessão criada com sucesso!\n";
	}
}

void Casting::criaClassificacao() {
	string numCandidatoS, numSessaoS, nota0,nota1, nota2;
	unsigned int numCandidato, numSessao, nota_0, nota_1, nota_2;
	string confs;
	unsigned int conf;

	cin.ignore();

	cout << "Escolha o ID do Candidato que deseja avaliar.\n";

	showAllCandidatos();

	getline(cin, numCandidatoS); numCandidato = stoi(numCandidatoS);

	cout << "Escolha o ID da sessão para ser avaliado.\n";

	showAllSessoesSortById();

	getline(cin, numSessaoS); numSessao = stoi(numSessaoS);

	do {
		cout << "Introduza a primeira nota de 0 a 10:";
		getline(cin, nota0); nota_0 = stoi(nota0);

		if(nota_0 > 10) {
			cout << "Nota inválida. Tente novamente.\n";
		}
	} while(nota_0 > 10);

	do {
		cout << "Introduza a segunda nota de 0 a 10:";
		getline(cin, nota1); nota_1 = stoi(nota1);

		if(nota_1 > 10) {
			cout << "Nota inválida. Tente novamente!\n";
		}
	} while(nota_1 >10);

	do {
		cout << "Introduza a terceira nota de 0 a 10:";
		getline(cin, nota2); nota_2 = stoi(nota2);

		if(nota_2 > 10) {
			cout << "Nota inválida. Tente novamente.\n";
		}
	} while(nota_2 > 10);

	Classificacao * c1 = new Classificacao(numCandidato, numSessao, nota_0, nota_1, nota_2);

	cout << * c1 << endl;
	cout << "Confirmar?\n1. Sim            0. Não" << endl;
	getline(cin, confs);
	conf = stoi(confs);

	if (conf >1) {
		cout << "Opção Inválida.\n";
	}

	if (conf == 1) {
		classificacoes.push_back(c1);
		guardaClassificacoes();

		cout << "Classificação criada com sucesso.\n";
	}
}

void Casting::guardaCandidatos() {
	ofstream f;
	f.open("candidatos.txt");

	if (f.is_open()) {

		BSTItrIn<Candidato> it(BSTCandidatos);

		while(!it.isAtEnd())
		{
			f << it.retrieve().getId() << " ; "
					<< it.retrieve().getNome() << " ; "
					<< it.retrieve().getMorada() << " ; "
					<< it.retrieve().getDataNascimento() << " ; "
					<< it.retrieve().getGenero() << " ; "
					<< it.retrieve().getIdade();

			it.advance();

			if (!it.isAtEnd()) {
				f << endl;
			}
		}
	}
	f.close();
}

void Casting::guardaJurados() {
	ofstream f;
	f.open("jurados.txt");

	if (f.is_open()) {

		for (unsigned int i = 0; i < jurados.size(); i++) {
			f << jurados[i]->getId() << " ; "
					<< jurados[i]->getNome() << " ; "
					<< jurados[i]->getMorada() << " ; "
					<< jurados[i]->getTelemovel() << " ; "
					<< jurados[i]->getGenero();

			if (i != jurados.size() - 1) {
				f << endl;
			}
		}
		f.close();
	}
}

void Casting::guardaSessoes() {
	ofstream f;
	f.open("sessoes.txt");

	if (f.is_open()) {

		for (unsigned int i = 0; i < sessoes.size(); i++) {
			f << sessoes[i]->getId() << " ; "
					<< sessoes[i]->getGenero_Arte() << " ; "
					<< sessoes[i]->getData();

			if (i != sessoes.size() - 1) {
				f << endl;
			}
		}
		f.close();
	}
}

void Casting::guardaClassificacoes() {
	ofstream f;
	f.open("classificacoes.txt");

	if (f.is_open()) {

		for (unsigned int i = 0; i < classificacoes.size(); i++) {
			f << classificacoes[i]->id_Candidato << " ; "
					<< classificacoes[i]->id_sessao << " ; "
					<< classificacoes[i]->notas[0] << " ; "
					<< classificacoes[i]->notas[1] << " ; "
					<< classificacoes[i]->notas[2] << " ; ";

			if (i != classificacoes.size() - 1) {
				f << endl;
			}
		}
		f.close();
	}
}

void Casting::editaCandidato() {
	cin.ignore();
	unsigned int indice, temp;
	string is, ts;

	for (unsigned int i = 0; i < candidatos.size(); i++) {
		cout << i + 1 << ". " << candidatos[i]->getNome() << endl;
	}

	cout << "\nQual o Candidato que deseja modificar?";
	getline(cin, is);
	indice = stoi(is);

	if (indice < 1 || indice > candidatos.size()) {
		cout << "Opção Inválida. Tente novamente.\n";

		pause();

		editaCandidato();
	}

	cout << *(candidatos[indice - 1]) << endl;
	cout << "\nO que pretende alterar?" << endl
			<< "1. Nome." << endl
			<< "2. Morada." << endl
			<< "3. Data de Nascimento." << endl
			<< "4. Género de Arte." << endl;

	getline(cin, ts);
	temp = stoi(ts);

	if (temp < 1 || temp > 4) {
		cout << "Opção Inválida. Tente novamente.\n";
	}

	switch (temp) {
	case 1:
	{
		string nome;
		cout << "Qual o novo nome?";
		getline(cin, nome);

		if(nome.size() > SIZETEXTO) {
			throw Overflow();
		}

		candidatos[indice - 1]->setNome(nome);
		//guardaCandidatos();


		cout << "Nome alterado com sucesso.\n";
	}
	break;

	case 2:
	{
		string morada;
		cout << "Qual a nova morada?";
		cin >> morada;

		candidatos[indice - 1]->setMorada(morada);
		// guardaCandidatos();

		cout << "Morada alterada com sucesso.\n";

		pause();
	}
	break;

	case 3:
	{
		string data, dia, mes, ano;

		cout << "Qual a nova data?\nDia:";
		getline(cin, dia);
		cout << "Mês: ";
		getline(cin, mes);
		cout << "Ano: ";
		getline(cin, ano);

		data = dia + "/" + mes + "/" + ano;

		candidatos[indice - 1]->setDataNascimento(data);

		//guardaCandidatos();

		cout << "Data de Nascimento alterada com sucesso.\n";

		pause();
	}
	break;

	case 4:
	{
		string genero;
		cout << "Qual é o novo Género de Arte?";
		getline(cin, genero);

		candidatos[indice - 1]->setGenero(genero);

		// guardaCandidatos();

		cout << "Género de Arte alterado com sucesso.\n";

		pause();
	}
	break;
	}
}

void Casting::editaJurado() {

	cin.ignore();

	unsigned int indice, temp;
	string is, ts;

	for (unsigned int i = 0; i < jurados.size(); i++) {
		cout << i + 1 << ". " << jurados[i]->getNome() << endl;
	}

	cout << "\nQual o Jurado que deseja modificar?";
	getline(cin, is);

	indice = stoi(is);

	if (indice < 1 || indice > jurados.size()) {
		cout << "Opção Inválida. Tente novamente.\n";

		pause();

		editaJurado();
	}

	cout << *(jurados[indice - 1]) << endl;
	cout << "\nO que pretende alterar?" << endl
			<< "1. Nome." << endl
			<< "2. Morada." << endl
			<< "3. Telemóvel." << endl
			<< "4. Género de Arte." << endl;
	getline(cin, ts);
	temp = stoi(ts);

	if (temp < 1 || temp > 4) {
		cout << "Opção Inválida. Tente novamente.\n";
	}

	switch (temp) {
	case 1:
	{
		string nome;

		cout << "Qual é o novo nome do Jurado?";
		getline(cin, nome);

		if(nome.size() > SIZETEXTO) {
			throw Overflow();
		}

		jurados[indice - 1]->setNome(nome);

		guardaJurados();

		cout << "Nome alterado com sucesso.\n";
	}
	break;

	case 2:
	{
		string morada;

		cout << "Qual é a nova morada do Jurado?";
		getline(cin, morada);

		if(morada.size() > SIZETEXTO) {
			throw Overflow();
		}

		jurados[indice - 1]->setMorada(morada);

		guardaJurados();

		cout << "Morada alterada com sucesso.\n";

		pause();
	}
	break;

	case 3:
	{
		int telemovel;
		string telemovelS;

		cout << "Qual é o novo número de telemóvel do Jurado?";
		getline(cin, telemovelS); telemovel = stoi(telemovelS);

		jurados[indice - 1]->setTelemovel(telemovel);

		guardaJurados();

		cout << "Número de telemóvel alterado com sucesso.\n";

		pause();
	}
	break;
	case 4:
	{
		string genero;

		cout << "Qual é o novo género de arte?";
		getline(cin, genero);

		jurados[indice - 1]->setGenero(genero);

		guardaJurados();

		cout << "Género de arte alterado com sucesso.\n";

		pause();
	}
	break;
	}
}

void Casting::removeJurado(unsigned int i) {
	jurados.erase(jurados.begin() + i);
}

Candidato *  Casting::escolher_candidato(){
	cin.ignore();
	int id;
	string idS;



	cout << "Introduza o ID do candidato: " << endl;
	getline(cin, idS); id = stoi(idS);

	//TODO CHECK BST
	BSTItrIn<Candidato> it(this->BSTCandidatos);

	while(! it.isAtEnd())
	{
		if(it.retrieve().getId() == id){
			cout << "O candidato é válido." << endl;
			return &it.retrieve();
		}

		it.advance();
	}

	cout << "Introduziu um ID que não existe." << endl;
	pressKeyToContinue();
}


void Casting::apagaCandidato() {
	cin.ignore();

	unsigned int num, conf;
	string nums, confs;

	BSTCandidatos.printTree();

	cout << "\nInsira o ID do candidato que prentede apagar: ";
	cout << endl;
	getline(cin, nums);
	num = stoi(nums);



	BSTItrIn<Candidato> it(this->BSTCandidatos);

	while(!it.isAtEnd())
	{
		if(it.retrieve().getId() == num){

			BSTCandidatos.remove(it.retrieve());
		}

		it.advance();
	}


	cout << "Tem a certeza que deseja remover o candidato?\n1.Sim\n0.Não\n";

	getline(cin, confs);
	conf = stoi(confs);

	if ( conf > 1) {
		cout << "Opção Inválida. Tente novamente.";
	}

	if (conf == 1) {

		guardaCandidatos();


		cout << "Candidato apagado do sistema.";
	}
}


void Casting::apagaJurado() {
	cin.ignore();

	unsigned int num, conf;
	string nums, confs;

	for (unsigned int i = 0; i < jurados.size(); i++) {
		cout << i + 1 << ". " << jurados[i]->getNome() << endl;
	}
	cout << "\nQual dos jurados deseja apagar?";
	getline(cin, nums);
	num = stoi(nums);

	if (num > jurados.size() || num < 1) {
		cout << "Opção Inválida. Tente novamente.\n";

		apagaJurado();
	}

	cout << *jurados[num - 1] << endl;
	cout << "Tem a certeza que deseja remover o jurado?\n1.Sim\n0.Não ";
	getline(cin, confs);
	conf = stoi(confs);

	if (conf > 1) {
		cout << "Opção Inválida. Tente novamente.";
	}

	if (conf == 1) {

		removeJurado(num - 1);


		guardaJurados();

		cout << "Jurado apagado do sistema.";
	}
	else
		return;
}

void Casting::showClassificacoes(){
	vector <Classificacao *> a = classificacoes;
	vector <Candidato *> c = candidatos;
	string nomeCandidato;
	float media;

	for(int i = 0; i < classificacoes.size(); i++) {

		for(int j = 0; j < candidatos.size(); j++) {

			if(a[i]->id_Candidato == c[j]->getId()) {
				nomeCandidato = c[j]->getNome();
			}

		}

		media = (a[i]->notas[0] + a[i]->notas[1] + a[i]->notas[2])/3.0;
		cout << "___________________________\n";
		cout << endl << nomeCandidato << " - Sessão: " << a[i]->id_sessao  <<  "\nClassificações: " << a[i]->notas[0] <<  " - " << a[i]->notas[1]<<  " - " << a[i]->notas[2] <<
				"\nMédia: " << media << endl;
	}
}

void Casting::showClassificacoesSegundaFase(int id_sessao){
	cout << "classificacao_2fase.size()" << this->sessoes[id_sessao]->classificacao_2fase.size();

	for(int i=0; i < this->sessoes[id_sessao]->classificacao_2fase.size(); i++){
		cout << this->sessoes[id_sessao]->classificacao_2fase[i].id_Candidato << " Média: " << this->sessoes[id_sessao]->classificacao_2fase[i].Media_SegundaFase << endl;
	}
}


void Casting::alteraCandidato(){
	int id;
	char resposta;

	while(1)
	{
		BSTItrIn<Candidato> it(BSTCandidatos);
		if (it.isAtEnd())
		{
			cout << "Não há candidatos disponíveis para editar. Carregue no enter para continuar.\n";
			cin.get();
			return;
		}

		cout << "Os candidatos disponíveis são:\n";

		BSTCandidatos.printTree();

		cout << "Introduza o ID do candidato que deseja alterar: " << endl;
		cin >> id;

		BSTItrIn<Candidato> it1(BSTCandidatos);
		while (!it1.isAtEnd()){
			if (it1.retrieve().getId() == id)
			{
				it1.retrieve().alteraCandidato(BSTCandidatos);
				cout << "O candidato foi alterado.\n";
				cin.get();
				return;
			}

			it1.advance();
		}

		cout << "Esse candidato não existe.\n" << "Pretende voltar atrás? (S/N)\n";
		while(true){
			cin >> resposta;

			if(resposta == 'S'){
				cout << "Nenhum candidato foi alterado.\n";
				cout << "Carregue no enter para continuar.\n";
				cin.get();
				return;
			}
			else if(resposta == 'N')
				break;
			else
				cout << "Input invalido.\n" << "Pretende voltar atrás? (S/N)\n";
		}
	}
}

//PRIORITY QUEUES

void Casting::addCandidatoFilaPorGenero(Candidato * c1) {
	bool generoArtePresente = false;
	for(unsigned int i = 0; i < this->candidatosOrdenados.size(); i++){
		if(candidatosOrdenados[i].top()->getGenero() == c1->getGenero()){
			generoArtePresente = true;
			candidatosOrdenados[i].push(c1);
		}
	}
	if(generoArtePresente == false){
		candidatosFila newFila;
		newFila.push(c1);
		candidatosOrdenados.push_back(newFila);
	}

}


void Casting::atualizaCandidatoFila(Candidato c1){
	for(unsigned int i = 0; i < candidatosOrdenados.size(); i++){
		if(candidatosOrdenados[i].top()->getGenero() == c1.getGenero()){
			vector<Candidato *> candidatosVector;

			while(!candidatosOrdenados[i].empty()){
				candidatosVector.push_back(candidatosOrdenados[i].top());
				candidatosOrdenados[i].pop();
			}

			for(unsigned i2=0; i2< candidatosVector.size(); i2++){
				if(candidatosVector[i2]->getId() == c1.getId()){
					candidatosVector.erase(candidatosVector.begin()+i2);
					candidatosVector.insert(candidatosVector.begin()+i2, new Candidato(c1));
				}
			}

			while(candidatosVector.size() > 0){
				candidatosOrdenados[i].push(candidatosVector[0]);
			}
		}
	}

}

//int id, string nome, string morada, string dataNascimento,string genero, int idade,string periodoDeIndisponibilidade, string razao
void Casting::addCandidatosFilaDePrioridade(){
	BSTItrIn<Candidato> it(BSTCandidatos);
	while(! it.isAtEnd())
	{
		addCandidatoFilaPorGenero(&it.retrieve());

		it.advance();
	}

}
/**
 * for(unordered_set<Candidato*>::const_iterator it = hashIndisponiveis.begin(); it != hashIndisponiveis.end(); it++)
		{
			cout << (*it)->getId() << " - " << (*it)->getNome() << endl;
		}
 */

candidatosFila Casting::getFilaGenero(string generoArte) {

	candidatosFila vazio;

	for(unsigned int i = 0; i < candidatosOrdenados.size(); i++){
		if(candidatosOrdenados[i].top()->getGenero() == generoArte){

			return candidatosOrdenados[i];

			vazio = candidatosOrdenados[i];
			return vazio;
		}
	}

	return vazio;

}



string Casting::imprimeConteudoFila() const {
	stringstream ss;
	if( candidatosOrdenados.empty() ) ss << "Fila de candidatos vazia!" << endl;
	else
	{
		for(int i = 0; i < candidatosOrdenados.size(); i++)
		{
			candidatosFila buffer = candidatosOrdenados[i];
			while(!buffer.empty() ) {
				Candidato *obj = buffer.top();
				buffer.pop();
				ss << " " << obj;
			}
		}
	}
	return ss.str();

}



// HASH TABLES

unordered_set <Candidato *> Casting::getCandidatosIndisponiveisHash() const {
	return hashIndisponiveis;
}

// funcao para inserir candidato na tabela de dispersao

void Casting::addCandidatoIndisponivel(Candidato * c1) {
	hashIndisponiveis.insert(c1);
}

void Casting::guardaCandidatosIndisponiveis() {
	ofstream f;
	int count = 0;
	f.open("candidatosIndisponiveis.txt");

	if (f.is_open())
	{
		for (unordered_set<Candidato *>::const_iterator it = hashIndisponiveis.begin(); it != hashIndisponiveis.end(); it++)
		{

			f << (*it)->getId() << " ; "
					<< (*it)->getNome() << " ; "
					<< (*it)->getMorada() << " ; "
					<< (*it)->getDataNascimento() << " ; "
					<< (*it)->getGenero() << " ; "
					<< (*it)->getIdade() << " ; "
					<< (*it)->getPeriodoDeIndisponibilidade() << " ; "
					<< (*it)->getRazao() << " ; ";
			if (count != hashIndisponiveis.size() )
			{
				f << endl;
			}
			count++;
		}
		f.close();
	}
}

void Casting::apagaCandidatoHash() {
	cin.ignore();
	unsigned int id, conf;
	string nums, confs;

	for (unordered_set<Candidato*>::const_iterator it = hashIndisponiveis.begin(); it != hashIndisponiveis.end();it++) {
		cout << (*it)->getId() << ". " << (*it)->getNome() << endl;
	}

	cout << "\nQual dos candidatos deseja remover ";

	getline(cin, nums);

	id = stoi(nums);

	if (id < 1) {
		cout << "Invalida escolha! Tente novamente!\n";

		apagaCandidatoHash();
	}

	cout << "Tem a certeza que deseja remover o Candidato?\n1.Sim\n0.Nao ";

	getline(cin, confs);

	conf = stoi(confs);

	if (conf < 0 || conf > 1) {
		cout << "Opcao invalida!";
	}

	if (conf == 1) {
		Candidato* c1 = getCandidatoHashById(id);
		hashIndisponiveis.erase(c1);
		guardaCandidatosIndisponiveis();

		cout << "Candidato indisponivel removido!";
	}

	else
		cout << "Cancelado!\n";
	return;
}

bool Casting::removeCandidatoHash(int id) {
	Candidato* c1 = getCandidatoHashById(id);
	unordered_set<Candidato *>::iterator it = hashIndisponiveis.find(c1);

	if (it == hashIndisponiveis.end())
		return false;
	else {
		hashIndisponiveis.erase(it);

		return true;
	}
}

Candidato* Casting::getCandidatoHashById(int id) const {
	for (unordered_set<Candidato*>::const_iterator it = hashIndisponiveis.begin(); it != hashIndisponiveis.end(); it++) {

		if ((*it)->getId() == id)
			return (*it); //retorna o candidato
	}
	return 0;
}

void Casting::showAllCandidatosIndisponiveis()
{
	if(hashIndisponiveis.empty())
	{
		cout << "Nao existem candidatos indisponiveis!\n";
	}
	else{
		cout << "Candidatos indisponiveis:\n";

		for(unordered_set<Candidato*>::const_iterator it = hashIndisponiveis.begin(); it != hashIndisponiveis.end(); it++)
		{
			cout << (*it)->getId() << " - " << (*it)->getNome() << endl;
		}
	}
}

void Casting::examinarCandidatoIndisponivel()
{
	cin.ignore();
	unsigned int id, indice, temp;
	string is, ts;

	unordered_set<Candidato*>::const_iterator it;

	for (it = hashIndisponiveis.begin(); it != hashIndisponiveis.end(); it++)
	{
		cout << (*it)->getId() << "- " << (*it)->getNome() << endl;
	}


	cout << "\nQual o id do candidato que deseja examinar?";
	getline(cin, is);
	id = stoi(is);

	Candidato* c1 = getCandidatoHashById(id);
	cout << *c1 << endl;

}


