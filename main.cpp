#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Prototipo de funciones
void mostrarMenu();
void abrirCofre();
void luchar();
void descansar(int &vida);
void huir(int &vida);
void mostrarEstadoPersonaje(int life, string name, int attack, int gold);
void imprimirVida(int vida);

int main()
{
    // Semilla para números aleatorios
    srand(time(NULL));

    // Variables para el personaje
    int vida = 100;
    string nombre = "HEROE";
    int ataque = 20;
    int oroInicial = 0;

    // Condicion para salir del juego
    bool salir = false;

    // Presentación del juego
    cout << "Bienvenido al juego de aventuras!" << endl;
    mostrarEstadoPersonaje(vida, nombre, ataque, oroInicial);

    do
    {
        // Mostrar el menú de opciones
        mostrarMenu();

        // Leer la opción del usuario
        int opcion;
        cin >> opcion;

        // Procesar la opción seleccionada
        switch (opcion)
        {
        case 1:
            abrirCofre();
            break;
        case 2:
            luchar();
            break;
        case 3:
            huir(vida);
            break;
        case 4:
            descansar(vida);
            break;
        case 5:
            mostrarEstadoPersonaje(vida, nombre, ataque, oroInicial);
            break;
        case 6:
            salir = true;
            break;
        default:
            cout << "Opcion no valida. Por favor, elige una opcion del menu." << endl;
        }

    } while (salir == false);

    return 0;
}

void mostrarMenu()
{
    cout << "1. Abrir cofre." << endl;
    cout << "2. Luchar contra un monstruo." << endl;
    cout << "3. Huir." << endl;
    cout << "4. Descansar." << endl;
    cout << "5. Mostrar estado del personaje." << endl;
    cout << "6. Salir del juego." << endl;
}
void abrirCofre()
{

}
void luchar()
{

}
void descansar(int &vida)
{
    if(vida >= 100){
        cout << "Tu vida ya está al máximo. No necesitas descansar." << endl;
    }else{
        vida += 15;
        if(vida > 100){
            vida = 100;
        }
        cout << "Has descansado y recuperado vida." << endl;
        imprimirVida(vida);
    }
}
void huir(int &vida)
{
    int chance = rand() % 100; // Número aleatorio entre 0 y 99
    if(chance < 50){
        cout << "Has huido con éxito." << endl;
    }
    else{
        cout << "No has podido huir. El monstruo te ha alcanzado." << endl;
        int damage = rand() % 20 + 1;
        vida -= damage;
        if(vida < 0){
            vida = 0;
        }
        cout << "Has recibido " << damage << " de daño." << endl;
        imprimirVida(vida);
    }
}
void mostrarEstadoPersonaje(int life, string name, int attack, int gold)
{
    cout << "\n==== Estado del Personaje ====" << endl;
    cout << "Nombre: " << name << endl;
    imprimirVida(life);
    cout << "Ataque: " << attack << endl;
    cout << "Oro: " << gold << endl;
}

void imprimirVida(int vida){
    int interadorVida = vida / 5;
    string barraVida = "[";


    for(int i = 0; i < interadorVida; i++){
        barraVida += ":";
    } // [::::
    // [::::::::::] Vida: 100
    barraVida += "]";
    cout << barraVida << " Vida: " << vida << endl;
}