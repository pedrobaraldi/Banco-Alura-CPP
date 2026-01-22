#pragma once
#include "Funcionario.hpp"
#include "DiaDaSemana.hpp"

/**
 * @class Caixa
 * @brief Classe que representa um funcionário do tipo Caixa
 * 
 * Herda de Funcionario e implementa a bonificação específica para caixas.
 * A classe é marcada como 'final', impedindo que outras classes herdem dela.
 */
class Caixa final : public Funcionario
{
public:
    /**
     * @brief Construtor da classe Caixa
     * @param cpf CPF do caixa
     * @param nome Nome do caixa
     * @param salario Salário do caixa
     * @param diaDoPagamento Dia da semana em que o caixa recebe o pagamento
     */
    Caixa(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagamento);

    /**
     * @brief Calcula a bonificação do caixa
     * @return Valor da bonificação (10% do salário)
     * 
     * Implementa o método virtual puro da classe base Funcionario.
     */
    float bonificacao() const;
};

