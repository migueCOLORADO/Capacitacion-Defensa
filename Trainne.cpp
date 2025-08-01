// Importar Librerias
#include <iostream>     // Libreria para entrada/salida
#include <vector>       // Libreria para usar vectores
using namespace std;    // Usar el espacio de nombres estandar (Evita usar std::)s

class DetectorSeries {      // Clase | Permite crear la matriz a analizar y las funciones que la analizan
private:
    int matriz[3][10] = {   // Crear matriz 3x10 con series matematicas (Esta se podra modificar para probar)
        // Nota | Inicialmente se creo introduciendo errores intencionales para mostrar el funciamiento del detector
        {1, 3, 6, 10, 15, 21, 7, 36, 45, 55},    // Error: 7 en lugar de 28
        {2, 3, 5, 7, 20, 13, 17, 19, 23, 29},    // Error: 20 en lugar de 11
        {0, 1, 1, 2, 3, 5, 8, 13, 19, 34}       // Error: 19 en lugar de 21
    };

public:
    int numeroTriangular(int posicion) {    // Funcion | Genera el n-ésimo número triangular
        return (posicion * (posicion + 1)) / 2;
    }
    
    bool esPrimo(int numero) {  // Funcion | Verifica si un número es primo
        if (numero < 2) return false;
        if (numero == 2) return true;
        if (numero % 2 == 0) return false;
        
        for (int i = 3; i * i <= numero; i += 2) {
            if (numero % i == 0) return false;
        }
        return true;
    }
    
    int nEsimoPrimo(int posicion) {     // Funcion | Genera el n-ésimo número primo
        int contador = 0;
        int numero = 2;
        
        while (contador < posicion) {
            if (esPrimo(numero)) {
                contador++;
                if (contador == posicion) return numero;
            }
            numero++;
        }
        return numero;
    }
    
    int fibonacci(int posicion) {   // Funcion | Genera el n-ésimo número de la secuencia Fibonacci
        if (posicion == 0) return 0;
        if (posicion == 1) return 1;
        
        int a = 0, b = 1, resultado = 0;
        for (int i = 2; i <= posicion; i++) {
            resultado = a + b;
            a = b;
            b = resultado;
        }
        return resultado;
    }
    
    
    int verificarFilaTriangular(int fila) {   // Funcion | Verifica la fila 1 (números triangulares)
        cout << "\n" << string(50, '=') << endl;
        cout << "\n| VERIFICACION | 🔍 Verificando Fila " << (fila + 1) << " | Números Triangulares" << endl;
        cout << string(50, '=') << endl;
        
        cout << "| INFO | Valores actuales => ";
        for (int j = 0; j < 10; j++) {
            cout << matriz[fila][j] << " ";
        }
        cout << endl;
        
        cout << "| INFO | Valores esperados => ";
        for (int j = 0; j < 10; j++) {
            int esperado = numeroTriangular(j + 1);
            cout << esperado << " ";
            
            if (matriz[fila][j] != esperado) {
                cout << "\n| ERROR | ❌ Error encontrado en la posición " << (j + 1) 
                    << ": encontrado " << matriz[fila][j] 
                    << ", esperado " << esperado << endl;
                return matriz[fila][j];
            }
        }
        cout << "\n| ¡ALERTA! | ✅ Fila correcta" << endl;
        return -1; // No hay error
    }
    
    int verificarFilaPrimos(int fila) {     // Funcion | Verifica la fila 2 (números primos)

        cout << "\n" << string(50, '=') << endl;
        cout << "\n| VERIFICACION | 🔍 Verificando Fila " << (fila + 1) << " | Números Primos:" << endl;
        cout << string(50, '=') << endl;

        cout << "| INFO | Valores actuales => ";
        for (int j = 0; j < 10; j++) {
            cout << matriz[fila][j] << " ";
        }
        cout << endl;
        
        cout << "| INFO | Valores esperados => ";
        for (int j = 0; j < 10; j++) {
            int esperado = nEsimoPrimo(j + 1);
            cout << esperado << " ";
            
            if (matriz[fila][j] != esperado) {
                cout << "\n| ERROR | ❌ Error encontrado en posición " << (j + 1) 
                    << ": encontrado " << matriz[fila][j] 
                    << ", esperado " << esperado << endl;
                return matriz[fila][j];
            }
        }
        cout << "\n| ¡ALERTA! | ✅ Fila correcta" << endl;
        return -1; // No hay error
    }
    
    int verificarFilaFibonacci(int fila) {  // Funcion | Verifica la fila 3 (secuencia Fibonacci)
        cout << "\n" << string(50, '=') << endl;
        cout << "\n| VERIFICACION | 🔍 Verificando Fila " << (fila + 1) << " | Secuencia Fibonacci:" << endl;
        cout << string(50, '=') << endl;

        cout << "| INFO | Valores actuales => ";
        for (int j = 0; j < 10; j++) {
            cout << matriz[fila][j] << " ";
        }
        cout << endl;
        
        cout << "| INFO | Valores esperados =>";
        for (int j = 0; j < 10; j++) {
            int esperado = fibonacci(j);
            cout << esperado << " ";
            
            if (matriz[fila][j] != esperado) {
                cout << "\n| ERROR | ❌ Error encontrado en posición " << (j + 1) 
                    << ": encontrado " << matriz[fila][j] 
                    << ", esperado " << esperado << endl;
                return matriz[fila][j];
            }
        }
        cout << "\n| ¡ALERTA! | ✅ Fila correcta" << endl;
        return -1; // No hay error
    }
    
