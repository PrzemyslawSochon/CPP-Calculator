#pragma once

#include <QMainWindow>

void badInputDialog();

namespace Ui
{
    class Calculator;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::Calculator *ui;

private slots:
    void buttonPressed();
    void equalButtonPressed();
    void oppositeNumberSignPressed();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionQt_Creator_triggered();
    void on_actionCalculator_triggered();
    void on_actionconfig_triggered();
    void enableMainWindow();
    void on_AllClear_pressed();
};
