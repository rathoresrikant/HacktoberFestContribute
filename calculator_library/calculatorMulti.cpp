#include <iostream>
#include <cmath>
/*#include <conio.h>
#include <stdio.h>
#include <cstdlib>*/
using namespace std;

int main()
{
    int n=0;
    int ex=0;
    double n1, n2, n3, n4, n5, n6;
    cout << "Bienvenido a la calculadora cientifica" << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "4. Divicion" << endl;
    cout << "5. Raiz" << endl;
    cout << "6. Seno" << endl;
    cout << "7. Coseno" << endl;
    cout << "8. Tangente" << endl;
    cout << "9. Cotangente" << endl;
    cout << "10. Secante" << endl;
    cout << "11. Cosecante" << endl;
    cout << "12. Enesima Potencia" << endl;
    cout << "13. Ecuacion Cuadratica" << endl;
    cout << "14. Area y perimetro de poligono" << endl;
    cout << "15. Volumen hexaedro regular" << endl;
    cout << "16. Ln" << endl;
    cout << "17. Secante" << endl;
    cout << "18. Secante" << endl;
    //Prueba numero valido
    cout << "Digite el numero de la funcion: ";
    cin >> n;
    if (n >18 || n<1){
    cout << "Error ingrese un numero valido" << endl;
    cin >> n;
    }
//ejecucion segun menu
    system("cls");
    switch (n){
    case 1:
    cout << "Eligio 1. suma" << endl;
    cout << "Ingrese primer numero" << endl;
    cin >> n1;
    cout << "Ingrese segundo numero" << endl;
    cin >> n2;
    n3=n1+n2;
    cout << "El resultado de la suma es: " << n3 << endl;
    break;

    case 2:
    cout << "Eligio 2. resta" << endl;
    cout << "Ingrese primer numero" << endl;
    cin >> n1;
    cout << "Ingrese segundo numero" << endl;
    cin >> n2;
    n3=n1-n2;
    cout << "El resultado de la resta es: " << n3 << endl;
    break;

    case 3:
    cout << "Eligio 3. multiplicacion" << endl;
    cout << "Ingrese primer numero" << endl;
    cin >> n1;
    cout << "Ingrese segundo numero" << endl;
    cin >> n2;
    n3=n1*n2;
    cout << "El resultado de la multiplicacion es: " << n3 << endl;
    break;

    case 4:
    cout << "Eligio 4. division" << endl;
    cout << "Ingrese primer numero" << endl;
    cin >> n1;
    cout << "Ingrese segundo numero" << endl;
    cin >> n2;
    while (n2 ==0){
    cout << "Error, Ingrese segundo numero" << endl;
    cin >> n2;
    }
    n3=n1/n2;
    cout << "El resultado de la division es: " << n3 << endl;
    break;

    case 5:
    cout << "Eligio 5. Raiz" << endl;
    cout << "Ingrese primer numero" << endl;
    cin >>n1;
    cout << "Ingrese indice raiz" << endl;
    cin >>n2;
    while (n1 ==0){
    cout << "Error, Ingrese de nuevo primer numero" << endl;
    cin >> n1;
    }
    n3=pow(n1, (1/n2));
    cout << "El resultado raiz es: " << n3 << endl;
    break;

    case 6:
    cout << "Eligio 6. Seno" << endl;
    cout << "Ingrese numero" << endl;
    cin >> n1;
    n3=sin(n1*(3.14159/180));
    cout << "El resultado es: " << n3 << endl;
    break;

    case 7:
    cout << "Eligio 7. Coseno" << endl;
    cout << "Ingrese numero" << endl;
    cin >> n1;
    n3=cos(n1*(3.14159/180));
    cout << "El resultado es: " << n3 << endl;
    break;

    case 8:
    cout << "Eligio 8. Tangente" << endl;
    cout << "Ingrese numero" << endl;
    cin >> n1;
    n3=tan(n1*(3.14159/180));
    cout << "El resultado es: " << n3 << endl;
    break;

    case 9:
    cout << "Eligio 9. Cotangente" << endl;
    cout << "Ingrese numero" << endl;
    cin >> n1;
    n3=1/(tan(n1*(3.14159/180)));
    cout << "El resultado es: " << n3 << endl;
    break;

    case 10:
    cout << "Eligio 10. Secante" << endl;
    cout << "Ingrese numero" << endl;
    cin >> n1;
    n3=1/cos(n1*(3.14159/180));
    cout << "El resultado es: " << n3 << endl;
    break;

    case 11:
    cout << "Eligio 11. Cosecante" << endl;
    cout << "Ingrese numero" << endl;
    cin >> n1;
    n3=1/sin(n1*(3.14159/180));
    cout << "El resultado es: " << n3 << endl;
    break;

    case 12:
    cout << "Eligio 12. Potencia" << endl;
    cout << "Ingrese primer numero" << endl;
    cin >>n1;
    cout << "Ingrese indice potencia" << endl;
    cin >>n2;
    while (n1 ==0){
    cout << "Error, Ingrese de nuevo primer numero" << endl;
    cin >> n1;
    }
    n3=pow(n1, (n2));
    cout << "El resultado potencia es: " << n3 << endl;
    break;

    case 13:
    cout << "Eligio funcion cuadratica" << endl;
    cout << "Ingrese a" << endl;
    cin >> n1;
    cout << "Ingrese b" << endl;
    cin >> n2;
    cout << "Ingrese c" << endl;
    cin >> n3;
    n4=(-n2+(sqrt(pow(n2, 2)-4*n1*n3)))/(2*n1);
    n5=(-n2-(sqrt(pow(n2, 2)-4*n1*n3)))/(2*n1);
    cout << "El resultado de la suma es: " << n4 << endl;
    cout << "El resultado de la suma es: " << n5 << endl;
    break;

    }
    /*cout << "Si desea cerrar la calculadora ingrese 1 sino pulse enter" << endl;
    cin >> ex;
    if (ex =1){
    return main();
    }
*/
    system("PAUSE");
}
