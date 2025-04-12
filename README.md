# Generador de r-Combinaciones en Orden Lexicográfico

## Descripción
Este proyecto implementa un algoritmo eficiente para generar todas las r-combinaciones de un conjunto dado, asegurando que las combinaciones sean generadas en orden lexicográfico. Además, valida la entrada y realiza una verificación del conteo total de combinaciones utilizando la fórmula combinatoria C(n, r).

## Autor
David Armando Angulo Gil

## Requisitos del Sistema
Las específicaciones del sistema con las que se hicieron pruebas fueron las siguientes:
- **Procesador: Intel Core i7-1185G7**
- **Memoria RAM: 16GB**
- **Tarjeta Gráfica: Intel Iris XE Graphics**
- **Sistema Operativo: Windows 11 Pro**
- **Compilador:** g++

## Instrucciones de Compilación y Ejecución
1. Compilar el código utilizando el siguiente comando en la terminal:
   ```bash
   g++ -o OrdenLexicografico OrdenLexicografico.cpp
2. Ejecutar el programa con el siguiente comando:
   ```bash
   ./OrdenLexicografico

3. Proporcionar los valores de entrada n y r según se soliciten

## Explicación del Algoritmo
El algoritmo utiliza un enfoque iterativo para generar las r-combinaciones de un conjunto de tamaño n. Se asegura que las combinaciones sean generadas una a una sin redundancias, utilizando estructuras de datos y operaciones eficientes.
- **Inicialización**: Se crea un arreglo inicial con los primeros r elementos.
- **Generación de combinaciones**: Se modifica el arreglo para iterar por todas las posibles combinaciones en orden lexicográfico.
- **Almacenamiento**: Cada combinación generada es almacenada o exportada al archivo CSV.

## Orden Lexicográfico
El orden lexicográfico es un criterio de clasificación en el cual las combinaciones se generan siguiendo el mismo orden en que serían listadas en un diccionario. Por ejemplo, para el conjunto {1, 2, 3} y r=2, las combinaciones en orden lexicográfico serían:
- {1, 2}
- {1, 3}
- {2, 3}

El algoritmo asegura este orden ajustando los índices de los elementos de manera sistemática.

## Validación de Entrada
El programa realiza las siguientes validaciones para garantizar que los parámetros de entrada sean válidos:
- **n >= 1**: El tamaño del conjunto debe ser al menos 1.
- **r >= 0**: El número de elementos a elegir debe ser mayor o igual a 0.
- **r <= n**: No se pueden elegir más elementos que los que hay en el conjunto.

Si alguna de estas condiciones no se cumple, el programa muestra un mensaje de error y solicita una nueva entrada.

## Formato de Salida
El programa genera un archivo CSV con las combinaciones en orden lexicográfico. La estructura del archivo es la siguiente:
- Cada línea representa una combinación.
- Los elementos de cada combinación están separados por comas.
- **Ejemplo**:
   ```bash
       {1, 2}
       {1, 3}
       {2, 3}

## Verificación de C(n, r)
Para garantizar que todas las combinaciones se han generado correctamente, el programa calcula el total esperado de combinaciones utilizando la fórmula:
$$C(n, r) = \frac{n!}{r! \cdot (n - r)!}$$

El valor calculado se compara con el número real de combinaciones generadas, asegurando precisión en la implementación del algoritmo.
