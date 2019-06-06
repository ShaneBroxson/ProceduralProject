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
//////repeat for each instance of production
//#include <iostream>
//#include <fstream>
//#include <iomanip>
//#include <string>
//#include <algorithm>
//#include <vector>
///** @file main.cpp
// *  @brief Main file.
// *  Saves 3 text documents storing data used in program.
// *
// *  @author Shane Broxson
// *  @bug No Known Bugs.
//*/
////Prototypes
//int userInputMain;
//int menu();
//void produceItems();
//void addProduct();
//void statistics();
//void empAccount();
//void createAccount();
//void countlines();
//
//
//std::vector<std::string> productionLineManufacturer;
////parallel vector to store product name
//std::vector<std::string> productLineName;
////parallel vector to store product item type
//std::vector<std::string> productLineItemType;
////parallel vector to store production numer
//std::vector<std::string> productionNumber;
//void addToFile();
//void output_product_line(std::vector<std::string>, std::vector<std::string>,
//                         std::vector<std::string>);
//void addToProductLine(std::vector<std::string>&,std::vector<std::string>&,std::vector<std::string>&, int&);
//
//int main(){
//    //initialize for vector pass in
//    int productionNumber = 1;
////    std::string manufacturer;
////    std::string prodName;
////    std::string choice;
////    std::string prodNum;
//    countlines();
//
//
//    std::cout<<"Production Line Tracker\n";
//    std::cout<<"Press Associated Key to Continue:\n\n";
////    addToProductLine(productionLineManufacturer,productLineName,productLineItemType,productionNumber);
//    menu();
//    //Initiate endless loop with terminator
//    int loop = 0;
//    while (loop != 1){
//
//        loop++;
//        loop--;
//        if(userInputMain == 1){
//            countlines();
//            addToProductLine(productionLineManufacturer,productLineName,productLineItemType,productionNumber);
//            menu();
//        }
//        if(userInputMain == 2){
//            menu();
//        }
//        if(userInputMain == 3){
//            menu();
//        }
//        if(userInputMain == 4){
//            menu();
//        }
//        if(userInputMain >=7 || userInputMain < 1){
//            std::cout<<"You have entered an invalid number, please try again.\n\n"<<std::endl;
//            menu();
//        }
//        if(userInputMain == 5){
//            break;
//        }
//    }
//    //vector to store product line information
//    addToProductLine(productionLineManufacturer,productLineName,productLineItemType,productionNumber);
//    return 0;
//}
//
//int menu(){
//    //Menu selection prompt
//    std::cout<<"1) Produce Items\n";
//    std::cout<<"2) Add New Items\n";
//    std::cout<<"3) Production Statistics\n";
//    std::cout<<"4) Employee Account\n";
//    std::cout<<"5) Add Employee Account\n";
//    std::cin>>userInputMain;
//    return 0;
//}
//
//void produceItems(){
//    //storing for
//    std::cout<<"Enter the Manufacturer\n";
//    std::string manufacturer;
//    std::cin>>manufacturer;
//    std::cout<<"Enter the item type\n";
//    std::string prodName;
//    std::cin>>prodName;
//    std::cout<<"Enter the item type\n";
//    std::cout<<"1. Audio\n"<< "2. Visual\n"<<"3. AudioMobile\n"<<"4. VisualMobile\n";
//    int itemTypeChoice;
//    std::cin>>itemTypeChoice;
//    //Audio "MM", Visual "VI", AudioMobile "AM", or VisualMobile "VM".
//    std::string choice;
//    if (itemTypeChoice == 1) {
//        choice = "MM";
//    }
//    if (itemTypeChoice == 2) {
//        choice = "VI";
//    }
//    if (itemTypeChoice == 3) {
//        choice = "AM";
//    }
//    if (itemTypeChoice == 4) {
//        choice = "VM";
//    }
//
//    std::cout << "Enter the number of items that were produced\n";
//    int numProduced;
//    std::cin >> numProduced;
//    addToFile();
//}
//void addToProductLine(std::vector<std::string> &productLineManufacturer,
//                      std::vector<std::string> &productLineName, std::vector<std::string> &productLineItemType, int &productNum)
//{
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//    std::cout << "Adding a new product to the product line\n";
//
//    std::cout << "Enter the Manufacturer\n";
//    std::string manufacturer;
//    //std::cin>>manufacturer;
//    getline(std::cin, manufacturer);
//    // add manufacturer to the vector here
//    productLineManufacturer.push_back(manufacturer);
//
//    std::cout << "Enter the Product Name\n";
//    std::string prodName;
//    getline(std::cin, prodName);
//    // add prodName to the vector
//    productLineName.push_back(prodName);
//
//    std::cout << "Enter the item type\n";
//    std::cout << "1. Audio\n" <<
//              "2. Visual\n" <<
//              "3. AudioMobile\n" <<
//              "4. VisualMobile\n";
//    int itemTypeChoice;
//    std::cin >> itemTypeChoice;
//    std::string itemTypeCode;
//    switch (itemTypeChoice) {
//        case 1:
//            itemTypeCode = "MM";
//            break;
//        case 2:
//            itemTypeCode = "VI";
//            break;
//        case 3:
//            itemTypeCode = "AM";
//            break;
//        case 4:
//            itemTypeCode = "VM";
//            break;
//        default:
//            std::cout << "Not a valid selection\n";
//            std::cout << "Setting type to 'NA'\n";
//            itemTypeCode = "NA";
//            break;
//    }
//    // add itemTypeCode to the vector
//    productLineItemType.push_back(itemTypeCode);
//    std::cin.ignore();
//
//    productNum += 1;
//    output_product_line(productLineManufacturer, productLineName, productLineItemType);
//
//}
//void addToFile(){
//    for(int product_index = 0; product_index < productionLineManufacturer.size(); product_index++) {
//        std::ofstream myfile;
//        myfile.open("example.txt", std::ios_base::app);
//        std::string manReduced = "Hello";
//        myfile << productionLineManufacturer[product_index] << std::endl;
//        myfile.close();
//    }
//}
//void output_product_line(std::vector<std::string> productLineManufacturer,
//                         std::vector<std::string> productLineName, std::vector<std::string> productLineItemType) {
//    for (int product_index = 0; product_index < productLineManufacturer.size(); product_index++) {
//        std::cout << productLineManufacturer[product_index] << ",";
//        std::cout << productLineName[product_index] << ",";
//        std::cout << productLineItemType[product_index] << "\n";
//        std::ofstream myfile;
//        myfile.open ("example.csv",std::ios_base::app);
//        myfile <<product_index<<","<<productLineManufacturer[product_index]<<","<<productLineName[product_index]<<","<< productLineItemType[product_index]<<std::endl;
//        myfile.close();
//    }
//
//}
//void countlines(){
//    std::string line;
//    int count=0;
//    std::ifstream myfile("example.csv");
//    while(getline(myfile, line)) {
//        count++;
//    }
//    std::cout<<count<<std::endl;
//
////    std::cout<<"Enter words"<<std::endl;
////    std::string words="MM";
////    std::vector<std::string> stringholder;
////    while(std::cin>>words){
////        stringholder.push_back(words);
////    }
////    sort(stringholder.begin(),stringholder.end());
////    int vSize= stringholder.size();
////    if(vSize==0){
////        std::cout<<"No Words "<<std::endl;
////    }
////    int wordCount = 1;
////    words = stringholder[0];
////    for(int i=1; i<vSize;i++){
////        if(words!=stringholder[i]) {
////            std::cout << words << " Appeared " << wordCount << " times" << std::endl;
////            wordCount = 0;
////            words = stringholder[i];
////        }
////        wordCount++;
////    }
////    std::cout << words << " Appeared " << wordCount << " times" << std::endl;
//
//
//
//
//}
//
/////serial number counter
////void countcertainline(){
////    std::string line;
////    int count2=0;
////    std::ifstream myfile("example.csv");
////    if((myfile,line)='MM')
////}
/////total production number counter