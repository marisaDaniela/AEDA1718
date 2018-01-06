#include "Menus.h"
#include "Utils.h"

using namespace std;

unsigned int maxId = 1;

void Casting::atualizaMaxID(int n)
{
	if (n > maxId)
		maxId = n + 1;

}

class CandidatoOFB{};
class Overflow : public CandidatoOFB{
	virtual const char* what() const throw()
		{
		return "Frase muito grande!\n";
		}
};


Casting::Casting() {

	ifstream ficheiroJurados, ficheiroCandidatos, ficheiroSessoes, fichClassificacoes;
	string line_e;

	ficheiroJurados.open("jurados.txt");

	if (!ficheiroJurados.is_open())
	{
		cerr << "Ficheiro <jurados.txt> nao encontrado! Tente de novo. \n";

	}

	while (getline(ficheiroJurados, line_e)) {
		istringstream i1;
		string idS, nome,morada, telS, generoArte;
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
		cerr << "Ficheiro <candidatos.txt> nao encontrado! Tente de novo. \n";

	}

	while (getline(ficheiroCandidatos, line_e)) {
		istringstream i1;
		string idS, nome,morada, dataNasc, generoArte;
		int id;
		i1.str(line_e);
		getline(i1, idS, ';'); trim(idS); id = stoi(idS);
		getline(i1, nome, ';'); trim(nome);
		getline(i1, morada, ';'); trim(morada);
		getline(i1, dataNasc, ';'); trim(dataNasc);
		getline(i1, generoArte, ';'); trim(generoArte);

		atualizaMaxID(id);

		Candidato *c1 = new Candidato(id, nome, morada, dataNasc, generoArte);

		candidatos.push_back(c1);
	}

	ficheiroSessoes.open("sessoes.txt");

	if (!ficheiroSessoes.is_open())
	{
		cerr << "Ficheiro <sessoes.txt> nao encontrado! Tente de novo. \n";

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

	if (!fichClassificacoes.is_open())
	{
		cerr << "Ficheiro <classificacoes.txt> nao encontrado! Tente de novo. \n";

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
	cout << "ID do Candidato? ";
	cin >> idi;
	for (unsigned int i = 0; i < candidatos.size(); i++)
	{
		if (candidatos[i]->getId() == idi)
		{
			cout << endl << *(candidatos[i]) << endl; //
			a = false;
		}
	}
	if (a)
		cout << "Candidato com id: " << idi << " nao encontrado!\n";
}

void Casting::searchJuradoById() {
	int idi;
	bool a = true;
	cout << "ID do Jurado? ";
	cin >> idi;
	for (unsigned int i = 0; i < jurados.size(); i++) {
		if (jurados[i]->getId() == idi)
		{
			a = false;
			cout << endl << *(jurados[i]);
		}
	}
	if (a) cout << "Jurado com id: " << idi << " nao encontrado!\n";
}


bool sortCandidatosByID(Candidato *lhs, Candidato *rhs)
{
	return lhs->getId() < rhs->getId();
}
void Casting::showAllCandidatos()
{
	vector<Candidato *> a = candidatos;
	sort(a.begin(), a.end(), sortCandidatosByID);
	cout << "ID:       NOME:\n";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i]->getId() << " - " << a[i]->getNome() << endl;
	}
}

bool sortCandidatosByName(Candidato *lhs, Candidato *rhs)
{
	return lhs->getNome() < rhs->getNome() ;
}
void Casting::showAllCandidatosOrderByName()
{
	vector<Candidato *> a = candidatos;
	sort(a.begin(), a.end(), sortCandidatosByName);
	cout << "NOME:       ID\n";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i]->getNome() << " - " << a[i]->getId() << endl;
	}
}

bool sortJuradosByID(Jurado *lhs, Jurado *rhs)
{
	return lhs->getId() < rhs->getId();
}
void Casting::showAllJurados() {
	vector<Jurado *> t = jurados;
	sort(t.begin(), t.end(), sortJuradosByID);
	cout << "ID:     NOME:\n";
	for (int i = 0; i < t.size(); i++)
	{
		cout << t[i]->getId() <<" -   " << t[i]->getNome() << endl;
	}
}

bool sortSessoesByGenero(Sessao *lhs, Sessao *rhs)
{
	return lhs->getGenero_Arte() < rhs->getGenero_Arte();
}

