#include "../../std_lib_facilities.h"

class Token {
    public:
        char kind;
        double value;
        Token(char ch)
            :kind(ch), value(0) {}
        Token(char ch, double val)
            :kind(ch), value(val) {}
};

Token get_token()    // read a token from cin
{
    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)
    switch (ch) {
        //not yet   case ';':    // for "print"
        //not yet   case 'q':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token('8', val);   // let '8' represent "a number"
    }
    case '\0':
        break;
    default:
        error("Bad token");
    }
}
double expression();
double term();

double primary()
{
    Token t = get_token();
    switch (t.kind) {
        case '(':
        {
            double d = expression();
            t = get_token();
            if (t.kind!=')') error("')' expected");
            return d;
        }
        case '8':
            return t.value;
        default:
            error("primary expected");
    }
}

vector<Token> tok;
double expression()
{
    double left = term();
    Token t = get_token();
    while (true) {
        switch(t.kind) {
            case '+':
                left += term();
                t = get_token();
                break;
            case '-':
                left -= term();
                t = get_token();
                break;
            default:
                return left;
        }
    }
}

double term()
{
    double left = primary();
    Token t = get_token();
    while (true) {
        switch (t.kind) {
            case '*':
                left *= primary();
                t = get_token();
                break;
            case '/':
            {
                double d = primary();
                if (d==0) error("divide by zero");
                left /= primary();
                t = get_token();
                break;
            }
            default:
                return left;
        }
    }
}

int main()
{
    try {
        while (cin)
            cout << "= " << expression() << '\n';
    }
    catch (exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "exception\n";
        return 2;
    }
}
