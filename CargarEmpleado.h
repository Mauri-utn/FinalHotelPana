#ifndef CARGAREMPLEADO_H_INCLUDED
#define CARGAREMPLEADO_H_INCLUDED

#include "menuClientes.h"
#include "CargarEmpleado.h"

void cargarEmpleado();
void ListarTodosLosEmpleados();
void modificarEmpleado();
void EmpleadosActivosInactivos();


class Personaa{
	 protected:
		char dni[20];
		char nombres[50];
		char apellidos[50];
		Fecha fecha_nac;
		Direccion domicilio;
		char telefono[20];
	 public:
		void Cargar();
		void Mostrar();
		char * getNdoc(){return dni;}
		char * getNombre(){return nombres;}
		char * getApellido(){return apellidos;}
		Fecha getFecha(){return fecha_nac;}
		Direccion getDomicilio(){return domicilio;}
		char * getTelefono(){return telefono;}
		void setNdoc(char *n){strcpy(dni,n);}
		void setNombre(char *n){strcpy(nombres,n);}
		void setApellido(char *a){strcpy(apellidos,a);}
		void setFecha_nac(Fecha f){fecha_nac=f;}
		void setDomicilio(Direccion d){domicilio=d;}
		void setTelefono(char *tel){strcpy(telefono,tel);}
	 };


class Empleados:public Personaa{
    private:
        int Id;
        char Area[50];
        char Genero[2];
        char Turno[10];
        char Sueldo[10];
        char Cuil[15];
        char ActivoInactivo[10];
      public:
        void Cargar();
        void Mostrar();
        char * getArea(){return Area;}
        int getId(){return Id;}
        char * getGenero(){return Genero;}
        char * getTurno(){return Turno;}
        char * getSueldo(){return Sueldo;}
        char * getCuil(){return Cuil;}
        char * getActivoInactivo(){return ActivoInactivo;}
        void setArea(char *a){strcpy(Area,a);}
        void setId(int i){Id=i;}
        void setGenero(char *g){strcpy(Genero,g);}
        void setTurno(char *t){strcpy(Turno,t);}
        void setSueldo(char *s){strcpy(Sueldo,s);}
        void setCuil(char *c){strcpy(Cuil,c);}
        void setActivoInactivo(char *a){strcpy(ActivoInactivo,a);}
        bool EscribirEnDisco();
        bool LeerDeDisco(int);
        void EscribirPosicionEnDisco(int);
};

int buscarId(Empleados);
int comprobarCadNumericas(char *);
int comprobarNombresApellidos(char *);
int comprobarGenero(char *);
int comprobarTurno(char *);
int comprobarSueldo(char *);
int comprobarCuil(char *,char *);
int buscarDNI(char *);

int MenuEmpleados(){
    setlocale(LC_ALL,"spanish");
    int opcion;
    while(true){
    system("cls");
    cout << "\t\tELIJA UNA CATEGORIA" <<endl;
    cout << "\t\t--------------" <<endl;
    cout << "\t\t1)Cargar Empleado " <<endl;
    cout << "\t\t2)Mostrar Empleados " <<endl;
    cout << "\t\t3)Modificar Empleado " <<endl;
    cout << "\t\t4)Dar de Baja un empleado" <<endl;
    cout << "\t\t0)Volver " << endl;
    cout << "\t\t--------------" <<endl;
    cout << "\t\tIngrese opcion:" << endl;
    cin >> opcion;
    system ("cls");
    switch(opcion){
    case 0:
       return -1;
    break;
    case 1:
        cargarEmpleado();
    break;
    case 2:
        ListarTodosLosEmpleados();
        system("pause");
    break;
    case 3:
        modificarEmpleado();
    break;
    case 4:
        EmpleadosActivosInactivos();
    break;

        }
    }
}