void Casting::showAllSessoes()
{
	sort(sessoes.begin(), sessoes.end(), sortSessoesByGenero);
	for (int i = 0; i < sessoes.size(); i++)
	{
		cout << *(sessoes[i]) << endl;
	}
}

bool sortSessoesByID(Sessao *lhs, Sessao *rhs)
{
	return lhs->getId() < rhs->getId();
}

void Casting::showAllSessoesSortById()
{
	sort(sessoes.begin(), sessoes.end(), sortSessoesByID);
	for (int i = 0; i < sessoes.size(); i++)
	{
		cout << *(sessoes[i]) << endl;
	}
}

void Casting::criaCandidato()
{
	cin.ignore();
	unsigned int conf;
	int id = maxId++;

	atualizaMaxID(id);

	string nome, morada, generoArte, confS, dataNascimento, dia, mes, ano;
	cout << "Insira o nome: ";
	getline(cin, nome);
	if(nome.size() > SIZETEXTO)
	{
		throw Overflow();
	}

	cout << "Insira a morada: ";
	getline(cin, morada);

	cout << "Insira a dataNascimento\nDia: ";
	getline(cin, dia);
	cout << "Mes: ";
	getline(cin, mes);
	cout << "Ano: ";
	getline(cin, ano);

	dataNascimento = dia + "/" + mes + "/" + ano;

	cout << "Insira o generoArte: ";
	getline(cin, generoArte);


	Candidato* c1 = new Candidato(id, nome, morada, dataNascimento,generoArte);

	cout << *c1 << endl;

	cout << "Confirma?\n1. Sim            0. Nao" << endl;
	getline(cin, confS);
	conf = stoi(confS);
	if (conf >1)
	{
		cout<<" InvalidOption";
	}
	if (conf == 1)
	{
		candidatos.push_back(c1);
		guardaCandidatos();
		cout << "Candidato adicionado com sucesso!\n";
	}
}

void Casting::criaJurado() {
	string confs;
	unsigned int conf;
	int telemovel;
	string nome, morada, telemovelS, generoArte;
	int id = maxId++;

	atualizaMaxID(id);

	cin.ignore();

	cout << "Insira o nome: ";
	getline(cin, nome);
	if(nome.size() > SIZETEXTO)
	{
		throw Overflow();
	}


	cout << "Insira a morada: ";
	getline(cin, morada);

	cout << "Insira o telemovel: ";
	getline(cin, telemovelS); telemovel = stoi(telemovelS);

	cout << "Insira o generoArte: ";
	getline(cin, generoArte);

	Jurado* j1 = new Jurado(id, nome, morada, telemovel, generoArte);
	cout << *j1 << endl;

	cout << "Confirma?\n1. Sim            0. Nao" << endl;
	getline(cin, confs);
	conf = stoi(confs);
	if (conf > 1)
	{
		cout << "Invalid Option\n";
	}
	if (conf == 1)
	{
		jurados.push_back(j1);
		guardaJurados();
		cout << "Jurado adicionado com sucesso!\n";
	}

}

void Casting::criaSessao() {
	string generoArte, data, dia, mes, ano;
	string confs;
	unsigned int conf;
	int id = maxId++;

	atualizaMaxID(id);

	cin.ignore();

	cout << "Genero de Arte da sessao: ";
	getline(cin, generoArte);
	if(generoArte.size() > SIZETEXTO)
	{
		throw Overflow();
	}


	cout << "Insira a data da Sessao:\nDia: ";
	getline(cin, dia);
	cout << "Mes: ";
	getline(cin, mes);
	cout << "Ano: ";
	getline(cin, ano);

	data = dia + "/" + mes + "/" + ano;

	Sessao * s1 = new Sessao(id, generoArte, data);

	cout << * s1 << endl;

	cout << "Confirma?\n1. Sim            0. Nao" << endl;
	getline(cin, confs);
	conf = stoi(confs);
	if (conf >1)
	{
		cout << "Invalid Option\n";
	}
	if (conf == 1)
	{
		sessoes.push_back(s1);
		guardaSessoes();
		cout << "Sessao criada com sucesso!\n";
	}


}


