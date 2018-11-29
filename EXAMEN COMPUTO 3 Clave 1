//JOSE ADOLFO GUZMAN SOLIS
//GS18030

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <sstream>
#include <conio.h>

using namespace std;
//DECLARACION DE FUNCIONES
//------------------------------------------------------------------------------------------------------------------------------
void menu_principal();
int valid(int a);
void fibonacci();
void serie_taylor();
double tay(int n, int x);
double factorial(int n);
int ingresar(int o, string n, string d, string r);
void Mostrar();

//FUNCION MAIN PRINCIPAL
//------------------------------------------------------------------------------------------------------------------------------

int main(){
	int n;
	do
	{
	menu_principal();
	cout<<"Digite Opcion: ";
  	cin>>n;
  	valid(n);
  	system ("cls");
	  	switch(n)
		{
			case 1:
				fibonacci();
				system ("cls");
				break;
	
			case 2:
				serie_taylor();
				system ("cls");
				break;
			case 3:
		    	Mostrar();
		    	system ("cls");
				break;
		} 
	}while (n!=4 );
	return 0;
}

//FUNCIONES
//------------------------------------------------------------------------------------------------------------------------------
//Imprime las opciones del menu principal 
void menu_principal(){

	cout<<"\t\t\t\t	MENU PRINCIPAL "<<endl;
	cout<<endl;
	cout<<"\t\t\t|	1. Secuencia Fibonacci		|"<<endl;
	cout<<"\t\t\t|	2. Serie de Taylor		|"<<endl;
	cout<<"\t\t\t|	3. Resultados			|"<<endl;
	cout<<"\t\t\t|	4. Salir			|"<<endl;
	cout<<endl;
}

//------------------------------------------------------------------------------------------------------------------------------
//codigo para calcular la secuencia fibonacci
void fibonacci(){
	//declaracion de variables
	string nom = "Fibonacci";//Nombre asignado para su registro
    int i, n, cont = 0; 
    long long int a[100];//variable con los numeros de la secuencia y su espacio de memoria
    stringstream ss; //convertir el vector a un string
    a[0] = 0;
    a[1] = 1;
 	cout << "\n\n\t\t\t\tSecuencia Fibonacci"<< endl;
 	
    cout << "\n";
    cout << "\n";
    cout << "Ingrese un numero para la sucesion de fibonacci: ";
    cin >> n; //se guarda el dato ingresado para la secuencia
    cout << "\n";
    
    for(i=1; i < n; i++) //ciclos para ordenar y condicionar la secuencia
	{
 		a[i+1] = a[i-1] + a[i]; 
    }
 		for(i=0; i < n; i++)
		{
	        if (cont == 10)
			{ 
	            cout << "\n";
	            cont = 0;    //contador       
        	}
	        cout << "[ "<< a[i] << "] ";//imprime los numeros de la secuencia en su orden
	        cont += 1;   
	  		ss<< a[i] << " ";     
     }  
    cout << "\n";
    stringstream sq;    
  	sq<<"Numero para la sucesion de fibonacci: "<<n;       
    string datos= sq.str(); //datos en string
    string res= ss.str();  //se transformar las iteraciones de la secuencia fibonacci
    ingresar(1, nom, datos, res);//se envia a la funcion ingresar, para guardar la informacion obtenida de las secuencias
    getch();
}

//------------------------------------------------------------------------------------------------------------------------------

void serie_taylor(){
	
	cout << "\n\n\t\t\t\tSerie de Taylor"<< endl;
 	
    cout << "\n";
    cout << "\n";
	
	int n;
	int x;
	double res;
	string nom = "Serie de Taylor";//Nombre asignado para su registro
	
	cout<<"Valor de n: "; cin>> n;
	cout<<"Valor de x: "; cin>> x;
	cout<<endl;
    res = tay(n,x);//variable donde se realiza la operacion 
	cout<<"Para n= "<<n<<" y x= "<<x<<" = "<<res<<endl;//imprime los resultados
	
	
    stringstream ss;    //datos en string
  	ss<<"n= "<<n <<" y x= "<<x;       
    string datos= ss.str();
     stringstream sr;    
  	sr<<"El resultado es: "<<res;       
    string re= sr.str(); 
	ingresar(2, nom, datos, re);//se envia a la funcion ingresar, para guardar la informacion obtenida de las secuencias
	
	getch();
}

//------------------------------------------------------------------------------------------------------------------------------
//Proceso para calcular la serie de Taylor
double tay(int n, int x){
	
	double t; //declaracion de variables
	double s;
	
	for (int i = 0; i < n; i++){
		
		t = pow(x, i) / factorial(i);//se llama la funcion pow para elevar el numero y se llama la funcion de calculo de factorial
		s += t; //acumulador 
	}
	return s;
}

//------------------------------------------------------------------------------------------------------------------------------
double factorial(int n){ //funcion para calcular el factorial 
	
	double fact =1;
	for(int i= 2; i<=n; i++){
		fact*=i;
	}
	return fact;
}
//------------------------------------------------------------------------------------------------------------------------------
//Funcion para crear el archivo de bloc de notas de extension .txt
int ingresar(int o, string n, string d, string r)
{
	fstream file("datos.txt", ios::in | ios::out | ios::app);
 	//comprobacion de errores
	if (!file.is_open())
	  	{
	  	cout<<"Error!";	
  		}
	else
		{
  		cout<<"Listo..."<<endl;
	    stringstream sa;
	  	sa<<o;
	  	//asignacion de variables
	  	string opcion= sa.str();
	    string nombre = n;
	  	string datos = d;
	  	string resultado=r;	
	  	file<<opcion<<" - "<<nombre<<" - "<<datos<<" - "<<resultado<<endl;//los datos que se guardaran dentro del archivo ,txt
		}
	return 0;
}

//------------------------------------------------------------------------------------------------------------------------------
//Funcion para llamar los datos guardados en el archivo de texto y mostrarlos en pantalla
void Mostrar(){
	
	fstream file("datos.txt", ios::in | ios::out | ios::app);//se ubica el archivo de texto extension txt.

 	 if (!file.is_open())
	{
  		cout<<"Error al abrir archivo";
  	}
	else
	{	//Codigo para extraer el texto y mostratlo en consola 
	  	file.seekg(0);
	  	string line;
	  	cout << "\n\n\t\t\t\tINFORME DE ACTIVIDAD"<< endl;	
    	cout << "\n";
   		 cout << "\n";
	  	cout<<endl;
	  	while(file.good()){
	  	getline(file, line);
	  	cout << line << endl;
	}
}

getch();

}

int valid(int a){
 	if (cin.fail()||a<=0){
 		cin.clear();
 		cin.ignore();
 		cout<<"Error"<<endl;
		system("pause>nul");
	 }
	 system ("cls");

return a;
 }

