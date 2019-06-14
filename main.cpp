#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
/** @file main.cpp
 *  @brief Main file.
 *  Saves 3 text documents storing data used in program.
 *
 *  @author Shane Broxson
 *  @bug No Known Bugs.
*/
//Prototypes

int displayMenuAndGetChoice();

void
produceItems(std::vector<std::string> &, std::vector<std::string> &, std::vector<std::string> &, std::vector<int> &,
             std::vector<std::string> &, std::vector<std::string> &, std::vector<std::string> &,
             std::vector<std::string> &);

void addProduct();

void statistics();

void empAccount();

void createAccount();

void addToFile(std::vector<std::string> &, std::vector<std::string> &, std::vector<std::string> &, std::vector<int> &,
               std::vector<std::string> &, std::vector<std::string> &, std::vector<std::string> &,
               std::vector<std::string> &);

void output_product_line(std::vector<std::string>, std::vector<std::string>,
                         std::vector<std::string>);

//void save_product_line(std::vector<std::string>, std::vector<std::string>,
//                       std::vector<std::string>);
//
//void addToProductLine(std::vector<std::string> &, std::vector<std::string> &, std::vector<std::string> &, int &);

void add_sample_products(std::vector<std::string> &, std::vector<std::string> &,
                         std::vector<std::string> &);

void save_sample_products(std::vector<std::string> &, std::vector<std::string> &,
                          std::vector<std::string> &);


int main() {
    ///********* Vectors for ProductLine*********
//parallel vector to store product manufacturer
    std::vector<std::string> productLineManufacturers;
//parallel vector to store product name
    std::vector<std::string> productLineNames;
//parallel vector to store product item type
    std::vector<std::string> productLineItemTypes;

    ///********* Vectors for Production*********
//parallel vector to store product manufacturer
    std::vector<std::string> productionManufacturers;
//parallel vector to store product name
    std::vector<std::string> productionNames;
//parallel vector to store product item type
    std::vector<std::string> productionItemTypes;
//parallel vector to store the serial numbers
    std::vector<std::string> serialNumbers;
//parallel vector to store production number
    std::vector<int> productionNumbers;

    //initialize main count
    //int count = 0;
    //Starts menu
    int userMenuChoice;

    //Initiate endless loop with terminator
    bool continueProgram = true;
    while (continueProgram) {
        userMenuChoice = displayMenuAndGetChoice();
        if (userMenuChoice == 1) {
            produceItems(productLineManufacturers, productLineNames, productLineItemTypes, productionNumbers,
                         productionManufacturers, productionNames, productionItemTypes, serialNumbers);
            addToFile(productLineManufacturers, productLineNames, productLineItemTypes, productionNumbers,
                      productionManufacturers, productionNames, productionItemTypes, serialNumbers);
            //addToProductLine(productionLineManufacturers, productLineNames, productLineItemTypes, productionNumbers);
        } else if (userMenuChoice == 2) {
//            add_sample_products(productLineManufacturers,
//                                productLineNames, productLineItemTypes);
//            save_sample_products(productLineManufacturers,
//                                 productLineNames, productLineItemTypes);
            addProduct();
        } else if (userMenuChoice == 3) {
            //count;
            statistics();
        } else if (userMenuChoice == 4) {
            empAccount();
        } else if (userMenuChoice == 5) {
            createAccount();
        } else if (userMenuChoice == 6) {
            continueProgram = false;
        } else {
            std::cout << "You have entered an invalid number, please try again.\n\n" << std::endl;
        }
    }
    //vector to store product line information
    //addToProductLine(productionLineManufacturer,productLineName,productLineItemType,productionNumber);
    return 0;
}

int displayMenuAndGetChoice() {
    //Menu selection prompt
    std::cout << "1) Produce Items\n";
    std::cout << "2) Add New Items\n";
    std::cout << "3) Production Statistics\n";
    std::cout << "4) Employee Account\n";
    std::cout << "5) Add Employee Account\n";
    std::cout << "6) Exit Program\n";
    int userMenuChoice;
    std::cin >> userMenuChoice;
    return userMenuChoice;
}

void produceItems(std::vector<std::string> &productLineManufacturers,
                  std::vector<std::string> &productLineNames, std::vector<std::string> &productLineItemTypes,
                  std::vector<int> &productNumbers, std::vector<std::string> &productionManufacturers,
                  std::vector<std::string> &productionNames, std::vector<std::string> &productionItemTypes,
                  std::vector<std::string> &serialNumbers) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //count lines
    std::string line;
    int count = 0;
    std::ifstream catalog("Catalog.csv");
