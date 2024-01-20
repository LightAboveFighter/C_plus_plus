#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QPalette>
#include <QVector>
#include <QFrame>
#include <QLayout>
#include <QString>
#include <QObject>
#include <QColor>

// QWidget w;
//     w.setMinimumSize(600,600);
//     QWidget* play_field = new QWidget(&w);
//     play_field->setMinimumSize(100,100);

//     QVector<QVector<QPushButton*>> field_links(9, QVector<QPushButton*>(9));
//     QGridLayout* field = new QGridLayout(play_field);
//     field->setSpacing(2);
//     field->setMargin(2);
//     QPalette base_color;
//     QPalette changed_color;
//     for (int i = 0; i < 9; ++i) {
//         field->setRowStretch(i, 1);

//         for ( int j = 0; j < 9; ++j) {
//             QPushButton* t = new QPushButton();  //QString::number(j)
//             // t->setFlat(true);
//             QWidget* cup = new QWidget();
//             if (i == 0 && j == 0) {
//                 base_color.setColor(t->backgroundRole(), Qt::black);
//                 changed_color.setColor(t->backgroundRole(), Qt::red);
//             }

//             cup->setPalette(base_color);
//             cup->setMinimumSize(11, 11);
//             cup->setMaximumSize(51, 51);
//             cup->autoFillBackground();
//             t->setMinimumSize(10, 10);
//             t->setMaximumSize(50, 50);
//             field->addWidget(t, i, j);
//             field->addWidget(cup, i, j);
//             field_links[i][j] = t;
//             field->setColumnStretch(j, 1);
//             // QObject::connect(t, SIGNAL (clicked()), &a, SLOT (quit()));
//             QObject::connect(t, SIGNAL (clicked()), cup, SLOT (hide()));
//         }
//     }
//     // for (QVector<QPushButton*> i: field_links) {
//     //     for (QPushButton* j: i) {

//     //         for (QVector<QPushButton*> ii: field_links) {
//     //             for (QPushButton* jj: ii) {
//     //                 if (j != jj) QObject::connect(j, SIGNAL (clicked()), jj, SLOT ( show()));
//     //             }
//     //         }
//     //     }
//     // }
//     play_field->resize(500, 500);
//     play_field->move(200, 50);
//     // play_field->setGeometry(175, 25, 550, 550);
//     // play_field->resize(225, 550);

//     play_field->setLayout(field);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    QPushButton* t = new QPushButton(&w);
    t->setFlat(true);
    QWidget* cup = new QWidget(&w);
    QPalette pal;
    pal.setColor(cup->backgroundRole(), Qt::red);
    cup->autoFillBackground();
    cup->setPalette(pal);
    cup->resize(20, 20);
    QObject::connect(t, SIGNAL (clicked()), &a, SLOT (quit()));


    w.resize(1200, 600);
    w.show();
    return a.exec();
    //QDialog статические методы, могу сделать так, чтобы было модальное диалоговое окно
}