void Casting::criaClassificacao()
{
	string numCandidatoS, numSessaoS, nota0,nota1, nota2;
	unsigned int numCandidato, numSessao, nota_0, nota_1, nota_2;
	string confs;
	unsigned int conf;

	cin.ignore();

	cout << "Escolha o id do candidato que deseja avaliar\n";
	showAllCandidatos();
	getline(cin, numCandidatoS); numCandidato = stoi(numCandidatoS);

	cout << "Escolha o id da sessao para ser avaliado \n";
	showAllSessoesSortById();
	getline(cin, numSessaoS); numSessao = stoi(numSessaoS);

	do{
		cout << "Introduza a primeira nota[0-10]:";
		getline(cin, nota0); nota_0 = stoi(nota0);

		if(nota_0 > 10)
		{
			cout << "Nota invalida. Tente novamente!\n";
		}

	}while(nota_0 > 10);

	do{
		cout << "Introduza a segunda nota[0-10]:";
		getline(cin, nota1); nota_1 = stoi(nota1);
		if(nota_1 > 10)
		{
			cout << "Nota invalida. Tente novamente!\n";
		}
	} while(nota_1 >10);

	do{
		cout << "Introduza a terceira nota[0-10]:";
		getline(cin, nota2); nota_2 = stoi(nota2);
		if(nota_2 > 10)
		{
			cout << "Nota invalida. Tente novamente!\n";
		}
	}while(nota_2 > 10);


	Classificacao * c1 = new Classificacao(numCandidato, numSessao, nota_0, nota_1, nota_2);

	cout << * c1 << endl;

	cout << "Confirma?\n1. Sim            0. Nao" << endl;
	getline(cin, confs);
	conf = stoi(confs);
	if (conf >1)
	{
		cout << "Invalid Option\n";
	}
	if (conf == 1)
	{
		classificacoes.push_back(c1);
		guardaClassificacoes();
		cout << "Classificacao criada com sucesso!\n";
	}


}

void Casting::guardaCandidatos()
{
	ofstream f;
	f.open("candidatos.txt");

	if (f.is_open())
	{
		for (unsigned int i = 0; i < candidatos.size(); i++)
		{
			f << candidatos[i]->getId() << " ; "
					<< candidatos[i]->getNome() << " ; "
					<< candidatos[i]->getMorada() << " ; "
					<< candidatos[i]->getDataNascimento() << " ; "
					<< candidatos[i]->getGenero();
			if (i != candidatos.size() - 1)
			{
				f << endl;
			}
		}
		f.close();
	}
}

void Casting::guardaJurados()
{
	ofstream f;
	f.open("jurados.txt");

	if (f.is_open())
	{
		for (unsigned int i = 0; i < jurados.size(); i++)
		{
			f << jurados[i]->getId() << " ; "
					<< jurados[i]->getNome() << " ; "
					<< jurados[i]->getMorada() << " ; "
					<< jurados[i]->getTelemovel() << " ; "
					<< jurados[i]->getGenero();
			if (i != jurados.size() - 1)
			{
				f << endl;
			}
		}
		f.close();
	}
}

void Casting::guardaSessoes()
{
	ofstream f;
	f.open("sessoes.txt");

	if (f.is_open())
	{
		for (unsigned int i = 0; i < sessoes.size(); i++)
		{
			f << sessoes[i]->getId() << " ; "
					<< sessoes[i]->getGenero_Arte() << " ; "
					<< sessoes[i]->getData();
			if (i != sessoes.size() - 1)
			{
				f << endl;
			}
		}
		f.close();
	}
}

void Casting::guardaClassificacoes()
{
	ofstream f;
	f.open("classificacoes.txt");

	if (f.is_open())
	{
		for (unsigned int i = 0; i < classificacoes.size(); i++)
		{
			f << classificacoes[i]->id_Candidato << " ; "
					<< classificacoes[i]->id_sessao << " ; "
					<< classificacoes[i]->notas[0] << " ; "
					<< classificacoes[i]->notas[1] << " ; "
					<< classificacoes[i]->notas[2] << " ; ";
			if (i != classificacoes.size() - 1)
			{
				f << endl;
			}
		}
		f.close();
	}
}


