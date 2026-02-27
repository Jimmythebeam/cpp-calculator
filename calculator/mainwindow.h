#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "calculator.h"
#include <QMainWindow>

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

    inline static const int MAX_INPUT_LEN = 32;    // максимальное число разрядов для отображения на дисплее

    enum class Operation {
        NO_OPERATION,
        ADDITION,
        SUBTRACTION,
        MULTIPLICATION,
        DIVISION,
        POWER
    };

    void AddText(const QString& suffix);
    void SetText(const QString& text);
    QString RemoveTrailingZeroes(const QString &text);
    QString NormalizeNumber(const QString &text);
    void SetOperation(Operation op);
    QString FormatDouble (const double value);         // форматирование числа с плавающей точкой (отображение без экспоненты)
    QString OpToString(Operation op);



private slots:
    void on_btn_one_clicked();

    void on_btn_zero_clicked();

    void on_btn_two_clicked();

    void on_btn_three_clicked();

    void on_btn_four_clicked();

    void on_btn_five_clicked();

    void on_btn_six_clicked();

    void on_btn_seven_clicked();

    void on_btn_eight_clicked();

    void on_btn_nine_clicked();

    void on_btn_dot_clicked();

    void on_btn_sign_clicked();

    void on_btn_bckspace_clicked();

    void on_btn_power_clicked();

    void on_btn_division_clicked();

    void on_btn_multiplication_clicked();

    void on_btn_subtraction_clicked();

    void on_btn_addition_clicked();

    void on_btn_clear_clicked();

    void on_btn_result_clicked();

    void on_btn_ms_clicked();

    void on_btn_mr_clicked();

    void on_btn_mc_clicked();


private:
    Ui::MainWindow *ui;
    Calculator calculator_;
    QString input_number_;
    Number active_number_;
    Operation current_operation_ = Operation::NO_OPERATION;
    double stored_number_;
    bool is_stored_ = false;
};
#endif // MAINWINDOW_H
