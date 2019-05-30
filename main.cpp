#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
/** @file main.cpp
 *  @brief Main file and whole file (for now).
 *
 *  Longer description of file.
 *
 *  @author Shane Broxson
 *  @bug No known bugs.
 */
//Prototypes
int userInputMain;

int menu();

void produceItems();

void musicPlayer();

void moviePlayer();

void statistics();

void createAccount();


//Initiate Loop
int main() {
    std::cout << "Production Line Tracker\n";
    std::cout << "Press Associated Key to Continue:\n\n";
    menu();
    //Loop Parameters
    int loop = 0;
    while (loop != 1) {
        loop++;
        loop--;
        if (userInputMain == 1) {
            produceItems();
            menu();
        }

        if (userInputMain >= 7 || userInputMain < 1) {
            std::cout << "You have entered an invalid number, please try again.\n\n" << std::endl;
            menu();
        }
        if (userInputMain == 2) {
            musicPlayer();
            menu();
        }
        if (userInputMain == 3) {
            moviePlayer();
            menu();
        }
        if (userInputMain == 4) {
            statistics();
            menu();
        }
        if (userInputMain == 5) {
            createAccount();
            menu();
        }
        if (userInputMain == 6) {
            break;
        }
    }


}

int menu() {
    //Main menu
    std::cout << "1) Produce Items\n";
    std::cout << "2) Add Music Player\n";
    std::cout << "3) Add Movie Player\n";
    std::cout << "4) Display Production Statistics\n";
    std::cout << "5) Create new employee account\n";
    std::cout << "6) Exit\n";
    std::cin >> userInputMain;
    return 0;
}

void produceItems() {
    std::cout << "Produce Item Stub" << std::endl;
    //Start for Producing Items
    std::cout << "Enter the Manufacturer\n";
    std::string manufacturer;
    std::cin >> manufacturer;
    std::cout << "Enter the Product Name\n";
    std::string prodName;
    std::cin >> prodName;
    std::cout << "Enter the item type\n";
    std::cout << "1. Audio\n" <<
              "2. Visual\n" <<
              "3. AudioMobile\n" <<
              "4. VisualMobile\n";
    int itemTypeChoice;
    std::cin >> itemTypeChoice;
    std::string itemTypeCode;
    // Audio "MM", Visual "VI", AudioMobile "AM", or VisualMobile "VM".
    std::string choice;
    if (itemTypeChoice == 1) {
        choice = "MM";
    }
    if (itemTypeChoice == 2) {
        choice = "VI";
    }
    if (itemTypeChoice == 3) {
        choice = "AM";
    }
    if (itemTypeChoice == 4) {
        choice = "VM";
    }

    std::cout << "Enter the number of items that were produced\n";
    int numProduced;
    std::cin >> numProduced;
    //Printing serial numbers
    int y = 1;
    for (int i = numProduced; y <= numProduced; y++) {
        std::string manReduced = manufacturer.substr(0, 3);
        std::cout << "Production Number: " << y << " Serial Number: " << manReduced << choice << std::setfill('0')
                  << std::setw(5) << y << std::endl;
    }
}

void musicPlayer() {
    std::cout << "Music Player Stub" << std::endl;
}

void moviePlayer() {
    std::cout << "Movie Player Stub" << std::endl;
}

void statistics() {
    std::cout << "Statistics Stub" << std::endl;
}

void createAccount() {
    std::cout << "Create Employee Account Stub" << std::endl;
}

//
//
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <string>
//#include <vector>
//
////using namespace std;
//
//void test();
//
//void test2();
//
//void numberoflines();
//
//void storeArray();
//
//void storeArray();
//void sortArray();
//void printArray();
//
//int itemTypeChoice;
//std::string prodName;
//std::string manufacturer;
////std::string itemTypeCode;
//int numProduced;
//extern int count = 0;
//std::string line;
//
//std::string choice;
//int y = 1;
//
//int main() {
//    numberoflines();
//
//
//
//    std::cout << "Enter the Manufacturer\n";
//
//    std::cin >> manufacturer;
//    std::cout << "Enter the Product Name\n";
//
//    std::cin >> prodName;
//    std::cout << "Enter the item type\n";
//    std::cout << "1. Audio\n" <<
//              "2. Visual\n" <<
//              "3. AudioMobile\n" <<
//              "4. VisualMobile\n";
//
//    std::cin >> itemTypeChoice;
//
//    // Audio "MM", Visual "VI", AudioMobile "AM", or VisualMobile "VM".
//
//    if (itemTypeChoice == 1) {
//        choice = "MM";
//    }
//    std::cout << "Enter the number of items that were produced\n";
//
//    std::cin >> numProduced;
//    //Printing serial numbers
//
//    for (int i = numProduced; y <= numProduced; y++) {
//        std::string manReduced = manufacturer.substr(0, 3);
//        std::cout << "Production Number: " << y << " Serial Number: " << manReduced << choice << std::setfill('0')
//                  << std::setw(5) << y << std::endl;
//
//
//        std::ofstream myfile;
//        myfile.open ("example.txt",std::ios_base::app);
//        test2;
//        myfile << manReduced<<" "<<choice<<" "<<std::setfill('0')<<std::setw(5)<<y<<std::endl;
//        myfile.close();
//
//    }
//
//
//    numberoflines();
//}
//
////
//void test() {
//    std::string manReduced = manufacturer.substr(0, 3);
//    std::ifstream myfile("example.txt");
//    while(myfile>>manReduced>>choice>>y){
//        std::cout<<manReduced<<choice<<y<<std::endl;
//    }
//
//}
//
//void test2() {}
//
//
//
////count number of lines in text file
//void numberoflines(){
//    std::ifstream myfile("example.txt");
//    while(getline(myfile, line))
//        count++;
//    std::cout<<count<<std::endl;
//}
//
////move into array
//void storeArray(){
//
//
//}
////sort array
//void sortArray(){
//
//}
//
////Print Array
//void printArray(){
//
//}
//
////repeat for each instance of production