void Casting::editaCandidato()
{
	cin.ignore();
	unsigned int indice, temp;
	string is, ts;

	for (unsigned int i = 0; i < candidatos.size(); i++)
	{
		cout << i + 1 << ". " << candidatos[i]->getNome() << endl;
	}

	cout << "\nQual o candidato que deseja modificar?";
	getline(cin, is);
	indice = stoi(is);
	if (indice < 1 || indice > candidatos.size())
	{
		cout << "Opcao invalida! Tente novamente\n";
		pause();
		editaCandidato();
	}
	cout << *(candidatos[indice - 1]) << endl;

	cout << "\nO que pretende alterar?" << endl
			<< "1. Nome" << endl
			<< "2. Morada" << endl
			<< "3. Data de Nascimento" << endl
			<< "4. Genero de Arte" << endl;

	getline(cin, ts);
	temp = stoi(ts);

	if (temp < 1 || temp > 4)
	{
		cout << "Opcao invalida! Tente Novamente!\n";
	}
	switch (temp)
	{
	case 1:
	{
		string nome;
		cout << "Qual o novo nome?";
		getline(cin, nome);
		if(nome.size() > SIZETEXTO)
		{
			throw Overflow();
		}

		candidatos[indice - 1]->setNome(nome);
		guardaCandidatos();
		cout << "Nome alterado com sucesso!\n";
	}break;
	case 2:
	{
		string morada;
		cout << "Qual a nova morada?";
		cin >> morada;
		candidatos[indice - 1]->setMorada(morada);
		guardaCandidatos();
		cout << "Morada alterada com sucesso!\n";
		pause();
	}break;
	case 3:
	{
		string data, dia, mes, ano;
		cout << "Qual a nova data?\nDia:";
		getline(cin, dia);
		cout << "Mes: ";
		getline(cin, mes);
		cout << "Ano: ";
		getline(cin, ano);
		data = dia + "/" + mes + "/" + ano;
		candidatos[indice - 1]->setDataNascimento(data);
		guardaCandidatos();
		cout << "Data de nascimento alterada com sucesso!\n";
		// pause();
	}break;
	case 4:
	{
		string genero;
		cout << "Qual o novo genero?";
		getline(cin, genero);
		candidatos[indice - 1]->setGenero(genero);
		guardaCandidatos();
		cout << "Genero de arte alterado com sucesso!\n";
		//pause();
	}break;
	}
}

void Casting::editaJurado()
{
	cin.ignore();
	unsigned int indice, temp;
	string is, ts;

	for (unsigned int i = 0; i < jurados.size(); i++)
	{
		cout << i + 1 << ". " << jurados[i]->getNome() << endl;
	}

	cout << "\nQual o Jurado que deseja modificar?";
	getline(cin, is);
	indice = stoi(is);
	if (indice < 1 || indice > jurados.size())
	{
		cout << "Opcao invalida! Tente novamente\n";
		pause();
		editaJurado();
	}
	cout << *(jurados[indice - 1]) << endl;

	cout << "\nO que pretende alterar?" << endl
			<< "1. Nome" << endl
			<< "2. Morada" << endl
			<< "3. Telemovel" << endl
			<< "4. Genero" << endl;
	getline(cin, ts);
	temp = stoi(ts);

	if (temp < 1 || temp > 4)
	{
		cout << "Opcao invalida! Tente Novamente!\n";
	}
	switch (temp)
	{
	case 1:
	{
		string nome;
		cout << "Qual o novo nome?";
		getline(cin, nome);
		if(nome.size() > SIZETEXTO)
		{
			throw Overflow();
		}
		jurados[indice - 1]->setNome(nome);
		guardaJurados();
		cout << "Nome alterado com sucesso!\n";
	}break;
	case 2:
	{
		string morada;
		cout << "Qual a nova Morada?";
		getline(cin, morada);
		if(morada.size() > SIZETEXTO)
		{
			throw Overflow();
		}
		jurados[indice - 1]->setMorada(morada);
		guardaJurados();
		cout << "Morada alterada com sucesso!\n";
		//pause();
	}break;
	case 3:
	{
		int telemovel;
		string telemovelS;
		cout << "Qual o novo numero de telemovel?";
		getline(cin, telemovelS); telemovel = stoi(telemovelS);
		jurados[indice - 1]->setTelemovel(telemovel);
		guardaJurados();
		cout << "Telemovel alterado com sucesso!\n";
		//pause();
	}break;
	case 4:
	{
		string genero;
		cout << "Qual o novo genero?";
		getline(cin, genero);
		jurados[indice - 1]->setGenero(genero);
		guardaJurados();
		cout << "Genero de arte alterado com sucesso!\n";
		//pause();
	}break;
	}


}

void Casting::removeCandidato(unsigned int i)
{
	candidatos.erase(candidatos.begin() + i);
}

