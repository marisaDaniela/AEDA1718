#include "Menus.hpp"

void pause()
{
	cin.get();
}


void inicio(Casting c1) {
	unsigned int op;

	cout << "*" << string(50, '*') << "*" << endl;
	cout << "*" << string(13, ' ') << "ORGANIZAÇÃO DE CASTINGS" << string(14, ' ')<<"*" << endl;
	cout << "*" << string(50, ' ') << "*" << endl;
	cout << "*" << "         Algoritmos e Estrutura de Dados          " << "*" << endl;
	cout << "*" << string(21, ' ') << "2017/2018" << string(20, ' ') << "*" << endl;
	cout << "*" << string(50, ' ') << "*" << endl;
	cout << "*" << string(18, ' ') << "André Ferreira " << string(17, ' ') << "*" << endl;
	cout << "*" << string(18, ' ') << "Marisa Oliveira" << string(17, ' ') << "*" << endl;
	cout << "*" << string(50, ' ') << "*" << endl;
	cout << "*" << string(50, '*') << "*" << endl;
	cout << "Prima: 1 para começar\n       0 para sair\n";

	cin >> op;

	if ( op > 1) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n";

		pause();

		inicio(c1);
	}

	switch (op) {
	case 1:
	{
		primeiroMenu(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void primeiroMenu(Casting c1) {
	unsigned int op;

	cout << "*" << string(50, '*') << "*" << endl;
	cout << "*" << string(19, ' ') << "CASTINGS++" << string(21, ' ') << "*" << endl;
	cout << "*" << string(50, '*') << "*" << endl;
	cout << "* " << " 1. Candidatos       " << string(28, ' ') << "*" << endl;
	cout << "* " << " 2. Jurados          " << string(28, ' ') << "*" << endl;
	cout << "* " << " 3. Sessões          " << string(28, ' ') << "*" << endl;
	cout << "* " << " 4. Informações      " << string(28, ' ') << "*" << endl;
	cout << "* " << " 5. Back             " << string(28, ' ') << "*" << endl;
	cout << "* " << " 0. Exit             " << string(28, ' ') << "*" << endl;
	cout << "*" << string(50, '*') << "*" << endl;
	cout << "Escolha um número [0-5]: \n";

	cin >> op;

	if (op > 5) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n";

		pause();

		primeiroMenu(c1);
	}

	switch (op) {
	case 1:
	{
		gestaoCandidatos(c1);
	}
	break;
	case 2:
	{
		gestaoJurados(c1);
	}
	break;
	case 3:
	{
		gestaoSessoes(c1);
	}
	break;
	case 4:
	{
		Informacoes(c1);
	}
	break;
	case 5:
	{
		inicio(c1);
	}
	break;

	case 0:
	{
		exit(1);
	}
	break;
	}
}

void gestaoCandidatos(Casting c1){
	unsigned int op;

	cout << "*" << string(50, '*') << "*" << endl;
	cout << "*" << string(17, ' ') << "GERIR CANDIDATOS" << string(17, ' ') << "*" << endl;
	cout << "*" << string(50, '*') << "*" << endl;
	cout << "* " << " 1. Inscrever      " << string(30, ' ') << "*" << endl;
	cout << "* " << " 2. Remover        " << string(30, ' ') << "*" << endl;
	cout << "* " << " 3. Editar         " << string(30, ' ') << "*" << endl;
	cout << "* " << " 4. Pesquisar      " << string(30, ' ') << "*" << endl;
	cout << "* " << " 5. Listar         " << string(30, ' ') << "*" << endl;
	cout << "* " << " 6. Indisponíveis  " << string(30, ' ') << "*" << endl;
	cout << "* " << " 7. Back           " << string(30, ' ') << "*" << endl;
	cout << "* " << " 0. Exit           " << string(30, ' ') << "*" << endl;
	cout << "*" << string(50, '*') << "*" << endl;
	cout << "Escolha um numero [0-7]: \n";

	cin >> op;

	if (op > 7) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n";

		pause();

		gestaoCandidatos(c1);
	}

	switch (op) {
	case 1:
	{
		adicionarCandidato(c1);
	}
	break;
	case 2:
	{
		removerCandidato(c1);
	}
	break;
	case 3:
	{
		editarCandidato(c1);
	}
	break;
	case 4:
	{
		pesquisarCandidato(c1);
	}
	break;
	case 5:
	{
		MenuListarCandidatos(c1);
	}
	break;
	case 6:
	{
		menuIndisponiveis(c1);
	}
	break;
	case 7:
	{
		primeiroMenu(c1);
	}
	break;

	case 0:
	{
		exit(1);
	}
	break;
	}
}

void MenuListarCandidatos(Casting c1){
	unsigned int op;

	cout << "*" << string(50, '*') << "*" << endl;
	cout << "*" << string(16, ' ') << "LISTAR CANDIDATOS" << string(17, ' ') << "*" << endl;
	cout << "*" << string(50, '*') << "*" << endl;
	cout << "* " << " 1. Todos          " << string(30, ' ') << "*" << endl;
	cout << "* " << " 2. Por género de arte" << string(27, ' ') << "*" << endl;
	cout << "* " << " 3. Indisponíveis  " << string(30, ' ') << "*" << endl;
	cout << "* " << " 4. Back           " << string(30, ' ') << "*" << endl;
	cout << "* " << " 0. Exit           " << string(30, ' ') << "*" << endl;
	cout << "*" << string(50, '*') << "*" << endl;
	cout << "Escolha um número [0-4] : \n";

	cin >> op;

	if (op > 4) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n";

		pause();

		MenuListarCandidatos(c1);
	}

	switch (op) {
	case 1:
	{
		listarCandidatosTodos(c1);
	}
	break;
	case 2:
	{
		listarCandidatosPorGeneroDeArte(c1);
	}
	case 3:
	{
		listarCandidatosIndisponiveis(c1);
	}
	break;
	case 4:
	{
		gestaoCandidatos(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void adicionarCandidato(Casting c1) {
	unsigned int op;

	c1.criaCandidato();

	cout << endl << "Prima: 1. Voltar                       0. Sair";

	cin >> op;

	if ( op > 1) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

		cin >> op;
	}

	switch (op) {
	case 1:
	{
		gestaoCandidatos(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void removerCandidato(Casting c1) {

	c1.apagaCandidato();

	unsigned int op;

	cout << endl << "Prima: 1. Voltar                       0. Sair";

	cin >> op;

	if (op > 1) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

		cin >> op;
	}

	switch (op) {
	case 1:
	{
		gestaoCandidatos(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void editarCandidato(Casting c1) {
	c1.alteraCandidato();

	unsigned int op;

	cout << endl << "Prima: 1. Voltar                       0. Sair";

	cin >> op;

	if (op > 1) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

		cin >> op;
	}

	switch (op) {
	case 1:
	{
		gestaoCandidatos(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void pesquisarCandidato(Casting c1) {
	unsigned int op;

	c1.escolher_candidato();

	cout << endl << "Prima: 1. Voltar                       0. Sair";

	cin >> op;

	if (op > 1) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

		cin >> op;
	}

	switch (op) {
	case 1:
	{
		gestaoCandidatos(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void listarCandidatosTodos(Casting c1) {
	unsigned int op;

	c1.showAllCandidatos();

	cout << endl << "Prima: 1. Voltar                       0. Sair";

	cin >> op;

	if (op > 1) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

		cin >> op;
	}

	switch (op) {
	case 1:
	{
		MenuListarCandidatos(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void listarCandidatosPorGeneroDeArte(Casting c1){
	unsigned int op;

	c1.showAllCandidatosGeneroArte();

	cout << endl << "Prima: 1. Voltar                       0. Sair";

	cin >> op;

	if (op > 1) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

		cin >> op;
	}

	switch (op) {
	case 1:
	{
		MenuListarCandidatos(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void menuIndisponiveis(Casting c1)
{
	unsigned int op;
	cout << "*" << string(50, '*') << "*" << endl;
	cout << "*" << string(10, ' ') << "GERIR CANDIDATOS INDISPONÍVEIS" << string(11, ' ') << "*" << endl;
	cout << "*" << string(50, '*') << "*" << endl;
	cout << "* " << " 1. Remover        " << string(30, ' ') << "*" << endl;
	cout << "* " << " 2. Listar         " << string(30, ' ') << "*" << endl;
	cout << "* " << " 3. Examinar       " << string(30, ' ') << "*" << endl;
	cout << "* " << " 4. Back           " << string(30, ' ') << "*" << endl;
	cout << "* " << " 0. Exit           " << string(30, ' ') << "*" << endl;
	cout << "*" << string(50, '*') << "*" << endl;
	cout << "Escolha um numero[0-4] : \n";
	cin >> op;

	if (op > 4) {
		cout << "Opção inválida. Prima enter para tentar novamente.";

		pause();

		menuIndisponiveis(c1);
	}

	switch (op)
	{
	case 1:
	{
		unsigned int op;

		c1.apagaCandidatoHash();

		cout << endl << "Prima: 1. Voltar                       0. Sair";

		cin >> op;

		if (op > 1) {
			cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

			cin >> op;
		}

		switch (op)
		{
		case 1:
		{
			menuIndisponiveis(c1);
		}
		break;
		case 0:
		{
			exit(1);
		}
		break;
		}
	}
	break;
	case 2:
	{
		unsigned int op;
		c1.showAllCandidatosIndisponiveis();
		cout << endl << "Prima: 1. Voltar                       0. Sair";
		cin >> op;

		if (op > 1) {
			cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

			cin >> op;
		}

		switch (op)
		{
		case 1:
		{
			menuIndisponiveis(c1);
		}
		break;
		case 0:
		{
			exit(1);
		}
		break;
		}
	}
	break;

	case 3:
	{
		unsigned int op;
		c1.examinarCandidatoIndisponivel();
		cout << endl << "Prima: 1. Voltar                       0. Sair";
		cin >> op;

		if (op > 1) {
			cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

			cin >> op;
		}

		switch (op)
		{
		case 1:
		{
			menuIndisponiveis(c1);
		}
		break;
		case 0:
		{
			exit(1);
		}
		break;
		}
	}
	break;
	case 4:
	{
		gestaoCandidatos(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}



/****************************************************************************************************************************************
 * 			  			 									JURADOS
 * **************************************************************************************************************************************/

void gestaoJurados(Casting c1){
	unsigned int op;

	cout << "*" << string(50, '*') << "*" << endl;
	cout << "*" << string(17, ' ') << "GERIR JURADOS   " << string(17, ' ') << "*" << endl;
	cout << "*" << string(50, '*') << "*" << endl;
	cout << "* " << " 1. Inscrever      " << string(30, ' ') << "*" << endl;
	cout << "* " << " 2. Remover        " << string(30, ' ') << "*" << endl;
	cout << "* " << " 3. Editar         " << string(30, ' ') << "*" << endl;
	cout << "* " << " 4. Pesquisar      " << string(30, ' ') << "*" << endl;
	cout << "* " << " 5. Listar         " << string(30, ' ') << "*" << endl;
	cout << "* " << " 6. Classificar    " << string(30, ' ') << "*" << endl;
	cout << "* " << " 7. Back           " << string(30, ' ') << "*" << endl;
	cout << "* " << " 0. Exit           " << string(30, ' ') << "*" << endl;

	cout << "*" << string(50, '*') << "*" << endl;
	cout << "Escolha um número [0-7]: \n";
	cin >> op;

	if (op > 7) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n";

		pause();

		gestaoJurados(c1);
	}

	switch (op) {
	case 1:
	{
		adicionarJurado(c1);
	}
	break;
	case 2:
	{
		removerJurado(c1);
	}
	break;
	case 3:
	{
		editarJurado(c1);
	}
	break;
	case 4:
	{

		pesquisarJurado(c1);
	}
	break;
	case 5:
	{
		listarJurados(c1);

	}
	break;
	case 6:
	{
		adicionarClassificacao(c1);

	}
	break;
	case 7:
	{
		primeiroMenu(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void adicionarJurado(Casting c1) {
	unsigned int op;

	c1.criaJurado();

	cout << endl << "Prima: 1. Voltar                       0. Sair";

	cin >> op;

	if ( op > 1) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

		cin >> op;
	}

	switch (op) {
	case 1:
	{
		gestaoJurados(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void adicionarClassificacao(Casting c1){
	unsigned int op;

	c1.criaClassificacao();

	cout << endl << "Prima: 1. Voltar                       0. Sair";

	cin >> op;

	if ( op > 1) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

		cin >> op;
	}

	switch (op) {
	case 1:
	{
		gestaoJurados(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void removerJurado(Casting c1) {
	c1.apagaJurado();

	unsigned int op;

	cout << endl << "Prima: 1. Voltar                       0. Sair";

	cin >> op;

	if (op > 1) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

		cin >> op;
	}

	switch (op)
	{
	case 1:
	{
		gestaoJurados(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void editarJurado(Casting c1) {
	c1.editaJurado();

	unsigned int op;

	cout << endl << "Prima: 1. Voltar                       0. Sair";

	cin >> op;

	if (op > 1) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

		cin >> op;
	}

	switch (op) {
	case 1:
	{
		gestaoJurados(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void pesquisarJurado(Casting c1) {
	unsigned int op;

	c1.searchJuradoById();

	cout << endl << "Prima: 1. Voltar                       0. Sair";

	cin >> op;

	if (op > 1) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

		cin >> op;
	}

	switch (op) {
	case 1:
	{
		gestaoJurados(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void listarJurados(Casting c1) {
	unsigned int op;

	c1.showAllJurados();

	cout << endl << "Prima: 1. Voltar                       0. Sair";

	cin >> op;

	if (op > 1) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

		cin >> op;
	}

	switch (op)
	{
	case 1:
	{
		gestaoJurados(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

/********************************************************************************
 * 										SESSOES
 ********************************************************************************/

void gestaoSessoes(Casting c1) {
	unsigned int op;

	cout << "*" << string(50, '*') << "*" << endl;
	cout << "*" << string(17, ' ') << "GERIR SESSÕES   " << string(17, ' ') << "*" << endl;
	cout << "*" << string(50, '*') << "*" << endl;
	cout << "* " << " 1. Criar          " << string(30, ' ') << "*" << endl;
	cout << "* " << " 2. Listar         " << string(30, ' ') << "*" << endl;
	cout << "* " << " 3. Back           " << string(30, ' ') << "*" << endl;
	cout << "* " << " 0. Exit           " << string(30, ' ') << "*" << endl;
	cout << "*" << string(50, '*') << "*" << endl;
	cout << "Escolha um nÚmero [0-5]: \n";
	cin >> op;

	if (op > 3) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n";

		pause();

		gestaoSessoes(c1);
	}

	switch (op) {
	case 1:
	{
		criaSessao(c1);
	}
	break;
	case 2:
	{

		listarSessao(c1);
	}
	break;
	case 3:
	{
		primeiroMenu(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void criaSessao(Casting c1) {
	unsigned int op;

	c1.criaSessao();

	cout << endl << "Prima: 1. Voltar                       0. Sair";

	cin >> op;

	if ( op > 1) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

		cin >> op;
	}

	switch (op) {
	case 1:
	{
		gestaoSessoes(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void listarSessao(Casting c1) {
	unsigned int op;

	c1.showAllSessoes();

	cout << endl << "Prima: 1. Voltar                       0. Sair";

	cin >> op;

	if (op > 1) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";
		cin >> op;
	}

	switch (op) {
	case 1:
	{
		gestaoSessoes(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}


/********************************************************************************
 * 									INFORMACOES
 ********************************************************************************/

void Informacoes(Casting c1) {
	unsigned int op;

	cout << "*" << string(50, '*') << "*" << endl;
	cout << "*" << string(17, ' ') << "  INFORMACOES   " << string(17, ' ') << "*" << endl;
	cout << "*" << string(50, '*') << "*" << endl;
	cout << "* " << " 1. Classificações " << string(30, ' ') << "*" << endl;
	cout << "* " << " 2. Mostrar Candidatos" << string(27, ' ') << "*" << endl;
	cout << "* " << " 3. Mostrar Jurados" << string(30, ' ') << "*" << endl;
	cout << "* " << " 4. Mostrar Sessões" << string(30, ' ') << "*" << endl;
	cout << "* " << " 5. Mostrar Fila   " << string(30, ' ') << "*" << endl;
	cout << "* " << " 6. Back           " << string(30, ' ') << "*" << endl;
	cout << "* " << " 0. Exit           " << string(30, ' ') << "*" << endl;
	cout << "*" << string(50, '*') << "*" << endl;
	cout << "Escolha um número [0-6]: \n";
	cin >> op;

	if (op > 6) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n";

		pause();

		Informacoes(c1);
	}

	switch (op) {
	case 1:
	{
		showClassificacoes(c1);
	}
	break;
	case 2:
	{
		unsigned int op;

		c1.showAllCandidatos();

		cout << endl << "Prima: 1. Voltar                       0. Sair";

		cin >> op;

		if (op > 1) {

			cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

			cin >> op;
		}

		switch (op)
		{
		case 1:
		{
			Informacoes(c1);
		}
		break;
		case 0:
		{
			exit(1);
		}
		break;
		}
	}
	break;
	case 3:
	{
		unsigned int op;
		c1.showAllJurados();
		cout << endl << "Prima: 1. Voltar                       0. Sair";
		cin >> op;

		if (op > 1) //
		{
			cout << "Opcao Invalida. Tente novamente!\nOpcao:";
			cin >> op;

		}

		switch (op)
		{
		case 1:
		{
			Informacoes(c1);
		}break;
		case 0:
		{
			exit(1);
		}
		break;
		}
	}
	break;
	case 4:
	{
		unsigned int op;

		c1.showAllSessoes();

		cout << endl << "Prima: 1. Voltar                       0. Sair";

		cin >> op;

		if (op > 1) {
			cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

			cin >> op;
		}

		switch (op)
		{
		case 1:
		{
			Informacoes(c1);
		}
		break;
		case 0:
		{
			exit(1);
		}
		break;
		}
	}
	break;
	case 5:
	{
		showPriorityQueue(c1);
	}
	case 6:
	{
		primeiroMenu(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void showClassificacoes(Casting c1) {
	unsigned int op;

	cout << "*" << string(50, '*') << "*" << endl;
	cout << "*" << string(17, ' ') << "GERIR JURADOS   " << string(17, ' ') << "*" << endl;
	cout << "*" << string(50, '*') << "*" << endl;
	cout << "* " << " 1. Primeira fase  " << string(30, ' ') << "*" << endl;
	cout << "* " << " 2. Segunda fase   " << string(30, ' ') << "*" << endl;
	cout << "* " << " 3. Back           " << string(30, ' ') << "*" << endl;
	cout << "* " << " 0. Exit           " << string(30, ' ') << "*" << endl;
	cout << "*" << string(50, '*') << "*" << endl;
	cout << "Escolha um número [0-3] : \n";

	cin >> op;

	if (op > 3) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n";

		pause();

		showClassificacoes(c1);
	}

	switch (op) {
	case 1:
	{
		CandidatoClassificacoes(c1);
	}
	break;
	case 2:
	{
		ClassificacoesCandidatosFase2(c1);
	}
	break;
	case 3:
	{
		Informacoes(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void ClassificacoesCandidatosFase2(Casting c1) {
	c1.showAllSessoes();

	unsigned int op;

	cout << "Escolha uma sessão: ";

	cin >> op;

	for (int i=0; i < c1.sessoes.size(); i++) {
		if (op == c1.sessoes[i]->id) {
			c1.sessoes[i]->Compute_SegundaFase();

			cout << "encontrei sessao";

			c1.showClassificacoesSegundaFase(i);
		}
	}

	cout << endl << "Prima: 1. Voltar                       0. Sair";

	cin >> op;

	if (op > 1) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

		cin >> op;
	}

	switch (op) {
	case 1:
	{
		showClassificacoes(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void CandidatoClassificacoes(Casting c1) {
	unsigned int op;

	c1.showClassificacoes();

	cout << endl << "Prima: 1. Voltar                       0. Sair";

	cin >> op;

	if (op > 1) {
		cout << "Opção inválida. Prima enter para tentar novamente.\n Opção: ";

		cin >> op;
	}

	switch (op)
	{
	case 1:
	{
		showClassificacoes(c1);
	}
	break;
	case 0:
	{
		exit(1);
	}
	break;
	}
}

void listarCandidatosIndisponiveis(Casting c1)
{
	unsigned int op;
	c1.showAllCandidatosIndisponiveis();
	cout << endl << "Prima: 1. Voltar                       0. Sair";
	cin >> op;

	if (op > 1) //
	{
		cout << "Opcao Invalida. Tente novamente!\nOpcao:";
		cin >> op;

	}

	switch (op)
	{
	case 1:
	{
		MenuListarCandidatos(c1);
	}break;
	case 0:
	{
		exit(1);
	}break;
	}
}

void showPriorityQueue(Casting c1)
{
	unsigned int op;
	c1.imprimeConteudoFila();
	cout << endl << "Prima: 1. Voltar                       0. Sair";
	cin >> op;

	if (op > 1) //
	{
		cout << "Opcao Invalida. Tente novamente!\nOpcao:";
		cin >> op;

	}

	switch (op)
	{
	case 1:
	{
		MenuListarCandidatos(c1);
	}break;
	case 0:
	{
		exit(1);
	}break;
	}
}
