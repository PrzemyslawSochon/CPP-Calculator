#pragma once
#include <QCheckBox>
#include <QComboBox>
#include <QDialog>
#include <QSettings>

enum Percent
{
decimal,
modulo,

max
};

namespace Ui
{
    class ConfigWindow;
}

class ConfigWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigWindow(QWidget *parent = nullptr);
    ~ConfigWindow();

private slots:

    void on_checkBoxInput_stateChanged(int arg1);

    void on_checkBoxTerminal_stateChanged(int arg1);

    void on_comboBox_currentIndexChanged(int arg1);

private:
    Ui::ConfigWindow *ui;
    QComboBox *comboBox;
};
