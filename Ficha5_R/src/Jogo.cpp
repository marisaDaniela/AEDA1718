/*
 * Jogo.cpp
 *
 */

#include "Jogo.h"
#include <sstream>
using namespace std;


unsigned Jogo::numPalavras(string frase)
{
	if ( frase.length() == 0 ) return 0;
	int n=1;
	int pos = frase.find(' ');
	while ( pos != string::npos ) {
		frase = frase.substr(pos+1);
		pos = frase.find(' ');
		n++;
	}
	return n;
}


Jogo::Jogo()
{
	// a alterar
}

Jogo::Jogo(list<Crianca>& lc2)
{
	this->criancas = lc2;
}

void Jogo::insereCrianca(const Crianca &c1)
{
	criancas.push_back(c1);
}

list<Crianca> Jogo::getCriancasJogo() const
{
	return this->criancas;
}

////
//b)
string Jogo::escreve() const
{
	stringstream ss;

	list<Crianca>::const_iterator it = criancas.begin();
	list<Crianca>::const_iterator it2 = criancas.end();

	while(it != it2){
		ss << it->escreve() << endl;
		it++;
	}
	return ss.str();
}


/////
//c)
Crianca& Jogo::perdeJogo(string frase)
{
	int numP = numPalavras(frase) - 1;
	list<Crianca>::iterator it = criancas.begin();
	list<Crianca>::iterator it2 = criancas.end();

	while(criancas.size() > 1){
		int criancasRestantes = numP % criancas.size();
		for(int i = 0; i < criancasRestantes; i++)
		{
			it++;
			if(it == it2)
				it = criancas.begin();
		}

		it = criancas.erase(it);
		if(it ==  it2)
			it = criancas.begin();
	}
	return *it;
}

/////
//d)
list<Crianca>& Jogo::inverte()
{
	criancas.reverse();
	return this->criancas;
}

/////
//e)
list<Crianca> Jogo::divide(unsigned id)
{
	list<Crianca>::iterator it = criancas.begin();
	list<Crianca>::iterator it2 = criancas.end();
	list<Crianca>listaParaRetornar;
	while(it != it2)
	{
		if(it->getIdade() > id)
		{
			listaParaRetornar.push_back(*it);
			it = criancas.erase(it);
		}
		else
			it++;
	}
	return listaParaRetornar;
}


void Jogo::setCriancasJogo(const list<Crianca>& l1)
{
	this->criancas = l1;
}

////
//f)
bool Jogo::operator==(Jogo& j2)
{
	if( this->criancas.size() != j2.criancas.size() ) return false;

	list<Crianca>::iterator ita;
	list<Crianca>::iterator itb = j2.criancas.begin();

	for(ita = this->criancas.begin() ; ita != this->criancas.end(); ita++, itb++){
		if( !((*ita) == (*itb)) ) return false;
	}
	return true;
}


list<Crianca> Jogo::baralha() const
{
	list<Crianca> lista = this->criancas;
	list<Crianca> novaLista;

	srand(time(NULL));

	while(!lista.empty())
	{
		int pos = rand() % lista.size();
		list<Crianca>::iterator it = lista.begin();
		for(int i = 0; i < pos; i++, it++);
		novaLista.push_back(*it);
		lista.erase(it);
	}
	return novaLista;

}
