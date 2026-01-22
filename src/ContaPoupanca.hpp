#pragma once
#include "Conta.hpp"

/**
 * @class ContaPoupanca
 * @brief Classe que representa uma conta poupança bancária
 * 
 * Herda de Conta e implementa a taxa de saque específica para conta poupança (3%).
 * A classe é marcada como 'final', impedindo que outras classes herdem dela.
 * Conta poupança possui taxa de saque menor que conta corrente.
 */
class ContaPoupanca final : public Conta
{
public:
    /**
     * @brief Construtor da classe ContaPoupanca
     * @param numero Número da conta poupança
     * @param titular Titular da conta
     */
    ContaPoupanca(std::string numero, Titular titular);

    /**
     * @brief Retorna a taxa de saque da conta poupança
     * @return Taxa de saque (3% = 0.03)
     * 
     * Implementa o método virtual puro da classe base Conta.
     */
    float taxaDeSaque() const override;
};

