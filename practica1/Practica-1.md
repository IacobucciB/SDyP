# Practica 1

## Ejercicio 1 - Álgebra de Matrices

### Inciso Ai

Con un N = 1024
Ejecución Original : Tiempo en segundos 55.154259
Ejecución sin Overhead : Tiempo en segundos 5.157322

Estas funciones son necesarias cuando queremos decidir que tipo de recorrido en la matriz queremos realizar.
Cambiando el valor de la definición ORDEN FILAS u ORDEN COLUMNAS podremos alternar el recorrido.

Perdemos desde el código la decisión del recorrido a cambio de una rapidez en el orden de ejecución en la magnitud de un orden de diferencia.

### Inciso Aii

Con un N = 1024
Multiplicación por FILAS = Tiempo en segundos 5.041677
Multiplicación por COLUMNAS = Tiempo en segundos 5.441509

La mejora es mínima en con esta cantidad de valores y comparada con la eliminación del Overhead.
Sin embargo, en este caso se aprovecha el principio de localidad debido a como se recorren las matrices.
El principio de localidad ... #TODO

### Inciso B

expMatrices1 : 512
Tiempo en segundos UN BUCLE 5.297311 
Tiempo en segundos CUATRO BUCLES 5.890926 


expMatrices2 : 512
Tiempo en segundos UN BUCLE 3.656211 
Tiempo en segundos TRES BUCLES 3.070120 

expMatrices3 : 512
Tiempo en segundos DOS BUCLES 4.408571 
Tiempo en segundos CUATRO BUCLES 4.396022 

expMatrices1 : 1024
Tiempo en segundos UN BUCLE 55.428518 
Tiempo en segundos CUATRO BUCLES 39.155487 

expMatrices2 : 1024
Tiempo en segundos UN BUCLE 21.990037 
Tiempo en segundos TRES BUCLES 22.626628 

expMatrices3 : 1024
Tiempo en segundos DOS BUCLES 33.799275 
Tiempo en segundos CUATRO BUCLES 33.895008 

### Inciso C

Multiplicacion de matrices AA valor N 1024

Con mismo orden
Tiempo en segundos 69.288260

Con diferente orden
Tiempo en segundos 12.529852

No se esta aprovechando la localidad en el primer caso

### Inciso D

La relacion entre el tamaño de la matriz y el bloque dependera en el caso mas teorico del tamaño de cache
En el caso ideal los bloques parciales tanto de la matriz resultado como de las matrices a multiplicar entra directamente en la cache
Esto producira menos fallos de cache ya que todos los datos entraran el la cache

En el mundo real, puede suceder que al traer los bloques de memoria me falte o sobre cache (supongamos una palabra)
En este caso entra en accion el principio de localidad, sera necesario traerse de memoria el bloque correcto y tener en cuenta el bloque contiguo que se va a tomar en la siguiente iteracion. 

### Inciso E

PENDIENTE

## Ejercicio 2 - Fibonacci

El metodo de calculo para fibonacci recursivo es varios ordenes de magnitud mas lento comparado al metodo iterativo en el caso de N = 50
Esto se debe al excesivo overhead que produce el metodo recursivo
Este metodo realiza una nueva llamada a funcion para cada calculo nuevo del siguiente numero en la serie


