#include "config-utilities.hpp"
#include "confirmation-dialog.hpp"

#include <nlohmann/json.hpp>

#include <array>
#include <fstream>
#include <iostream>
#include <typeinfo>

bool g_verbose_terminal_prompts;
bool g_automatically_fix_errors;
Percent g_treat_percent_sign_as;

std::unordered_map<std::string, Percent> stringToPercent{
    {"decimal", Percent::decimal},
    {"modulo", Percent::modulo}};

void setDefaultConfigValues()
{
    g_verbose_terminal_prompts = true;
    g_automatically_fix_errors = true;
    g_treat_percent_sign_as = Percent::decimal;
}

void createNewConfigFile()
{
    constexpr std::string_view configDefaultContents{
        "{\n"
        "    \"Automatically fix user input errors\": false,\n"
        "    \"Show debug prompts in terminal\": false,\n"
        "    \"Treat percent sign as\": \"decimal\"\n"
        "}"};

    try
    {
        std::ofstream fout("./source/config.json");
        fout << configDefaultContents;
        fout.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error writing file: " << e.what() << '\n';
    }
    std::cout << "Setting default values.\n";
    setDefaultConfigValues();
}

void loadConfigFile()
{
    try
    {
        std::ifstream fin("./source/config.json");
        nlohmann::json config{nlohmann::json::parse(fin)};
        std::cout << config.dump(4) << std::endl;
        fin.close();

        g_automatically_fix_errors = config.at(0).at("Automatically fix user input errors").get<bool>();
        g_verbose_terminal_prompts = config.at(0).at("Show debug prompts in terminal").get<bool>();
        g_treat_percent_sign_as = stringToPercent[config.at(0).at("Treat percent sign as").get<std::string>()];
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error reading file " << e.what() << "\nCreating new config file.\n";
        createNewConfigFile();
    }
}

void modifyConfigFile(std::string_view key, bool setting)
{
    try
    {
        std::ifstream fin("./source/config.json");
        nlohmann::json config;
        fin >> config;

        config[key.data()] = setting;

        std::ofstream fout("./source/config.json");
        fout << std::setw(4) << config << '\n';
        fout.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error writing file: " << e.what() << '\n';
    }
}

void toggleConfig(std::string_view key, bool &setting)
{
    setting = !setting;

    auto onYesClicked = [key, setting]()
    {
        modifyConfigFile(key, setting);
    };

    QString message{"Successfully changed settings. Would like to save it?"};
    ConfirmationDialog dialog(message, onYesClicked);
    dialog.exec();
}

void badInputDialog()
{
    QString message{
        "Bad input!\n"};
    ConfirmationDialog dialog(message);
    dialog.exec();
}

void askUserToHandleBadInput()
{
    auto onYesClicked = []()
    {
        toggleConfig("Automatically fix user input errors", g_automatically_fix_errors);
    };
    QString message{
        "Your equation has some errors.\n"
        "Would you like to let the program fix it?sad\n"
        "Warning: possible data loss.\n"
        "Save the equation beforehand."};
    ConfirmationDialog dialog(message, onYesClicked);
    dialog.exec();
}
