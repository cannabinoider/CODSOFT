#include<iostream> // necessary header files 
#include<cmath>
using namespace std;

//function to know about operation
double calc (double x, double y, char z){
    double a = 0.0;
    if(z == '+'){
        a = x + y;
    }
    else if(z == '-'){
        a = x - y;
    }
    else if(z == '*'){
        a = x * y;
    }
    else if(z == '/'){
        a = x / y;
    }
    else {
        cout << "Not possible\n";
    }
    return a;
}

int main(){
    double x, y, z;
    char p, ch, ans;
    bool useLastAnswer = false;
    
    double lastAnswer = 0.0;
    
    cout << "This is a simple calculator performing + - * /\n";
    
    do {
        if (!useLastAnswer) {
            cout << "Enter first number: ";
            cin >> x;
            cout << "Choose operation: ";
            cin >> p;
            cout << "Enter second number: ";
            cin >> y;
            z = calc(x, y, p);
        }
        else {
            x = lastAnswer;
            cout << "Use last answer: " << x << endl;
            cout << "Choose operation: ";
            cin >> p;
            cout << "Enter second number: ";
            cin >> y;
            z = calc(x, y, p);
        }
        
        cout << "Your answer is " << z << endl;
        
        cout << "If you want to continue, press 'c'. To quit, press 'q': ";
        cin >> ch;
        
        if (ch == 'q'){
            cout << "End" << endl;
            break;
        }
        else if (ch != 'c') {
            cout << "Invalid input. End" << endl;
            break;
        }
        
        lastAnswer = z;
        
        cout << "Do you want to use the previously calculated answer (y/n)? ";
        cin >> ans;
        useLastAnswer = (ans == 'y' || ans == 'Y');
        
    } while (true);
    
    return 0;
}