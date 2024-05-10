//EKM 10/05/2024

#include <stdio.h>

// Função para verificar se o ano é bissexto
int fAnoBissexto(int a) {
    return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}

// Função para verificar se uma data é válida
int fDataValida(int d, int m, int a) {
    if (a < 1600 || a > 5000 || m < 1 || m > 12 || d < 1 || d > 31) {
        return 0; // Data inválida
    }

    // Verifica os meses com 30 ou 31 dias
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
        return 0; // Data inválida
    }

    // Verifica fevereiro
    if (m == 2) {
        if (fAnoBissexto(a)) {
            if (d > 29) {
                return 0; // Data inválida
            }
        } else {
            if (d > 28) {
                return 0; // Data inválida
            }
        }
    }

    return 1; // Data válida
}

// Função para calcular a quantidade de dias desde o início do ano até a data
int fDiasInicioAno(int d, int m, int a) {
    int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDias = 0;
    int i;

    for (i = 1; i < m; i++) {
        totalDias += diasPorMes[i];
    }

    if (fAnoBissexto(a) && m > 2) {
        totalDias++; // Acrescenta um dia para fevereiro em anos bissextos
    }

    totalDias += d;
    return totalDias;
}

// Função para calcular a quantidade de dias que faltam para o fim do ano
int fDiasFimAno(int d, int m, int a) {
    int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDias = 0;
    int i;

    for (i = m + 1; i <= 12; i++) {
        totalDias += diasPorMes[i];
    }

    if (fAnoBissexto(a) && m <= 2) {
        totalDias++; // Acrescenta um dia para fevereiro em anos bissextos
    }

    totalDias += (diasPorMes[m] - d);
    return totalDias;
}

int main() {
    int dia, mes, ano;
    printf("Digite uma data no formato DD/MM/AAAA: ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    if (!fDataValida(dia, mes, ano)) {
        printf("Data invalida.\n");
        return 1;
    }

    int diasInicio = fDiasInicioAno(dia, mes, ano);
    int diasFim = fDiasFimAno(dia, mes, ano);
    int totalDias = diasInicio + diasFim;

    printf("Dias desde o inicio do ano ate %02d/%02d/%04d: %d\n", dia, mes, ano, diasInicio);
    printf("Dias que faltam ate o fim do ano: %d\n", diasFim);
    printf("Total de dias no ano: %d\n", totalDias);

    return 0;
}

