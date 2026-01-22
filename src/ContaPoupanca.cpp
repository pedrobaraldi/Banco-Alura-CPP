#include <iostream>
#include "ContaPoupanca.hpp"

/**
 * @brief Construtor da classe ContaPoupanca
 * @param numero Número da conta poupança
 * @param titular Titular da conta
 * 
 * Inicializa a conta poupança chamando o construtor da classe base Conta.
 */
ContaPoupanca::ContaPoupanca(std::string numero, Titular titular)
    : Conta(numero, titular)
{
}

/**
 * @brief Retorna a taxa de saque da conta poupança
 * @return Taxa de saque (3% = 0.03)
 * 
 * Implementa o método virtual puro da classe base Conta.
 * A conta poupança cobra 3% de taxa sobre cada saque (menor que conta corrente).
 */
float ContaPoupanca::taxaDeSaque() const
{
    return 0.03;  // 3% de taxa de saque
}

