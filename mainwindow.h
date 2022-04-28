#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include "QAction"

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    //显示标签
        QLabel * label1;
        QLabel * label2;
        //文本编辑框
        QTextEdit * showEdit;
        QTextEdit * resultEdit;
        //按钮布局成员变量
        //QPushButton * backBt;
        QPushButton * removeBt;
        QPushButton * clearBt;
        QPushButton * sumBt;

        QPushButton * sevenBt;
        QPushButton * eightBt;
        QPushButton * nineBt;
        QPushButton * decBt;

        QPushButton * fourBt;
        QPushButton * fiveBt;
        QPushButton * sixBt;
        QPushButton * starBt;

        QPushButton * oneBt;
        QPushButton * twoBt;
        QPushButton * threeBt;
        QPushButton * divBt;

        //QPushButton * _Bt;  //+/-按钮
        QPushButton * zeroBt;
        QPushButton * pointBt;
        QPushButton * equalBt;
        //QMenu *menu1;
        //QMenu *menu2;
        //QMenu *menu3;
        //QAction *action1;
        //QAction *action2;
        //QAction *action3;
        //QAction *action4;
        //QAction *action5;
        //QAction *action6;
        //QAction *action7;
        //QAction *action8;
        //显示结果
            qreal result;
            //第一个操作数
            qreal firstOpeNum;
            //第二个操作数
            qreal secondOpeNum;
            //显示字符串
            QString contextStr;
            int operat = 0;   //操作符
            int const ADD = 1;
            int const DEC = 2;
            int const MUL = 3;
            int const DIV = 4;
            int edittext;




public:
        void mylayout();
        void addMenu();
        void addMenuAction();
        void JudgeZero();
        void BeforeOperator(int iOperator);
        void init();
        void keyPressEvent(QKeyEvent * e);
private slots:
    //点击关于槽函数
    //void onClickAbort();
    //点击帮助槽函数
    //void onClickHelp();
    //点击复制槽函数
    //void onClickCopy();
    //点击粘贴槽函数
    void onClickPaste();
    void onPushBtone();
    void onPushBttwo();
    void onPushBtthree();
    void onPushBtdiv();
    void onPushBtBack();
    void onPushBtRemove();
    void onPushBtClear();
    void onPushBtSum();
    void onPushBtSeven();
    void onPushBtEight();
    void onPushBtNine();
    void onPushBtDec();
    void onPushBtMul();
    void onPushBtFour();
    void onPushBtFive();
    void onPushBtSix();
    void onPushBtSign();
    void onPushBtPoint();
    void onPushBtZero();
    void onPushBtEqual();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
