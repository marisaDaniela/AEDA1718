#include "zoo.h"
// Veterinario

//////
//a)
Veterinario::Veterinario(string nome, int cod){
	this->nome = nome;
	this->codOrdem = cod;
}

string Veterinario::getNome() const {
	return nome;
}

string Veterinario::getInformacao() const {
	stringstream ss;
	ss << nome << ", " << codOrdem;
	return ss.str();
}

// Animal

int Animal::maisJovem = 999;

Animal::Animal(string nome, int idade)
{
	this->nome = nome;
	this->idade = idade;
	this->vet = 0;
	if(idade < maisJovem)
		maisJovem = idade;
}
string Animal::getNome() const {
	return nome;
}

int Animal::getMaisJovem() {
	return maisJovem;
}

string Animal::getInformacao() const
{
	stringstream ss;
	ss << nome << ", " << idade;
	if(vet != 0) {
		ss << ", " << vet->getInformacao();
	}
	return ss.str();
}

Veterinario *Animal::getVeterinario() const
{
	return vet;
}
void Animal::setVeterinario(Veterinario *v1)
{
	this->vet = v1;
}

int Animal::getIdade() const {
	return idade;
}

// Cao

Cao::Cao(string nome, int idade, string raca):Animal(nome, idade) {
	this->raca = raca;
}

bool Cao::eJovem() const{
	if(idade < 5)
		return true;
	else
		return false;
}

string Cao::getInformacao() const {
	stringstream ss;
	ss << Animal::getInformacao() <<", " << raca;
	return ss.str();
}
// Voador
Voador::Voador(int vmax, int amax){
	this->velocidade_max = vmax;
	this->altura_max = amax;
}

string Voador::getInformacao() const {
	stringstream ss;
	ss << velocidade_max << ", " << altura_max;
	return ss.str();
}
// Morcego
Morcego::Morcego(string nome, int idade, int vmax, int amax):Animal(nome, idade), Voador(vmax, amax){

}

bool Morcego::eJovem() const{
	if(idade < 4)
		return true;
	else
		return false;
}

string Morcego::getInformacao() const {
	stringstream ss;
	ss << Animal::getInformacao() <<", " << Voador::getInformacao();
	return ss.str();
}

// Zoo
int Zoo::numAnimais() const {
	return animais.size();
}

int Zoo::numVeterinarios() const {
	return veterinarios.size();
}

/////
//b)
void Zoo::adicionaAnimal(Animal *a1){
	animais.push_back(a1);
}

/////
//c)
string Zoo::getInformacao() const {
	stringstream ss;
	for(unsigned int i = 0; i < animais.size(); i++)
	{
		ss << animais[i]->getInformacao() << endl;
	}
	return ss.str();
}

/////
//d)

bool Zoo::animalJovem(string nomeA) {
	for(int i = 0; i < animais.size(); i++)
	{
		if(animais[i]->getNome() == nomeA)
		{
			if(animais[i]->eJovem())
				return true;
		}
	}
	return false;
}

/////
//e----> pq veterinarios[i%veterinarios.size()]?

void Zoo::alocaVeterinarios(istream &isV){
	string nome, codOrdemS;
	long codOrdem;
	while(!isV.eof())
	{
		getline(isV, nome);
		getline(isV, codOrdemS);
		codOrdem = stoi(codOrdemS);
		Veterinario *v1 = new Veterinario(nome, codOrdem);
		veterinarios.push_back(v1);
	}
	for(unsigned int i = 0; i < animais.size(); i++)
	{
		animais[i]->setVeterinario(veterinarios[i%veterinarios.size()]);
	}

}
/////
//f)

//bool Zoo::removeVeterinario (string nomeV){
//	for(unsigned int i = 0; i < veterinarios.size(); i++)
//	{
//		if(veterinarios[i]->getNome() == nomeV)
//		{
//			for(unsigned j = 0; j < animais.size(); j++)
//			{
//				if(animais[j]->getVeterinario() == veterinarios[i]) {
//					animais[j]->setVeterinario(veterinarios[(i + 1)%veterinarios.size()]);
//				}
//			}
//
//			veterinarios.erase( veterinarios.begin() + i );
//			return true;
//		}
//	}
//	return false;
//}

/////
//g) Pode o vetor veterinarios ser “vector<Veterinario>” e não “vector<Veterinario *>

/**
 * std::vector<Object> obj creates obj on the stack and it will contain Object variables.
 *  Where is actual vector is located is up to your implementation of vector but it is almost
 *  certainly on the heap. std::vector<Object *> obj creates obj on the stack and it will
 *  contain pointers to Object variables. The disdadvantage here is that you must insure
 *  that all the pointers in the vector are valid for the lifeof the vector. Another
 *  disadvantage is that vector will move things around as the array expands an contracts and
 *  this may result in a delete of one of those pointers which will also delete the Object.
 *  You should use a vector of handles to Object (see the Bridge design pattern)
 *  rather than naked pointers.
 *
 *  You must also ask yourself if the Objects or the Object* are unique.
 *  If not, then to change an Object in a vector<Object> you will have to
 *  iterate the entire vector to find it. If ouy had a vector<Object*> you jusy
 *   change the Object and not worry about the vector.
 *   /
 **/

/////
//h)

bool Zoo::operator < (Zoo& zoo2) const {
	int soma1, soma2;
	for(int i = 0; i < zoo2.animais.size(); i++)
	{
		soma2 += animais[i]->getIdade();
	}
	for(int i = 0; i < this->animais.size(); i++)
	{
		soma1 += animais[i]->getIdade();
	}
	return soma1 < soma2;
}
