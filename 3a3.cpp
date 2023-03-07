#include <cstdlib>
#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <ostream>

using namespace std;
void title_screen();
void error_screen();
string whileloop (string value);
void title();
double calculation(double price, int enrollment, string required, string book);
int amountofbooks (int enrolled, string required, string book);
void exit_screen();

int main(){

    //title
    cout << "\x1b[2J"; //clearing terminal for VS code
    //system("cls");   //if your not using VS code, pls use this code
    string ISBN;
    std::string author, title_book, usedornot;
    string enrolled, prices_book, required;
    title_screen();
    cout << "\n\n\n ";
    cin.get();


//-----------------------------------------------------------------------------------------------------------------
    //input
    cout << "\x1b[2J"; //clearing terminal for VS code
    //system("cls");   //if your not using VS code, pls use this code

    std::cout << title << std::endl;
    cout << "\n";
    
    cout << "\nenter the ISBN (barcode) :   " << endl;
    cin >> ISBN; 

    cout << "\nenter the title of the book\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears previous inputs that may claug the input status allowing the next input to not be skipped
    std::getline(std::cin, title_book);

    cout << "\nenter the authors name" << endl;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::getline(std::cin, author);
    
    cout << "\nenter the number of students in your class" << endl;
    cin >> enrolled;
    enrolled = whileloop(enrolled);

    cout << "\nenter the prices of the book" << endl;
    cin >> prices_book;
    prices_book = whileloop(prices_book);                       //checks if the number is greater than 0

    cout << "\nenter 'new' if you want to book to be new, otherwise type something else" << endl;
    cin >> usedornot;

    cout << "\nenter 'required' if the book is required, otherwise type something else" << endl;
    cin >> required;

    cout << "please press 'ENTER' to continue";
    cin.get();

//-----------------------------------------------------------------------------------------------------------------
    //output
    cout << "\x1b[2J"; //clearing terminal for VS code
    //system("cls");   //if your not using VS code, pls use this code
    
    title();

    double newprice = atof(prices_book.c_str());
    int newenroll = atoi(enrolled.c_str());
    cout << "\t\t\t" << endl;
    cout << "-----------------YOUR INPUTS-------------" <<endl;
    cout << "barcode : " << ISBN << endl;
    cout << "author : " << author << endl;
    cout << "title : " << title_book << endl;
    cout << "# of students : " << enrolled << endl;
    cout << "is or is not required : " << required << endl;
    cout << "----------------------------------------" <<endl;

    cout << "the price is $" << fixed << setprecision(2) << calculation(newprice, newenroll, required, usedornot);
    cout << "\nthe number of books needed is : " << amountofbooks(newenroll, required, usedornot);

    // newprice, newenroll, required, usedornot


    cout << "\npress enter to continue ..........";
    cin.get();
    title();
    exit_screen();
    return 0;

}

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
    //output stuff

void title_screen() {
    const char* stuff= "                                            TITLE SCREEN                    \n"
                          "                        ***** < Miramar College Book Ordering System > *****   \n"
                          "                                       3/3/2023 Aaron Goff             \n"
                          "                                please press 'ENTER' to continue";
    cout<<stuff;
}  // just initializing a title and then printing it out

void exit_screen(){
    cout << "\x1b[2J"; //clearing terminal for VS code
    //system("cls");   //if your not using VS code, pls use this code
    cout<<"              thank you for your purchase and have a great rest of your day\n\n\n";
} //clears the terminal then prints out a statement

void title(){
    const char* titlescreen = "< Miramar College Book Ordering System >";
    cout << titlescreen;
}  //initializes a variable to then be printed out

void error_screen(){
    cout << "\x1b[2J"; //clearing terminal for VS code
    //system("cls");   //if your not using VS code, pls use this code
    cout << "sorry that is an invalid number, please type a number greater than 0\n\n\n\n";

} // an error screen that 
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
    //calculations and conversions stuff


int amountofbooks (int enrolled, string required, string book){
    double numBooks = enrolled;
    double factored = 1;
    if(book == "new"){
        if(required == "required"){
         factored = 1.0;   // Book is new and required
        }
        else{
         factored = 0.35;  // Book is new but not required
        }
    }
    else {
        if(required == "required"){
            factored = 0.6;  // Book is not new but is required
        }
        else  {
            factored = 0.1;  // Book is not new and is not required
        }
    }
    numBooks= enrolled * factored;
    return numBooks;
} //determines the amount of books depending on the inputed values

double calculation(double price, int enrollment, string required, string book) {
    double numBooks;
    double factored = 1;
    if (book == "new") {
        if (required == "required") {
            factored = 1.0;   // Book is new and required
        }
        else {
            factored = 0.35;  // Book is new but not required
        }
    }
    else {
        if (required == "required") {
            factored = 0.6;  // Book is not new but is required
        }
        else {
            factored = 0.1;  // Book is not new and is not required
        }
    }
    numBooks = enrollment * factored;
    double cost = numBooks * price;
    return cost;
}
// determines the price depending on the 


string whileloop (string value){
    if (std::atof(value.c_str()) <= 0){
        while ((std::atof(value.c_str()) <= 0)) {
        error_screen();
        cin >> value;
        }
    }
    return value;
}
// this while loop will check for the value to be greater than 0, if not shows the error screen and ask for another input value
