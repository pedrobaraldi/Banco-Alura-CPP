#include "Cpf.hpp"
#include <iostream>

/**
 * @brief Construtor da classe Cpf
 * @param numero Número do CPF
 * 
 * Inicializa o objeto Cpf com o número fornecido.
 * O construtor é explícito para evitar conversões implícitas.
 */
Cpf::Cpf(std::string numero) : numero(numero)
{
}

/**
 * @brief Recupera o número do CPF
 * @return Número do CPF como string
 * 
 * Retorna uma cópia do número do CPF armazenado.
 */
std::string Cpf::recuperaNumero() const
{
    return numero;
}