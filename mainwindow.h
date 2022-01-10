#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gamelogic.h"
#include <QMainWindow>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



const int SIZE = 40;
const int Y = 50;
const int X = 10;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int get_board_size();

    void init_board();

    void click_tile();

    void init_answer_options();

    void init_won_lost();

    void init_restart_button();

    void click_answer_options();

    void click_restart();

    void game_over();

    void victory();

    void reset();

    void loss();



private:
    Ui::MainWindow *ui;

    std::vector<std::vector<QPushButton*>> Buttons_;
    std::vector<std::vector<std::pair<QPushButton*,int>>> Buttons_clicks;

    std::vector<QPushButton*> options;

    QPushButton* won_lost = nullptr;

    gamelogic logicBoard;

    int board_size = 10;

    int sum = 0;

};
#endif // MAINWINDOW_H
