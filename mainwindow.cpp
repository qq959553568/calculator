#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QHBoxLayout"
#include "QAction"
#include "QMessageBox"
#include "QDebug"

#include<QKeyEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mylayout();
    addMenuAction();
    addMenu();

}
void MainWindow::mylayout()
{
    //设置中心窗口
    QWidget *centerWindow = new QWidget;
    this->setCentralWidget(centerWindow);

    label1 = new QLabel("显示");
    label2 = new QLabel("结果");
    QHBoxLayout * h1 = new QHBoxLayout;
    h1->addWidget(label1);
    h1->addWidget(label2);
    label1->setMaximumHeight(15);
    label2->setMaximumHeight(15);
    h1->setStretch(0,2);
    h1->setStretch(1,1);

   showEdit = new QTextEdit;
    resultEdit = new QTextEdit;
    QHBoxLayout * h2 = new QHBoxLayout;
    h2->addWidget(showEdit);
    h2->addWidget(resultEdit);
    showEdit->setMaximumHeight(30);
    resultEdit->setMaximumHeight(30);
    showEdit->setReadOnly(true);
    resultEdit->setReadOnly(true);
    h2->setStretch(0,2);
    h2->setStretch(1,1);

    //第三行按钮
    //backBt   = new QPushButton("Back");
    removeBt = new QPushButton("后退一步(back)");
    clearBt  = new QPushButton("清空(clear)");
    sumBt    = new QPushButton("加(+)");
    //backBt->setMinimumHeight(50);
    removeBt->setMinimumHeight(50);
    clearBt->setMinimumHeight(50);
    sumBt->setMinimumHeight(50);
    QHBoxLayout * h3 = new QHBoxLayout;
    //h3->addWidget(backBt);
    h3->addWidget(removeBt);
    h3->addWidget(clearBt);
    h3->addWidget(sumBt);
    sevenBt = new QPushButton("7");
    eightBt = new QPushButton("8");
    nineBt  = new QPushButton("9");
    decBt   = new QPushButton("减(-)");
    sevenBt->setMinimumHeight(50);
    eightBt->setMinimumHeight(50);
    nineBt->setMinimumHeight(50);
    decBt->setMinimumHeight(50);
    QHBoxLayout * h4 = new QHBoxLayout;
    h4->addWidget(sevenBt);
    h4->addWidget(eightBt);
    h4->addWidget(nineBt);
    h4->addWidget(decBt);

    fourBt = new QPushButton("4");
    fiveBt = new QPushButton("5");
    sixBt  = new QPushButton("6");
    starBt = new QPushButton("乘(*)");
    fourBt->setMinimumHeight(50);
    fiveBt->setMinimumHeight(50);
    sixBt->setMinimumHeight(50);
    starBt->setMinimumHeight(50);
    QHBoxLayout * h5 = new QHBoxLayout;
    h5->addWidget(fourBt);
    h5->addWidget(fiveBt);
    h5->addWidget(sixBt);
    h5->addWidget(starBt);

    oneBt    = new QPushButton("1");
    twoBt    = new QPushButton("2");
    threeBt  = new QPushButton("3");
    divBt    = new QPushButton("除(/)");
    oneBt->setMinimumHeight(50);
    twoBt->setMinimumHeight(50);
    threeBt->setMinimumHeight(50);
    divBt->setMinimumHeight(50);
    QHBoxLayout * h6 = new QHBoxLayout;
    h6->addWidget(oneBt);
    h6->addWidget(twoBt);
    h6->addWidget(threeBt);
    h6->addWidget(divBt);

    //_Bt      =  new QPushButton("+/-");
    zeroBt   =  new QPushButton("0");
    pointBt  =  new QPushButton(".");
    equalBt  =  new QPushButton("等于(=)");
    //_Bt->setMinimumHeight(50);
    zeroBt->setMinimumHeight(50);
    pointBt->setMinimumHeight(50);
    equalBt->setMinimumHeight(50);
    QHBoxLayout * h7 = new QHBoxLayout;
    //h7->addWidget(_Bt);
    h7->addWidget(zeroBt);
    h7->addWidget(pointBt);
    h7->addWidget(equalBt);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(h1);
    mainLayout->addLayout(h2);
    mainLayout->addLayout(h3);
    mainLayout->addLayout(h4);
    mainLayout->addLayout(h5);
    mainLayout->addLayout(h6);
    mainLayout->addLayout(h7);

    centerWindow->setLayout(mainLayout);
    //connect(backBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtBack()));
        connect(removeBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtRemove()));
        connect(clearBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtClear()));
        connect(sumBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtSum()));
        connect(sevenBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtSeven()));
        connect(eightBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtEight()));
        connect(nineBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtNine()));
        connect(decBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtDec()));
        connect(fourBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtFour()));
        connect(fiveBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtFive()));
        connect(sixBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtSix()));
        connect(starBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtMul()));
        connect(oneBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtone()));
        connect(twoBt,SIGNAL(clicked(bool)),this,SLOT(onPushBttwo()));
        connect(threeBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtthree()));
        connect(divBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtdiv()));
        //connect(_Bt,SIGNAL(clicked(bool)),this,SLOT(onPushBtSign()));
        connect(pointBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtPoint()));
        connect(equalBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtEqual()));
        connect(zeroBt,SIGNAL(clicked(bool)),this,SLOT(onPushBtZero()));


}
void MainWindow::addMenu()
{

//    menu1=menuBar()->addMenu("选择");
//    menu1->addAction(action1);
//    menu1->addAction(action2);
//    //增加横线
//    menu1->addSeparator();
//    menu1->addAction(action3);
//    menu1->addAction(action4);

//    menu2=menuBar()->addMenu("编辑");
//    menu2->addAction(action5);
//    menu2->addSeparator();
//    menu2->addAction(action6);

//    menu3=menuBar()->addMenu("帮助");
//    menu3->addAction(action7);
//    menu3->addSeparator();
//    menu3->addAction(action8);
}
//增加菜单栏选项
void MainWindow::addMenuAction()
{
    //action1 = new QAction("标准",this);
   //action1->setShortcut(tr("alt+l"));
    //action2 = new QAction("科学",this);
    //action2->setShortcut(tr("alt+2"));
    //action3 = new QAction("历史记录",this);
    //action3->setShortcut(tr("alt+3"));
    //action4 = new QAction("时间设置",this);
    //action4->setShortcut(tr("alt+4"));
    //action5 = new QAction("复制",this);
    //action5->setShortcut(tr("ctrl+1"));
    //action6 = new QAction("粘贴",this);
    //action6->setShortcut(tr("ctrl+2"));
    //action7 = new QAction("帮助",this);
    //action7->setShortcut(tr("ctrl+3"));

    //action8 = new QAction("关于",this);
    //action8->setShortcut(tr("ctrl+4"));
}
void MainWindow::BeforeOperator(int iOperator)
{
    if(contextStr.size() == 0 || contextStr == "-")
    {
        return;
    }
    if(operat == 0)
    {
         firstOpeNum = contextStr.toDouble();
    }
    operat = iOperator;
    contextStr.clear();
    showEdit->setText(contextStr);
}

