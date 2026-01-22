#pragma once

/**
 * @enum DiaDaSemana
 * @brief Enumeração que representa os dias da semana
 * 
 * Usado para especificar o dia de pagamento dos funcionários.
 * O tipo subjacente é unsigned char para economizar memória.
 */
enum class DiaDaSemana : unsigned char
{
    Domingo,   // 0 - Domingo
    Segunda,   // 1 - Segunda-feira
    Terca,     // 2 - Terça-feira
    Quarta,    // 3 - Quarta-feira
    Quinta,    // 4 - Quinta-feira
    Sexta,     // 5 - Sexta-feira
    Sabado     // 6 - Sábado
};