void cargarEmpleado(){
    setlocale(LC_ALL,"spanish");
    class Empleados reg;
    int opcion;
    system("cls");
    cout << "\t\tELIJA UNA CATEGORIA" <<endl;
    cout << "\t\t--------------" <<endl;
    cout << "\t\t1) LIMPIEZA" <<endl;
    cout << "\t\t2) ADMINISTRACION" <<endl;
    cout << "\t\t3) SEGURIDAD" <<endl;
    cout << "\t\t4) MANTENIMIENTO" <<endl;
    cout << "\t\t5) OTROS" <<endl;
    cout << "\t\t0) Volver " << endl;
    cout << "\t\t--------------" <<endl;
    cout << "\t\tIngrese opcion:" << endl;
    cin >> opcion;
    system ("cls");
    switch(opcion){
    case 0:
       return ;
    break;
    case 1:
        {
        reg.setArea("Limpieza");
        reg.Cargar();
        int aux = buscarId(reg);
        reg.setId(aux);
        reg.EscribirEnDisco();
        }
    break;
    case 2:
        {
        reg.setArea("Administracion");
        reg.Cargar();
        int aux = buscarId(reg);
        reg.setId(aux);
        reg.EscribirEnDisco();
        }
    break;
    case 3:
        {
        reg.setArea("Seguridad");
        reg.Cargar();
        int aux = buscarId(reg);
        reg.setId(aux);
        reg.EscribirEnDisco();
        }
    break;
    case 4:
        {
        reg.setArea("Mantenimiento");
        reg.Cargar();
        int aux = buscarId(reg);
        reg.setId(aux);
        reg.EscribirEnDisco();
        }
    break;
    case 5:
        {
        reg.setArea("otros");
        reg.Cargar();
        int aux = buscarId(reg);
        reg.setId(aux);
        reg.EscribirEnDisco();
        }
    break;
        }

}



void Personaa::Cargar()
	{

    fflush(stdin);
    do{
	cout<<"Ingrese el nombre: ";
	cin.getline(nombres,50);
    }while(comprobarNombresApellidos(nombres)==-1);
    do{
	cout<<"Ingrese el apellido: ";
	cin.getline(apellidos,50);
    }while(comprobarNombresApellidos(apellidos)==-1);
	cout<<"Ingrese la fecha de nacimiento: ";
	fecha_nac.cargar();
	cout<<"Ingrese la direccion: ";
	domicilio.cargar();
	fflush(stdin);
    do{
	cout<<"Ingrese el numero de documento: ";
	cin.getline(dni,20);
	}while(comprobarCadNumericas(dni)==-1 || buscarDNI(dni)==false);
	do{
	cout<<"Ingrese el numero de telefono(sin 0 y 15): ";
	cin.getline(telefono,20);
	}while(comprobarCadNumericas(telefono)==-1);
	}
void Personaa::Mostrar()
	{
	cout<<"\t\tNombre: ";
	cout<<nombres<<endl;
	cout<<"\t\tApellido: ";
	cout<<apellidos<<endl;
	cout << "\t\tFECHA DE NACIMIENTO ---> " ; fecha_nac.mostrarConBarra();
	cout<<"\t\tDomicilio: "<< endl;
	domicilio.mostrar();
	cout<<"\t\tDocumento: ";
	cout<<dni<<endl;
	cout<<"\t\tTelefono: ";
	cout<<telefono<<endl;
	}
void Empleados::Cargar(){
    Personaa::Cargar();
    do{
    cout << "Ingrese Genero(F o M)" << endl;
    cin.getline(Genero,2);
    }while(comprobarGenero(Genero)==-1);
    do{
    cout << "ingrese Turno" << endl;
    cin.getline(Turno,10);
    }while(comprobarTurno(Turno)==-1);
    do{
    cout << "Ingrese Sueldo" << endl;
    cin.getline(Sueldo,10);
    }while(comprobarSueldo(Sueldo)==-1);
    do{
    cout << "Ingrese Cuil" << endl;
    cin.getline(Cuil,15);
    }while(comprobarCuil(Cuil,dni)==-1 || comprobarCadNumericas(Cuil)==-1);
    strcpy(ActivoInactivo,"Activo");
}



