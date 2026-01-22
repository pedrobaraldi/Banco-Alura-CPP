#include <iostream>
#include "Pessoa.hpp"

/**
 * @brief Construtor da classe Pessoa
 * @param cpf CPF da pessoa
 * @param nome Nome da pessoa
 * 
 * Inicializa a pessoa com CPF e nome fornecidos.
 * Valida o tamanho do nome após a inicialização.
 */
Pessoa::Pessoa(Cpf cpf, std::string nome)
    : cpf(cpf),
      nome(nome)
{
    verificaTamanhoDoNome();
}

/**
 * @brief Recupera o nome da pessoa
 * @return Nome da pessoa
 */
std::string Pessoa::recuperaNome() const
{
    return nome;
}

/**
 * @brief Verifica se o nome tem tamanho válido
 * 
 * Valida que o nome tenha pelo menos 5 caracteres.
 * Se o nome for muito curto, exibe uma mensagem de erro e encerra o programa.
 */
void Pessoa::verificaTamanhoDoNome()
{
    if (nome.size() < 5) {
        std::cout << "Nome muito curto" << std::endl;
        exit(1);
    }
}