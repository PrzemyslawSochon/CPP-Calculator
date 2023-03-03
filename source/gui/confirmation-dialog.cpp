#include "confirmation-dialog.hpp"
#include "ui_confirmation-dialog.h"
#include <QPushButton>

ConfirmationDialog::ConfirmationDialog(QString text, std::function<void()> onYesClicked, QWidget *parent) : QDialog(parent),
                                                                                                            ui(new Ui::ConfirmationDialog),
                                                                                                            label(new QLabel)
{
    ui->setupUi(this);
    label->setText(text);
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("No");
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Yes");
    ui->verticalLayout->addWidget(label);
    label->adjustSize();
}

ConfirmationDialog::~ConfirmationDialog()
{
    delete label;
    delete ui;
}
