#pragma once
#include <string>
#include "Pessoa.hpp"
#include "Cpf.hpp"
#include "Autenticavel.hpp"

/**
 * @class Titular
 * @brief Classe que representa o titular de uma conta bancária
 * 
 * Herda de Pessoa e Autenticavel (herança múltipla).
 * Um titular possui CPF, nome e senha para autenticação.
 * É usado para criar contas bancárias (ContaCorrente, ContaPoupanca).
 */
class Titular : public Pessoa, public Autenticavel
{
public:
    /**
     * @brief Construtor da classe Titular
     * @param cpf CPF do titular
     * @param nome Nome do titular
     * @param senha Senha para autenticação do titular
     * 
     * Inicializa o titular chamando os construtores das classes base:
     * Pessoa (para dados pessoais) e Autenticavel (para autenticação).
     */
    Titular(Cpf cpf, std::string nome, std::string senha);
};