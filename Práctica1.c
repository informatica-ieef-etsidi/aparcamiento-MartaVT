//Desarrollador: Marta Vinagre Teba


#include <stdio.h>
#include <string.h> // incluyo esta librería para que me funcione el strcmp

void main() {
	
	//inicializo las variables

	int plaza_1 = 0;
	int plaza_2 = 0;
	char matricula_1[8];
	char matricula_2[8];
	char matricula[8];
	char opcion;
	int i;

	while (1) {

		printf_s("Elige una de estas opciones:\n");
		printf_s("Introduce R para reservar una plaza\n");
		printf_s("Introduce A para abandonar una plaza\n");
		printf_s("Introduce E para conocer el estado del aparcamiento\n");
		scanf_s("%c", &opcion);

		switch (opcion) {

		case 'R':
			if (plaza_1 == 1 && plaza_2 == 1) {
				printf_s("Ambas plazas estan ocupadas\n");

			}
			else if (plaza_1 == 0 && plaza_2 == 1) {
				printf_s("La plaza 1 esta libre\n");
				printf_s("Introduce tu matricula:\n");
				for (i = 0; i < 7; i++) {
					getchar(); // como voy a introducir caracteres necesito un getchar
					scanf_s("%c", &matricula_1[i]);
				}
				plaza_1 = 1; //se cambia la plaza 1 de vacia a ocupada

			}
			else if (plaza_1 == 1 && plaza_2 == 0) {
				printf_s("La plaza 2 esta libre\n");
				printf_s("Introduce tu matricula:\n");
				for (i = 0; i < 7; i++) {
					getchar();
					scanf_s("%c", &matricula_2[i]);
				}
				plaza_2 = 1;

			}
			else if (plaza_1 == 0 && plaza_2 == 0) {
				printf_s("Ambas plazas están libres, se te asigna la plaza 1\n");
				printf_s("Introduce tu matricula:\n");
				for (i = 0; i < 7; i++) {
					getchar();
					scanf_s("%c", &matricula_1[i]);
				}
				plaza_1 = 1;
			}

			break; 


		case 'A':
			if (plaza_1 == 0 && plaza_2 == 0) {
				printf_s("El aparcamiento esta vacio\n");
			}
			else {
				printf_s("Introduce tu matricula:\n");
				for (i = 0; i < 7; i++) {
					getchar();
					scanf_s("%c", &matricula[i]);
				}

				if (strcmp(matricula, matricula_1) == 1) {
					printf_s("Abandonando plaza 1\n");
					plaza_1 = 0; //se cambia la plaza 1 de ocupada a vacia
				}
				else if (strcmp(matricula, matricula_2) == 1) {
					printf_s("Abandonando plaza 2\n");
					plaza_2 = 0;
				}
				else {
					printf_s("Tu matricula no coincide con ninguna del aparcamiento\n");
				}
			}

			break;

		case 'E':
			printf_s("Mostrando el estado del aparcamiento:\n");
			if (plaza_1 == 0) {
				printf_s("Plaza 1 - Libre\n");
			}
			if (plaza_1 == 1) {
				printf_s("Plaza 1 - Ocupada - Matricula: %s\n", matricula_1);
			}
			if (plaza_2 == 0) {
				printf_s("Plaza 2 - Libre\n");
			}
			if (plaza_2 == 1) {
				printf_s("Plaza 2 - Ocupada - Matricula: %s\n", matricula_2);
			}

			break;
		default : 
			printf_s("La opcion introducida es incorrecta, introduzca R, A o E\n");
		}

		system("PAUSE");
	}	
}