#pragma once
#include <string>

/**
 * @class Cpf
 * @brief Classe que representa um CPF (Cadastro de Pessoa Física)
 * 
 * Encapsula um número de CPF como uma string.
 * O construtor é marcado como 'explicit' para evitar conversões implícitas indesejadas.
 */
class Cpf
{
private:
    std::string numero;  // Número do CPF armazenado como string

public:
    /**
     * @brief Construtor da classe Cpf
     * @param numero Número do CPF
     * 
     * Construtor explícito para evitar conversões implícitas de string para Cpf.
     */
    explicit Cpf(std::string numero);

    /**
     * @brief Recupera o número do CPF
     * @return Número do CPF como string
     */
    std::string recuperaNumero() const;
};

