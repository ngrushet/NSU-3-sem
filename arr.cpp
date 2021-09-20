#include <iostream>
#include <fstream>
//#include <windows.h>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

    int f(ifstream& fin, char podposl[20]) {
/*
Входные параметры: *файл с последовательностью
*подпоследовательность

Выходные параметры: *Функция возвращает количество вхождений подпоследовательности при успешном завершении
*1, если файл не открылся
*/

    if (!fin.is_open()) return 1;

    char posl[13];
    int i = 0;
    int kol = 0;
    while (i != 13) {
        fin.get(posl[i]);
        i++;
    }
    int j = 0;
    
    while (podposl[j] != '\0') {
        j++;
    }
    int size_of_podposl = j;

    for (int i = 0; i < sizeof(posl) - size_of_podposl; i++) {      
        for (int j = 0; j <= size_of_podposl; j++) {
            if (!(posl[i + j] == podposl[j])) {
                // printf("j = %d, break\n", j);
                break;
            }
            if (j == sizeof(podposl[j])) {
                kol++;
                // printf("j = %d, kol++\n", j);
            }
        }
        // cout << "kol: " << kol <<endl;
    }
    return kol;
}

int main() {

    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);

    ifstream fin;
    fin.open("file.txt");
    char podposl[20]= "";
    cout << "Введите подпоследовательность: ";
    cin.getline(podposl, 20);

    int res = f(fin, podposl);

    if (res == 1) cout << "Файл не открылся";
    else cout << res << endl;

    fin.close();
    return 0;
}