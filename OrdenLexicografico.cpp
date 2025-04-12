#include <iostream>
#include <limits>
#include <fstream>

using namespace std;

#define MAX_TAM 22 // Definir el tamaño máximo del conjunto

// Función para generar las combinaciones en orden lexicográfico
void OrdenLexicografico(int n, int r);
int CapturaSegura(const char solicitud[]);
int main() {
    int n;
    do{
        n = CapturaSegura("De que tama\244o es el conjunto? [n > 0, n < 23]: ");
        if(n < 1 || n > MAX_TAM) {
            cout << "El tama\244o del conjunto debe estar entre 1 y 22." << endl;
        }
    }while(n < 1 || n > MAX_TAM); // Validar que n esté en el rango [1, 100]
    int r;

    do{
        r = CapturaSegura("Cuantos elementos quieres elegir? [0 <= r <= n]: ");
        if(r < 0 || r > n) {
            cout << "El n\243mero de elementos a elegir debe estar entre 0 y " << n << "." << endl;
        }
    }while(r < 0 || r > n); // Validar que r esté en el rango [0, n]

    OrdenLexicografico(n, r);

    system("pause");
    return 0;
}

void OrdenLexicografico(int n, int r) {
    // Validar entrada
    if (n >= 1 && 0 <= r && r <= n) {
        // Caso especial cuando r = 0
        if (r == 0) {
            cout << "No hay combinaciones posibles para r = 0." << endl;
            return; // Terminar la función
        }

        // Reservar memoria para el arreglo que almacenará la combinación actual
        int *s = new int[r];

        // Inicializar el arreglo con la primera combinación
        for (int i = 0; i < r; i++) {
            s[i] = i + 1;
        }

        // Abrir archivo CSV para escribir las combinaciones
        ofstream archivo("combinaciones_n" + to_string(n) + "_r" + to_string(r) + ".csv");
        if (!archivo.is_open()) {
            cout << "Error al abrir el archivo para escribir las combinaciones." << endl;
            delete[] s;
            return;
        }

        // Imprimir la primera combinación
        do {
            for (int i = 0; i < r; i++) {
                cout << s[i] << " ";
            }
            cout << endl;

            // Escribir la combinación en el archivo
            archivo << "{";
            for (int i = 0; i < r; i++) {
                archivo << s[i];
                if (i < r - 1) {
                    archivo << ", ";
                }
            }
            archivo << "}" << endl;

            // Generar la siguiente combinación
            int m = r - 1;
            while (m >= 0 && s[m] == n - r + m + 1) {
                m--;
            }

            if (m >= 0) {
                s[m]++;
                for (int j = m + 1; j < r; j++) {
                    s[j] = s[j - 1] + 1;
                }
            } else {
                break; // No hay más combinaciones posibles
            }
        } while (true);

        // Cerrar el archivo
        archivo.close();

        // Liberar la memoria reservada
        delete[] s;
    } else {
        // Mensaje de error si las entradas no son válidas
        cout << "Input inv\240lido. Verifique que 0 <= r <= n y n > 0." << endl; //Yo se que se esta cuidando esto desde el main, pero mejor prevenir que lamentar.
    }
}

int CapturaSegura(const char texto[]) {
    int n;
    cout << texto;
    cin >> n;
    while (cin.fail()) { // Verifica si la entrada es válida
        cin.clear(); // Limpia el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora la entrada inválida
        cout << "Entrada inv\240lida. Intente de nuevo: ";
        cin >> n;
    }
    return n;
}