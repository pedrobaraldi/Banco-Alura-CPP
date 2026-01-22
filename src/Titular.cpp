#include "Titular.hpp"
#include <iostream>

/**
 * @brief Construtor da classe Titular
 * @param cpf CPF do titular
 * @param nome Nome do titular
 * @param senha Senha para autenticação do titular
 * 
 * Inicializa o titular chamando os construtores das classes base:
 * Pessoa (para dados pessoais) e Autenticavel (para autenticação).
 */
Titular::Titular(Cpf cpf, std::string nome, std::string senha)
    : Pessoa(cpf, nome),
      Autenticavel(senha)
{
}
