/**

23/10/17
Steven O' Brien
Operational Amplifier Circuits

Exercise 8

*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdio>
#include <windows.h>

using namespace std;

using namespace std;

    char displayMenu(void);
    void invVals (void);
    void noninvVals (void);

  //Function declarations
    void inverting(double *avPtr, double rf, double rin, double *voutPtr, double vin);
    void noninverting(double *avPtr, double r2, double r1, double *voutPtr, double vin);



int main(void)
{
    //Displays Programme Title
    cout << "Operational Amplifier Circuits" << endl;

    //Variable declarations
    char choice;

    //Do While loop to display menu driven program
    do
    {
        choice = displayMenu();

        switch (choice)
        {
            case 'a':       invVals ();
                            break;

            case 'b':       noninvVals ();
                            break;

            case 'q':       system("cls");
                            cout <<"Goodbye...\n";
                            break;

            default:	    cout <<"\nInvalid input, press any key to continue..." ;
                            fflush(stdin);
                            getchar();
                            break;
        }
    }
    while (choice != 'q' );

    return 0;
}


char displayMenu(void)
{
    //Variable declarations
    char choice;
    // turns previous screen off
    system("cls");

    // user enters which command they want to use
    cout <<"Operational Amplifier Circuits" ;
    cout <<"\n\nPress 'a' for an inverting amplifier ...";
    cout <<"\nPress 'b' for a non-inverting amplifier ...";
    cout <<"\nPress 'q' to quit ...\n\nChoice: ";

    fflush(stdin);
    choice = getchar();
    return choice;
}

void invVals ()
{
    // turns previous screen off
    system("cls");

    double vcc = -1, vee = 1, vin, rin = 0, rf = 0, av, vout;
    double *avPtr = &av, *voutPtr = &vout;

   // Displays Programme Title
    cout << "Inverting Amplifier Circuit\n\n" ;

    // Ensures positive values for rin
    while (rin <= 0)
    {
        cout << "\nRin :\t";
        cin >> rin;
    }
    // Ensures positive values for rf
    while (rf <= 0)
    {
        cout << "\nRf :\t";
        cin >> rf;
    }
    // Ensures positive values for vcc
    while (vcc <= 0)
    {
        cout << "\nVcc :\t";
        cin >> vcc;
    }
    // Ensures positive values for vee
    while (vee >= 0)
    {
        cout << "\nVee :\t";
        cin >> vee;
    }
    //user input for vin
    cout << "\nVin :";
    cin >> vin;

    //calling sub function inverting
    inverting (avPtr, rf, rin, voutPtr, vin);
    // displaying values for gain and vout
    cout << "\nAv =\t" << av << "\n\nVout =\t" << vout;

    /** if vout is outside of vcc or vcc, display correct vcc or vee value */
    if(vout >= vcc || vout <= vee)
    {
        if(vin <= 0)
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << vcc ;
        }
        else
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << vee ;
        }
    }
    //allows user get back to main screen
    cout << "\n\nPress enter to return to the main menu..." ;
    fflush(stdin);
    getchar();

    return ;
}
//Sub function to calculate gain and vout
void inverting(double *avPtr, double rf, double rin, double *voutPtr, double vin)
{
    *avPtr = -(rf/rin);

    *voutPtr = *avPtr * vin;

    return ;
}
 // Sub function for non inverting amplifier
void noninvVals ()
{
    // turns previous screen off
    system("cls");
   //Variable declarations
    double vcc = -1, vee = 1, vin, r1 = 0, r2 = 0, av, vout;
    double *avPtr = &av, *voutPtr = &vout;

    //Displays Function Title
    cout << "Non - Inverting Amplifier Circuit\n\n" ;

    // Ensuring positive values for r1 in a while loop
    while (r1 <= 0)
    {
        cout << "\nR1 :\t";
        cin >> r1;
    }
   // Ensuring positive values for r2 in a while loop
    while (r2 <= 0)
    {
        cout << "\nR2 :\t";
        cin >> r2;
    }
    // Ensuring positive values for vcc in a while loop
    while (vcc <= 0)
    {
        cout << "\nVcc :\t";
        cin >> vcc;
    }
    // Ensuring neg values for vee in a while loop
    while (vee >= 0)
    {
        cout << "\nVee :\t";
        cin >> vee;
    }
    //user input for vin
    cout << "\nVin :\t";
    cin >> vin;

    //calling subfunction noninverting
    noninverting (avPtr, r2, r1, voutPtr, vin);

    // displaying values for gain and vout
    cout << "\nAv =\t" << av << "\n\nVout =\t" << vout ;

    /** if vout is outside of vcc or vcc, display correct vcc or vee value */
    if(vout >= vcc || vout <= vee)
    {
        if(vin >= 0)
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << vcc ;
        }
        else
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << vee ;
        }
    }

    // Allows user to get back to main screen
    cout << "\n\nPress enter to return to the main menu..." ;
    fflush(stdin);
    getchar();

    return ;
}
// sub function to calculate gain and vout for non inverting amplifier
void noninverting(double *avPtr, double r2, double r1, double *voutPtr, double vin)
{
    *avPtr = 1 + (r2 / r1);

    *voutPtr = *avPtr * vin;

    return ;
}
