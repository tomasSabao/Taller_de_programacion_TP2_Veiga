# Taller_de_programacion_TP2_Veiga

### Objetos creados

- Cola bloqueante
- Cola resultados
- Particionador
- Particion
- Input Manager

### Objeto Particion
Las particiones guardan los datos sobre las operaciones que van a ejecutar. En el momento en que el hilo receptor de operaciones las guarda en la cola bloqueante, no hay datos del dataset en su interior. Es cuando el worker thread toma la partición para procesarla que los números del dataset son añadidos a la partición, tras lo cual el resultado se procesa en función de la operacion especificada.

### Input Manager
Encargado de recibir las operaciones por entrada

### Cola bloqueante
Cola protegida por mutex donde se encuentraan las particiones que van a ser tomadas por los worker threads. 

### Particionador
Objeto que se encarga de determinar que elementos tiene que tomar cada partición, y es el encargado de crearlas. 

### Cola resultados
Elemento compartido entre los distintos threads. Se almacenan los resultados en ella. Posee un mapa de operaciones en su interior, al que accede unicamente el thread encolador al momento de encolar una nueva operación. Es usado para una vez obtenidos los resultados de todas las operaciones, imprimir los resultados en el orden en el que fueron ejecutados.

### Diagrama de ejecucion de el thread receptor de operaciones
![diagrama_clases](/Diagrama_ejecucion_receptor_thread.png) 

### Diagrama de ejecución de un thread worker
![diagrama_clases](/Diagrama_ejecucion_worker_thread.png) 

### Diagrama del uso de objetos en función de los threads

###

