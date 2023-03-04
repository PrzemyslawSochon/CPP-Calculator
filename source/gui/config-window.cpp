#include "../shared.hpp"

#include "config-window.hpp"
#include "./ui_config-window.h"

ConfigWindow::ConfigWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::ConfigWindow) {
  ui->setupUi(this);
  //ui->checkBoxInput->setChecked(g_automatically_fix_errors);
  //ui->checkBoxTerminal->setChecked(g_verbose_terminal_prompts);
  //ui->comboBox->setCurrentIndex(g_treat_percent_sign_as);
}

ConfigWindow::~ConfigWindow() { delete ui; }

void ConfigWindow::on_checkBoxInput_stateChanged(int arg1) {
  switch (arg1) {
  case Qt::Unchecked:
    //g_automatically_fix_errors = false;
    break;
  case Qt::Checked:
    //g_automatically_fix_errors = true;
    break;
  default:
    //g_automatically_fix_errors = false;
    break;
  }
}

void ConfigWindow::on_checkBoxTerminal_stateChanged(int arg1) {
  switch (arg1) {
  case Qt::Unchecked:
    //g_verbose_terminal_prompts = false;
    break;
  case Qt::Checked:
    //g_verbose_terminal_prompts = true;
    break;
  default:
    //g_verbose_terminal_prompts = false;
    break;
  }
}

void ConfigWindow::on_comboBox_currentIndexChanged(int arg1) {
  switch (arg1) {
  case 0:
    //g_treat_percent_sign_as = Percent::decimal;
    break;
  case 1:
    //g_treat_percent_sign_as = Percent::modulo;
    break;
  default:
    //g_treat_percent_sign_as = Percent::decimal;
    break;
  }
}
