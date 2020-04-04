
/*Descripción de problema:  Escribir una función Salario que calcule los salarios de un trabajador
para un número dado de horas trabajadas y un salario hora. Las horas que superen las 40 horas semanales
se pagarán como extras con un salario hora 1,5 veces el salario ordinario. Así mismo se deberá calcular el monto
a pagar de IGSS por cada trabajador.

El programa debera contener un menu para:
1) Invocar dicha funcion y grabar datos a un archivo,
2) Adicionalmente deberá tener una opción para leer el archivo y grabar los datos en memoria.
3) Una opción para mostrar cuanto se paga de total de planilla e IGSS.

*/

#include <fstream>
#include <iostream>
#include <string>
//#include <sstream>
#include <iomanip>
using namespace std;
struct empleado {
	int codemp;
	string nombre;
	float salarioo;
	float salariop;
	float costoh;
	float costohe;
	int horast;
	int horase;
	float igss;
};


void insertar_datos_archivo();
void read_file();
void salario(empleado& ingreso);
void mp();//menu principal


int main() {
	///empleado datos;	
	mp();
	//	salario(datos);
		//read_file();

		/*cout<<"**Programa principal"<<endl;
		cout<< datos.nombre<<"\n";
		cout<< datos.codemp<<endl;*/
}

void salario(empleado& ingreso) {
	ofstream archivo;
	string nombreArchivo;
	fflush(stdin); //borrar el buffer existente
	cout << "Indique nombre de archivo: ";
	getline(cin, nombreArchivo);
	archivo.open(nombreArchivo.c_str(), ios::app);
	/*Comprobar archivo*/
	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	system("CLS");
	float salarioo, igss, salariop, costoho, costohe;
	string nombre;
	int horast, horase, codemp;
	/*Ingreso de datos*/
	cout << "Ingrese Codigo de Empleado: " << endl;
	cin >> codemp; //ingreso.codemp;
	fflush(stdin);
	cout << "Ingrese Nombre de Empleado: " << endl;
	getline(cin, nombre, '\n');//,ingreso.nombre);
	cout << "Ingrese Salario Ordinario: " << endl;
	cin >> salarioo;
	cout << "Ingrese Horas Trabajadas: " << endl;
	cin >> horast;
	/*Calculos*/
	costoho = salarioo / 30 / 8; // calculo de costo hora ordinaria
	if (horast > 40)//calculo de horas extras
		horase = horast - 40;
	igss = ((horast - horase)*costoho) * 0.0483;
	costohe = (horase *costoho)*1.5;
	salariop = ((horast - horase)*costoho + costohe) - igss;
	/*Graba datos a la estructura*/
	ingreso.codemp = codemp;
	ingreso.nombre = nombre;
	ingreso.salarioo = salarioo;
	ingreso.salariop = salariop;
	ingreso.costoh = costoho;
	ingreso.costohe = costohe;
	ingreso.igss = igss;
	ingreso.horast = horast;
	ingreso.horase = horase;
	/*Graba datos al archivo*/
	archivo << codemp << "\t" << nombre << "\t" << salarioo << "\t" << salariop << "\t" << costoho << "\t" << costohe << "\t" << igss << "\t" << horast << "\t" << horase << endl;
	archivo.close();
} //salario()

void mp() {
	int i;
	empleado datos;

	do {
		system("CLS");
		cout << "-------------------" << "\n";
		cout << "Menu Principal" << "\n";
		cout << "-------------------" << "\n";
		cout << "1 - Ingresar Empleado " << "\n";
		cout << "2 - Leer archivo" << "\n";
		cout << "3 - Reporte" << "\n";
		cout << "4 - Salir" << "\n";
		cout << "-------------------\n";
		cout << "Seleccione su opcion: ";
		cin >> i;
		if (i == 1)
			salario(datos);
		else if (i == 2)
			read_file();
		else if (i == 3)
			read_file();
		else if (i == 4)
			break;
		else
			break;

	} while (i != 4);
}


void read_file() {
	ifstream archivo; //leer archivo
	string nombreArchivo;
	fflush(stdin);
	cout << "Indique nombre de archivo: ";
	getline(cin, nombreArchivo);
	archivo.open(nombreArchivo.c_str(), ios::in);
	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo!!!";
		exit(1);
	}

	int lineas;
	string s;
	while (getline(archivo, s))
		lineas++;

	archivo.close();
	system("CLS");
	cout << "Lineas: " << lineas << endl;
	empleado recordset[lineas];

	archivo.open(nombreArchivo.c_str(), ios::in);
	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo!!!";
		exit(1);
	}

	for (int i = 0; i < lineas; i++)
	{

		//indata >> list[index].menuItem;
		//indata >> list[index].menuPrice;
		archivo >> recordset[i].codemp;
		getline(archivo, recordset[i].nombre, ',');
		//archivo>>
		//getline(archivo, recordset[i].nombre, ",");
	}
	for (int i = 0; i < lineas; i++)
		cout << recordset[i].codemp << " " << recordset[i].nombre << " " << recordset[i].salarioo;

	archivo.close();
	system("Pause");

}

void insertar_datos_archivo() {
	cout << "Insertando datos\n\n";
	system("PAUSE");
	system("CLS");
}
