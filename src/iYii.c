#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deKbaMb(int *numero);

int main() {
    int RAM_total, RAM_libre, RAM_disponible,SwapOcupada;

        int SwapLibre,SwapTotal,temp;
        char *palabra;
        FILE *archivo1;
        archivo1 = fopen("/proc/meminfo", "r");
        while (fscanf(archivo1, "%s %d %*s", palabra, &temp)) {
            if (!strcmp(palabra, "MemTotal:")) {
                RAM_total=temp;
            }
            else if(!strcmp(palabra, "MemFree:")) {
                RAM_libre=temp;
            }
            else if (!strcmp(palabra, "MemAvailable:")) {
                RAM_disponible=temp;
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



        deKbaMb(&RAM_disponible);
        deKbaMb(&RAM_libre);
        deKbaMb(&RAM_total);
        SwapOcupada=SwapTotal-SwapLibre;

    printf("la Ram disponible es: %dMb\nla Ram libre es: %dMb\nla Ram total es: %dMb\nLa Swap Ocupada es: %dKb\n"
           ,RAM_disponible,RAM_libre,RAM_total,SwapOcupada);

};

void deKbaMb(int *numero){
    *numero/=1024;
};
