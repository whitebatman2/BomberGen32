#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QString>
#include <QClipboard>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    password()
{
    ui->setupUi(this);

    //Disable window resizing
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);

    on_btn_generate_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_generate_clicked()
{
    QString pass = QString::fromStdString(password.getString());
    ui->lbl_code->setText(pass);
}

void MainWindow::on_btn_copy_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->lbl_code->text());
}

void MainWindow::on_spin_level_valueChanged(int arg1)
{
    password.setLevel(static_cast<uint8_t>(arg1));
}

void MainWindow::on_spin_score_valueChanged(int arg1)
{
    password.setScore(static_cast<uint32_t>(arg1) * 100);
}

void MainWindow::on_spin_radius_valueChanged(int arg1)
{
    password.setBombRadius(static_cast<uint8_t>(arg1) - 1);
}

void MainWindow::on_spin_bombs_valueChanged(int arg1)
{
    password.setBombCount(static_cast<uint8_t>(arg1) - 1);
}

void MainWindow::on_chk_speed_toggled(bool checked)
{
    password.setSpeed(checked);
}

void MainWindow::on_chk_detonator_toggled(bool checked)
{
    password.setDetonator(checked);
}

void MainWindow::on_chk_wallpass_toggled(bool checked)
{
    password.setWallpass(checked);
}

void MainWindow::on_chk_flameproof_toggled(bool checked)
{
    password.setFlameproof(checked);
}

void MainWindow::on_chk_highlight_toggled(bool checked)
{
    password.setHighlight(checked);
}
