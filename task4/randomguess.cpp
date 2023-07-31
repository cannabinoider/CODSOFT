#include <iostream>
#include <ctime>          //necessary libraries
#include <cstdlib>

using namespace std;

int main() {
    int max, random, x, attempt;  //will be used in code ahead
    char p;

    do {
        attempt = 0;                                               // this was not asked in email but i decided to give in order to get a gamy touch

        cout << "Enter the maximum number from which to guess: "; //self explanatory
        cin >> max;

        srand(time(0));                                          //function that generates random numbers 
        random = rand() % max + 1;

        do {
            cout << "Enter your guess (between 1 and " << max << ") (dont enter  numbers above max as attempts will increase) \n: ";
            cin >> x;

            attempt++;

            if (x > random) {
                cout << "Guess lower!" << endl;
            } else if (x < random) {
                cout << "Guess higher!" << endl;
            }
             else {
                cout << "Congratulations! You guessed the number " << random << " correctly in "
                     << attempt << " attempts" << endl;
            }
        } while (x != random);

        cout << "Do you want to play again? (press Y for yes and N for no): \n";
        cin >> p;
        cout << endl;
    } while (p == 'Y' || p == 'y');     //incase capslock is on and user wanted to press yes

    return 0;
}
