#pragma once

#include <string_view>
#include <unordered_map>

enum Percent
{
    decimal,
    modulo,

    max
};

extern bool g_verbose_terminal_prompts;
extern bool g_automatically_fix_errors;
extern Percent g_treat_percent_sign_as;

extern std::unordered_map<std::string, Percent> stringToPercent;

void setDefaultConfigValues();
void createNewConfigFile();
void loadConfigFile();
void modifyConfigFile(std::string_view key, bool setting);
void toggleConfig(std::string_view key, bool &setting);
void badInputDialog();
void askUserToHandleBadInput();
