#include <QMessageBox>
#include <QRegularExpression>
#include <QStyle>

#include "../shared.hpp"
#include "../equation-standard/equation.hpp"
#include "../equation-solution/solve.hpp"

#include "config-utilities.hpp"
#include "confirmation-dialog.hpp"
#include "config-window.hpp"
#include "main-window.hpp"
#include "./ui_main-window.h"

#include <iostream>

// Holds current value of calculation
std::string calculation_result{"0"};

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calculator)
{
    ui->setupUi(this);
    // Put 0 in Display
    ui->Display->setText(QString::fromStdString(calculation_result));

    QPushButton *buttonsDigits[10];

    // Cycle through locating the buttons
    for (std::size_t i{0}; i < 10; ++i)
    {
        QString buttonName {"Button" + QString::number(i)};

        // Get the buttons by name and add to array
        buttonsDigits[i] = MainWindow::findChild<QPushButton *>(buttonName);

        connect(buttonsDigits[i], SIGNAL(released()), this,
                SLOT(buttonPressed()));
    }

    connect(ui->Plus, SIGNAL(released()), this,
            SLOT(buttonPressed()));
    connect(ui->Minus, SIGNAL(released()), this,
            SLOT(buttonPressed()));
    connect(ui->Asterisk, SIGNAL(released()), this,
            SLOT(buttonPressed()));
    connect(ui->ForwardSlash, SIGNAL(released()), this,
            SLOT(buttonPressed()));
    connect(ui->Caret, SIGNAL(released()), this,
            SLOT(buttonPressed()));
    connect(ui->Percent, SIGNAL(released()), this,
            SLOT(buttonPressed()));
    connect(ui->Period, SIGNAL(released()), this,
            SLOT(buttonPressed()));

    connect(ui->Equals, SIGNAL(released()), this,
            SLOT(equalButtonPressed()));

    connect(ui->OppositeSign, SIGNAL(released()), this,
            SLOT(oppositeNumberSignPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonPressed()
{
    QPushButton *button{(QPushButton *)sender()};
    QString buttonValue{button->text()};
    QString displayedValue{ui->Display->text()};
    if ((displayedValue == "0" || displayedValue == "0.0") && buttonValue != "=" && buttonValue != "AC")
    {
        displayedValue = "";
    }
    // Append the button value to the current text in the display
    displayedValue += buttonValue;

    ui->Display->setText(displayedValue);
}

void MainWindow::equalButtonPressed()
{
    // Get value from display
    QString displayedValue{ui->Display->text()};
    std::string userEquation{displayedValue.toStdString()};
     if(isUserInputBrokenBeyondAutoRepair(userEquation))
     {
         badInputDialog();
         return;
     }
     autoRepairUserInput(userEquation);
     solveEquation(userEquation);
     ui->Display->setText(QString::fromStdString(userEquation));
}

void MainWindow::oppositeNumberSignPressed()
{
    // Get value from display
    QString displayedValue {ui->Display->text()};

    // Regular expression checks if it is a number
    QRegularExpression reg("[-+]?[0-9.]*");
    QRegularExpressionMatch match = reg.match(displayedValue);
    // If it is a number change the sign
    if (match.hasMatch())
    {
        ui->Display->setText(QString::number(-(displayedValue.toDouble())));
    }
}

void MainWindow::on_actionCopy_triggered()
{
    ui->Display->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->Display->paste();
}

void MainWindow::on_actionQt_Creator_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_actionCalculator_triggered()
{
    QMessageBox::information(this, "About Calculator", "Made by Przemyslaw Sochon\nVersion 0.6");
}

void MainWindow::enableMainWindow()
{
    this->setEnabled(true);
}

void MainWindow::on_actionconfig_triggered()
{
    ConfigWindow *newWindow {new ConfigWindow};
    this->setEnabled(false);
    newWindow->show();
    connect(newWindow, &ConfigWindow::finished, this, &MainWindow::enableMainWindow);
}

void MainWindow::on_AllClear_pressed()
{
    calculation_result = "0";
    ui->Display->setText("0");
}
