#include <stdio.h>
#include <string.h>

int main() {
    char temp[12],Cpu[40],Cores[40],Thread[40];

    for(int i=0; i<40;i++){
        Cpu[i]='\000';
        Cores[i]='\000';
        Thread[i]='\000';
    }
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
             int i=0;
             while (palabra[j]!='\n'){
                 Cpu[i]=palabra[j];
                 i++;
                 j++;
             };
         }
         else if(!strcmp(temp,"siblings\t")){
             int i=0;
             while (palabra[j]!='\n'){
                 Cores[i]=palabra[j];
                 i++;
                 j++;
             };
         }
         else if(!strcmp(temp,"cpu cores\t")){
             int i=0;
             while (palabra[j]!='\n'){
                 Thread[i]=palabra[j];
                 i++;
                 j++;
             };
         }
         else if(!strcmp(temp,"flags\t\t")){
             break;
         }
     }while (!feof(archivo));
     fclose(archivo);

    printf("Cpu%s \n Cantidad de cores%s \n Cantidad de Threads%s",Cpu,Cores,Thread);

    return 0;
}

