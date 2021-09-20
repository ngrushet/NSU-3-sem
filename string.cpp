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
            //byte = (char *) malloc ((length) * sizeof(char));
            byte = new char[length];
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
        ~String() {
            //delete byte;
        };

    // outputs: 
        void getInfo() {
            cout << "length: " << length << endl
                    << "bytes: '" << byte << "'\n";     
        }

    // operators
        String operator = (const String & other) {  // operator "="
            length = other.length;
            byte = other.byte;
            return * this;
        }

        operator const char *() const {  // type changing to char *
            return (const char *)(byte);
        }
        
        // for 4 mark:
        String operator + (const String & second) const {  // concatination of Strings
            String result;
            result.length = length + (second.length);
            result.byte = new char[result.length]; 
            /*(char *) realloc (result.byte, result.length);*/
            for (int i = 0; i < length; i++) {
                result.byte[i] = byte[i];
            }
            for (int i = length; i <= result.length; i++) {
                result.byte[i] = second.byte[i - length];
            }
            return result;
        }

        String operator += (const String & second) {  // concatination using "+="
        *this = *this + second;
        return *this;
        }

        // for '5'mark:

        const char * operator[] (const int index) const {  // read byte with index = @index@
            switch (index>=0) {
                case 1: return (const char *)(this);
                default: throw "incorrect index"; 
            }
        }

        char& operator[] (const int index) {  // change byte with index = @index@
            switch (index>=0) {
                case 1: return this->byte[index];
                default: throw "incorrect index"; 
            }
        }
};

int main() {
    char a[15] = "supernova_plus";

    cout << "\nCreate Empty:\n";
    String empty;
    empty.getInfo(); 

    cout << "\nCreate From char *:\n";
    String copy_chars = String(a); 
        /* what happened, explain: 
            on the left side of '=', 'copy_chars' "String" object is already constructed empty. 
            On the right side, we see "String(a)", but this is just new object, constructed from "char*". 
            It could be like two-strings code:
                | String b;  // b.bytes = "smth"
                | String copy_chars = b; 
        */
    copy_chars.getInfo();

    cout << "\nCopy From String:\n";
    String copy_String = String(copy_chars);
    copy_String.getInfo();

    cout << "\nFrom String using '=':\n";
    String new_str = copy_chars;
    new_str.getInfo();

    cout << "\nFrom String to const char *:\n";
    cout << (const char *) new_str << endl;

    // for "4" mark:
    cout << "\nConcat using '+':\n";
    String sum = copy_chars + copy_String;
    sum.getInfo();

    cout << "\nConcat using '+=':\n";
    copy_chars += copy_String;
    copy_chars.getInfo();
    
    
    // cout << "\nBonus: multiplication of operators and constructors:"<< endl;
    // const char* fromString;
    // fromString = (const char *) (String("Hellowold")+String("+another_Hello")); 
    // cout << fromString << endl;
    
    // and for "5" mark:

    int n = 5;
    cout << "\nReading the String[" << n <<"] element:" << endl;
    copy_String.getInfo();
    cout << copy_String[n] << endl;
    
    n = 3;
    char change = 'B';
    cout << "\nChanging the String[" << n <<"] element:" << endl;
    copy_String.getInfo();
    copy_String[n] = change;
    cout << copy_String[n] << endl;
    copy_String.getInfo();
    
    return 0;
}
