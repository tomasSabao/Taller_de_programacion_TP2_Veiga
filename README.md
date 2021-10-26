# Taller_de_programacion_TP2_Veiga

### Objetos creados

- Cola bloqueante
- Cola resultados
- Particionador
- Particion
- Input Manager

### Objeto Particion
Las particiones no almacenan datos precentes en el dataset, solamente tienen valores acerca de las "delimitaciones" sobre las que puede trabajar la particion (número de columnas del set de datos, comienzo y fin de la sección asignada al mismo, nombre del set de datos) y datos sobre la operación que se va a ejecutar en la misma (tipo de operación y columna que interesa procesar). El procesamiento de la partición queda delegada al thread encargado de trabajar sobre la misma. Posee un método procesar, que al llamarse, abre el archivo y calcula el resultado obtenido iterando por cada nmero que se quiere procesar, evitando tener que guardar datos de más. Con múltples threads, esto implica que puedo tener el mismo archivo abierto múltiples veces al mismo tiempo, pero, dado que se hacen solo operaciones de lectura, no generaria problemas.  

### Input Manager
Encargado de recibir las operaciones por entrada. Almacena los datos de la operación a ser ejecutada en su interior.

### Cola bloqueante
Cola protegida por mutex donde se encuentran las particiones que van a ser tomadas por los worker threads.  Objeto monitor

### Particionador
Objeto que se encarga de determinar que elementos tiene que tomar cada partición, y es el encargado de crearlas. 

### Cola resultados
Elemento compartido entre los distintos threads. Se almacenan los resultados en ella. Posee un mapa de operaciones en su interior, al que accede unicamente el thread encolador al momento de encolar una nueva operación. Es usado para una vez obtenidos los resultados de todas las operaciones, imprimir los resultados en el orden en el que fueron ejecutados.

### Caso de interés: Extracción de una cola vacia
Se hace uso de una condition variable asociada a la cola para que los hilos threads entren en un estado de espera al tratar de extraer de una cola que se encuentra vacia. El hilo encolador de operaciones toma el mutex asociado, encola y notifica a los demás threads para que reanuden la operación.

### Caso de interés: Finalización de la ejecución de los worker threads al finalizar la entrada de operaciones.
Se decidió que, dado que los threads extraen continuamente particiones para procesar de la cola, insertar particiones en la misma con una operación especial "end" que le indica al thread que debe finalizar su ejecución. El número de estas particiones que se encolan es igual al número de workers, y se realiza una vez que el thread de recepcion de operaciones determina que no se le van a ingresar más operaciones.

### Caso de interés: Mostrado de resultados
Como no se puede garantizar el tiempo de ejecución que se le va a asignar a cada thread, no puedo garantizar que las particiones van a ser procesadas en el orden en el cual son tomadas por los hilos (puede ser que un hilo tome y finalice el procesamiento de una operación que fue ingresada posteriormente a las operaciones procesadas por los otros hilos). Por eso se decidio almacenar el resultado de la operacion con un identificador único asociado a la misma, y procesar los resultados a imprimir una vez que la ejecución de todos los hilos haya finalizado.


### Diagrama de ejecucion del thread receptor de operaciones
![diagrama_clases](/Diagrama_ejecucion_receptor_thread.png) 

### Diagrama de ejecución de un thread worker
![diagrama_clases](/Diagrama_ejecucion_worker_thread.png) 



### Entregas realizadas en el SERCOM


