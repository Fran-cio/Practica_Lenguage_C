## Respuestas
1.
	1. ¿Cómo utilizar typedef junto a struct? ¿Para qué sirve? Ejemplo.
	-El typedef permite genererar tipos de datos struc de manera implicita, facilita la 
	escritura de codigo y la comprension, ademas de volverlo menos engorroso.
	
	struct var
	{
   		int data1;
   		int data2;
   		char data3;
	};
	
	//para crear una variable de tipo var seria necesario
	
	struct var a;
	
	//en cambio.
	
	typedef struct
	{
   		int data1;
   		int data2;
   		char data3;
	}var;
	
	//solo seria necesario
	
	var a; //para crear la variable
	
	2. ¿Qué es packing and padding ?
	-Packing se le llama a la manera que tienen de organizarce los datos de distintos
	tipos y tamaños dentro de una structura. Basicamente, asignan packetes del tamaño
	del tipo mas grande y a este se le asigna un puntero de memoria. Esto lleva a que
	cuando guardamos variables de tamaño dispar, se produzca padding, es decir,
	queden packetes de memoria con espacio sin asignar.

2.
	1.Explique a que se debe los tamanios de cada una de las estructuras
	-Si sumamos la cantidad de bytes y como cada uno la empaqueta, tenemos:
	
	typedef struct {			typedef struct {
    		char a;				char a;
    		char b;//2.4				char b;//2.4
    		int  x;//4.4				int  x;//4.4
    		unsigned short int y;		 	unsigned short int y;
    		char c;//3.4				unsigned short int z;//4.4
    		unsigned short int z;//2.4		char c;
    		char d[3];//3.4			char d[3];//4.4
	} BaseData;				} ReorderData;
	
	typedef struct {
    		long unsigned int ll;//8.8
    		char a;
    		char b;
    		unsigned short int y;
    		int  x;//8.8
    		unsigned short int z;
    		unsigned short int w;
    		char c;
    		char d[3];//8.8
	} ExtendedData;
	
	(la syntax seria, "ocupado"."Empaquetado")
	Ahi vemos como hay mejores formas de ordenar el codigo donde se produce mas
	menos padding segun como declaramos las variables. 
	En el ultimo struct que no inclui aca pero es igual al BaseData, se le 
	agrega el atributo packed, de esta forma, cambiamos la asignacion de packetes
	y aprovechamos todo el espacio de asignado a la memoria (A costas de un
	acceso a la informacion tal vez menos eficiente)
	
	2.Explique por que la expresion que calcula  limit y limit_aux generan el mismo resutado 
	-Porque cuando yo tomo la direccion donde esta data y le sumo el sizeof de si mismo,
	resulta lo mismo que tomar el la direccion y hacerle un "+1" simbolizando que muevo
	el puntero una direccion de memoria del tamaño del tipo en cuestion (data).
	
	3.Explique los valores que se muestran en pantalla en cada iteracion del for
	-El primer valor impreso esta formateado como %02d, es decir, un decimal, con los valores
	a la derecha de la coma de ancho 0 y a la izquierda de ancho 2, este valor es la variable 
	i declarada como entero y que aumenta desde 0.
	El segundo valor impreso es a lo que apunta un puntero inicializado en el primer valor
	de la estructura data del tamaño de un char y que va moviendose de byte a byte imprimiendo
	el valor contenido, en el formato %02hhx, es decir, con los valores
	a la derecha de la coma de ancho 0 y a la izquierda de ancho 2, hh para pasar de char
	a entero imprimible y x para expresarlo en hexa sin signo.
	
	
 
	
	
