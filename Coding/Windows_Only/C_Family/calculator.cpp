#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Globally initialize variables
float numberOne, numberTwo;
string chosenOperator;

// Check if number input is valid
float numCheck(string prompt, float number)

{
    while(true)
    {

        // Define first float
        cout << prompt << endl;
        cin >> number;

        // If the input is invalid, reset the loop to redefine the variable
        if(cin.fail())
        {
            cout << "Invalid response, try again" << endl;
            cin.clear();
            cin.ignore(sizeof(number), '\n');
            continue;
        }

        // If input is valid, continue
        else
        {
            return number;
            break;
        }
    }
}

// Check if operator input is valid
string opCheck(string prompt, string chosenOperator)
{
    while(true)
    {

        // Define first float
        cout << prompt << endl;
        cin >> chosenOperator;

        // Move on if input is an operator
        if((chosenOperator == "+") || (chosenOperator == "-") || (chosenOperator == "x") || (chosenOperator == "/"))
        {
            return chosenOperator;
            break;
        }
        // Retry if input is invalid
        else
        {
            cout << "Invalid response, try again" << endl;
            cin.clear();
            cin.ignore(sizeof(chosenOperator), '\n');
            continue;
        }
            
    }
}

// Check if operator input is valid
bool doMath(string chosenOperator, float numberOne, float numberTwo)
{

    if(chosenOperator == "+")
    {
        cout << "\n" << numberOne << chosenOperator << numberTwo << "= " << (numberOne + numberTwo);
        return true;
    }
    else if(chosenOperator == "-")
    {
        cout << numberOne << chosenOperator << numberTwo << "= " << (numberOne - numberTwo);
        return true;
    }
    else if(chosenOperator == "x")
    {
        cout << numberOne << chosenOperator << numberTwo << "= " << (numberOne * numberTwo);
        return true;
    }
    else if(chosenOperator == "/")
    {
        cout << numberOne << chosenOperator << numberTwo << "= " << (numberOne / numberTwo);
        return true;
    }
    else
    {
        cout << "\nCritical error in line 102, quitting..." << endl;
        return false;
    }

}

int main()
{
    // Introduce program
    cout << "\nWELCOME TO THE BEST CPP CALCULATOR EVER!\n" << "Coded by Sargon\n" << endl;

    // Prompt for the first numbe
    numberOne = numCheck("First number: ", numberOne);

    // Prompt for operator
    chosenOperator = opCheck("Operator: ", chosenOperator);

    // Prompt for the second number
    numberTwo = numCheck("Second number: ", numberTwo);

    // Perform the calculation
    if (doMath(chosenOperator, numberOne, numberTwo))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}