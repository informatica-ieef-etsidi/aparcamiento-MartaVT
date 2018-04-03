//Desarrollador: Marta Vinagre Teba
//Practica 3:Cadenas y estructuras


#include <stdio.h>
#include <string.h> // incluyo esta librería para que me funcione el strcmp


struct plaza {
	int estado; // 0 - Libre / 1 - Ocupada
	char matricula[8]; // Formato de la matrícula: NNNNLLL
	char c_o_m[2];
};

void main() {

	//inicializo las variables

	struct plaza plaza1 = { 0, 'C' };
	struct plaza plaza2 = { 0, 'M' };
	char opcion;
	char matricula[8];
	char usuario[20] = "Marta";
	char contraseña[20] = "1234";
	char usuarioaux[20];
	char contraseñaaux[20];
	int coche;
	int moto;
	int i;
	int intentos = 0;
	int aux = 1;
	int aux2 = 0;

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
					if (plaza1.estado == 1 && plaza2.estado == 1) {
						printf_s("Ambas plazas estan ocupadas\n");

					}
					else if (plaza1.estado == 0 && plaza2.estado == 1) {
						printf_s("La plaza 1 esta libre\n");
						printf_s("Escriba 'C' si es un Coche o 'M' si es una Moto\n");
						for (i = 0; i < 1; i++) {
							getchar();
							scanf_s("%c", &plaza1.c_o_m[i]);
						}
						if (strcmp(plaza1.c_o_m, "C") == 1) {
							coche = 1;
						}
						else if (strcmp(plaza1.c_o_m, "M") == 1) {
							moto = 1;
						}

						printf_s("Introduce tu matricula:\n");
						for (i = 0; i < 7; i++) {
							getchar(); // como voy a introducir caracteres necesito un getchar
							scanf_s("%c", &plaza1.matricula[i]);
						}
						plaza1.estado = 1; //se cambia la plaza 1 de vacia a ocupada

					}
					else if (plaza1.estado == 1 && plaza2.estado == 0) {
						printf_s("La plaza 2 esta libre\n");
						printf_s("Escriba 'C' si es un Coche o 'M' si es una Moto\n");
						for (i = 0; i < 1; i++) {
							getchar();
							scanf_s("%c", &plaza2.c_o_m[i]);
						}
						if (strcmp(plaza2.c_o_m, "C") == 1) {
							coche = 1;
						}
						else if (strcmp(plaza2.c_o_m, "M") == 1) {
							moto = 1;
						}
						printf_s("Introduce tu matricula:\n");
						for (i = 0; i < 7; i++) {
							getchar();
							scanf_s("%c", &plaza2.matricula[i]);
						}
						plaza2.estado = 1;

					}
					else if (plaza1.estado == 0 && plaza2.estado == 0) {
						printf_s("Ambas plazas están libres, se te asigna la plaza 1\n");
						printf_s("Escriba 'C' si es un Coche o 'M' si es una Moto\n");
						for (i = 0; i < 1; i++) {
							getchar();
							scanf_s("%c", &plaza1.c_o_m[i]);
						}
						if (strcmp(plaza1.c_o_m, "C") == 1) {
							coche = 1;
						}
						else if (strcmp(plaza1.c_o_m, "M") == 1) {
							moto = 1;
						}
						printf_s("Introduce tu matricula:\n");
						for (i = 0; i < 7; i++) {
							getchar();
							scanf_s("%c", &plaza1.matricula[i]);
						}
						plaza1.estado = 1;
					}

					break;


				case 'A':
					if (plaza1.estado == 0 && plaza2.estado == 0) {
						printf_s("El aparcamiento esta vacio\n");
					}
					else {
						printf_s("Introduce tu matricula:\n");
						for (i = 0; i < 7; i++) {
							getchar();
							scanf_s("%c", &matricula[i]);
						}

						if (strcmp(matricula, plaza1.matricula) == 1) {
							printf_s("Abandonando plaza 1\n");
							plaza1.estado = 0; //se cambia la plaza 1 de ocupada a vacia
						}
						else if (strcmp(matricula, plaza2.matricula) == 1) {
							printf_s("Abandonando plaza 2\n");
							plaza2.estado = 0;
						}
						else {
							printf_s("Tu matricula no coincide con ninguna del aparcamiento\n");
						}
					}

					break;

				case 'E':
					printf_s("Mostrando el estado del aparcamiento:\n");
					if (plaza1.estado == 0) {
						printf_s("Plaza 1 - Libre\n");
					}
					if (plaza1.estado == 1) {
						if (coche == 1) {
							printf_s("Plaza 1 - Ocupada - Coche - Matricula: %s\n", plaza1.matricula);
						}
						else if (moto == 1) {
							printf_s("Plaza 1 - Ocupada - Moto - Matricula: %s\n", plaza1.matricula);
						}
					}
					if (plaza2.estado == 0) {
						printf_s("Plaza 2 - Libre\n");
					}
					if (plaza2.estado == 1) {
						if (coche == 1) {
							printf_s("Plaza 2 - Ocupada - Coche - Matricula: %s\n", plaza2.matricula);
						}
						else if (moto == 1) {
							printf_s("Plaza 2 - Ocupada - Moto - Matricula: %s\n", plaza2.matricula);
						}
					}

					break;


				case 'B':
					printf_s("Introduce tu matricula:\n");
					for (i = 0; i < 7; i++) {
						getchar();
						scanf_s("%c", &matricula[i]);
					}

					if (strcmp(matricula, plaza1.matricula) == 1) {
						printf_s("Su vehiculo esta en la plaza 1\n");
					}
					else if (strcmp(matricula, plaza2.matricula) == 1) {
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

			} while (opcion != -1); // como la opcion salir cambia la variable opcion a -1, al poner en el while opcion distinto de -1 hacemos que el bucle se repita excepto para este caso.

		}

	}
	system("pause");
}