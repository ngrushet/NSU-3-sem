#include <iostream>
using namespace std;
class String {
    private:
        int length;  // size of string, including '\0' symbol in the end
        char * byte;  // array of chars = bytes in string 

    public:
    // constructors:
        String() {  // constuctor of empty String
            length = 0;
            byte = (char *) malloc ((length) * sizeof(char));
        }

        String(char * array_of_chars) {  // constructs from "char*" type
            byte = array_of_chars; 
            length = 0;
            while (array_of_chars[length] !='\0') {
                length++;
            }       
        }
        // инициализацию полей можно вынести из тела конструктора - как?

        String(const String & orig) {  // constructor of copying
            if (&orig == this) {throw "Tried to create a String from not-initialized String";}
            length = orig.length;
            byte = orig.byte;
        }

    // destructor:
        ~String() { };

    // outputs: 
        void getInfo() {
            cout << "length: " << length << endl
                    << "bytes: '" << byte << "'\n";     
        }

    // operators
        String operator= (const String & other) {  // operator "="
            length = other.length;
            byte = other.byte;
            return * this;
        }

        operator const char *() const {  // type changing to char *
            return (const char *)(byte);
        }
        
        // for 4 mark:
        String operator+ (const String & second) const {  // concatination of Strings
            String result;
            result.length = length + (second.length);
            result.byte = (char *) realloc (result.byte, result.length);
            for (int i = 0; i < length; i++) {
                result.byte[i] = byte[i];
            }
            for (int i = length; i <= result.length; i++) {
                result.byte[i] = second.byte[i - length];
            }
            return result;
        }

        // String operator+= (const String & second) {  
        //     this = result;
        // }
};

int main() {
    char a[15] = "supernova_plus";

    cout << "\nEmpty:\n";
    String empty;
    empty.getInfo();

    cout << "\nFrom char *:\n";
    String copy_chars = String(a); 
        /* what happened, explain: 
            on the left side of '=', 'copy_chars' "String" object is already constructed empty. 
            On the right side, we see "String(a)", but this is just new object, constructed from "char*". 
            It could be like two-strings code:
                | String b;  // b.bytes = "smth"
                | String copy_chars = b; 
        */
    copy_chars.getInfo();

    cout << "\nFrom String:\n";
    String copy_String = String(copy_chars);
    copy_String.getInfo();

    cout << "\nFrom String using '=':\n";
    String new_str = copy_chars;
    new_str.getInfo();

    cout << "\nConcat:\n";
    String sum = copy_chars + copy_String;
    sum.getInfo();

    cout << "\nFrom String to const char *:\n";
    // char fromString[10] = const char * (String("Hellowold")); 
    return 0;    
}
