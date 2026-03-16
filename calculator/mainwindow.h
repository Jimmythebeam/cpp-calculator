#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <enums.h>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void SetInputText(const std::string& text);
    void SetErrorText(const std::string& text);
    void SetFormulaText(const std::string& text);
    void SetMemText(const std::string& text);
    void SetExtraKey(const std::optional<std::string>& key);
    void SetDigitKeyCallback(std::function<void(int key)> cb);
    void SetProcessOperationKeyCallback(std::function<void(Operation key)> cb);
    void SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb);
    void SetControllerCallback(std::function<void(ControllerType controller)> cb);


private slots:
    void on_btn_one_clicked();

    void on_btn_two_clicked();

    void on_btn_three_clicked();

    void on_btn_four_clicked();

    void on_btn_five_clicked();

    void on_btn_six_clicked();

    void on_btn_seven_clicked();

    void on_btn_eight_clicked();

    void on_btn_nine_clicked();

    void on_btn_zero_clicked();

    void on_btn_addition_clicked();

    void on_btn_subtraction_clicked();

    void on_btn_multiplication_clicked();

    void on_btn_division_clicked();

    void on_btn_power_clicked();

    void on_btn_result_clicked();

    void on_btn_clear_clicked();

    void on_btn_ms_clicked();

    void on_btn_mr_clicked();

    void on_btn_mc_clicked();

    void on_btn_sign_clicked();

    void on_btn_bckspace_clicked();

    void on_cmb_controller_currentIndexChanged(int index);

    void on_tb_extra_clicked();

private:
    Ui::MainWindow *ui;
    std::function<void(int key)> digit_key_callback_;
    std::function<void(Operation key)> operation_key_callback_;
    std::function<void(ControlKey key)> control_key_callback_;
    std::function<void(ControllerType controller)> controller_key_callback_;

};
#endif // MAINWINDOW_H
