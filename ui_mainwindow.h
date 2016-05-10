/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *bottomFrame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *inputLayout;
    QLabel *excelLbl;
    QLineEdit *excelPathLe;
    QPushButton *excelPathBtn;
    QHBoxLayout *outputLayout;
    QLabel *xmlLbl;
    QLineEdit *xmlPathLe;
    QPushButton *xmlPathBtn;
    QHBoxLayout *outputLayout_3;
    QLabel *searchLbl;
    QLineEdit *searchPathLe;
    QPushButton *searchPathBtn;
    QFrame *topFrame;
    QLabel *logoLabel;
    QLabel *nameLabel;
    QLabel *descriptionLabel;
    QProgressBar *progressBar;
    QPushButton *convertButton;
    QListWidget *listWidget;
    QComboBox *machineryCb;
    QPushButton *fitBtn;
    QLabel *statusLabel;
    QLabel *excelLbl_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(621, 521);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QLatin1String("QListWidget {\n"
"  background-color: \"white\";\n"
"  font-size: 10pt;\n"
"  color: \"gray\";\n"
"  font-size: 9pt;\n"
"  font-family: \"Arial\";\n"
"  border-radius: 5px;\n"
"  border-width: 2px solid lightgray;\n"
"}\n"
"\n"
"#centralWidget QScrollBar:vertical {\n"
"  border: none;\n"
"  background: \"transparent\";\n"
"  width: 15px;\n"
"  margin: 20px 0px 20px 0px;\n"
"}\n"
"\n"
"#centralWidget QScrollBar::handle:vertical {\n"
"  background: \"lightgray\";\n"
"  min-height: 20px;\n"
"  border-radius: 2px;\n"
"}\n"
"\n"
"#centralWidget QScrollBar::add-line:vertical {\n"
"  image: url(:/images/images/downArrow.png);\n"
"  background: \"lightgray\";\n"
"  height: 15px;\n"
"  subcontrol-position: bottom;\n"
"  subcontrol-origin: margin;\n"
"  border-radius: 2px;\n"
"}\n"
"\n"
"#centralWidget QScrollBar::sub-line:vertical {\n"
"  image: url(:/images/images/upArrow.png);\n"
"  background: \"lightgray\";\n"
"  height: 15px;\n"
"  subcontrol-position: top;\n"
"  subcontrol-origin: margin;\n"
"  border-radius: 2px"
                        ";\n"
"}\n"
"\n"
"QMessageBox QPushButton {\n"
"color: \"gray\";\n"
"border-radius: 5px;\n"
"border: 1px solid lightgray;\n"
"background: \"white\";\n"
"min-width: 80px;\n"
"min-height: 25px;\n"
"}\n"
"\n"
"QMessageBox QPushButton:hover {\n"
"background: \"lightgray\";\n"
"color: \"white\";\n"
"width: 300px;\n"
"}\n"
"\n"
"QMessageBox QPushButton:pressed {\n"
"border: 1px solid \"gray\";\n"
"background: #A9A9A9 ;\n"
"}\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("QComboBox {\n"
"	border: 1px solid lightgray;\n"
"	border-radius: 5px;\n"
"	padding: 1px 18px 1px 3px;\n"
"	min-width: 6em;\n"
"	color: \"gray\";\n"
"	background-color: \"white\";\n"
"	margin: 0 0 0 0;\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"	background: \"green\"}\n"
"	QComboBox:!editable {\n"
"	background: \"white\"\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"	background: \"lightgray\";\n"
"	color: \"white\";\n"
"}\n"
"\n"
"QComboBox:on{\n"
"	padding-top: 3px;\n"
"	padding-left: 4px;\n"
"	background-color:#A9A9A9 ;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	subcontrol-origin: padding;\n"
"	subcontrol-position: center right;\n"
"	width: 50px;\n"
"	height: 50px;\n"
"	border-width: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow{\n"
"	image: url(:/images/images/arrow.png);\n"
"	height: 70px;\n"
"	width:  70px;\n"
"}\n"
"\n"
"QComboBox::down-arrow:on{\n"
"	top: 1px;\n"
"	left: 1px;\n"
"}\n"
"\n"
"QComboBox QListView{\n"
"	border-width: 1px;\n"
"	border-color: darkgray;\n"
"	border-style: solid;\n"
"	color: gray;\n"
"	backgrou"
                        "nd-color: white;\n"
"}\n"
"\n"
""));
        bottomFrame = new QFrame(centralWidget);
        bottomFrame->setObjectName(QStringLiteral("bottomFrame"));
        bottomFrame->setGeometry(QRect(0, 420, 621, 101));
        bottomFrame->setStyleSheet(QLatin1String("#bottomFrame {\n"
"border: none;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #a6a6a6, stop: 0.08 #7f7f7f,\n"
"stop: 0.49999 #717171);\n"
"border-top-right-radius: 10px;\n"
"border-top-left-radius:10px;\n"
"}\n"
""));
        bottomFrame->setFrameShape(QFrame::StyledPanel);
        bottomFrame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(bottomFrame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 8, 591, 83));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        inputLayout = new QHBoxLayout();
        inputLayout->setSpacing(6);
        inputLayout->setObjectName(QStringLiteral("inputLayout"));
        excelLbl = new QLabel(layoutWidget);
        excelLbl->setObjectName(QStringLiteral("excelLbl"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(excelLbl->sizePolicy().hasHeightForWidth());
        excelLbl->setSizePolicy(sizePolicy);
        excelLbl->setMinimumSize(QSize(135, 0));
        excelLbl->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        excelLbl->setFont(font);
        excelLbl->setToolTipDuration(-1);

        inputLayout->addWidget(excelLbl);

        excelPathLe = new QLineEdit(layoutWidget);
        excelPathLe->setObjectName(QStringLiteral("excelPathLe"));
        excelPathLe->setMinimumSize(QSize(0, 25));
        excelPathLe->setMaximumSize(QSize(16777215, 25));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(9);
        excelPathLe->setFont(font1);
        excelPathLe->setToolTipDuration(-1);
        excelPathLe->setAutoFillBackground(false);
        excelPathLe->setStyleSheet(QLatin1String("QLineEdit {\n"
"    font-size: 9pt; \n"
"    color: \"gray\";\n"
"    font-family: \"Arial\";\n"
"	border-radius: 5px;\n"
"    border-width: 2px solid lightgray;\n"
"}"));
        excelPathLe->setFrame(true);
        excelPathLe->setReadOnly(false);
        excelPathLe->setPlaceholderText(QStringLiteral(""));
        excelPathLe->setClearButtonEnabled(true);

        inputLayout->addWidget(excelPathLe);

        excelPathBtn = new QPushButton(layoutWidget);
        excelPathBtn->setObjectName(QStringLiteral("excelPathBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(excelPathBtn->sizePolicy().hasHeightForWidth());
        excelPathBtn->setSizePolicy(sizePolicy1);
        excelPathBtn->setMinimumSize(QSize(30, 25));
        excelPathBtn->setMaximumSize(QSize(30, 25));
        excelPathBtn->setStyleSheet(QLatin1String("QPushButton {\n"
"color: \"gray\";\n"
"border: 1px solid lightgray;\n"
"border-radius: 5px;\n"
"background: \"white\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: \"lightgray\";\n"
"color: \"white\";\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"border: 1px solid \"gray\";\n"
"background: #A9A9A9 ;\n"
"}\n"
""));

        inputLayout->addWidget(excelPathBtn);


        verticalLayout->addLayout(inputLayout);

        outputLayout = new QHBoxLayout();
        outputLayout->setSpacing(6);
        outputLayout->setObjectName(QStringLiteral("outputLayout"));
        xmlLbl = new QLabel(layoutWidget);
        xmlLbl->setObjectName(QStringLiteral("xmlLbl"));
        sizePolicy.setHeightForWidth(xmlLbl->sizePolicy().hasHeightForWidth());
        xmlLbl->setSizePolicy(sizePolicy);
        xmlLbl->setMinimumSize(QSize(156, 0));
        xmlLbl->setMaximumSize(QSize(16777215, 16777215));
        xmlLbl->setFont(font);

        outputLayout->addWidget(xmlLbl);

        xmlPathLe = new QLineEdit(layoutWidget);
        xmlPathLe->setObjectName(QStringLiteral("xmlPathLe"));
        xmlPathLe->setMinimumSize(QSize(0, 25));
        xmlPathLe->setMaximumSize(QSize(16777215, 25));
        xmlPathLe->setFont(font1);
        xmlPathLe->setAutoFillBackground(false);
        xmlPathLe->setStyleSheet(QLatin1String("QLineEdit {\n"
"    font-size: 9pt; \n"
"    color: \"gray\";\n"
"    font-family: \"Arial\";\n"
"	border-radius: 5px;\n"
"    border-width: 2px solid lightgray;\n"
"}"));
        xmlPathLe->setReadOnly(false);
        xmlPathLe->setClearButtonEnabled(true);

        outputLayout->addWidget(xmlPathLe);

        xmlPathBtn = new QPushButton(layoutWidget);
        xmlPathBtn->setObjectName(QStringLiteral("xmlPathBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(xmlPathBtn->sizePolicy().hasHeightForWidth());
        xmlPathBtn->setSizePolicy(sizePolicy2);
        xmlPathBtn->setMinimumSize(QSize(30, 25));
        xmlPathBtn->setMaximumSize(QSize(30, 25));
        xmlPathBtn->setStyleSheet(QLatin1String("QPushButton {\n"
"color: \"gray\";\n"
"border: 1px solid lightgray;\n"
"border-radius: 5px;\n"
"background: \"white\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: \"lightgray\";\n"
"color: \"white\";\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"border: 1px solid \"gray\";\n"
"background: #A9A9A9 ;\n"
"}"));

        outputLayout->addWidget(xmlPathBtn);


        verticalLayout->addLayout(outputLayout);

        outputLayout_3 = new QHBoxLayout();
        outputLayout_3->setSpacing(6);
        outputLayout_3->setObjectName(QStringLiteral("outputLayout_3"));
        searchLbl = new QLabel(layoutWidget);
        searchLbl->setObjectName(QStringLiteral("searchLbl"));
        sizePolicy.setHeightForWidth(searchLbl->sizePolicy().hasHeightForWidth());
        searchLbl->setSizePolicy(sizePolicy);
        searchLbl->setMinimumSize(QSize(156, 0));
        searchLbl->setMaximumSize(QSize(16777215, 16777215));
        searchLbl->setFont(font);

        outputLayout_3->addWidget(searchLbl);

        searchPathLe = new QLineEdit(layoutWidget);
        searchPathLe->setObjectName(QStringLiteral("searchPathLe"));
        searchPathLe->setMinimumSize(QSize(0, 25));
        searchPathLe->setMaximumSize(QSize(16777215, 25));
        searchPathLe->setFont(font1);
        searchPathLe->setAutoFillBackground(false);
        searchPathLe->setStyleSheet(QLatin1String("QLineEdit {\n"
"    font-size: 9pt; \n"
"    color: \"gray\";\n"
"    font-family: \"Arial\";\n"
"	border-radius: 5px;\n"
"    border-width: 2px solid lightgray;\n"
"}"));
        searchPathLe->setReadOnly(false);
        searchPathLe->setClearButtonEnabled(true);

        outputLayout_3->addWidget(searchPathLe);

        searchPathBtn = new QPushButton(layoutWidget);
        searchPathBtn->setObjectName(QStringLiteral("searchPathBtn"));
        sizePolicy2.setHeightForWidth(searchPathBtn->sizePolicy().hasHeightForWidth());
        searchPathBtn->setSizePolicy(sizePolicy2);
        searchPathBtn->setMinimumSize(QSize(30, 25));
        searchPathBtn->setMaximumSize(QSize(30, 25));
        searchPathBtn->setStyleSheet(QLatin1String("QPushButton {\n"
"color: \"gray\";\n"
"border: 1px solid lightgray;\n"
"border-radius: 5px;\n"
"background: \"white\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: \"lightgray\";\n"
"color: \"white\";\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"border: 1px solid \"gray\";\n"
"background: #A9A9A9 ;\n"
"}"));

        outputLayout_3->addWidget(searchPathBtn);


        verticalLayout->addLayout(outputLayout_3);

        topFrame = new QFrame(centralWidget);
        topFrame->setObjectName(QStringLiteral("topFrame"));
        topFrame->setGeometry(QRect(0, 0, 621, 101));
        topFrame->setStyleSheet(QLatin1String("#topFrame {\n"
"border: none;\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #a6a6a6, stop: 0.08 #7f7f7f,\n"
"stop: 0.39999 #717171, stop: 0.4 #626262,\n"
"stop: 0.9 #4c4c4c, stop: 1 #333333);\n"
"border-bottom-right-radius: 10px;\n"
"border-bottom-left-radius:10px;\n"
"}\n"
"\n"
"#topFrame QPushButton {\n"
"color: #333;\n"
"border: 2px solid #555;\n"
"border-radius: 11px;\n"
"padding: 5px;\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #888);\n"
"}\n"
"\n"
"#topFrame QPushButton:hover {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #bbb);\n"
"}\n"
"\n"
"#topFrame QPushButton:pressed {\n"
"background: qradialgradient(cx: 0.4, cy: -0.1,\n"
"fx: 0.4, fy: -0.1,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #ddd);\n"
"}"));
        topFrame->setFrameShape(QFrame::StyledPanel);
        topFrame->setFrameShadow(QFrame::Raised);
        logoLabel = new QLabel(topFrame);
        logoLabel->setObjectName(QStringLiteral("logoLabel"));
        logoLabel->setGeometry(QRect(10, 0, 101, 101));
        logoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/images/icon.ico")));
        logoLabel->setScaledContents(true);
        nameLabel = new QLabel(topFrame);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(120, 15, 251, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(36);
        nameLabel->setFont(font2);
        nameLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/images/name.png")));
        descriptionLabel = new QLabel(topFrame);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));
        descriptionLabel->setGeometry(QRect(120, 55, 291, 21));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(4);
        font3.setBold(false);
        font3.setWeight(50);
        descriptionLabel->setFont(font3);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 350, 451, 31));
        progressBar->setMaximumSize(QSize(16777211, 16777215));
        progressBar->setStyleSheet(QLatin1String("QProgressBar {\n"
"border: 1px solid lightgray;\n"
"border-radius: 5px;\n"
"padding: 1px;\n"
"color: \"white\";\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1,\n"
"stop: 0 #06A6DA, \n"
"stop: 0.5 #1E90FF ,\n"
"stop: 1 #238 );\n"
"border-radius: 3px;\n"
"border: 1px solid black;\n"
"}"));
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        convertButton = new QPushButton(centralWidget);
        convertButton->setObjectName(QStringLiteral("convertButton"));
        convertButton->setGeometry(QRect(468, 350, 141, 61));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        convertButton->setFont(font4);
        convertButton->setStyleSheet(QLatin1String("QPushButton {\n"
"color: \"gray\";\n"
"border-radius: 5px;\n"
"border: 1px solid lightgray;\n"
"background: \"white\";\n"
"min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: \"lightgray\";\n"
"color: \"white\";\n"
"width: 300px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"border: 1px solid \"gray\";\n"
"background: #A9A9A9 ;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/convert.png"), QSize(), QIcon::Normal, QIcon::Off);
        convertButton->setIcon(icon1);
        convertButton->setIconSize(QSize(30, 30));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 150, 601, 191));
        listWidget->setStyleSheet(QStringLiteral(""));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget->setAlternatingRowColors(true);
        machineryCb = new QComboBox(centralWidget);
        machineryCb->setObjectName(QStringLiteral("machineryCb"));
        machineryCb->setEnabled(false);
        machineryCb->setGeometry(QRect(130, 110, 261, 31));
        QFont font5;
        font5.setFamily(QStringLiteral("Calibri"));
        font5.setPointSize(12);
        machineryCb->setFont(font5);
        fitBtn = new QPushButton(centralWidget);
        fitBtn->setObjectName(QStringLiteral("fitBtn"));
        fitBtn->setEnabled(false);
        fitBtn->setGeometry(QRect(400, 110, 211, 31));
        QFont font6;
        font6.setFamily(QStringLiteral("Calibri"));
        font6.setPointSize(12);
        font6.setBold(false);
        font6.setWeight(50);
        fitBtn->setFont(font6);
        fitBtn->setStyleSheet(QLatin1String("QPushButton {\n"
"color: \"gray\";\n"
"border-radius: 5px;\n"
"border: 1px solid lightgray;\n"
"background: \"white\";\n"
"min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background: \"lightgray\";\n"
"color: \"white\";\n"
"width: 300px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"border: 1px solid \"gray\";\n"
"background: #A9A9A9 ;\n"
"}\n"
""));
        statusLabel = new QLabel(centralWidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(10, 390, 341, 20));
        statusLabel->setStyleSheet(QLatin1String("QLabel {\n"
"border: none;\n"
"background: \"transparent\";\n"
"color: \"gray\";\n"
"font-size: 9pt;\n"
"font-family: \"Arial\";\n"
"font-weight: bold;\n"
"}"));
        excelLbl_2 = new QLabel(centralWidget);
        excelLbl_2->setObjectName(QStringLiteral("excelLbl_2"));
        excelLbl_2->setGeometry(QRect(10, 110, 191, 31));
        sizePolicy.setHeightForWidth(excelLbl_2->sizePolicy().hasHeightForWidth());
        excelLbl_2->setSizePolicy(sizePolicy);
        excelLbl_2->setMinimumSize(QSize(135, 0));
        excelLbl_2->setMaximumSize(QSize(16777215, 16777215));
        excelLbl_2->setFont(font);
        excelLbl_2->setToolTipDuration(-1);
        excelLbl_2->setStyleSheet(QStringLiteral("color: gray"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "XML Converter", 0));
#ifndef QT_NO_TOOLTIP
        excelLbl->setToolTip(QApplication::translate("MainWindow", "Scie\305\274ka przeszukiwania plik\303\263w *.PDF", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        excelLbl->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        excelLbl->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Scie\305\274ka do harmonogramu:</span></p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        excelPathLe->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        excelPathLe->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        excelPathLe->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        excelPathLe->setText(QString());
        excelPathBtn->setText(QApplication::translate("MainWindow", "...", 0));
#ifndef QT_NO_TOOLTIP
        xmlLbl->setToolTip(QApplication::translate("MainWindow", "\305\232cie\305\274ka zapisu wyszukanych plik\303\263w *.PDF", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        xmlLbl->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        xmlLbl->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">\305\232cie\305\274ka do pliku XML:                                 </span></p></body></html>", 0));
#ifndef QT_NO_WHATSTHIS
        xmlPathLe->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        xmlPathBtn->setText(QApplication::translate("MainWindow", "...", 0));
#ifndef QT_NO_TOOLTIP
        searchLbl->setToolTip(QApplication::translate("MainWindow", "\305\232cie\305\274ka zapisu wyszukanych plik\303\263w *.PDF", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        searchLbl->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        searchLbl->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">\305\232cie\305\274ka wyszukiwania:</span></p></body></html>", 0));
#ifndef QT_NO_WHATSTHIS
        searchPathLe->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        searchPathLe->setText(QApplication::translate("MainWindow", "//k1/Produkcja/TECHNOLODZY/BAZA DO TXT/txt", 0));
        searchPathBtn->setText(QApplication::translate("MainWindow", "...", 0));
        logoLabel->setText(QString());
        nameLabel->setText(QString());
        descriptionLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:8pt; color:#ffffff;\">Konwersja do formatu XML</span></p></body></html>", 0));
        convertButton->setText(QApplication::translate("MainWindow", "Konwertuj", 0));
        fitBtn->setText(QApplication::translate("MainWindow", "Przyporz\304\205dkuj", 0));
        statusLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        excelLbl_2->setToolTip(QApplication::translate("MainWindow", "Scie\305\274ka przeszukiwania plik\303\263w *.PDF", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        excelLbl_2->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        excelLbl_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Wybierz maszyn\304\231:</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
