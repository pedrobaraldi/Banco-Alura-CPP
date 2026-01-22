#pragma once
#include <string>

/**
 * @class Autenticavel
 * @brief Classe abstrata que fornece funcionalidade de autenticação por senha
 * 
 * Esta classe permite que objetos sejam autenticados através de uma senha.
 * É usada como classe base para classes que precisam de autenticação, como Titular e Gerente.
 */
class Autenticavel
{
private:
    std::string senha;  // Senha armazenada para autenticação

public:
    /**
     * @brief Construtor da classe Autenticavel
     * @param senha Senha a ser armazenada para autenticação
     */
    Autenticavel(std::string senha);

    /**
     * @brief Verifica se a senha fornecida corresponde à senha armazenada
     * @param senha Senha a ser verificada
     * @return true se a senha estiver correta, false caso contrário
     */
    bool autenticado(std::string senha) const;
};

