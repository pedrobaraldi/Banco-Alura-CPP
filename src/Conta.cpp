#include "Conta.hpp"
#include <iostream>

// Inicialização do contador estático de contas
int Conta::numeroDeContas = 0;

/**
 * @brief Construtor da classe Conta
 * @param numero Número da conta bancária
 * @param titular Titular da conta
 * 
 * Inicializa a conta com o número e titular fornecidos, e saldo zero.
 * Incrementa o contador estático de contas.
 */
Conta::Conta(std::string numero, Titular titular)
    : numero(numero),
      titular(titular),
      saldo(0)
{
    numeroDeContas++;
}

/**
 * @brief Destrutor da classe Conta
 * 
 * Decrementa o contador estático de contas quando a conta é destruída.
 */
Conta::~Conta()
{
    numeroDeContas--;
}

/**
 * @brief Realiza um saque na conta
 * @param valorASacar Valor a ser sacado
 * @return Variant contendo o erro (ResultadoDeErroDoSaque) ou o novo saldo (float)
 * 
 * Processo:
 * 1. Verifica se o valor é negativo
 * 2. Calcula a tarifa de saque usando o método virtual taxaDeSaque()
 * 3. Verifica se há saldo suficiente (valor + tarifa)
 * 4. Se tudo estiver ok, debita o valor total do saldo
 */
std::variant<Conta::ResultadoDeErroDoSaque, float> Conta::sacar(float valorASacar)
{
    // Validação: não permite saque de valores negativos
    if (valorASacar < 0) {
        std::cout << "Não pode sacar valor negativo" << std::endl;
        return ValorNegativo;
    }

    // Calcula a tarifa de saque (chama método virtual implementado pelas classes filhas)
    float tarifaDeSaque = valorASacar * taxaDeSaque();
    float valorDoSaque = valorASacar + tarifaDeSaque;

    // Verifica se há saldo suficiente para o saque + tarifa
    if (valorDoSaque > saldo) {
        std::cout << "Saldo insuficiente" << std::endl;
        return SaldoInsuficiente;
    }

    // Realiza o débito do saldo
    saldo -= valorDoSaque;

    // Retorna o novo saldo
    return saldo;
}

/**
 * @brief Realiza um depósito na conta
 * @param valorADepositar Valor a ser depositado
 * 
 * Adiciona o valor ao saldo da conta. Valores negativos são rejeitados.
 */
void Conta::depositar(float valorADepositar)
{
    // Validação: não permite depósito de valores negativos
    if (valorADepositar < 0) {
        std::cout << "Não pode depositar valor negativo" << std::endl;
        return;
    }

    // Adiciona o valor ao saldo
    saldo += valorADepositar;
}

/**
 * @brief Sobrecarga do operador += para depósito
 * @param valorADepositar Valor a ser depositado
 * 
 * Permite usar a sintaxe: conta += valor;
 * Internamente chama o método depositar().
 */
void Conta::operator+=(float valorADepositar)
{
    depositar(valorADepositar);
}

/**
 * @brief Recupera o saldo atual da conta
 * @return Saldo atual da conta
 */
float Conta::recuperaSaldo() const
{
    return saldo;
}

/**
 * @brief Recupera o número total de contas criadas
 * @return Número total de contas
 * 
 * Método estático que retorna o contador de todas as contas criadas no sistema.
 */
int Conta::recuperaNumeroDeContas()
{
    return numeroDeContas;
}
