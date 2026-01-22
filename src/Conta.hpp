#pragma once
#include <string>
#include <utility>
#include <variant>
#include "Titular.hpp"

/**
 * @class Conta
 * @brief Classe abstrata base que representa uma conta bancária
 * 
 * Esta classe define a interface e funcionalidades básicas de uma conta bancária,
 * incluindo operações de saque, depósito e consulta de saldo.
 * É uma classe abstrata pois possui o método virtual puro taxaDeSaque().
 */
class Conta
{
private:
    static int numeroDeContas;  // Contador estático de todas as contas criadas

public:
    /**
     * @brief Recupera o número total de contas criadas
     * @return Número total de contas
     */
    static int recuperaNumeroDeContas();

private:
    std::string numero;  // Número da conta bancária
    Titular titular;     // Titular da conta

protected:
    float saldo;  // Saldo atual da conta (protected para acesso das classes filhas)

public:
    /**
     * @enum ResultadoDeErroDoSaque
     * @brief Enumeração que representa possíveis erros ao realizar um saque
     */
    enum ResultadoDeErroDoSaque
    {
        ValorNegativo,      // Tentativa de sacar valor negativo
        SaldoInsuficiente   // Saldo insuficiente para realizar o saque
    };

    /**
     * @brief Construtor da classe Conta
     * @param numero Número da conta bancária
     * @param titular Titular da conta
     */
    Conta(std::string numero, Titular titular);

    /**
     * @brief Destrutor virtual da classe Conta
     * 
     * Destrutor virtual para garantir que o destrutor das classes filhas seja chamado corretamente.
     */
    virtual ~Conta();

    /**
     * @brief Realiza um saque na conta
     * @param valorASacar Valor a ser sacado
     * @return Variant contendo o erro (ResultadoDeErroDoSaque) ou o novo saldo (float)
     * 
     * Calcula a tarifa de saque e verifica se há saldo suficiente antes de realizar o saque.
     */
    std::variant<ResultadoDeErroDoSaque, float> sacar(float valorASacar);

    /**
     * @brief Realiza um depósito na conta
     * @param valorADepositar Valor a ser depositado
     * 
     * Adiciona o valor ao saldo da conta. Valores negativos são rejeitados.
     */
    void depositar(float valorADepositar);

    /**
     * @brief Sobrecarga do operador += para depósito
     * @param valorADepositar Valor a ser depositado
     * 
     * Permite usar a sintaxe: conta += valor;
     */
    void operator+=(float valorADepositar);

    /**
     * @brief Recupera o saldo atual da conta
     * @return Saldo atual da conta
     */
    float recuperaSaldo() const;

    /**
     * @brief Método virtual puro que retorna a taxa de saque
     * @return Taxa de saque (valor entre 0 e 1)
     * 
     * Este método deve ser implementado pelas classes filhas (ContaCorrente, ContaPoupanca).
     * A taxa é usada para calcular a tarifa cobrada em cada saque.
     */
    virtual float taxaDeSaque() const = 0;

    /**
     * @brief Função friend para sobrecarga do operador <<
     * 
     * Permite exibir informações da conta usando: cout << conta;
     * Tem acesso aos membros privados da classe, incluindo o titular.
     */
    friend std::ostream& operator<<(std::ostream& cout, const Conta& conta);
};
