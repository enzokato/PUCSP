//EKM - Atividade 02
//Enzo Kato Mootooka - 18/04/2024
/*Calcular o IMC, baseado no peso (kg) e altura (metros), além disso estabelecer limites que classificam o IMC da pessoa entre as categorias de: PESO BAIXO, PESO NORMAL, SOBREPESO, OBESIDADE DE GRAU I, II OU 3.
*/


#include <stdio.h>

int main() {
    float peso, altura, imc;
    float pesoIdealMin, pesoIdealMax;
    char resposta;

    do {
        // Solicita ao usuário o peso em quilogramas e a altura em metros
        printf("Digite o seu peso (em kg): ");
        scanf("%f", &peso);

        // Verifica se o peso é igual a zero
        if (peso == 0) {
            printf("Programa encerrado. Peso não pode ser zero.\n");
            break; // Sai do loop
        }

        printf("Digite a sua altura (em metros): ");
        scanf("%f", &altura);

        // Calcula o IMC
        imc = peso / (altura * altura);

        // Classifica o IMC
        printf("Seu IMC é: %.2f\n", imc);
        if (imc < 18.5) {
            printf("Classificacao: Peso Baixo\n");
        } else if (imc >= 18.5 && imc < 24.9) {
            printf("Classificacao: Peso Normal\n");
        } else if (imc >= 25 && imc < 29.9) {
            printf("Classificacao: Sobrepeso\n");
        } else if (imc >= 30 && imc < 34.9) {
            printf("Classificacao: Obesidade (Grau I)\n");
        } else if (imc >= 35 && imc < 39.9) {
            printf("Classificacao: Obesidade Severa (Grau II)\n");
        } else {
            printf("Classificacao: Obesidade Morbida (Grau III)\n");
        }

        // Calcula o peso ideal com base na altura
        pesoIdealMin = 18.5 * (altura * altura);
        pesoIdealMax = 24.9 * (altura * altura);
        printf("Peso ideal - Minimo e Maximo (em kg): Entre %.2f e %.2f\n", pesoIdealMin, pesoIdealMax);

        // Pergunta se deseja recalcular
        printf("Deseja recalcular? (S/N): ");
        scanf(" %c", &resposta);
    } while (resposta == 'S' || resposta == 's');

    return 0;
}
