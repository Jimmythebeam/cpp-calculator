#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::SetInputText(const std::string &text){
    ui->l_result->setStyleSheet("");
    ui->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetErrorText(const std::string &text){
    ui->l_result->setStyleSheet("color: red;");
    ui->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetFormulaText(const std::string &text){
    ui->l_formula->setText(QString::fromStdString(text));
}

void MainWindow::SetMemText(const std::string &text){
    ui->l_memory->setText(QString::fromStdString(text));
}

void MainWindow::SetExtraKey(const std::optional<std::string> &key){
    if (key == std::nullopt)
        ui->tb_extra->hide();
    else {
        ui->tb_extra->show();
        ui->tb_extra->setText(QString::fromStdString(key.value()));
    }
}

void MainWindow::SetDigitKeyCallback(std::function<void (int)> cb){
    digit_key_callback_ = cb;
}

void MainWindow::SetProcessOperationKeyCallback(std::function<void (Operation)> cb){
    operation_key_callback_ = cb;
}

void MainWindow::SetProcessControlKeyCallback(std::function<void (ControlKey)> cb){
    control_key_callback_ = cb;
}

void MainWindow::SetControllerCallback(std::function<void (ControllerType)> cb){
    controller_key_callback_ = cb;
}

void MainWindow::on_btn_one_clicked(){
    if (digit_key_callback_) {
        digit_key_callback_(1);
    }
}

void MainWindow::on_btn_two_clicked(){
    if (digit_key_callback_) {
        digit_key_callback_(2);
    }
}

void MainWindow::on_btn_three_clicked(){
    if (digit_key_callback_) {
        digit_key_callback_(3);
    }
}

void MainWindow::on_btn_four_clicked(){
    if (digit_key_callback_) {
        digit_key_callback_(4);
    }
}

void MainWindow::on_btn_five_clicked(){
    if (digit_key_callback_) {
        digit_key_callback_(5);
    }
}

void MainWindow::on_btn_six_clicked(){
    if (digit_key_callback_) {
        digit_key_callback_(6);
    }
}

void MainWindow::on_btn_seven_clicked(){
    if (digit_key_callback_) {
        digit_key_callback_(7);
    }
}

void MainWindow::on_btn_eight_clicked(){
    if (digit_key_callback_) {
        digit_key_callback_(8);
    }
}

void MainWindow::on_btn_nine_clicked(){
    if (digit_key_callback_) {
        digit_key_callback_(9);
    }
}

void MainWindow::on_btn_zero_clicked(){
    if (digit_key_callback_) {
        digit_key_callback_(0);
    }
}

void MainWindow::on_btn_addition_clicked(){
    if (operation_key_callback_) {
        operation_key_callback_(Operation::ADDITION);
    }
}

void MainWindow::on_btn_subtraction_clicked(){
    if (operation_key_callback_) {
        operation_key_callback_(Operation::SUBTRACTION);
    }
}

void MainWindow::on_btn_multiplication_clicked(){
    if (operation_key_callback_) {
        operation_key_callback_(Operation::MULTIPLICATION);
    }
}

void MainWindow::on_btn_division_clicked(){
    if (operation_key_callback_) {
        operation_key_callback_(Operation::DIVISION);
    }
}

void MainWindow::on_btn_power_clicked(){
    if (operation_key_callback_) {
        operation_key_callback_(Operation::POWER);
    }
}

void MainWindow::on_btn_result_clicked(){
    if (control_key_callback_) {
        control_key_callback_(ControlKey::EQUALS);
    }
}

void MainWindow::on_btn_clear_clicked(){
    if (control_key_callback_) {
        control_key_callback_(ControlKey::CLEAR);
    }
}

void MainWindow::on_btn_ms_clicked(){
    if (control_key_callback_) {
        control_key_callback_(ControlKey::MEM_SAVE);
    }
}

void MainWindow::on_btn_mr_clicked(){
    if (control_key_callback_) {
        control_key_callback_(ControlKey::MEM_LOAD);
    }
}

void MainWindow::on_btn_mc_clicked(){
    if (control_key_callback_) {
        control_key_callback_(ControlKey::MEM_CLEAR);
    }
}

void MainWindow::on_btn_sign_clicked(){
    if (control_key_callback_) {
        control_key_callback_(ControlKey::PLUS_MINUS);
    }
}

void MainWindow::on_btn_bckspace_clicked(){
    if (control_key_callback_) {
        control_key_callback_(ControlKey::BACKSPACE);
    }
}

void MainWindow::on_tb_extra_clicked(){
    if (control_key_callback_) {
        control_key_callback_(ControlKey::EXTRA_KEY);
    }
}

 void MainWindow::on_cmb_controller_currentIndexChanged(int index){
    if (controller_key_callback_) {
        controller_key_callback_ (static_cast<ControllerType>(index));
    }
}




