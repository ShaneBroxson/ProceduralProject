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

void resetAndRepopulateVectors(std::vector<std::string> &, std::vector<std::string> &, std::vector<std::string> &,
                               std::vector<int> &,
                               std::vector<std::string> &, std::vector<std::string> &, std::vector<std::string> &,
                               std::vector<std::string> &);

void addNewItems(std::vector<std::string> &, std::vector<std::string> &, std::vector<std::string> &);

void sortProductionList(std::vector<int> &, std::vector<std::string> &, std::vector<std::string> &,
                        std::vector<std::string> &, std::vector<std::string> &);

void produceStatistics(std::vector<int> &, std::vector<std::string> &, std::vector<std::string> &,
                       std::vector<std::string> &, std::vector<std::string> &, std::vector<std::string> &);

void employeeLogin();

void addEmployeeAccount();

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

    std::string line;
    //file to string and string to vector
    //catalog
    std::ifstream catalog("Catalog.csv");
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
    int prodNum;
    std::string prodNumString;
    std::string serialNum;
    std::ifstream productionList("production_list.csv");
    while (getline(productionList, line)) {
        std::stringstream ss(line);
        getline(ss, prodNumString, ',');
        prodNum = std::stoi(prodNumString);
        getline(ss, manufacturer, ',');
        getline(ss, itemTypeCode, ',');
        getline(ss, prodName, ',');
        getline(ss, serialNum, ',');
        productionNumbers.push_back(prodNum);
        productionManufacturers.push_back(manufacturer);
        productionItemTypes.push_back(itemTypeCode);
        productionNames.push_back(prodName);
        serialNumbers.push_back(serialNum);

        // std::cout<<itemTypeCode<<std::endl;


    }
    productionList.close();
//    for(int i=0; i<serialNumbers.size();i++){
//        std::cout<<serialNumbers[i]<<std::endl;
//    }
    resetAndRepopulateVectors(productLineManufacturers, productLineNames, productLineItemTypes, productionNumbers,
                              productionManufacturers, productionNames, productionItemTypes, serialNumbers);

    //Welcome greeting
    std::cout << "Production Line Tracker\n" << std::endl;

    //Starts menu
    int userMenuChoice;

    //Initiate endless loop with terminator
    bool continueProgram = true;
    while (continueProgram) {
        userMenuChoice = displayMenuAndGetChoice();
        if (userMenuChoice == 1) {
            produceItems(productLineManufacturers, productLineNames, productLineItemTypes, productionNumbers,
                         productionManufacturers, productionNames, productionItemTypes, serialNumbers);
            resetAndRepopulateVectors(productLineManufacturers, productLineNames, productLineItemTypes,
                                      productionNumbers,
                                      productionManufacturers, productionNames, productionItemTypes, serialNumbers);
            system("pause");
        } else if (userMenuChoice == 2) {
            addNewItems(productLineManufacturers, productLineNames, productLineItemTypes);
            resetAndRepopulateVectors(productLineManufacturers, productLineNames, productLineItemTypes,
                                      productionNumbers,
                                      productionManufacturers, productionNames, productionItemTypes, serialNumbers);
        } else if (userMenuChoice == 3) {
            produceStatistics(productionNumbers,
                              productionManufacturers, productionNames, productionItemTypes, serialNumbers,
                              productLineItemTypes);
        } else if (userMenuChoice == 4) {
//            empAccount();
        } else if (userMenuChoice == 5) {
//            createAccount();
        } else if (userMenuChoice == 6) {
            continueProgram = false;
        } else {
            std::cout << "You have entered an invalid number, please try again.\n\n" << std::endl;
        }
    }
    return 0;
}

int displayMenuAndGetChoice() {
    //Menu selection prompt
    std::cout << "\n**********Menu************" << std::endl;
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
                  std::vector<int> &productionNumbers, std::vector<std::string> &productionManufacturers,
                  std::vector<std::string> &productionNames, std::vector<std::string> &productionItemTypes,
                  std::vector<std::string> &serialNumbers) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //output catalog
    std::cout << "\nChoose a Product to Produce:" << std::endl;
    std::cout << "****************************" << std::endl;
    for (int product_index = 0; product_index < productLineManufacturers.size(); product_index++) {
        std::cout << product_index + 1 << ". ";
        std::cout << productLineManufacturers[product_index] << " ";
        std::cout << productLineNames[product_index] << " ";
        std::cout << productLineItemTypes[product_index] << "\n";
    }
    //choice for production
    int userChoiceForProduct;
    std::cin >> userChoiceForProduct;
    userChoiceForProduct = userChoiceForProduct - 1;

    //output for number to produce
    std::cout << "How many would you like to Produce?:" << std::endl;
    int serialNumInput;
    std::cin >> serialNumInput;

    //get num for serial
    int countItemType = 0;
    std::string itemType = productLineItemTypes[userChoiceForProduct];
    //std::cout << productionItemTypes.size() << std::endl;
    for (int i = 0; i < productionItemTypes.size(); i++) {
        if (itemType == productionItemTypes[i]) {
            countItemType++;
        }
        //std::cout << productionItemTypes[i] << std::endl;
    }
    //test line for item count
    //std::cout << itemType << " appeared " << countItemType << " times" << std::endl;

    //create serial num and save
    int serialCount = 1;
    int prodNum = productionNumbers.size();
    //std::cout << productionManufacturers.size()<<std::endl;
    while (serialCount < serialNumInput + 1) {
        prodNum++;
        std::ofstream productionList;
        productionList.open("production_list.csv", std::ios_base::app);
        std::string manReduced = productLineManufacturers[userChoiceForProduct].substr(0, 3);
        std::string serialNumber;
        productionList << prodNum << "," << productLineManufacturers[userChoiceForProduct]
                       << "," << productLineItemTypes[userChoiceForProduct] << ","
                       << productLineNames[userChoiceForProduct] << "," << manReduced
                       << productLineItemTypes[userChoiceForProduct] << std::setfill('0') << std::setw(5)
                       << countItemType + serialCount << std::endl;
        serialCount++;
    }

}

