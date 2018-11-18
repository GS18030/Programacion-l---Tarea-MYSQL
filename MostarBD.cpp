#include <cstdlib>
#include <iostream>
#include <winsock2.h>
#include <mysql.h>
#include <mysqld_error.h>
using namespace std;
//Declaracion de funciones	
void menu_principal();
void insertar_clientes();
void insertar_productos();
void mostrar_clientes();
void mostrar_productos();
void lim();
int valid(int a);
//funcion principal MAIN
int main(int argc, char *argv[])
{  	
	int opcion;//variables de entrada
   	MYSQL *conn;//variable mysql

	do{
		cout<<"\n\n";
		menu_principal ();//llama la funcion para el menu
		cout<<"\n\n";
	    cout<<"Digite opcion: ";
		cin>>opcion; //guarda el dato para la opcion 
		valid (opcion); //valida que sea un entero 
		lim();//limpia la pantalla
		switch(opcion) //ciclo para opciones del menu 
		{
			case 1://muestra la opcion de poder agregar un cliente
			{ 	
				lim();	
				insertar_clientes();//llama la funcion para agregar clientes
	            break;
			}
	        case 2://muestra la opcion de poder agregar un cliente
			{ 	
				lim();	
				insertar_productos();//llama la funcion para agregar clientes
	            break;    
			}
	    	case 3:		
	    		lim();//muestra la opcion para poder mostrar los clientes en la base de datos
	    		mostrar_clientes();//llama la funcion para mostrar los clientes
				break;
	
			case 4: //muestra la opcion para poder mostrar los productos
				lim();
				mostrar_productos();//llama la funcion para mostrar los productos
				break;
		}
	} while (opcion!=5);//se sale del ciclo segun la condicion y se sale del programa
 
  	//mysql_close(conn);
    cout<<"Saliendo"<<endl;
    system("pause>null");
    return 0;
}


//FUNCIONES

void menu_principal()
{	//funcion que solo imprime el menu
	cout<<"\n\n\t\t\t--------------------------"<<endl;
	cout<<"\t\t\t||   MENU DE OPCIONES\t||"<<endl;
	cout<<"\t\t\t||1.Add clientes\t||"<<endl;
	cout<<"\t\t\t||2.Add productos\t||"<<endl;
	cout<<"\t\t\t||3.Mostrar clientes\t||"<<endl;
	cout<<"\t\t\t||4.Mostrar productos\t||"<<endl;
	cout<<"\t\t\t||5.Salir\t\t||"<<endl;
}

void lim() //funcion para limpiar la pantalla
{
	system("cls");
}

int valid(int a){ //funcion para validar los datos que sean enteros
 	if (cin.fail()||a<=0){
 		cin.clear();
 		cin.ignore();
 		cout<<"Error"<<endl;
		system("pause>nul");
	 }
	 lim();

return a;
}

void insertar_clientes()
	{ //funcion para agregar clientes
	MYSQL *conn; //variable mysql
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    int qstate;
    conn=mysql_real_connect(&mysql,"localhost","root","","practica",0,0,0);//linea para la conexion con la base de datos
	if(conn)//condicion para comprobar la consulta
    {
        cout<<"\n\n\t\t\tCONECTADO A LA BASE DE DATOS"<<endl;
        cout<<"\t\t\t	Agregar Clientes"<<endl;

        string id; //declaracion de variablbes
		string nombre;
		string apellido;
		string telefono;
		string direccion;
		string email;
		
        cout<<"Ingresar id: "<<endl;  //guardar los datos en las variables
		cin>>id;
        cout<<"Nombre: "<<endl; 
        cin.ignore();//no tomar datos cuando se presione enter
		getline(cin, nombre);
        cout<<"Apellidos: "<<endl; 
		getline(cin, apellido);
        cout<<"Telefono: "<<endl; 
		getline(cin, telefono);
        cout<<"Direccion: "<<endl; 
		getline(cin, direccion);
        cout<<"Email: "<<endl; 
		getline(cin, email);  
		string query="insert into clientes(id_cliente,Nombre,Apellidos,Telefono,Direccion,Email) values('"+id+"','"+nombre+"','"+apellido+"','"+telefono+"','"+direccion+"','"+email+"')"; //linea para insertar los nuevos datos en la tabla clientes de la base de datos		
        const char* q = query.c_str(); //declaracion de query
        //cout<<"query es: "<<q<<endl;
        qstate = mysql_query(conn,q); //identificacion de query para facilidad
        if(!qstate)//condicion if
            cout<<"DATOS GUARDADOS CON EXITO..."<<endl;//se imprime si ha sido guardad la informacion con exito
        else
            cout<<"query error: "<<mysql_error(conn)<<endl;//imprime el error
    }
    else
    {
        cout<<"PROBLEMA DE CONEXION: "<<mysql_error(conn)<<endl;//La base de datos no se ha conectado
    }

}