void MainWindow::init()
{
     firstOpeNum = 0;
    //第二个操作数
    secondOpeNum = 0;
    operat = 0;

}
//void MainWindow::onClickAbort()
//{

//}

//void MainWindow::onClickHelp()
//{

//}

//void MainWindow::onClickCopy()
//{

//}

void MainWindow::onClickPaste()
{

}

void MainWindow::onPushBtone()
{
    JudgeZero();
      contextStr = contextStr + "1";
      showEdit->setText(contextStr);

}

void MainWindow::onPushBttwo()
{
    JudgeZero();
      contextStr = contextStr + "2";
      showEdit->setText(contextStr);

}

void MainWindow::onPushBtthree()
{
    JudgeZero();
      contextStr = contextStr + "3";
      showEdit->setText(contextStr);

}

void MainWindow::onPushBtdiv()
{
    BeforeOperator(DIV);

}

void MainWindow::onPushBtBack()
{

}

void MainWindow::onPushBtRemove()
{
    edittext = contextStr.toInt();
    //qDebug()<<edittext<<"!"<<endl;
    edittext = edittext / 10;
    //qDebug()<<edittext<<"!"<<endl;
    contextStr = QString::number(edittext);
    showEdit->setText(contextStr);



}

void MainWindow::onPushBtClear()
{
    contextStr.clear();
    showEdit->setText(contextStr);

}

