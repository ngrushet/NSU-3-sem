#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

class MyString {

    private:
        // char * find_last (MyString one) {  // функция ищет конец строки
        //     return "go";
        // }

    public:
    
    char * data;
    int size;  // size is needed for serving
    char * last_symbol;  // pointer to the end of MyString
    // constructors:

        MyString() {  // пустая строка по умолчанию  
            size = 0;
            data = (char *) malloc ((size + 1) * sizeof(char));
            data[size+1] = '\0';
        }

        MyString(char * m_data) {  // создание строки из char *
            size = sizeof(m_data);
            data = (char *) malloc ((size + 1) * sizeof(char));
            for (int i = 0; i <= size; i++) {
                data[i] = m_data[i];
            }   
        }

        MyString(const MyString & orig) {  // копирование строки из строки MyString
            if (&orig == this) { 
                throw "Trying copying from a self (not initialized MyString)"; 
            }
            data = orig.data;
            size = orig.size;
        }

    // destructor:

        ~MyString() {}
    
    // operators: 

        MyString& operator= (const MyString &other) const{  // оператор присваивания "="
            data = other.data;
            size = other.size;
            return 0;
        }

        MyString operator+ (const MyString other) const {  // оператор конкатенации двух строк
            data = (char *) realloc (data, other.size);
            for (int i = 0; i < other.size + 1; i++) {
                data[i + size] = other.data[i];
            }
            size += other.size;
            return 0;
        }
    
};

int main() {
    MyString empty = MyString();

    char other[19] = "supernova";
    char smthing[19] = "something good";

    MyString smth = MyString(other);
    MyString smth2 = MyString(smth);
    cout <<"Empty:\n" << empty.data << 
        "\nNot empty:\n" << smth.data << 
        "\nNot empty2:\n" << smth2.data << endl;

    MyString smth3 = smth2;
    cout << "smt3 : " <<  smth3.data << endl;

    smth2 + smth;
    printf("her\n");
    cout << smth3.data << endl;
    return 0;
}
