#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init_board();
    init_answer_options();
    init_won_lost();
    init_restart_button();

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::get_board_size(){
    return board_size;
}

void MainWindow::init_board(){
    board_size = get_board_size();

    int X_ =0;
    int Y_ = 0;

    for (int y = 0; y < board_size; y++) {

        std::vector<QPushButton*> row;

        Buttons_clicks.push_back({});

        for (int x = 0; x < board_size; x++) {

            QPushButton* button = new QPushButton(this);

            button->show();
            row.push_back(button);

            button->setGeometry(X + x*SIZE, Y + y*SIZE, SIZE, SIZE);

            button->setEnabled(true);

            connect(button, &QPushButton::clicked, this, &MainWindow::click_tile);

            X_ += 20;

            Buttons_clicks.at(y).push_back({button,0});
        }

        Buttons_.push_back(row);
        row.clear();
        X_ = 0;
        Y_ += 20;
    }
    MainWindow::resize(300 + Y_, 300 + Y_);
}

void MainWindow::click_tile(){

    for(int i=0; i<static_cast<int>(options.size());i++){
        options.at(i)->setStyleSheet("QPushButton{ background-color: white }");
    }


    for(int y = 0; y < board_size; ++y)
    {
        for(int x = 0; x < board_size; ++x)
        {
            if(Buttons_.at(y).at(x)== sender())
            {
                int randomNum = logicBoard.get_board().at(x).at(y).get_number();
                QString num = QString::number(randomNum);
                Buttons_.at(y).at(x)->setText(num);
                sum += randomNum;

                if(Buttons_clicks.at(y).at(x).second>0){
                    logicBoard.add_to_sum(randomNum);
                }
                Buttons_clicks.at(y).at(x).second+=1;

                int opt1 = (rand()%3+0);
                QString sum_ = QString::number(sum);
                options.at(opt1)->setText(sum_);
                if(opt1 == 0){
                    QString wrong1 = QString::number(rand()%10+sum);
                    QString wrong2 = QString::number(rand()%10+sum);
                    options.at(1)->setText(wrong1);
                    options.at(2)->setText(wrong2);

                }else if(opt1 == 1){
                    QString wrong1 = QString::number(rand()%10+sum);
                    QString wrong2 = QString::number(rand()%10+sum);
                    options.at(0)->setText(wrong1);
                    options.at(2)->setText(wrong2);

                }else if(opt1 ==2){
                    QString wrong1 = QString::number(rand()%10+sum);
                    QString wrong2 = QString::number(rand()%10+sum);
                    options.at(0)->setText(wrong1);
                    options.at(1)->setText(wrong2);
                }
                return;
            }
        }
    }
}

void MainWindow::init_answer_options(){

    for (int i = 1; i < 4; i++) {

        QPushButton* button = new QPushButton(this);

        button->show();

        button->setGeometry(440, i*100, SIZE+30, SIZE+30);

        button->setEnabled(true);

        connect(button, &QPushButton::clicked, this, &MainWindow::click_answer_options);
        options.push_back(button);

    }
    MainWindow::resize(600, 600);
}

void MainWindow::init_won_lost(){

    QPushButton *button = new QPushButton(this);
    button->show();
    button->setGeometry(430,60,100,30);
    button->setStyleSheet("QPushButton{ background-color: white }");
    won_lost =button;
}

void MainWindow::init_restart_button(){

    QPushButton *button = new QPushButton(this);
    button->show();
    button->setGeometry(430,20,100,30);
    button->setText("New game");
    connect(button, &QPushButton::clicked, this, &MainWindow::click_restart);
}

void MainWindow::click_restart(){
    Buttons_.clear();
    Buttons_clicks.clear();
    options.clear();
    won_lost = nullptr;
    sum = 0;

    logicBoard.new_board();
    init_board();
    init_answer_options();
    init_won_lost();
    init_restart_button();
}

void MainWindow::click_answer_options(){
    for(int i = 0; i< static_cast<int>(options.size()); i++){

        if(options.at(i) == sender()){
            int sum_ = options.at(i)->text().toInt();
            if(sum_ == sum){
                options.at(i)->setStyleSheet("QPushButton{ background-color: green }");
                if(sum_ == logicBoard.get_total_sum()){
                    victory();
                }

            }else{
                loss();
                options.at(i)->setStyleSheet("QPushButton{ background-color: red }");

            }
        }
    }
}

void MainWindow::victory(){
    won_lost->setText("You Won!");
}

void MainWindow::loss(){
    won_lost->setText("You Lost!");
    for(int y = 0; y< board_size; y++){
        for(int x = 0; x < board_size; x++){
            Buttons_.at(y).at(x)->setEnabled(false);
        }
    }
    for (int i = 0;i < static_cast<int>(options.size()); i++){
        options.at(i)->setEnabled(false);
    }
}
