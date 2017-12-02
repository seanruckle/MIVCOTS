#include "splitter.hpp"

#include<iostream>
#include<sstream>
#include<fstream>

splitter::splitter(){}
splitter::~splitter(){}

void splitter::initialize(std::string configFile){
    std::ifstream confFile(configFile);

    if (!confFile.is_open()){
        std::cerr<<"Could not open configuration file!"<<std::endl;
        return;
    }

    std::string configLine;
    std::string key;

    while (getline(confFile, configLine)){
        // Ignore lines if they are comments, empty, or only spaces
        if (isComment(configLine) 
            || configLine.empty()
            || (configLine.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
            ){
            continue;
        }

        // Find the key by looking for the first comma
        key = configLine.substr(0, configLine.find(','));

        // Add the the vector that will be used to store parsed items
        latestParsed.push_back(std::make_pair(key, 0));
    }

    m_numFields = latestParsed.size();

    confFile.close();
}

void splitter::parseString(std::string toParse){
    // To read into
    std::string fieldName, fieldValue;

    // For parsing
    std::stringstream inputStream(toParse);
    int resultPosition = -1;
    int newResultPosition = 0;

    // Read the name
    while(getline(inputStream, fieldName, ',')){
        // Read the value
        getline(inputStream, fieldValue, ',');

        newResultPosition = checkPair(fieldName, fieldValue);

        if (newResultPosition < 0){
            return;
        }

        if ((newResultPosition - resultPosition) == 1) {
            latestParsed.at(newResultPosition) = std::make_pair(fieldName, stol(fieldValue));
            resultPosition = newResultPosition;
        }
     }
}

void splitter::printLatest(){
    resultVector::iterator iter;

    std::cout<<std::endl;

    for (iter = latestParsed.begin(); iter != latestParsed.end(); ++iter){
        std::cout<<iter->first<<" : "<<iter->second<<std::endl;
    }

}

bool splitter::isComment(std::string configLine) {
    if (configLine.length() >= 2) {
        if ((configLine.at(0) == '/') && (configLine.at(1) == '/')) {
            return true;
        }
    }

    return false;
}

int splitter::checkPair(std::string key, std::string value){
    int ii = 0;

    if (value.empty()){
        std::cerr<<"Warning: empty field value"<<std::endl;
        return -1;
    }

    for (ii; ii < latestParsed.size(); ++ii){
        if (key == latestParsed.at(ii).first) {
            return ii;
        }
    }

    std::cerr<<"Warning: unexpected field name"<<std::endl;
    return -1;
}