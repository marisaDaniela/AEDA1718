#ifndef _DIC
#define _DIC
#include <string>
#include <fstream>
#include "BST.h"


class PalavraSignificado {
      string palavra;
      string significado;
public:
       PalavraSignificado(string p, string s): palavra(p), significado(s) {}
       string getPalavra() { return palavra; }
       string getSignificado() { return significado; }
       void setSignificado(string sig) { significado = sig; }
       bool operator < (const PalavraSignificado &ps1) const;
       bool operator == (const PalavraSignificado &ps1) const;
};

class Dicionario
{
      BST<PalavraSignificado> palavras;
public:
      Dicionario(): palavras(PalavraSignificado("","")){};
      BST<PalavraSignificado> getPalavras() const;
      void lerDicionario(ifstream &fich);
      string consulta(string palavra) const;
      bool corrige(string palavra, string significado);
      void imprime() const;
};


// a alterar
class PalavraNaoExiste
{
	string palavraAntes, significadoAntes;
	string palavraApos, significadoApos;
public:
	PalavraNaoExiste(string palavraAntes, string significadoAntes, string palavraApos, string significadoApos) {
		this->palavraAntes=palavraAntes;
		this->palavraApos = palavraApos;
		this->significadoAntes = significadoAntes;
		this->significadoApos = significadoApos;
	}
	string getPalavraAntes() const { return palavraAntes; }
	string getSignificadoAntes() const { return significadoAntes; }
	string getPalavraApos() const { return palavraApos; }
	string getSignificadoApos() const { return significadoApos; }
};



#endif
