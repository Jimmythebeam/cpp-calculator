#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->l_formula->clear();
    ui->l_memory->clear();
    SetText("0");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::AddText(const QString &suffix) {
    if (input_number_.size() <= MAX_INPUT_LEN){
    input_number_ += suffix;
    SetText(input_number_);
    }
}

void MainWindow::SetText(const QString &text) {
    input_number_ = NormalizeNumber(text);
    ui->l_result->setText(input_number_);
    active_number_ = input_number_.toDouble();
}

QString MainWindow::RemoveTrailingZeroes(const QString &text) {
    for (qsizetype i = 0; i < text.size(); ++i) {
        if (text[i] != '0') {
            return text.mid(i);
        }
    }
    return "";
}

QString MainWindow::NormalizeNumber(const QString &text) {
    if (text.isEmpty() ) {
        return "0";
    }
    if (text.startsWith('.')) {
        return NormalizeNumber("0" + text);
    }
    if (text.startsWith('-')) {
        QString inner = NormalizeNumber(text.mid(1));
        return (inner == "0") ? "0" : "-" + inner;
    }
    if (text.startsWith('0') && !text.startsWith("0.")) {
        return NormalizeNumber(RemoveTrailingZeroes(text));
    }
    return text;
}

void MainWindow::SetOperation(Operation op) {
    if (current_operation_== Operation::NO_OPERATION) {
        calculator_.Set(active_number_);
    }
     current_operation_ = op;
     ui->l_formula->setText(QString("%1 %2")
        .arg(FormatNumber(calculator_.GetNumber()))
        .arg(OpToString(current_operation_)));
    input_number_.clear();
}

QString MainWindow::FormatNumber(const Number value)
{
   int int_part = QString::number(std::floor(value)).size();
    if (std::floor(value) == value) {
        return QString::number(value, 'f', 0);
    }
    else {
        QString str = QString::number(value, 'f', MAX_INPUT_LEN - int_part - 1);
        while (str.contains('.') && str.endsWith('0')) {
        str.chop(1);
    }
    if (str.endsWith('.')) {
        str.chop(1);
    }
    return str;
    }
}

QString MainWindow::OpToString(Operation op)
{
    switch (op) {
        case Operation::NO_OPERATION: return "";
        case Operation::ADDITION: return "+";
        case Operation::DIVISION: return "÷";
        case Operation::MULTIPLICATION: return "×";
        case Operation::SUBTRACTION: return "−";
        case Operation::POWER: return "^";
        default: return "";
    }
}

void MainWindow::on_btn_zero_clicked() {
    AddText ("0");
}

void MainWindow::on_btn_one_clicked() {
    AddText ("1");
}

void MainWindow::on_btn_two_clicked() {
    AddText ("2");
}


void MainWindow::on_btn_three_clicked() {
    AddText ("3");
}


void MainWindow::on_btn_four_clicked() {
    AddText ("4");
}


void MainWindow::on_btn_five_clicked() {
    AddText ("5");
}


void MainWindow::on_btn_six_clicked() {
    AddText ("6");
}


void MainWindow::on_btn_seven_clicked() {
    AddText ("7");
}


void MainWindow::on_btn_eight_clicked() {
    AddText ("8");
}


void MainWindow::on_btn_nine_clicked() {
    AddText ("9");
}


void MainWindow::on_btn_dot_clicked() {
    if (!input_number_.contains(".")){
        AddText (".");
    }
}


void MainWindow::on_btn_sign_clicked()
{
    if (input_number_.startsWith("-")) {
        input_number_ = input_number_.mid(1);
    }
    else if (input_number_ != "0"){
        input_number_.insert(0, "-");
    }
    SetText(input_number_);
}


void MainWindow::on_btn_bckspace_clicked()
{
    if (!input_number_.isEmpty()) {
        input_number_.chop(1);
        SetText(input_number_);
    }
}


void MainWindow::on_btn_power_clicked()
{
    SetOperation(Operation::POWER);
}


void MainWindow::on_btn_division_clicked()
{
    SetOperation(Operation::DIVISION);
}


void MainWindow::on_btn_multiplication_clicked()
{
    SetOperation(Operation::MULTIPLICATION);
}


void MainWindow::on_btn_subtraction_clicked()
{
    SetOperation(Operation::SUBTRACTION);
}


void MainWindow::on_btn_addition_clicked()
{
    SetOperation(Operation::ADDITION);
}


void MainWindow::on_btn_clear_clicked()
{
    SetOperation(Operation::NO_OPERATION);
    ui->l_formula->setText("");
    SetText("0");
}


void MainWindow::on_btn_result_clicked()
{
    if (current_operation_== Operation::NO_OPERATION) {
        return;
    }
    else {
        ui->l_formula->setText(QString("%1 %2 %3 =")
            .arg(FormatNumber(calculator_.GetNumber()))
            .arg (OpToString(current_operation_))
            .arg (FormatNumber(active_number_)));
        switch (current_operation_) {
            case Operation::ADDITION: {
                calculator_.Add(active_number_);
                break;
            }
            case Operation::DIVISION: {
                calculator_.Div(active_number_);
                break;
            }
            case Operation::MULTIPLICATION: {
                calculator_.Mul(active_number_);
                break;
            }
            case Operation::SUBTRACTION: {
                calculator_.Sub(active_number_);
                break;
            }
            case Operation::POWER: {
                calculator_.Pow(active_number_);
                break;
            }
            default: break;
        }
        active_number_ = calculator_.GetNumber();
        ui->l_result->setText(FormatNumber(active_number_));
        input_number_.clear();
        current_operation_ = Operation::NO_OPERATION;
    }
}

void MainWindow::on_btn_ms_clicked()
{
    stored_number_ = active_number_;
    is_stored_ = true;
    ui->l_memory->setText("M");
}

void MainWindow::on_btn_mc_clicked()
{
    stored_number_ = 0;
    is_stored_ = false;
    ui->l_memory->clear();
}

void MainWindow::on_btn_mr_clicked()
{
    if (is_stored_) {
        active_number_ = stored_number_;
        ui->l_result->setText(FormatNumber(active_number_));
        input_number_.clear();
    }
}

