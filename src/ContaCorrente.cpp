#include "ContaCorrente.hpp"
#include <iostream>

/**
 * @brief Construtor da classe ContaCorrente
 * @param numero Número da conta corrente
 * @param titular Titular da conta
 * 
 * Inicializa a conta corrente chamando o construtor da classe base Conta.
 */
ContaCorrente::ContaCorrente(std::string numero, Titular titular)
    : Conta(numero, titular)
{
}

/**
 * @brief Retorna a taxa de saque da conta corrente
 * @return Taxa de saque (5% = 0.05)
 * 
 * Implementa o método virtual puro da classe base Conta.
 * A conta corrente cobra 5% de taxa sobre cada saque.
 */
float ContaCorrente::taxaDeSaque() const
{
    return 0.05;  // 5% de taxa de saque
}

/**
 * @brief Transfere um valor desta conta para outra conta
 * @param destino Conta de destino da transferência
 * @param valor Valor a ser transferido
 * 
 * Processo:
 * 1. Tenta sacar o valor desta conta (incluindo a tarifa)
 * 2. Se o saque for bem-sucedido (resultado.index() == 1 significa que retornou float),
 *    deposita o valor na conta de destino
 * 
 * Nota: O valor depositado na conta destino é o valor solicitado, não o valor após a tarifa.
 */
void ContaCorrente::transferePara(Conta& destino, float valor)
{
    // Tenta sacar o valor desta conta
    auto resultado = sacar(valor);

    // Se o saque foi bem-sucedido (index 1 = float, index 0 = erro)
    if (resultado.index() == 1) {
        // Deposita o valor na conta de destino
        destino.depositar(valor);
    }
}

/**
 * @brief Sobrecarga do operador += para transferência entre contas correntes
 * @param contaOrigem Conta corrente de origem da transferência
 * 
 * Transfere metade do saldo da conta origem para esta conta.
 * Permite usar a sintaxe: contaDestino += contaOrigem;
 */
void ContaCorrente::operator+=(ContaCorrente& contaOrigem)
{
    // Transfere metade do saldo da conta origem para esta conta
    contaOrigem.transferePara(*this, contaOrigem.recuperaSaldo() / 2);
}