void resetAndRepopulateVectors(std::vector<std::string> &productLineManufacturers,
                               std::vector<std::string> &productLineNames,
                               std::vector<std::string> &productLineItemTypes,
                               std::vector<int> &productionNumbers, std::vector<std::string> &productionManufacturers,
                               std::vector<std::string> &productionNames, std::vector<std::string> &productionItemTypes,
                               std::vector<std::string> &serialNumbers) {

    while (0 < productLineItemTypes.size()) {
        productLineManufacturers.pop_back();
        productLineNames.pop_back();
        productLineItemTypes.pop_back();
    }

    while (0 < productionNumbers.size()) {
        productionNumbers.pop_back();
        productionManufacturers.pop_back();
        productionItemTypes.pop_back();
        productionNames.pop_back();
        serialNumbers.pop_back();
    }
//    for(int i=0; i<serialNumbers.size();i++){
//        std::cout<<serialNumbers[i]<<std::endl;
//    }

    std::string line;
    //file to string and string to vector
    //catalog
    std::ifstream catalog("Catalog.csv");
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
    int prodNum;
    std::string prodNumString;
    std::string serialNum;
    std::ifstream productionList("production_list.csv");
    while (getline(productionList, line)) {
        std::stringstream ss(line);
        getline(ss, prodNumString, ',');
        prodNum = std::stoi(prodNumString);
        getline(ss, manufacturer, ',');
        getline(ss, itemTypeCode, ',');
        getline(ss, prodName, ',');
        getline(ss, serialNum);
        productionNumbers.push_back(prodNum);
        productionManufacturers.push_back(manufacturer);
        productionItemTypes.push_back(itemTypeCode);
        productionNames.push_back(prodName);
        serialNumbers.push_back(serialNum);
    }
//    for(int i=0; i<serialNumbers.size();i++){
//        std::cout<<serialNumbers[i]<<std::endl;
//    }
}

void addNewItems(std::vector<std::string> &productLineManufacturers,
                 std::vector<std::string> &productLineNames, std::vector<std::string> &productLineItemTypes) {
    std::cout << "\nAdd Product to Cataglog" << std::endl;
    std::cout << "***********************" << std::endl;
    std::string manufacturer, prodName;
    int itemType;
    std::cout << "Enter Manufacturer:" << std::endl;
    std::cin >> manufacturer;
    std::cout << "Enter Product Name:" << std::endl;
    std::cin >> prodName;
    std::cout << "What is the Item Type:\n1. Audio\n2. Visual\n3. AudioMobile\n4. VisualMobile" << std::endl;
    std::cin >> itemType;
    std::string itemTypeCode;
    switch (itemType) {
        case 1:
            itemTypeCode = "MM";
            break;
        case 2:
            itemTypeCode = "VI";
            break;
        case 3:
            itemTypeCode = "AM";
            break;
        case 4:
            itemTypeCode = "VM";
            break;
        default:
            std::cout << "Not a valid selection\n";
            std::cout << "Setting type to 'NA'\n";
            itemTypeCode = "NA";
            break;
    }
    int catalogCount = 0;
    while (catalogCount < 1) {
        std::ofstream catalog;
        catalog.open("Catalog.csv", std::ios_base::app);
        catalog << manufacturer << "," << prodName << "," << itemTypeCode << std::endl;
        catalogCount++;
    }
}
///delete option with remove and sort

///sort vectors
void sortProductionList(std::vector<int> &productionNumbers, std::vector<std::string> &productionManufacturers,
                        std::vector<std::string> &productionNames, std::vector<std::string> &productionItemTypes,
                        std::vector<std::string> &serialNumbers) {

}

