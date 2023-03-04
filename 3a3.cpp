#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;
void title_screen();
void input_screen();
void output_screen();
void error_screen();

int main(){
    // title
    cout << "\x1b[2J"; //clearing terminal for VS code
    //system("cls");   //if your not using VS code, pls use this code

    title_screen(); 

    std::cout << titlescreen << std::endl;
    cin.get();


//-----------------------------------------------------------------------------------------------------------------
    //input
    std::cout << title << std::endl;

    cout << "please enter an integer";
    std::string str;
    cin >> str;                                             //takes in the input
    int val_str = std:: stoi(str);                          //converts the string into an int
    input_screen(val_str);

    while((val_str.at(0) < '0')|| (val_str.at(0) > '9'))   // checks the character at position 0
                                                           // reminder: numbers 1-8 shouldn't work for the while loop
    {
        numb_error_scrn(); 
        getline(cin, val_str);                             // error screen function call and user response
    }                                                      // End of while((val_str.at(0) < '0')|| (val_str.at(0) > '9'))

    value = atoi(val_str.data());                          // conversion of the string after error check
    cout << "The number entered is --> " << value << endl; // outputs the numeric value

    cout << "please press 'ENTER' to continue";
    cin.get();

//-----------------------------------------------------------------------------------------------------------------
    //output
    std::cout << title << std::endl;

    cout << "please press 'ENTER' to continue";
    cin.get();

}

void title_screen(){
    const char* titlescreen = 
"                                            TITLE SCREEN                    \n"
"                        ***** < Miramar College Book Ordering System > *****   \n"
"                                       3/3/2023 Aaron Goff             \n"
"                                please press 'ENTER' to continue";
}

void title(){
    const char* titlescreen = "< Miramar College Book Ordering System >";
}

void input_screen(int& input){
    cin >> input;
}

void output_screen(){

}
void error_screen(){
    cout << "\x1b[2J"; //clearing terminal for VS code
    //system("cls");   //if your not using VS code, pls use this code

    cout << "ERROR Screen - Enter a Numeric value:  ";

}
