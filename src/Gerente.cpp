#include "Gerente.hpp"

/**
 * @brief Construtor da classe Gerente
 * @param cpf CPF do gerente
 * @param nome Nome do gerente
 * @param salario Salário do gerente
 * @param diaDoPagamento Dia da semana em que o gerente recebe o pagamento
 * @param senha Senha para autenticação do gerente
 * 
 * Inicializa o gerente chamando os construtores das classes base:
 * Funcionario (para dados de funcionário) e Autenticavel (para autenticação).
 */
Gerente::Gerente(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagamento, std::string senha)
    : Funcionario(cpf, nome, salario, diaDoPagamento),
      Autenticavel(senha)
{
}

/**
 * @brief Calcula a bonificação do gerente
 * @return Valor da bonificação (50% do salário)
 * 
 * A bonificação de um gerente corresponde a 50% do seu salário,
 * que é maior que a bonificação de outros funcionários.
 */
float Gerente::bonificacao() const
{
    return recuperaSalario() * 0.5;  // 50% de bonificação
}