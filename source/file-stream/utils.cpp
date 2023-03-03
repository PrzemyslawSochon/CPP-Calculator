#include "utils.hpp"

#include <fstream>

bool isIllegal(const std::string &str) {

  if (str.size() > 250) {
    std::cerr << "Max filename length is 250\n";
    return true;
  }

for (char c : str) {
    if (isCharIllegal(c)) {
      std::cerr << "Illegal character " << c << " inside filename\n";
      return true;
    }
  }
  return false;
}

void createNewFile(const std::string &filename) {

  std::ofstream fout(filename);
  if (!fout) {
    throw std::runtime_error("Failed to create file: " + filename);
  }
  fout.close();
}

void loadFile(const std::string &filename) {
 
    std::ifstream fin(filename);
    if(!fin.good()){
    std::cerr << "Error reading file "
              << "\nCreating new config file.\n";
    createNewFile(filename);
    return;
    }
    fin.close();
}
