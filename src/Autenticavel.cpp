#include "Autenticavel.hpp"

/**
 * @brief Construtor da classe Autenticavel
 * @param senha Senha a ser armazenada para autenticação
 * 
 * Inicializa o objeto com a senha fornecida.
 */
Autenticavel::Autenticavel(std::string senha) : senha(senha)
{
}

/**
 * @brief Verifica se a senha fornecida corresponde à senha armazenada
 * @param senha Senha a ser verificada
 * @return true se a senha estiver correta, false caso contrário
 * 
 * Compara a senha fornecida com a senha armazenada no objeto.
 */
bool Autenticavel::autenticado(std::string senha) const
{
    return senha == this->senha;
}