//    while (getline(catalog, line)) {
//        count++;
//    }
//    std::cout << count << std::endl;

    //file to string and string to vector
    //catalog
    std::string manufacturer;
    std::string prodName;
    std::string itemTypeCode;
    while (getline(catalog, line)) {
        std::stringstream ss(line);
        getline(ss, manufacturer, ',');
        getline(ss, prodName, ',');
        getline(ss, itemTypeCode);
        productLineManufacturers.push_back(manufacturer);
        productLineNames.push_back(prodName);
        productLineItemTypes.push_back(itemTypeCode);

    }
    catalog.close();

    //file to string and string to vector
    //production list
    std::ifstream productionList("production_list.csv");
    while (getline(productionList, line)) {
        std::stringstream ss(line);
        getline(ss, manufacturer, ',');
        getline(ss, prodName, ',');
        getline(ss, itemTypeCode, ',');
        productionManufacturers.push_back(manufacturer);
        productionNames.push_back(prodName);
        productionItemTypes.push_back(itemTypeCode);

        std::cout << manufacturer << std::endl;
    }
    productionList.close();


//    while (catalog >> manufacturer >> prodName >> itemTypeCode) {
//        std::cout << manufacturer << prodName << itemTypeCode;
//        productLineManufacturers.push_back(manufacturer);
//        productLineNames.push_back(prodName);
//        productLineItemTypes.push_back(itemTypeCode);
//    }
///    for (int product_index = 0;product_index<count;product_index++){
///        std::cout <<
///    }
//    //output catalog
//    for (int product_index = 0; product_index < productLineManufacturers.size(); product_index++) {
//        std::cout << product_index + 1 << ". ";
//        std::cout << productLineManufacturers[product_index] << " ";
//        std::cout << productLineNames[product_index] << " ";
//        std::cout << productLineItemTypes[product_index] << "\n";
//    }
//    //choice for production
//    std::cout << "Choose a Product to Produce:" << std::endl;
//    int userChoiceForProduct;
//    std::cin >> userChoiceForProduct;
//
//    //output for number to produce
//    std::cout << "How many would you like to Produce?:" << std::endl;
//    int serialNumInput;
//    std::cin >> serialNumInput;


//    for (serialNumInput; y <= serialNumInput; y++) {
//        std::string manReduced = productionManufacturers[serialNumInput].substr(0, 3);
//        std::cout << "Production Number: " << y << " Serial Number: " << productionManufacturers[userChoiceForProduct]
//                  << productLineItemTypes[userChoiceForProduct] << std::setfill('0')
//                  << std::setw(5) << y << std::endl;
//    }


}

void saveCatalog() {

}

void addProduct() {}

void statistics() {}

void empAccount() {}

void createAccount() {}

void addToFile(std::vector<std::string> &productLineManufacturers,
               std::vector<std::string> &productLineNames, std::vector<std::string> &productLineItemTypes,
               std::vector<int> &productNumbers, std::vector<std::string> &productionManufacturers,
               std::vector<std::string> &productionNames, std::vector<std::string> &productionItemTypes,
               std::vector<std::string> &serialNumbers) {

    //output catalog
    for (int product_index = 0; product_index < productLineManufacturers.size(); product_index++) {
        std::cout << product_index + 1 << ". ";
        std::cout << productLineManufacturers[product_index] << " ";
        std::cout << productLineNames[product_index] << " ";
        std::cout << productLineItemTypes[product_index] << "\n";
    }
    //choice for production
    std::cout << "Choose a Product to Produce:" << std::endl;
    int userChoiceForProduct;
    std::cin >> userChoiceForProduct;

    //output for number to produce
    std::cout << "How many would you like to Produce?:" << std::endl;
    int serialNumInput;
    std::cin >> serialNumInput;
///         CHECK !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //variable count for serials
//    std::vector<std::string>::iterator it;
//    int serial = 0;
//    int serialCount = 0;
//    for(serialCount; serialCount<productLineManufacturers.size();serialCount++){
//        it = find (productionItemTypes.begin(),productionItemTypes.end(), productionItemTypes[userChoiceForProduct]);
//        if(it != productionItemTypes.end()){
//            serial++;
//        }
//        else{
//            std::cout<<"Element not found"<<std::endl;
//        }
//    }
//    std::cout<<serial<<std::endl;
/// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

/// fix this
    int countItemType = 0;
    std::string itemType = productLineItemTypes[userChoiceForProduct];
    std::cout<<productionItemTypes.size()<<std::endl;
    for (int i = 0; i < productionItemTypes.size(); i++) {
        if (itemType == productionItemTypes[i]) {
            countItemType++;
        }
        std::cout<<productionItemTypes[i]<<std::endl;
    }
    std::cout << itemType << " appeared " << countItemType << " times" << std::endl;
/// *************

    //create serial num
    int y = 1;
    while (y < serialNumInput) {
        std::ofstream productionList;
        productionList.open("production_list.csv", std::ios_base::app);
        std::string manReduced = productLineManufacturers[userChoiceForProduct].substr(0, 3);
        std::string serialNumber;
        productionList << y << "," << productLineManufacturers[userChoiceForProduct]
                       << "," << productLineItemTypes[userChoiceForProduct] << "," << y << std::endl;
        std::cout << y << "," << productLineManufacturers[userChoiceForProduct]
                  << "," << productLineItemTypes[userChoiceForProduct] << "," << y << std::endl;
        y++;
    }
}

