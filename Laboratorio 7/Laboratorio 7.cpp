#include <iostream>
#include <string>
#include <#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <windows.h> // Incluir para usar gotoxy y system("cls")

using namespace std;

// Función para posicionar el cursor en la consola
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función para limpiar la pantalla
void clearScreen() {
	system("cls");
}

class cuentabancaria {
private:
	string numeroCuenta;
	double saldo;
	bool activa;
	bool bloqueada;
	int intentosfallidos;

public:
	cuentabancaria(string numCuenta, double saldo, bool activa, bool bloqueada, int intentosfallidos) {
		numeroCuenta = numCuenta;
		this->saldo = saldo;
		this->activa = activa;
		this->bloqueada = bloqueada;
		this->intentosfallidos = intentosfallidos;
	}

	string getnumeroCuenta() {
		return numeroCuenta;
	}

	double getsaldo() {
		return saldo;
	}

	bool estaactiva() {
		return activa;
	}

	bool establoqueada() {
		return bloqueada;
	}

	void depositar(double monto) {
		if (!activa) {
			cout << "No se puede depositar, su cuenta está bloqueada por inactividad" << endl;
			return;
		}

		if (bloqueada) {
			cout << "No se puede depositar, su cuenta está bloqueada por alcanzar los intentos permitidos." << endl;
			return;
		}

		saldo += monto;
		cout << "Depósito realizado con éxito." << endl;
	}

	void retirar(double monto) {
		if (!activa) {
			cout << "No se puede retirar, su cuenta está bloqueada por inactividad." << endl;
			return;
		}

		if (bloqueada) {
			cout << "No se puede retirar, su cuenta está bloqueada por alcanzar los intentos permitidos." << endl;
			return;
		}

		if (monto > saldo) {
			cout << "Fondos insuficientes, saldo actual: Q" << saldo << endl;
			intentosfallidos++;

			if (intentosfallidos >= 3) {
				bloqueada = true;
				cout << "No se puede acceder a su cuenta, se ha excedido los intentos fallidos." << endl;
			}
			return;
		}

		saldo -= monto;
		intentosfallidos = 0;
		cout << "Retiro realizado con éxito." << endl;

		if (saldo < 500) {
			cout << "Saldo insuficiente. Deposite más dinero para acceder a retirar fondos." << saldo << endl;
		}
	}

	void desactivarcuenta() {
		activa = false;
		cout << "Su cuenta ha sido desactivada." << endl;
	}

	void activarcuenta() {
		activa = true;
		cout << "Su cuenta ha sido activada." << endl;
	}

	void desbloquearcuenta() {
		bloqueada = false;
		intentosfallidos = 0;
		cout << "Cuenta desbloqueada." << endl;
	}

	void mostrarmenu() {
		int opcion;
		double monto;

		do {
			clearScreen(); // Limpiar la pantalla antes de mostrar el menú
			gotoxy(35, 10); // Posicionar el menú en el centro de la pantalla
			cout << "---Menu de opciones para la cuenta: " << getnumeroCuenta() << "---" << endl;
			gotoxy(35, 11);
			cout << "1. Ver saldo." << endl;
			gotoxy(35, 12);
			cout << "2. Depositar." << endl;
			gotoxy(35, 13);
			cout << "3. Retirar" << endl;
			gotoxy(35, 14);
			cout << "4. Desactivar cuenta" << endl;
			gotoxy(35, 15);
			cout << "5. Activar cuenta" << endl;
			gotoxy(35, 16);
			cout << "6. Desbloquear cuenta" << endl;
			gotoxy(35, 17);
			cout << "7. Salir" << endl;
			gotoxy(35, 18);
			cout << "Seleccione una opción: ";
			cin >> opcion;

			switch (opcion) {
			case 1:
				gotoxy(35, 20);
				cout << "Saldo actual: Q" << getsaldo() << endl;
				system("pause");
				break;
			case 2:
				gotoxy(35, 20);
				cout << "Ingrese el monto a depositar: ";
				cin >> monto;
				depositar(monto);
				system("pause");
				break;
			case 3:
				gotoxy(35, 20);
				cout << "Ingrese el monto a retirar: ";
				cin >> monto;
				retirar(monto);
				system("pause");
				break;
			case 4:
				desactivarcuenta();
				system("pause");
				break;
			case 5:
				activarcuenta();
				system("pause");
				break;
			case 6:
				desbloquearcuenta();
				system("pause");
				break;
			case 7:
				gotoxy(35, 20);
				cout << "Saliendo del programa, por favor espere..." << endl;
				system("pause");
				break;
			default:
				gotoxy(35, 20);
				cout << "Opción no válida, ingrese opciones que aparecen en el menú." << endl;
				system("pause");
			}
		} while (opcion != 7);
	}
};

