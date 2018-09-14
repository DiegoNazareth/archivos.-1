#include <iostream>
#include <fstream>
#include <cstring>

void abrirAr(char*,char*);
bool buscar(char*,char*);

using namespace std;

int main(int argc, char*argv[]){
	int i;
	
	for(i=2;i<argc;i++){
		abrirAr(argv[i],argv[1]);
		cout<<endl<<endl<<endl;
	}
	system("PAUSE");
}

void abrirAr(char *NomArchivo,char*palabra){
	fstream archivo;
	char linea[100];
	bool b,b2=true;;
	archivo.open(NomArchivo,ios::in);
	if(!archivo)
		cout<<"No se pudo abrir el archivo"<<endl;
	archivo.clear();
	archivo.seekg(0);
	//archivo.getline(linea,100);
	while(!archivo.eof()){
		archivo.getline(linea,100);
		b=buscar(linea,palabra);
		
		if(b){
			if(b2){
				cout<<NomArchivo<<endl<<endl;
				b2=false;
			}
			cout<<linea<<endl;
		}
			
			
	}
}

bool buscar(char*linea,char*palabra){
	char tem[30];
	bool b,bandera;
	int i=0,x=0;
	while(linea[i]!='\0'){
		if(linea[i]!=' ')
			tem[x++]=linea[i];
		else{
			tem[x]='\0';
			x=0;
			b=true;
		}
		if(b)
			if(strcmp(tem,palabra)==0)
				return true;
			else 
				bandera=false;
		i++;
	}
	return bandera;
}