void Empleados::Mostrar(){
    Personaa::Mostrar();
    cout << "\t\tId: " << Id << endl;
    cout << "\t\tGenero: " << Genero << endl;
    cout << "\t\tArea: " << Area << endl;
    cout << "\t\tTurno: " << Turno << endl;
    cout << "\t\tSueldo: $" << Sueldo << endl;
    cout << "\t\tCuil: " << Cuil << endl;
    cout << "\t\tEstado " << ActivoInactivo << endl;
    cout << endl;
    cout << "\t\t-------------------------------------" << endl;
    cout << endl;
}

///LISTAR EMPLEADOS









void ListarTodosLosEmpleados(){
    Empleados reg;
    int pos=0;
    while(reg.LeerDeDisco(pos++)){
            reg.Mostrar();
    }
}

///MODIFICAR EMPLEADOS


bool buscarId(int id){
    Empleados buscar;
    int pos=0;
    while(buscar.LeerDeDisco(pos++)){
        if(id==buscar.getId()){
            return pos;
        }
    }
    return -1;
}
void modificarEmpleado(){
    int id;
    cout << "\t\tIngrese Id del Empleado" << endl;
    cin >> id;
    int aux = buscarId(id);
    if(aux==-1){ cout << "\t\tNo se encontro el Id" << endl; system("pause"); return ;}
    cout << "VALOR DE AUX " << aux << endl;
    Empleados reg;
    aux=aux-1;
    reg.LeerDeDisco(aux);
    reg.Cargar();
    reg.EscribirPosicionEnDisco(aux);
}
///EMPLEADOS ACTIVOS INACTIVOS
void EmpleadoActivo(void);
void EmpleadoInactivo(void);
void EmpleadosActivosInactivos(){
    class Empleados reg;
    int opcion;
    system("cls");
    cout << "\t\tELIJA UNA CATEGORIA" <<endl;
    cout << "\t\t--------------" <<endl;
    cout << "\t\t1) Cambiar estado de empleado a Activo" <<endl;
    cout << "\t\t2) Cambiar estado de empleado a Inactivo" <<endl;
    cout << "\t\t0) Volver " << endl;
    cout << "\t\t--------------" <<endl;
    cout << "\t\tIngrese opcion:" << endl;
    cin >> opcion;
    system ("cls");
    switch(opcion){
    case 0:
       return ;
    break;
    case 1:
        EmpleadoActivo();
    break;
    case 2:
        EmpleadoInactivo();
    break;
    }
}

void EmpleadoActivo(){
    char documento[20];
    int pos;
    fflush(stdin);
    cout << "\t\tingrese el DNI del empleado que quiere dar de alta" << endl;
    cin.getline(documento,20);
    pos = buscarDNI(documento);
    if(pos==-1){cout << "\t\tNo se encontro el dni" << endl; return;}
    Empleados reg;
    pos = pos-1;
    reg.LeerDeDisco(pos);
    reg.setActivoInactivo("Activo");
    reg.EscribirPosicionEnDisco(pos);
}


void EmpleadoInactivo(){
    char documento[20];
    int pos;
    fflush(stdin);
    cout << "\t\tingrese el DNI del empleado que quiere dar de Baja" << endl;
    cin.getline(documento,20);
    pos = buscarDNI(documento);
    if(pos==-1){cout << "\t\tNo se encontro el dni" << endl; return;}
    Empleados reg;
    pos = pos-1;
    reg.LeerDeDisco(pos);
    reg.setActivoInactivo("Inactivo");
    reg.EscribirPosicionEnDisco(pos);
}


///FUNCIONES GENERALES

int buscarId(Empleados);
int comprobarCadNumericas(char *);
int comprobarNombresApellidos(char *);
int comprobarGenero(char *);
int comprobarTurno(char *);
int comprobarSueldo(char *);
int comprobarCuil(char *,char *);

const char *FILE_EMPLEADOS    = "empleados.dat";

