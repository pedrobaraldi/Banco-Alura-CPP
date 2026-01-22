#pragma once
#include "Pessoa.hpp"
#include "DiaDaSemana.hpp"
#include "Cpf.hpp"
#include <string>

/**
 * @class Funcionario
 * @brief Classe abstrata que representa um funcionário do banco
 * 
 * Herda de Pessoa e adiciona informações específicas de funcionário:
 * salário e dia de pagamento. É uma classe abstrata pois possui o método
 * virtual puro bonificacao() que deve ser implementado pelas classes filhas.
 */
class Funcionario : public Pessoa
{
private:
    float salario;                    // Salário do funcionário
    DiaDaSemana diaDoPagamento;       // Dia da semana em que o funcionário recebe o pagamento

public:
    /**
     * @brief Construtor da classe Funcionario
     * @param cpf CPF do funcionário
     * @param nome Nome do funcionário
     * @param salario Salário do funcionário
     * @param diaDoPagamento Dia da semana em que o funcionário recebe o pagamento
     */
    Funcionario(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagamento);

    /**
     * @brief Recupera o nome do funcionário
     * @return Nome do funcionário
     * 
     * Sobrescreve o método da classe base Pessoa para retornar o nome.
     */
    std::string recuperaNome() const;

    /**
     * @brief Recupera o salário do funcionário
     * @return Salário do funcionário
     */
    float recuperaSalario() const;

    /**
     * @brief Método virtual puro que calcula a bonificação do funcionário
     * @return Valor da bonificação
     * 
     * Este método deve ser implementado pelas classes filhas (Caixa, Gerente).
     * Cada tipo de funcionário tem uma bonificação diferente.
     */
    virtual float bonificacao() const = 0;
};
