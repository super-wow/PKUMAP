/********************************************************************************
** Form generated from reading UI file 'map.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_H
#define UI_MAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_map
{
public:
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView_map;

    void setupUi(QWidget *map)
    {
        if (map->objectName().isEmpty())
            map->setObjectName("map");
        map->resize(378, 328);
        verticalLayout = new QVBoxLayout(map);
        verticalLayout->setObjectName("verticalLayout");
        graphicsView_map = new QGraphicsView(map);
        graphicsView_map->setObjectName("graphicsView_map");

        verticalLayout->addWidget(graphicsView_map);


        retranslateUi(map);

        QMetaObject::connectSlotsByName(map);
    } // setupUi

    void retranslateUi(QWidget *map)
    {
        map->setWindowTitle(QCoreApplication::translate("map", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class map: public Ui_map {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_H
