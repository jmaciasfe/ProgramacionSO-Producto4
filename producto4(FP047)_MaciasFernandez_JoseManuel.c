#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <xmllite.h>

void infoAdaptador();
void infoDNS();
void speedDNS();
void generarXML();



int main (){

    int opcion;
    char DNS;

    do {
        printf("\nSeleccione una opcion: \n");
        printf("\n1. Mostrar informacion adaptador de red.\n");
        printf("\n2. Mostrar informacion servidor DNS.\n");
        printf("\n3. Velocidad media y numero de saltos servidor DNS.\n");
        printf("\n4. Generar archivo XML\n");
        printf("\n5. Salir de la aplicacion.\n");
        printf("\n");
        printf("Opcion: ");
        scanf("\n%i", &opcion);

        switch (opcion){

            case 1: infoAdaptador();
                    break;
            case 2: infoDNS();
                    break;
            case 3: speedDNS();
                    break;
            case 4: generarXML();
                    break;
            case 5: printf("\nHas seleccionado salir de la aplicacion.\n");
                    printf("\n");

        }

    }while (opcion != 5);

    system ("pause");

    return 0;
}

void infoAdaptador(){

    char command [100];
    
    strcpy(command, "ipconfig");
    system(command);

}

void infoDNS(){

    char adaptador [50];
    char command [100];
    char aux;
    FILE *f;

    printf("\nDe que adaptador de los anteriores deseas ver la informacion DNS?\n");
    printf("\n");
    printf("Adaptador: ");
    scanf("%s", &adaptador);

    printf("Introduzca el siguiente comando: \n");
    printf("interface ip show dns \"%s\"\n", adaptador);
    printf("Escriba exit para salir despues\n");
    strcpy(command, "netsh");
    system(command);
    printf("Esta es la configuracion DNS del adaptador %s\n", adaptador);
    
    system("pause");

}

void speedDNS(){

    char DNS[30];
    char command[50];

    printf("Introduzca el DNS mostrado anteriormente: ");
    scanf("%s", &DNS);

    printf("\n//////////////////////////////////////////////////////\n");
    printf("\nMediendo velocidad media de respuesta del servidor DNS\n");
    printf("\n//////////////////////////////////////////////////////\n");

    sprintf(command, "ping %s", DNS);
    system(command);

    system ("pause");

    printf("\n//////////////////////////////////////////////////////\n");
    printf("\nMostrando informacion del numero de saltos del servidor DNS\n");
    printf("\n//////////////////////////////////////////////////////\n");
    sprintf(command, "tracert %s", DNS);
    system(command);

    system ("pause");

}

void generarXML(){
    
    printf ("funcion generar archivo XML");

    FILE *fp;

    fp = fopen ("archivo.xml", "w");
    if (fp = NULL){
        perror("Error al crear el archivo XML");
        fclose (fp);
        
    }

}