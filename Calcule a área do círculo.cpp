#include <stdio.h>
float a, r, p = 3.14;
main()
{
	printf("Digite o raio do circulo:");
	scanf("%f", &r);
	if (r < 0){
	printf("Valor invalido, o raio nao pode ser negativo\n");
	}
	else {
	a = p * (r * r);
	printf("A area do circulo eh: %.2f\n", a);
}
}
