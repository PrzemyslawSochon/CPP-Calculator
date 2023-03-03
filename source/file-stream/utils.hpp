#pragma once

#include <iostream>
#include <string>

const std::string illegalFilenameChars{" !@#$%<>`?=*&{}|\'\":"};

inline bool isCharIllegal(char c) {
  return illegalFilenameChars.find(c) != std::string::npos;
}

bool isIllegal(const std::string &str);
void createNewFile(const std::string &filename);
void loadFile(const std::string &filename);
