#pragma once
#include "Conta.hpp"

/**
 * @class ContaCorrente
 * @brief Classe que representa uma conta corrente bancária
 * 
 * Herda de Conta e implementa a taxa de saque específica para conta corrente (5%).
 * A classe é marcada como 'final', impedindo que outras classes herdem dela.
 * Possui funcionalidades adicionais como transferência entre contas.
 */
class ContaCorrente final : public Conta
{
public:
    /**
     * @brief Construtor da classe ContaCorrente
     * @param numero Número da conta corrente
     * @param titular Titular da conta
     */
    ContaCorrente(std::string numero, Titular titular);

    /**
     * @brief Retorna a taxa de saque da conta corrente
     * @return Taxa de saque (5% = 0.05)
     * 
     * Implementa o método virtual puro da classe base Conta.
     */
    float taxaDeSaque() const override;

    /**
     * @brief Transfere um valor desta conta para outra conta
     * @param conta Conta de destino da transferência
     * @param valor Valor a ser transferido
     * 
     * Realiza um saque nesta conta e um depósito na conta de destino.
     * Só transfere se o saque for bem-sucedido.
     */
    void transferePara(Conta& conta, float valor);

    /**
     * @brief Sobrecarga do operador += para transferência entre contas correntes
     * @param contaOrigem Conta corrente de origem da transferência
     * 
     * Transfere metade do saldo da conta origem para esta conta.
     * Permite usar a sintaxe: contaDestino += contaOrigem;
     */
    void operator+=(ContaCorrente& contaOrigem);
};

