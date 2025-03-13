# Practica 1

## Ejercicio 1 - Álgebra de Matrices

a 1

- pendiente hacer los “N” potencias de 2 -> 512 y 1024
Con un N = 1000
Ejecución Original : 0.120981 segundos
Ejecución sin Overhead : 85.241256 segundos

Estas funciones son necesarias cuando queremos decidir que tipo de recorrido en la matriz queremos realizar.
Cambiando el valor de la definición ORDEN FILAS u ORDEN COLUMNAS podremos alternar el recorrido.

Perdemos desde el código la decisión del recorrido a cambio de una rapidez en el orden de ejecución en la magnitud de un orden de diferencia.

a 2

Con un N = 1000
Multiplicación por FILAS = 14.603265 segundos
Multiplicación por COLUMNAS = 11.163515 segundos

La mejora es mínima en con esta cantidad de valores y comparada con la eliminación del Overhead.
Sin embargo, en este caso se aprovecha el principio de localidad debido a como se recorren las matrices.
El principio de localidad ... #TODO



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


