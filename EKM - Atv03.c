//EKM 10/05/2024

#include <stdio.h>

// Fun��o para verificar se o ano � bissexto
int fAnoBissexto(int a) {
    return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}

// Fun��o para verificar se uma data � v�lida
int fDataValida(int d, int m, int a) {
    if (a < 1600 || a > 5000 || m < 1 || m > 12 || d < 1 || d > 31) {
        return 0; // Data inv�lida
    }

    // Verifica os meses com 30 ou 31 dias
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
        return 0; // Data inv�lida
    }

    // Verifica fevereiro
    if (m == 2) {
        if (fAnoBissexto(a)) {
            if (d > 29) {
                return 0; // Data inv�lida
            }
        } else {
            if (d > 28) {
                return 0; // Data inv�lida
            }
        }
    }

    return 1; // Data v�lida
}

// Fun��o para calcular a quantidade de dias desde o in�cio do ano at� a data
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

// Fun��o para calcular a quantidade de dias que faltam para o fim do ano
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

