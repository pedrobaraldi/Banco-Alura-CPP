#pragma once
#include "Autenticavel.hpp"
#include "Funcionario.hpp"
#include "DiaDaSemana.hpp"

/**
 * @class Gerente
 * @brief Classe que representa um gerente do banco
 * 
 * Herda de Funcionario e Autenticavel (herança múltipla).
 * Implementa a bonificação específica para gerentes (50% do salário).
 * A classe é marcada como 'final', impedindo que outras classes herdem dela.
 * Gerentes possuem autenticação para acessar funcionalidades administrativas.
 */
class Gerente final : public Funcionario, public Autenticavel
{
public:
    /**
     * @brief Construtor da classe Gerente
     * @param cpf CPF do gerente
     * @param nome Nome do gerente
     * @param salario Salário do gerente
     * @param diaDoPagamento Dia da semana em que o gerente recebe o pagamento
     * @param senha Senha para autenticação do gerente
     */
    Gerente(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagamento, std::string senha);

    /**
     * @brief Calcula a bonificação do gerente
     * @return Valor da bonificação (50% do salário)
     * 
     * Implementa o método virtual puro da classe base Funcionario.
     */
    float bonificacao() const;
};

