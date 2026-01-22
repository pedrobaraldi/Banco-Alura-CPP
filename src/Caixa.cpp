#include "Caixa.hpp"

/**
 * @brief Construtor da classe Caixa
 * @param cpf CPF do caixa
 * @param nome Nome do caixa
 * @param salario Salário do caixa
 * @param diaDoPagamento Dia da semana em que o caixa recebe o pagamento
 * 
 * Inicializa o caixa chamando o construtor da classe base Funcionario.
 */
Caixa::Caixa(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagamento)
    : Funcionario(cpf, nome, salario, diaDoPagamento)
{
}

/**
 * @brief Calcula a bonificação do caixa
 * @return Valor da bonificação (10% do salário)
 * 
 * A bonificação de um caixa corresponde a 10% do seu salário.
 */
float Caixa::bonificacao() const
{
    return recuperaSalario() * 0.1;
}