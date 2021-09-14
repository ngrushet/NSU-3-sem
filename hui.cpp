#include <iostream>
#include <string>
using namespace std;

int main() {
    char * b = (char *) malloc (10*sizeof(char));
    scanf("%s", b);
    for (int i = 0; i <= 10; i++) {
        printf("%c", b[i]);
        if (b[i] == '\0') printf("Teaaah\n");
    }
    cout << endl;
    cout << b << endl;
    return 0;
}