#pragma once

#include <QDialog>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>

namespace Ui
{
    class ConfirmationDialog;
}

class ConfirmationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmationDialog(
    QString message = "", std::function<void()> onYesClicked = [](){}, QWidget *parent = nullptr);
    QVBoxLayout verticalLayout;
    ~ConfirmationDialog();

private:
    Ui::ConfirmationDialog *ui;
    QLabel *label;
};
