#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "BomberPass.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_generate_clicked();
    void on_btn_copy_clicked();
    void on_spin_level_valueChanged(int arg1);
    void on_spin_score_valueChanged(int arg1);
    void on_spin_radius_valueChanged(int arg1);
    void on_spin_bombs_valueChanged(int arg1);
    void on_chk_speed_toggled(bool checked);
    void on_chk_detonator_toggled(bool checked);
    void on_chk_wallpass_toggled(bool checked);

    void on_chk_flameproof_toggled(bool checked);

    void on_chk_highlight_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    BomberPass password;
};

#endif // MAINWINDOW_H
