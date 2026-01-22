#pragma once
#include "Cpf.hpp"
#include <string>

/**
 * @class Pessoa
 * @brief Classe base que representa uma pessoa
 * 
 * Classe base para Titular e Funcionario. Armazena informações básicas
 * de uma pessoa: CPF e nome. O modificador 'protected' permite que as
 * classes filhas acessem os membros, mas mantém-os protegidos de acesso externo.
 */
class Pessoa
{
protected:
    Cpf cpf;              // CPF da pessoa (protected para acesso das classes filhas)
    std::string nome;     // Nome da pessoa (protected para acesso das classes filhas)

public:
    /**
     * @brief Construtor da classe Pessoa
     * @param cpf CPF da pessoa
     * @param nome Nome da pessoa
     * 
     * Inicializa a pessoa com CPF e nome, e valida o tamanho do nome.
     */
    Pessoa(Cpf cpf, std::string nome);

    /**
     * @brief Recupera o nome da pessoa
     * @return Nome da pessoa
     */
    std::string recuperaNome() const;

private:
    /**
     * @brief Verifica se o nome tem tamanho válido
     * 
     * Valida que o nome tenha pelo menos 5 caracteres.
     * Encerra o programa se o nome for muito curto.
     */
    void verificaTamanhoDoNome();
};

