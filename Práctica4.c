//Desarrollador: Marta Vinagre Teba
//Practica 4:Vectores de estructuras


#include <stdio.h>
#include <string.h> // incluyo esta librería para que me funcione el strcmp

#define NPLAZAS 5

struct plaza {
	int estado; // 0 - Libre / 1 - Ocupada
	char matricula[8]; // Formato de la matrícula: NNNNLLL
	char c_o_m;
};

void main() {

	//inicializo las variables

	struct plaza plaza[NPLAZAS];
	char opcion;
	char matricula2[8];
	char usuario[20] = "Marta";
	char contraseña[20] = "1234";
	char usuarioaux[20];
	char contraseñaaux[20];
	int coche;
	int moto;
	int i, k;
	int intentos = 0;
	int aux = 1;
	int aux2 = 0;
	int ocupado = 0;

	while (aux == 1) {
		for (i = 0; i < 3; i++) {

			printf("Introduzca su usuario:\n");
			gets(usuarioaux);
			printf("Introduzca su contraseña:\n");
			gets(contraseñaaux);

			if (strcmp(usuarioaux, usuario) == 0 && strcmp(contraseñaaux, contraseña) == 0) {
				printf("Entrando en el aparcamiento\n");
				aux2 = 1;
				break;
			}
			else if (strcmp(usuarioaux, usuario) == 1 || strcmp(contraseñaaux, contraseña) == 1) {
				printf("Contraseña o usuario incorrecto, intentalo otra vez\n");
				intentos++;
			}
		}
		if (intentos == 3) {
			aux = 0;
			printf("Ha superado el numero de intentos posibles. Cerrando programa...\n");
		}
		system("cls");
		while (aux2 == 1) {
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

					ocupado = 0;
					i = 0;


					if (ocupado == 0) {
						printf("No quedan plazas libres\n");
					}
					while (ocupado == 0 && i < NPLAZAS) {
						if (plaza[i].estado = 0) {
							plaza[i].estado = 1;
							printf("Introduzca el tipo de vehiculo que desea aparcar C-coche, M-moto\n");
							getchar();
							scanf_s("%c", &plaza[i].c_o_m);
							while (plaza[i].c_o_m != 'c' && plaza[i].c_o_m != 'C' && plaza[i].c_o_m != 'm' && plaza[i].c_o_m != 'M') {
								printf("La opción introducida no coincide con ninguna de las dadas, por favor, introduzcala de nuevo\n");
								getchar();
								scanf_s("%c", &plaza[i].c_o_m);
							}
							printf("Introduzca su matricula\n");
							scanf_s("%s", plaza[i].matricula, 8);
							ocupado = 1;

						}
						i++;



					}

					break;


				case 'A':
					k = 0;
					for (i = 0; i < NPLAZAS; i++) {
						if (plaza[i].estado == 0) {
							k++;
						}
					}
					if (k == (NPLAZAS - 1)) {
						printf_s("El aparcamiento esta vacio\n");
					}
					else {
						printf_s("Introduce tu matricula:\n");
						for (i = 0; i < 7; i++) {
							getchar();
							scanf_s("%c", &matricula2[i]);
						}
						ocupado = 0;
						i = 0;

						while (ocupado == 0 && i < NPLAZAS) {
							if (plaza[i].estado == 1) {
								if (strcmp(matricula2, plaza[i].matricula) == 0) {
									plaza[i].estado = 0; /*Actualizo que se ha quedado vacia la plaza*/
									printf("Abandonando plaza...\n");
									ocupado = 0;
								}
							}
							i++;
						}
						if (ocupado == 0) {
							printf_s("Tu matricula no coincide con ninguna del aparcamiento\n");
						}

					}

					break;

				case 'E':
					printf_s("Mostrando el estado del aparcamiento:\n");
					for (i = 0; i < NPLAZAS; i++) {
						if (plaza[i].estado == 0) {
							printf("Plaza %d - Libre\n", i + 1);
						}
						else {
							printf("Plaza %d de %c - Ocupada - Matricula: %s\n", i + 1, plaza[i].c_o_m, plaza[i].matricula);
						}
					}
					break;

				case 'B':
					k = 0;
					for (i = 0; i < NPLAZAS; i++) {
						if (plaza[i].estado == 0) {
							k++;
						}
					}

					printf_s("Introduce tu matricula:\n");
					for (i = 0; i < 7; i++) {
						getchar();
						scanf_s("%c", &matricula2[i]);
					}
					ocupado = 0;
					i = 0;

					if (ocupado == 0) {
						printf_s("Tu matricula no coincide con ninguna del aparcamiento\n");
					}
					else {
						while (ocupado == 0 && i <NPLAZAS) {
							if (plaza[i].estado == 1) {
								if (strcmp(matricula2, plaza[i].matricula) == 0) {
									printf_s("Su vehiculo esta en la plaza %d \n", i + 1);
									ocupado = 1;
								}

							}
						}

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


			} while (opcion != -1); // como la opcion salir cambia la variable opcion a -1, al poner en el while opcion distinto de -1 hacemos que el bucle se repita excepto para este caso.

		}

	}
	system("pause");
}