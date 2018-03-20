//Desarrollador: Marta Vinagre Teba
//Practica 2:Bucles


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
	int coche;
	int moto;
	char c_o_m[2];
	int i;
	int aux;

	do {

		printf_s("Elige una de estas opciones:\n");
		printf_s("Introduce R para reservar una plaza\n");
		printf_s("Introduce A para abandonar una plaza\n");
		printf_s("Introduce E para conocer el estado del aparcamiento\n");
		printf_s("Introduce B para buscar vehiculo por matricula\n");
		printf_s("Introduce S para salir del programa\n");
		scanf_s("%c", &opcion);

		switch (opcion) {

		case 'R':
			if (plaza_1 == 1 && plaza_2 == 1) {
				printf_s("Ambas plazas estan ocupadas\n");

			}
			else if (plaza_1 == 0 && plaza_2 == 1) {
				printf_s("La plaza 1 esta libre\n");
				printf_s("Escriba 'C' si es un Coche o 'M' si es una Moto\n");
				for (i = 0; i < 1; i++) {
					getchar();
					scanf_s("%c", &c_o_m[i]);
				}
					if (strcmp(c_o_m, "C") == 1) {
						coche = 1;
					}
					else if (strcmp(c_o_m, "M") == 1) {
						moto = 1;
					}

				printf_s("Introduce tu matricula:\n");
				for (i = 0; i < 7; i++) {
					getchar(); // como voy a introducir caracteres necesito un getchar
					scanf_s("%c", &matricula_1[i]);
				}
				plaza_1 = 1; //se cambia la plaza 1 de vacia a ocupada

			}
			else if (plaza_1 == 1 && plaza_2 == 0) {
				printf_s("La plaza 2 esta libre\n");
				printf_s("Escriba 'C' si es un Coche o 'M' si es una Moto\n");
				for (i = 0; i < 1; i++) {
					getchar();
					scanf_s("%c", &c_o_m[i]);
				}
				if (strcmp(c_o_m, "C") == 1) {
					coche = 1;
				}
				else if (strcmp(c_o_m, "M") == 1) {
					moto = 1;
				}
				printf_s("Introduce tu matricula:\n");
				for (i = 0; i < 7; i++) {
					getchar();
					scanf_s("%c", &matricula_2[i]);
				}
				plaza_2 = 1;

			}
			else if (plaza_1 == 0 && plaza_2 == 0) {
				printf_s("Ambas plazas están libres, se te asigna la plaza 1\n");
				printf_s("Escriba 'C' si es un Coche o 'M' si es una Moto\n");
				for (i = 0; i < 1; i++) {
				getchar();
				scanf_s("%c", &c_o_m[i]);
				}
				if (strcmp(c_o_m, "C") == 1) {
					coche = 1;
				}
				else if (strcmp(c_o_m, "M") == 1) {
					moto = 1;
				}
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
				if (coche == 1) {
					printf_s("Plaza 1 - Ocupada - Coche - Matricula: %s\n", matricula_1);
				}
				else if (moto == 1) {
					printf_s("Plaza 1 - Ocupada - Moto - Matricula: %s\n", matricula_1);
				}
			}
			if (plaza_2 == 0) {
				printf_s("Plaza 2 - Libre\n");
			}
			if (plaza_2 == 1) {
				if (coche == 1) {
					printf_s("Plaza 2 - Ocupada - Coche - Matricula: %s\n", matricula_2);
				}
				else if (moto == 1) {
					printf_s("Plaza 2 - Ocupada - Moto - Matricula: %s\n", matricula_2);
				}
			}

			break;


		case 'B':
			printf_s("Introduce tu matricula:\n");
			for (i = 0; i < 7; i++) {
				getchar();
				scanf_s("%c", &matricula[i]);
			}

			if (strcmp(matricula, matricula_1) == 1) {
				printf_s("Su vehiculo esta en la plaza 1\n");
			}
			else if (strcmp(matricula, matricula_2) == 1) {
				printf_s("Su vehiculo esta en la plaza 2\n");
			}
			else {
				printf_s("Tu matricula no coincide con ninguna del aparcamiento\n");
			}

			break;

		case 'S':
			aux = 0;
			while (aux == 0)
			{
					opcion = -1;
					aux = -1;
					printf("Saliendo del programa\n");
			}
			break;

		default:
			printf_s("La opcion introducida es incorrecta, introduzca R, A, E, B o S\n");
		}

		system("PAUSE");
	}	
	while (opcion != -1); // como la opcion salir cambia la variable opcion a -1, al poner en el while opcion distinto de -1 hacemos que el bucle se repita excepto para este caso.
}