#include "../../include/observers/FileObserver.hpp"
#include <fstream>
#include <iostream>

FileObserver::FileObserver(const std::string &filename) : outputFile(filename, std::ios::app){
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
    }
}

FileObserver::~FileObserver(){
    if (outputFile.is_open()){outputFile.close();}
}

void FileObserver::onEvent(const std::string &event){
    if (outputFile.is_open()){
        outputFile << "File Log: " << event << std::endl;
    }
    else{
        std::cerr << "Error: File is not open. Cannot write log." << std::endl;
    }
}

void FileObserver::getLogs(std::vector<std::string> &lines, const std::string &filename){
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()){
        std::cerr << "Error: Unable to open file " << filename << " for reading." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)){
        lines.push_back(line);
    }

    inputFile.close();
}