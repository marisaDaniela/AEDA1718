#include <iostream>
#include <string>
#include <fstream>
#include "Dicionario.h"
#include "BST.h"

using namespace std;


BST<PalavraSignificado> Dicionario::getPalavras() const
{ return palavras; }


////
//a)
bool PalavraSignificado::operator < (const PalavraSignificado &ps1) const {
	return palavra < ps1.palavra;
}

void Dicionario::lerDicionario(ifstream &fich)
{
	string palavra, significado;

	while(!fich.eof()){
		getline(fich, palavra);
		getline(fich, significado);

		PalavraSignificado p1(palavra, significado);
		palavras.insert(p1);
	}
}

bool PalavraSignificado::operator == (const PalavraSignificado &ps1) const {
	return palavra == ps1.palavra;
}

/////
//c)
string Dicionario::consulta(string palavra) const
{
	PalavraSignificado p1(palavra, "");
	PalavraSignificado px = palavras.find(p1);
	PalavraSignificado pNotFound("","");

	if(px == pNotFound)
	{
		BSTItrIn<PalavraSignificado> it(palavras);
		string palAntes ="", signifiAntes ="";
		while(!it.isAtEnd() && it.retrieve() < p1)
		{
			palAntes = it.retrieve().getPalavra();
			signifiAntes = it.retrieve().getSignificado();
			it.advance();
		}
		string palApos = "", signifApos="";
		if(!it.isAtEnd())
		{
			palApos = it.retrieve().getPalavra();
			signifApos = it.retrieve().getSignificado();
		}

		throw PalavraNaoExiste(palAntes,signifiAntes,palApos,signifApos);
	}
	else
		return px.getSignificado();
}

/////
//d)
bool Dicionario::corrige(string palavra, string significado)
{
	PalavraSignificado pDic = palavras.find(PalavraSignificado(palavra,""));
	if (pDic==PalavraSignificado("","")) {
		palavras.insert(PalavraSignificado(palavra,significado));
		return false;
	}
	else {
		palavras.remove(PalavraSignificado(palavra,""));
		pDic.setSignificado(significado);
		palavras.insert(pDic);
		return true;
	}

}

/////
//b)
void Dicionario::imprime() const
{
	BSTItrIn<PalavraSignificado> it(palavras);
	while(!it.isAtEnd())
	{
		cout << it.retrieve().getPalavra() << endl << it.retrieve().getSignificado() << endl;
		it.advance();
	}
}