void Casting::removeJurado(unsigned int i)
{
	jurados.erase(jurados.begin() + i);
}

void Casting::apagaCandidato()
{
	cin.ignore();
	unsigned int num, conf;
	string nums, confs;

	for (unsigned int i = 0; i < candidatos.size(); i++)
	{
		cout << i + 1 << ". " << candidatos[i]->getNome() << endl;
	}
	cout << "\nQual dos atletas deseja apagar ";
	getline(cin, nums);
	num = stoi(nums);

	if (num > candidatos.size() || num < 1)
	{
		cout << "Invalida escolha! Tente novamente!\n";
		apagaCandidato();
	}

	cout << *candidatos[num - 1] << endl;
	cout << "Tem a certeza que deseja remover o candidato?\n1.Sim\n0.Nao ";
	getline(cin, confs);
	conf = stoi(confs);
	if ( conf > 1)
	{
		cout << "Opcao invalida!";
	}
	if (conf == 1)
	{
		removeCandidato(num - 1);
		guardaCandidatos();
		cout << "Candidato apagado do sistema!";
	}
	else
		return;
}

void Casting::apagaJurado()
{
	cin.ignore();
	unsigned int num, conf;
	string nums, confs;

	for (unsigned int i = 0; i < jurados.size(); i++)
	{
		cout << i + 1 << ". " << jurados[i]->getNome() << endl;
	}
	cout << "\nQual dos jurados deseja apagar ";
	getline(cin, nums);
	num = stoi(nums);

	if (num > jurados.size() || num < 1)
	{
		cout << "Invalida escolha! Tente novamente!\n";
		apagaJurado();
	}
	cout << *jurados[num - 1] << endl;
	cout << "Tem a certeza que deseja remover o jurado?\n1.Sim\n0.Nao ";
	getline(cin, confs);
	conf = stoi(confs);
	if (conf > 1)
	{
		cout << "Opcao invalida!";
	}
	if (conf == 1)
	{
		removeJurado(num - 1);
		guardaJurados();
		cout << "Jurado apagado do sistema!";
	}
	else
		return;
}

/*
bool sortCandidatosByName(Candidato *lhs, Candidato *rhs)
{
	return lhs->getNome() < rhs->getNome() ;
}
void Casting::showAllCandidatosOrderByName()
{
	vector<Candidato *> a = candidatos;
	sort(a.begin(), a.end(), sortCandidatosByName);
	cout << "NOME:       ID\n";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i]->getNome() << " - " << a[i]->getId() << endl;
	}
}*/
void Casting::showClassificacoes(){
	vector <Classificacao *> a = classificacoes;
	vector <Candidato *> c = candidatos;
	string nomeCandidato;
	float media;

	for(int i = 0; i < classificacoes.size(); i++)
	{
		for(int j = 0; j < candidatos.size(); j++)
		{
			if(a[i]->id_Candidato == c[j]->getId())
			{
				nomeCandidato = c[j]->getNome();
			}

		}
		media = (a[i]->notas[0] + a[i]->notas[1] + a[i]->notas[2])/3.0;
		cout << "___________________________\n";
		cout << endl << nomeCandidato << " - Sessao: " << a[i]->id_sessao  <<  "\nClassificacoes: " << a[i]->notas[0] <<  " - " << a[i]->notas[1]<<  " - " << a[i]->notas[2] <<
				"\nMedia: " << media << endl;
	}

}

void Casting::showClassificacoesSegundaFase(){
	vector <Classificacao *> a = classificacoes;
	vector <Candidato *> c = candidatos;
	string nomeCandidato;
	float media;

	for(int i = 0; i < classificacoes.size(); i++)
	{
		for(int j = 0; j < candidatos.size(); j++)
		{
			if(a[i]->id_Candidato == c[j]->getId())
			{
				nomeCandidato = c[j]->getNome();
			}

		}
		media = (a[i]->notas[0] + a[i]->notas[1] + a[i]->notas[2] + a[i]->notas[2])/3.0; // Jurado responsavel o 3, corrigir isto
		cout << "___________________________\n";
		cout << endl << nomeCandidato << " - Sessao: " << a[i]->id_sessao  <<  "\nClassificacoes: " << a[i]->notas[0] <<  " - " << a[i]->notas[1]<<  " - " << a[i]->notas[2] <<
				"\nMedia: " << media << endl;
	}
}



