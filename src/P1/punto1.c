#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void iYii(int *RAM_total,int *RAM_Libre,int *RAM_disponible, int *SwapOcupada);
void iii(char *Cpu,char *Cores,char *Thread);

int main() {

    int RAM_total, RAM_libre, RAM_disponible,SwapOcupada;

    iYii(&RAM_total,&RAM_libre,&RAM_disponible,&SwapOcupada);
    printf("i.\nla Ram disponible es: %dMb\nla Ram libre es: %dMb\nla Ram total es: %dMb\n\nii.\nLa Swap Ocupada es: %dKb\n"
           ,RAM_disponible,RAM_libre,RAM_total,SwapOcupada);

    char *Cpu=malloc(64);
    char *Cores=malloc(2);
    char *Thread=malloc(2);

    iii(Cpu,Cores,Thread);
    printf("\niii.\nCpu%s \nCantidad de cores%s \nCantidad de Threads%s",Cpu,Cores,Thread);

    free(Cpu);
    free(Cores);
    free(Thread);

    return 0;
}

void deKbaMb(int *numero){
    *numero/=1024;
}

void iYii(int *RAM_total,int *RAM_Libre,int *RAM_disponible, int *SwapOcupada){
    int SwapLibre,SwapTotal,temp;
    char palabra[20];
    FILE *archivo1;

    archivo1 = fopen("/proc/meminfo", "r");
    while (fscanf(archivo1, "%s %d %*s", palabra, &temp)) {
        if (!strcmp(palabra, "MemTotal:")) {
            *RAM_total=temp;
        }
        else if(!strcmp(palabra, "MemFree:")) {
            *RAM_Libre=temp;
        }
        else if (!strcmp(palabra, "MemAvailable:")) {
            *RAM_disponible=temp;
        }
        else if (!strcmp(palabra, "SwapTotal:")) {
            SwapTotal=temp;
        }
        else if (!strcmp(palabra, "SwapFree:")) {
            SwapLibre=temp;
            break;
        }
    };
    fclose(archivo1);

    deKbaMb(RAM_disponible);
    deKbaMb(RAM_Libre);
    deKbaMb(RAM_total);
    *SwapOcupada=SwapTotal-SwapLibre;
}

void iii(char *Cpu,char *Cores,char *Thread){
    char temp[12];

    char palabra[64];
    FILE *archivo;
    archivo = fopen("/proc/cpuinfo", "r");
    do{
        int j=0;
        fgets(palabra,64,archivo);
        for(int i=0; i<12;i++){
            temp[i]='\000';
        }
        for(int i=0; palabra[i]!=':';i++){
            temp[i]=palabra[i];
            j=i;
        }
        if(!strcmp(temp,"model name\t")){
            while (palabra[j]!='\n'){
                *Cpu=palabra[j];
                j++;
                Cpu++;
            };
        }
        else if(!strcmp(temp,"siblings\t")){
            while (palabra[j]!='\n'){
                *Cores=palabra[j];
                j++;
                Cores++;
            };
        }
        else if(!strcmp(temp,"cpu cores\t")){
            while (palabra[j]!='\n'){
                *Thread=palabra[j];
                j++;
                Thread++;
            };
        }
        else if(!strcmp(temp,"flags\t\t")){
            break;
        }
    }while (!feof(archivo));
    fclose(archivo);
}
