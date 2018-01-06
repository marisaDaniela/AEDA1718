#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "BST.hpp"

using namespace std;

void trim(string &str);

/**
 * Metodo que espera que o utilizador pressione uma tecla
 *
 */
void pressKeyToContinue();

/**
 * Lê o input do utilizador e verifica se é composto apenas por números
 *
 * @return número introduzido pelo utilizador
 */
int read_number_Input();

/**
 * Verifica se uma data e menor do que outra
 * @param d1 data para ser comparada
 * @param d2 data para ser comparada
 * @return true se d1 menor do que a d2
 */
bool lessThan(string d1, string d2);

#define SIZETEXTO 100
