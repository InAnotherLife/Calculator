#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui_(std::make_unique<Ui::MainWindow>()),
      controller_(std::make_unique<my::Controller>()) {
  ui_->setupUi(this);
  this->setWindowTitle("Calculator");
  setlocale(LC_ALL, "en_US.UTF-8");
  error_calc_ = true, wait_push_ = false;
  connect(ui_->push_num_0, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_num_1, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_num_2, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_num_3, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_num_4, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_num_5, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_num_6, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_num_7, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_num_8, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_num_9, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_cos, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_sin, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_tan, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_acos, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_asin, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_atan, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_ln, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_log, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_sqrt, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_mod, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_left_bracket, SIGNAL(clicked()), this, SLOT(push_opt()));
  connect(ui_->push_right_bracket, SIGNAL(clicked()), this,
          SLOT(push_right_bracket()));
  connect(ui_->push_mult, SIGNAL(clicked()), this, SLOT(push_opt()));
  connect(ui_->push_div, SIGNAL(clicked()), this, SLOT(push_opt()));
  connect(ui_->push_plus, SIGNAL(clicked()), this, SLOT(push_opt()));
  connect(ui_->push_minus, SIGNAL(clicked()), this, SLOT(push_opt()));
  connect(ui_->push_power, SIGNAL(clicked()), this, SLOT(push_opt()));
  connect(ui_->push_scien_not, SIGNAL(clicked()), this, SLOT(push_opt()));
  connect(ui_->push_dot, SIGNAL(clicked()), this, SLOT(push_symbol()));
  connect(ui_->push_exp, SIGNAL(clicked()), this, SLOT(push_symbol()));
}

MainWindow::~MainWindow() {}

void MainWindow::push_symbol() {
  if (error_calc_ && !wait_push_) {
    QPushButton *button = (QPushButton *)sender();
    QString input_sym = ui_->area_result->text() + button->text();
    ui_->area_result->setText(input_sym);
  }
}

void MainWindow::push_opt() {
  if (error_calc_ && !wait_push_) {
    QPushButton *button = (QPushButton *)sender();
    QString input_sym = ui_->area_result->text() + button->text();
    input_sym.replace("^y", "^");
    ui_->area_result->setText(input_sym);
  }
  if (error_calc_ && wait_push_) {
    QString input_tmp = ui_->area_result->text();
    ui_->area_result->setText("");
    QPushButton *button = (QPushButton *)sender();
    QString input_sym = ui_->area_result->text() + button->text();
    input_sym.replace("^y", "^");
    ui_->area_result->setText(input_tmp + input_sym);
  }
  wait_push_ = false;
}

void MainWindow::on_button_clean_clicked() {
  ui_->area_result->setText("");
  wait_push_ = false;
  error_calc_ = true;
}

void MainWindow::on_button_backspace_clicked() {
  if (error_calc_) {
    QString inputBackSpace = ui_->area_result->text();
    inputBackSpace.chop(1);
    ui_->area_result->setText(inputBackSpace);
  }
}

void MainWindow::push_right_bracket() {
  if (error_calc_ && !wait_push_) {
    QPushButton *button = (QPushButton *)sender();
    QString input_sym = ui_->area_result->text() + button->text();
    ui_->area_result->setText(input_sym);
  }
}

void MainWindow::on_button_eq_clicked() {
  if (error_calc_) {
    QString input_expr = ui_->area_result->text();
    input_expr.replace("√", "g");
    input_expr.replace("X", "x");
    string input_expr_string = input_expr.toStdString();
    string result = controller_->GetResult(&input_expr_string);
    QString result_qstring = QString::fromStdString(result);
    ui_->area_result->setText(result_qstring);
    if (result_qstring.contains(QRegularExpression("^[A-Z]")))
      error_calc_ = false;
  }
  wait_push_ = true;
}
