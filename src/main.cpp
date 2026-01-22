#include <iostream>
#include <string>

// Headers do projeto
#include "DiaDaSemana.hpp"
#include "Gerente.hpp"
#include "Conta.hpp"
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"
#include "Funcionario.hpp"

using namespace std;

/**
 * @brief Função utilitária para exibir o saldo de uma conta
 * @param conta Conta cujo saldo será exibido (passada por referência constante)
 * 
 * Exibe o saldo atual da conta no formato: "O saldo da conta e: R$ X.XX"
 */
void ExibeSaldo(const Conta& conta)
{
    cout << "O saldo da conta e: R$ " << conta.recuperaSaldo() << endl;
}

/**
 * @brief Realiza um saque fixo de R$ 200 em uma conta
 * @param conta Conta onde será realizado o saque (passada por referência)
 * 
 * Tenta realizar um saque de R$ 200 na conta e exibe o resultado:
 * - Se bem-sucedido: mostra o novo saldo
 * - Se falhar: mostra a mensagem de erro apropriada
 */
void RealizaSaque(Conta& conta)
{
    // Tenta sacar R$ 200 da conta
    std::variant<Conta::ResultadoDeErroDoSaque, float> resultado = conta.sacar(200);

    // Verifica se o saque foi bem-sucedido (retornou float = novo saldo)
    if (auto saldo = std::get_if<float>(&resultado)) {
        cout << "Novo saldo da conta: " << *saldo << endl;
    }
    // Verifica se o erro foi saldo insuficiente
    else if (std::get<Conta::ResultadoDeErroDoSaque>(resultado) == Conta::SaldoInsuficiente) {
        cout << "Saldo disponivel na conta insuficiente!" << endl;
    }
    // Verifica se o erro foi valor negativo
    else if (std::get<Conta::ResultadoDeErroDoSaque>(resultado) == Conta::ValorNegativo) {
        cout << "Valor invalido para saque!" << endl;
    }
}

/**
 * @brief Simula um login usando a interface Autenticavel
 * @param alguem Objeto que implementa Autenticavel (Titular ou Gerente)
 * @param senha Senha a ser verificada
 * 
 * Tenta autenticar o objeto com a senha fornecida e exibe mensagem de sucesso.
 */
void FazLogin(Autenticavel& alguem, const string& senha)
{
    if (alguem.autenticado(senha)) {
        cout << "Login realizado com sucesso" << endl;
    }
}

/**
 * @brief Sobrecarga do operador << para exibir informações de uma Conta
 * @param out Stream de saída (cout)
 * @param conta Conta a ser exibida
 * @return Referência para a stream de saída
 * 
 * Permite exibir uma Conta diretamente com: cout << conta;
 * Exibe o saldo e o nome do titular da conta.
 */
ostream& operator<<(ostream& out, const Conta& conta)
{
    // Recupera o titular da conta (conversão implícita de Titular para Pessoa)
    Pessoa titular = conta.titular;

    // Exibe informações da conta
    out << "Saldo da conta: R$ " << conta.recuperaSaldo() << endl;
    out << "Titular da conta: " << titular.recuperaNome() << endl;

    return out;
}

/**
 * @brief Função principal do programa
 * 
 * Demonstra o uso das classes do sistema bancário:
 * - Criação de titulares e contas (poupança e corrente)
 * - Operações de depósito e saque
 * - Transferências entre contas
 * - Criação de funcionários (gerente)
 */
int main()
{
    /* --------------------------------------------------
       Criação do primeiro titular e conta poupança (contaUm)
    -------------------------------------------------- */
    Titular TitularPedro(
        Cpf("123.456.789-10"),
        "Pedro",
        "umasenha"
    );

    // Cria conta poupança
    ContaPoupanca contaUm("123456", TitularPedro);
    contaUm.depositar(500);
    RealizaSaque(contaUm);
    ExibeSaldo(contaUm);

    /* --------------------------------------------------
       Criação do segundo titular e contas correntes (contaDois e contaTres)
    -------------------------------------------------- */
    Titular TitularPedroBaraldi(
        Cpf("098.765.432-10"),
        "Pedro Baraldi",
        "outrasenha"
    );

    // Cria primeira conta corrente
    ContaCorrente contaDois("654321", TitularPedro);

    // Depósito usando sobrecarga do operador +=
    (Conta&)contaDois += 300;

    // Cria segunda conta corrente
    ContaCorrente contaTres("546312", TitularPedro);

    // Transfere metade do saldo da primeira conta corrente para a segunda
    contaTres += contaDois;

    // Exibe informações da primeira conta corrente usando operador <<
    cout << contaDois;

    // Exibe saldo da segunda conta corrente
    ExibeSaldo(contaTres);

    /* --------------------------------------------------
       Exibe o total de contas criadas no sistema
    -------------------------------------------------- */
    cout << "Numero de contas: "
         << Conta::recuperaNumeroDeContas()
         << endl;

    /* --------------------------------------------------
       Criação de um gerente do banco
    -------------------------------------------------- */
    Gerente gerenteBanco(
        Cpf("000.000.000-00"),
        "Nome do Gerente",
        1500,
        DiaDaSemana::Terca,
        "123456"
    );

    return 0;
}
