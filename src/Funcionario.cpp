#include "Funcionario.hpp"
#include <iostream>

/**
 * @brief Construtor da classe Funcionario
 * @param cpf CPF do funcionário
 * @param nome Nome do funcionário
 * @param salario Salário do funcionário
 * @param diaDoPagamento Dia da semana em que o funcionário recebe o pagamento
 * 
 * Inicializa o funcionário chamando o construtor da classe base Pessoa
 * e inicializando os atributos específicos de funcionário.
 */
Funcionario::Funcionario(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagamento)
    : Pessoa(cpf, nome),
      salario(salario),
      diaDoPagamento(diaDoPagamento)
{
}

/**
 * @brief Recupera o nome do funcionário
 * @return Nome do funcionário
 * 
 * Retorna o nome do funcionário (herdado de Pessoa, acessível via protected).
 */
std::string Funcionario::recuperaNome() const
{
    return nome;  // Acesso ao membro protected 'nome' da classe base Pessoa
}

/**
 * @brief Recupera o salário do funcionário
 * @return Salário do funcionário
 */
float Funcionario::recuperaSalario() const
{
    return salario;
}