    // Función principal para analizar toda la matriz
    void analizarMatriz() {
        cout << "\n" << string(50, '=') << endl;
        cout << "\n| ===🔐=== SISTEMA DE DETENCION DE CODIGOS ===🔐===  |" << endl;
        cout << string(50, '=') << endl;
        
        vector<int> errores;
        
        // Verificar cada fila
        int error1 = verificarFilaTriangular(0);
        int error2 = verificarFilaPrimos(1);
        int error3 = verificarFilaFibonacci(2);
        
        // Recopilar errores
        if (error1 != -1) errores.push_back(error1);
        if (error2 != -1) errores.push_back(error2);
        if (error3 != -1) errores.push_back(error3);
        
        // Mostrar resultado final
        cout << "\n" << string(60, '=') << endl;
        cout << "| ===🔐=== RESULTADO FINAL ===🔐===  |" << endl;
        cout << string(60, '=') << endl;
        
        if (errores.empty()) {
            cout << "| ¡ALERTA! | 🎉 ¡MATRIZ CORRECTA! No se encontraron errores." << endl;
        } else {
            cout << "| INFO | 🔓 CÓDIGO DESCIFRADO => ";
            for (size_t i = 0; i < errores.size(); i++) {
                cout << errores[i];
                if (i < errores.size() - 1) cout << "-";
            }
            cout << endl;
            
            cout << "\n| INFO | 📊 RESUMEN |" << endl;
            cout << "| INFO | Total de errores encontrados => " << errores.size() << endl;
            cout << "| INFO | Fila 1 (Triangulares) => " << (error1 != -1 ? "❌ Error" : "✅ Correcta") << endl;
            cout << "| INFO | Fila 2 (Primos) => " << (error2 != -1 ? "❌ Error" : "✅ Correcta") << endl;
            cout << "| INFO | Fila 3 (Fibonacci) => " << (error3 != -1 ? "❌ Error" : "✅ Correcta") << endl;
        }
    }
    
    void modificarMatriz(int fila, int columna, int nuevoValor) {   // Funcion | Modifica un valor en la matriz
        if (fila >= 0 && fila < 3 && columna >= 0 && columna < 10) {
            matriz[fila][columna] = nuevoValor;
            cout << "| ¡ALERTA! | ✏️ Matriz modificada => posición [" << fila << "][" << columna 
                << "] = " << nuevoValor << endl;
        }
    }
    
    void mostrarMatriz() {      // Funcion | Muestra la matriz actual
        cout << "\n| INFO | 📋 MATRIZ ACTUAL => " << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Fila " << (i + 1) << ": ";
            for (int j = 0; j < 10; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {    
    DetectorSeries detector; // Crear instancia del detector de series

    // Mensaje de Bienvenida
    cout << "\n| ===🔐=== SISTEMA DE DETENCION DE CODIGOS ===🔐===  |" << endl;
    cout << "| INFO | ¡Bienvenid@ a Trainne, una apuesta de MinDefensa para la Seguridad Informatica! \n| INFO | Este es un sistema para la detencion de codigos y vulnerabilidades de seguridad, \n| INFO | que te ayudara a analizar tu información y evitar su manipulación maliciosa.";
    cout << "\n| INFO | Antes de ir a la accion, para empezar dejanos darte una cucharada del Poder de esta apuesta; creenos, te sorprendera." << endl;
    
    cout << "\n| ¡ALERTA! | Cargando datos...⏳" << endl;  // Simula carga de datos
    cout << "\n| ¡ALERTA! | ✅ Datos cargados exitosamente" << endl;
    detector.mostrarMatriz();   // Mostrar la matriz inicial

    cout << "\n| ¡ALERTA! | Analizando datos...⏳" << endl;  // Simula carga de datos
    cout << "\n| ¡ALERTA! | ✅ Datos analizados exitosamente" << endl; 
    detector.analizarMatriz();      // Analizar la matriz
    
    // Opción para probar con diferentes valores

    
    cout << "\n" << string(50, '=') << endl;
    cout << "| ===🧪=== SISTEMA DE DETENCION DE CODIGOS | LAB DE PRUEBAS ===🧪===  |" << endl;
    cout << string(50, '=') << endl;
    cout << "| PREGUNTA | ¿Deseas modificar algún valor para probar? (Teclea s O Teclea n) => ";
    char respuesta;
    cin >> respuesta;
    
    if (respuesta == 's' || respuesta == 'S') {
        int fila, columna, valor;
        while (respuesta == 's' || respuesta == 'S') {
            cout << "\n| INFO | Introduce la fila (1-3): ";
            cin >> fila;
            cout << "| INFO | Introduce la columna (1-10): ";
            cin >> columna;
            cout << "| INFO | Introduce el nuevo valor: ";
            cin >> valor;
            
            detector.modificarMatriz(fila - 1, columna - 1, valor); // Ajustar a índice 0
            detector.mostrarMatriz(); // Mostrar matriz actualizada
            
            cout << "\n| PREGUNTA | ¿Deseas modificar otro valor? (Teclea s O Teclea n) => ";
            cin >> respuesta;
        }

        detector.analizarMatriz(); // Reanalizar la matriz después de modificaciones
    }
    
    cout << "\n| ¡ALERTA! | 🎯 Analisis Completado" << endl; 
    cout << "\n| ¡ALERTA! | Gracias por usar Trainne su Detector de confianza. ¡Vuelva Pronto!" << endl;
    return 0;
}
