#ifndef SRC_VIEW_MAINWINDOW_H_
#define SRC_VIEW_MAINWINDOW_H_

#include <QMainWindow>
#include <QRegularExpression>
#include <memory>
#include <string>

#include "../Controller/controller.h"

#define MAX_INPUT_NUM_X 1000000000000000

using std::string;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 signals:
  void SendData(QString, double, double, double, double);

 private slots:
  void push_symbol();
  void push_right_bracket();
  void push_opt();
  void on_button_clean_clicked();
  void on_button_backspace_clicked();
  void on_button_eq_clicked();

 private:
  bool error_calc_;
  bool wait_push_;
  std::unique_ptr<Ui::MainWindow> ui_;
  std::unique_ptr<my::Controller> controller_;
};
#endif  // SRC_VIEW_MAINWINDOW_H_
