
#include <stdio.h>
#include <stdlib.h>

int factorial(int);

int main(int argc, char **argv) {
	//printf("El numero de argumentos es %d y el primer argumento es %s", argc, argv[0]);
  int n = 0;
  if (argc == 2) {
		int n = atoi(argv[1]);
		printf("El factorial de 10 es: %d\n", factorial(n));
  } else if (argc) {
    char cad[20];
    printf("Escribe un numero: ");
    scanf("%s", &n);
    //n = atoi(cad);
    printf("El factorial de %d es: %d\n", n, factorial(n));
  }
  return 0;
}

int factorial(int n) {
	int r=1;
	for (int i=2; i<=n; i++) {
		r *= i;
	}
	return r;
}
