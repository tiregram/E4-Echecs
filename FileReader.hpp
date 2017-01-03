#pragma once
#include <iostream>
#include <string>

class FileReader {
  
public:
  std::ifstream file;

  FileReader(std::string FileName) {

    this->file(FileName);

    if (!this->file.is_open()) {
      throw "NO FILE";
    }
  }

  bool end() {}
  std::string next() {
    std::string f ;

    std::getline(this->file,f);
  }

  virtual ~FileReader() { this->file.close(); };
};