void MainWindow::onPushBtSum()
{
    BeforeOperator(ADD);

}

void MainWindow::onPushBtSeven()
{
    JudgeZero();
      contextStr = contextStr + "7";
      showEdit->setText(contextStr);

}

void MainWindow::onPushBtEight()
{
    JudgeZero();
      contextStr = contextStr + "8";
      showEdit->setText(contextStr);

}

void MainWindow::onPushBtNine()
{
    JudgeZero();
      contextStr = contextStr + "9";
      showEdit->setText(contextStr);

}

void MainWindow::onPushBtDec()
{
    BeforeOperator(DEC);

}

void MainWindow::onPushBtMul()
{
    BeforeOperator(MUL);

}

void MainWindow::onPushBtFour()
{
    JudgeZero();
      contextStr = contextStr + "4";
      showEdit->setText(contextStr);

}

void MainWindow::onPushBtFive()
{
    JudgeZero();
      contextStr = contextStr + "5";
      showEdit->setText(contextStr);

}

void MainWindow::onPushBtSix()
{
    JudgeZero();
      contextStr = contextStr + "6";
      showEdit->setText(contextStr);

}

void MainWindow::onPushBtSign()
{

}

void MainWindow::onPushBtPoint()
{
    JudgeZero();
      contextStr = contextStr + ".";
      showEdit->setText(contextStr);

}

void MainWindow::onPushBtZero()
{
    JudgeZero();
      contextStr = contextStr + "0";
      showEdit->setText(contextStr);

}

void MainWindow::onPushBtEqual()
{
    QString strTem;
       if(contextStr.size() == 0||contextStr == "-")
       {
           return;
       }
       //第一步，先将数据给第二个操作数
        secondOpeNum = contextStr.toDouble();
        int const add = 1;
        int const dec = 2;
        int const mul= 3;
        int const div = 4;
        switch(operat)
        {


           case 0:
           break;
           case add:
           {
               result = secondOpeNum + firstOpeNum;
               strTem = QString::number(result);
               resultEdit->setText(strTem);
           }
            break;
            case dec:
           {
                result =  firstOpeNum -secondOpeNum ;
                strTem = QString::number(result);
               resultEdit->setText(strTem);
            }
            break;
           case mul:
           {
                result = secondOpeNum*firstOpeNum;
               strTem = QString::number(result);
               resultEdit->setText(strTem);
           }
            break;
           case div:
           {
               if(secondOpeNum*2 == 0)
               {
                   QMessageBox::information(this,"错误","被除数不能为0");
                   return;
               }
               result = firstOpeNum/secondOpeNum;
               strTem = QString::number(result);
               resultEdit->setText(strTem);
            }
            break;
        }
        init();
        contextStr.clear();
        showEdit->setText(contextStr);

}
void MainWindow::JudgeZero()
{
    if(contextStr.size() == 1)
    {
        if(contextStr.contains("0"))
        {
            contextStr.clear();
        }
    }
}
//按键时间响应函数
void MainWindow::keyPressEvent(QKeyEvent * e)
{
    int iKey = e->key();
    switch(iKey)
    {
        case Qt::Key_0:onPushBtZero(); break;
        case Qt::Key_1:onPushBtone(); break;
        case Qt::Key_2:onPushBttwo(); break;
        case Qt::Key_3:onPushBtthree(); break;
        case Qt::Key_4:onPushBtFour(); break;
        case Qt::Key_5:onPushBtFive(); break;
        case Qt::Key_6:onPushBtSix(); break;
        case Qt::Key_7:onPushBtSeven(); break;
        case Qt::Key_8:onPushBtEight(); break;
        case Qt::Key_9:onPushBtNine(); break;
        case Qt::Key_Backspace:onPushBtBack();break;
        case Qt::Key_Equal:onPushBtEqual();break;
        case Qt::Key_Plus:onPushBtSum();break;
        case Qt::Key_Period:onPushBtPoint();break;
        case Qt::Key_Minus:onPushBtDec();break;
        case Qt::Key_Asterisk:onPushBtMul();break;
        case Qt::Key_Slash:onPushBtdiv();break;
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