void insertar_productos()
	{ //funcion para agregar productos
	MYSQL *conn; //variable mysql
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    int qstate;
    conn=mysql_real_connect(&mysql,"localhost","root","","practica",0,0,0);//linea para la conexion con la base de datos
	if(conn)//condicion para comprobar la consulta
    {
        cout<<"\n\n\t\t\tCONECTADO A LA BASE DE DATOS"<<endl;
		cout<<"\t\t\t	Agregar Productos"<<endl;
        string id; //declaracion de variablbes
		string nombre;
		string precio;
		
        cout<<"Ingresar id: "<<endl;  //guardar los datos en las variables
		cin>>id;
        cout<<"Nombre: "<<endl; 
        cin.ignore();//no tomar datos cuando se presione enter
		getline(cin, nombre);
        cout<<"Precio: "<<endl; 
		getline(cin, precio);
		string query="insert into productos(id_producto,Nombre,Precio) values('"+id+"','"+nombre+"','"+precio+"')"; //linea para insertar los nuevos datos en la tabla productos de la base de datos		
        const char* q = query.c_str(); //declaracion de query
        //cout<<"query es: "<<q<<endl;
        qstate = mysql_query(conn,q); //identificacion de query para facilidad
        if(!qstate)//condicion if
            cout<<"DATOS GUARDADOS CON EXITO..."<<endl;//se imprime si ha sido guardad la informacion con exito
        else
            cout<<"query error: "<<mysql_error(conn)<<endl;//imprime el error
    }
    else
    {
        cout<<"PROBLEMA DE CONEXION: "<<mysql_error(conn)<<endl;//La base de datos no se ha conectado
    }

}

void mostrar_clientes(){//funcion para mostrar los clientes de la base de datos
	MYSQL *conn;//declaracion de variables mysql
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    int qstate;
    conn=mysql_real_connect(&mysql,"localhost","root","","practica",0,0,0);//linea para la conexion con la base de datos
		if(conn==NULL)
		    {  
				cout<<mysql_error(&mysql)<<endl;
		       	system("pause");
		     	/// return 1;      
		    }
	    	mysql_query(conn,"select * from clientes");//se seleccion la tabla que se desea mostrar de la base de datos
	    	res=mysql_store_result(conn);	
		    while((row=mysql_fetch_row(res))!=NULL)//condicion mientras sea verdadera
		    {
		        cout<<row[0]<<"\t"; //imprime la informacion 
		        cout<<row[1]<<"\t";
		        cout<<row[2]<<"\t";
		        cout<<row[3]<<"\t";
		        cout<<row[4]<<"\t";
		        cout<<row[5]<<endl;
		    }
}

void mostrar_productos(){//funcion para mostrar los productos de la base de datos
	MYSQL *conn;//declaracion de variables mysql
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    int qstate;
    conn=mysql_real_connect(&mysql,"localhost","root","","practica",0,0,0);//linea para la conexion con la base de datos
	if(conn==NULL)
			    {  
					cout<<mysql_error(&mysql)<<endl;
			       	system("pause");
			     	/// return 1;      
			    }
		    	mysql_query(conn,"select * from productos");//se seleccion la tabla que se desea mostrar de la base de datos
		    	res=mysql_store_result(conn);	
			    while((row=mysql_fetch_row(res))!=NULL)
			    {
			        cout<<row[0]<<"\t";//imprime la informacion 
			        cout<<row[1]<<"\t";
			        cout<<row[2]<<endl;
		
			    }
}