int main() {
	setlocale(LC_ALL, "es_ES.UTF-8");
	double monto = 1234.89;
	std::cout << std::fixed << std::setprecision(2) << monto << std::endl;

	cuentabancaria cuenta1("1", 1000, true, false, 0);
	cuentabancaria cuenta2("2", 1000, true, false, 0);
	cuentabancaria cuenta3("3", 1000, true, false, 0);
	cuentabancaria cuenta4("4", 1000, true, false, 0);
	cuentabancaria cuenta5("5", 1000, true, false, 0);
	cuentabancaria cuenta6("6", 1000, true, false, 0);
	cuentabancaria cuenta7("7", 1000, true, false, 0);
	cuentabancaria cuenta8("8", 1000, true, false, 0);
	cuentabancaria cuenta9("9", 1000, true, false, 0);
	cuentabancaria cuenta10("10", 1000, true, false, 0);
	cuentabancaria cuenta11("11", 1000, true, false, 0);
	cuentabancaria cuenta12("12", 1000, true, false, 0);
	cuentabancaria cuenta13("13", 1000, true, false, 0);
	cuentabancaria cuenta14("14", 1000, true, false, 0);
	cuentabancaria cuenta15("15", 1000, true, false, 0);
	cuentabancaria cuenta16("16", 1000, true, false, 0);
	cuentabancaria cuenta17("17", 1000, true, false, 0);
	cuentabancaria cuenta18("18", 1000, true, false, 0);
	cuentabancaria cuenta19("19", 1000, true, false, 0);
	cuentabancaria cuenta20("20", 1000, true, false, 0);
	cuentabancaria cuenta21("21", 1000, true, false, 0);
	cuentabancaria cuenta22("22", 1000, true, false, 0);
	cuentabancaria cuenta23("23", 1000, true, false, 0);
	cuentabancaria cuenta24("24", 1000, true, false, 0);
	cuentabancaria cuenta25("25", 1000, true, false, 0);
	cuentabancaria cuenta26("26", 1000, true, false, 0);
	cuentabancaria cuenta27("27", 1000, true, false, 0);
	cuentabancaria cuenta28("28", 1000, true, false, 0);
	cuentabancaria cuenta29("29", 1000, true, false, 0);
	cuentabancaria cuenta30("30", 1000, true, false, 0);

	int opcionprincipal;
	int numerocuenta;

	do {
		clearScreen(); // Limpiar la pantalla antes de mostrar el menú principal
		gotoxy(35, 10);
		cout << "<-----Menú Principal----->" << endl;
		gotoxy(35, 12);
		cout << "1. Seleccionar una cuenta." << endl;
		gotoxy(35, 13);
		cout << "0. Salir" << endl;
		gotoxy(35, 14);
		cout << "Seleccione una opción: ";
		cin >> opcionprincipal;

		if (opcionprincipal == 1) {
			gotoxy(35, 16);
			cout << "Ingrese el número de cuenta: ";
			cin >> numerocuenta;

			switch (numerocuenta) {
			case 1:
				cuenta1.mostrarmenu();
				break;
			case 2:
				cuenta2.mostrarmenu();
				break;
			case 3:
				cuenta3.mostrarmenu();
				break;
			case 4:
				cuenta4.mostrarmenu();
				break;
			case 5:
				cuenta5.mostrarmenu();
				break;
			case 6:
				cuenta6.mostrarmenu();
				break;
			case 7:
				cuenta7.mostrarmenu();
				break;
			case 8:
				cuenta8.mostrarmenu();
				break;
			case 9:
				cuenta9.mostrarmenu();
				break;
			case 10:
				cuenta10.mostrarmenu();
				break;
			case 11:
				cuenta11.mostrarmenu();
				break;
			case 12:
				cuenta12.mostrarmenu();
				break;
			case 13:
				cuenta13.mostrarmenu();
				break;
			case 14:
				cuenta14.mostrarmenu();
				break;
			case 15:
				cuenta15.mostrarmenu();
				break;
			case 16:
				cuenta16.mostrarmenu();
				break;
			case 17:
				cuenta17.mostrarmenu();
				break;
			case 18:
				cuenta18.mostrarmenu();
				break;
			case 19:
				cuenta19.mostrarmenu();
				break;
			case 20:
				cuenta20.mostrarmenu();
				break;
			case 21:
				cuenta21.mostrarmenu();
				break;
			case 22:
				cuenta22.mostrarmenu();
				break;
			case 23:
				cuenta23.mostrarmenu();
				break;
			case 24:
				cuenta24.mostrarmenu();
				break;
			case 25:
				cuenta25.mostrarmenu();
				break;
			case 26:
				cuenta26.mostrarmenu();
				break;
			case 27:
				cuenta27.mostrarmenu();
				break;
			case 28:
				cuenta28.mostrarmenu();1
				break;
			case 29:
				cuenta29.mostrarmenu();
				break;
			case 30:
				cuenta30.mostrarmenu();
				break;
			default:
				gotoxy(35, 18);
				cout << "Número de cuenta no válido." << endl;
				system("pause");
			}
		}
		else if (opcionprincipal == 0) {
			gotoxy(35, 16);
			cout << "Saliendo del programa, por favor espere." << endl;
			system("pause");
		}
		else {
			gotoxy(35, 16);
			cout << "Opción no válida, intente otro número." << endl;
			system("pause");
		}
	} while (opcionprincipal != 0);

	return 0;
}
