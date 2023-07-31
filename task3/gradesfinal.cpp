#include<iostream>
#include<string>
#include<cctype> // necessary header files
using namespace std;


//its a function i made for range conversion 
char range(float grade) {              
    if (grade >= 4.5) return 'A';
    if (grade >= 3.5) return 'B';
    if (grade >= 2.5) return 'C';
    if (grade >= 1.5) return 'D';
    if (grade >= 0.5) return 'E';
    return 'F';
}

int main(){
    int x;
    cout << "Enter the total number of students: ";
    cin >> x;

    string studentNames[x];
    char finalGrades[x];

    for (int i = 0; i < x; i++)
    {
        cout << "\nEnter the name of student " << i + 1 << ": ";
        cin >> studentNames[i];

        char grade;
        cout << "Enter the final grade (A, B, C, D, E, or F) for " << studentNames[i] << ": ";
        cin >> grade;

        // it is used for uppercase conversion otherwise i have to write more switch cases
        finalGrades[i] = toupper(grade);
    }

    // i am initialising them 0 in order to calculate it later on my formula
    int numA = 0, numB = 0, numC = 0, numD = 0, numE = 0, numF = 0;

    for (int i = 0; i < x; i++)
    {
        switch (finalGrades[i])
        {
            case 'A':
                numA++;
                break;
            case 'B':
                numB++;
                break;
            case 'C':
                numC++;
                break;
            case 'D':
                numD++;
                break;
            case 'E':
                numE++;
                break;
            case 'F':
                numF++;
                break;
            default:
                cout << "Invalid grade entered for student " << studentNames[i] << ". Ignoring." << endl;
        }
    }

    // this is a formula i made to get average gradee
    float averageGrade = (5 * numA + 4 * numB + 3 * numC + 2 * numD + 1 * numE + 0 * numF) / static_cast<float>(x);

    // now since answer i get will be a float value so i need to round off
    int roundedGrade = static_cast<int>(averageGrade + 0.5);

    // it was not asked but i thought just to show user his output once again
    cout << "\nStudent list with final grades:\n";
    for (int i = 0; i < x; i++)
    {
        cout << studentNames[i] << ": " << finalGrades[i] << endl;
    }

    // output required
    cout << "\nDetails:\n";
    cout << "Average Grade: " << range(roundedGrade) << endl;
    cout << "Highest Grade: A" << endl;
    cout << "Lowest Grade: F" << endl;
    cout<<" \n do you want to see extra details : y/n";
    char y;
    cin>>y;
    if(y=='Y'||'y'){
    int num = numA;
        cout << "Number of students who scored the average grade: " << num << endl;
    }
    return 0;
}