bool Empleados::EscribirEnDisco(){
    FILE *p;
    p = fopen("empleados.dat","ab");
    if(p==NULL){return false;}
    fwrite(this,sizeof *this,1,p);
    fclose(p);
}
bool Empleados::LeerDeDisco(int posicion){
    FILE *p;
    p = fopen("empleados.dat","rb");
    if(p==NULL){ return false;}
    fseek(p,sizeof *this*posicion,0);
    bool leyo=fread(this,sizeof *this,1,p);
    fclose(p);
    return leyo;
}

void Empleados::EscribirPosicionEnDisco(int pos){
    FILE *p;
    p = fopen("empleados.dat","rb+");
    if(p==NULL){ return ;}
    fseek(p,sizeof *this*pos,0);
    fwrite(this,sizeof *this,1,p);
    fclose(p);
}

int comprobarCadNumericas(char *cadena){
    int i=0,tam;
    tam=strlen(cadena);
    if(tam==0){cout << "no aprete enter señor" << endl; system("pause"); return -1;}
    while(i<tam){
        if(isdigit(cadena[i])==0){
            cout << "esta cadena contiene algun caracter no numerico" << endl;
            system("pause");
            return -1;
        }
        i++;
    }
}
int comprobarNombresApellidos(char *cadena){
    int i=0,tam,onlySpace=0;
    tam=strlen(cadena);
    if(tam==0){ cout << "No aprete enter señor" << endl; system("pause"); return -1;}
    while(i<tam){
        if(isdigit(cadena[i])!=0){
            cout << "La cadena contiene un Numero" << endl;
            system("pause");
            cout << endl;
            return -1;
        }
        if(isspace(cadena[i])!=0){
            onlySpace++;
            if(tam==onlySpace){
                cout << "La cadena ingresada contiene solo Espacios" << endl;
                system("pause");
                cout << endl;
                return -1;
            }
        }
        if(isalnum(cadena[i])==0 && cadena[i]!=' '){
            cout << "La cadena ingresada contiene caracteres especiales " << endl;
            system("pause");
            cout << endl;
            return -1;
        }
        i++;
    }
    return 1;
}
int comprobarGenero(char *Genero){
    if(strcmpi(Genero,"f")!=0 && strcmpi(Genero,"m")!=0){
        cout << "Ha ingresado una letra incorrecta" << endl;
        system("pause");
        cout << endl;
        return -1;
    }
}
int comprobarTurno(char *Turno){
    if(strcmpi(Turno,"mañana")!=0 && strcmpi(Turno,"tarde")!=0 && strcmpi(Turno,"noche")!=0){
        cout << "Turno incorrecto" << endl;
        system("pause");
        cout << endl;
        return -1;
    }
}
int comprobarSueldo(char *Sueldo){
    int i=0,tam;
    tam = strlen(Sueldo);
    while(i<tam){
        if(isdigit(Sueldo[i])==0){
            cout << "Solo se admiten numeros" << endl;
            system("pause");
            cout << endl;
            return -1;
        }
        i++;
    }
}

int comprobarCuil(char *Cuil,char *Dni){
    if(strstr(Cuil,Dni)==NULL){
        cout << "El cuil no coincide con el DNI" << endl;
        system("pause");
        cout << endl;
        return -1;
    }
}

///CARGAR EMPLEADOS
int buscarId(Empleados reg){
    int aux;
    FILE *p;
    p = fopen(FILE_EMPLEADOS,"ab+");
    fseek(p,0,2);
    aux = (ftell(p)/sizeof reg)+1;
    fclose(p);
    return aux;
}


int buscarDNI(char *dni){
    Empleados buscar;
    int pos=0;
    while(buscar.LeerDeDisco(pos++)){
        if(strcmpi(dni,buscar.getNdoc())==0){
            cout << "numero de documento invalido" << endl;
            system("pause");
            return pos;
        }
    }
    return -1;
}


///LISTAR EMPLEADOS




///MODIFICAREMPLEADOS

#endif // CARGAREMPLEADO_H_INCLUDED