void produceStatistics(std::vector<int> &productionNumbers, std::vector<std::string> &productionManufacturers,
                       std::vector<std::string> &productionNames, std::vector<std::string> &productionItemTypes,
                       std::vector<std::string> &serialNumbers, std::vector<std::string> &productLineItemTypes) {
    ///number of each type
    ///total items produced
    ///view each type
    ///search by serial number
    int statisticChoice;
    std::cout << "\nChoose Statistic to Produce:" << std::endl;
    std::cout << "****************************" << std::endl;
    std::cout
            << "1. Number of each Item Type\n2. Total Items Produced\n3. Display Serials of Type\n"
               "4. Display Entire Production Log\n5. Search for Serial Number Info" << std::endl;
    std::cin >> statisticChoice;
    switch (statisticChoice) {
        case 1: {
            //Displaying number of each Item Type
            int countItemType = 0;
            std::string itemType = "MM";
            for (int i = 0; i < productionItemTypes.size(); i++) {
                if (itemType == productionItemTypes[i]) {
                    countItemType++;
                }
            }
            std::cout << "Number of 'MM': " << countItemType << std::endl;
            //Reset for next type
            countItemType = 0;
            itemType = "VI";
            for (int i = 0; i < productionItemTypes.size(); i++) {
                if (itemType == productionItemTypes[i]) {
                    countItemType++;
                }
            }
            std::cout << "Number of 'VI': " << countItemType << std::endl;
            //Reset for next type
            countItemType = 0;
            itemType = "AM";
            for (int i = 0; i < productionItemTypes.size(); i++) {
                if (itemType == productionItemTypes[i]) {
                    countItemType++;
                }
            }
            std::cout << "Number of 'AM': " << countItemType << std::endl;
            //Reset for next type
            countItemType = 0;
            itemType = "VM";
            for (int i = 0; i < productionItemTypes.size(); i++) {
                if (itemType == productionItemTypes[i]) {
                    countItemType++;
                }
            }
            std::cout << "Number of 'VM': " << countItemType << std::endl;
            system("pause");
            break;
        }
        case 2: {
            //total items produced
            int totalItemCount = 0;
            for (totalItemCount; totalItemCount < productionItemTypes.size(); totalItemCount++) {
            }
            std::cout << "Total Items Currently Produced: " << totalItemCount << std::endl;
            system("pause");
            break;
        }
        case 3: {
            //serials of certain type
            int itemType;
            std::cout << "What is the Item Type:\n1. Audio\n2. Visual\n3. AudioMobile\n4. VisualMobile" << std::endl;
            std::cin >> itemType;
            std::string itemTypeCode;
            switch (itemType) {
                case 1:
                    itemTypeCode = "MM";
                    break;
                case 2:
                    itemTypeCode = "VI";
                    break;
                case 3:
                    itemTypeCode = "AM";
                    break;
                case 4:
                    itemTypeCode = "VM";
                    break;
                default:
                    std::cout << "Not a valid selection\n";
                    std::cout << "Setting type to 'NA'\n";
                    itemTypeCode = "NA";
                    break;
            }
            std::cout << "Serial Numbers for Type of: " << itemTypeCode << std::endl;
            int ifPrinted = 0;
            for (int outputCount = 0; outputCount < productionItemTypes.size(); outputCount++) {
                if (itemTypeCode == productionItemTypes[outputCount]) {
                    std::cout << serialNumbers[outputCount] << std::endl;
                    ifPrinted++;
                }
            }
            if (ifPrinted == 0) {
                std::cout << "No Items of that Type found." << std::endl;
            }
            system("pause");
            break;
        }
        case 4: {
            //display entire production log
            for (int outputCount = 0; outputCount < productionItemTypes.size(); outputCount++) {
                    std::cout << productionNumbers[outputCount] << ". Manufacturer: '"
                              << productionManufacturers[outputCount] << "' Item Type: '"
                              << productionItemTypes[outputCount]
                              << "' Product Name: '" << productionNames[outputCount] << "' Serial Number: '" <<
                              serialNumbers[outputCount] << "'" << std::endl;
            }
            break;
        }
        case 5: {
            //search for serial number
            std::cout << "Enter the Serial Number: ";
            std::string serialInput;
            std::cin >> serialInput;
            int ifPrinted = 0;
            for (int serialCount = 0; serialCount < serialNumbers.size(); serialCount++){
                if(serialNumbers[serialCount] == serialInput){
                    std::cout << productionNumbers[serialCount] << ". Manufacturer: '"
                              << productionManufacturers[serialCount] << "' Item Type: '"
                              << productionItemTypes[serialCount]
                              << "' Product Name: '" << productionNames[serialCount] << "'" << std::endl;
                    ifPrinted++;
                }
            }
            if(ifPrinted == 0){
                std::cout << "That Serial Number Could Not Be Found." << std::endl;
            }
            break;
        }
        default:
            std::cout << "Invalid selection" << std::endl;
            break;
    }
}

void employeeLogin() {

}

void addEmployeeAccount() {

}