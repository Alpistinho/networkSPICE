#include "plotwindow.h"
#include <iostream>

/* PlotWindow constructor */
PlotWindow::PlotWindow() {
    QWidget *widget = new QWidget; // main widget
    setCentralWidget(widget);

    /* Setting horizontalLayout */
    horizontalLayout = new QHBoxLayout();
    labelNode = new QLabel(tr("<b>Node to be analyzed:</b>")); // label node
    horizontalLayout->addWidget(labelNode); // adds labelNode
    chosenNode = new QLineEdit("1"); // node to be analyzed
    horizontalLayout->addWidget(chosenNode); // adds chosenNode
    freqButton = new QPushButton("Frequency domain"); // analyze in freq domain
    horizontalLayout->addWidget(freqButton); // adds freqButton
    timeButton = new QPushButton("Time domain"); // analyze in time domain
    horizontalLayout->addWidget(timeButton); // adds freqButton

    /* Setting verticalLayout */
    verticalLayout = new QVBoxLayout;
    verticalLayout->addLayout(horizontalLayout); // adds horizontalLayout
    widget->setLayout(verticalLayout); // sets verticalLayout to widget

    /* Sets signal and slot for freqButton */
    connect(freqButton, SIGNAL(clicked()), this, SLOT(analyzeFreq()));
    connect(timeButton, SIGNAL(clicked()), this, SLOT(analyzeTime()));

    /* Declaring plots (module and phase) */
    modulePlot = new QCustomPlot; // modules plot
    phasePlot = new QCustomPlot; // phases plot

    /* Edit widget values */
    maximizedWindow = false;
    setWindowTitle(tr("SPICE-16")); // window title
} // end constructor

/* Chooses node and show frequency-domain response */
void PlotWindow::analyzeFreq() {
    node = atoi(chosenNode->text().toStdString().c_str());

    /* Local variables */
    std::ifstream inFile("freq_results.txt"); // input file
    std::string blank; // stores \n after reading n
    double d; // stores read element from file
    double x_max, x_min, y1_max, y1_min, y2_max, y2_min; // limits to the plots
    x_max = x_min = y1_max = y1_min = y2_max = y2_min = -1;
    int counter = 0; // counts position in element-reading

    /* Storing data from file */
    inFile >> nElemInLine; // first element of file is n
    std::getline(inFile, blank); // \n after n
    while (inFile >> d) { // loop through file
        if (counter == 0) { // it's a frequency value
            d /= (2*M_PI);
            vect_x.push_back(d);
            if(-1 == x_min || d < x_min)
                x_min = d;
            if(-1 == x_max || d > x_max)
                x_max = d;
        }
        else if (counter == 2 * node - 1) { // it's a module value
            if (d > 0) {
                d = 20 * log10(d);
            }
            vect_y1.push_back(d);
            if(-1 == y1_min || d < y1_min)
                y1_min = d;
            if(-1 == y1_max || d > y1_max)
                y1_max = d;
        }
        else if (counter == 2 * node) { // it's a phase value
            vect_y2.push_back(d);
            if(-1 == y2_min || d < y2_min)
                y2_min = d;
            if(-1 == y2_max || d > y2_max)
                y2_max = d;
        } // end if-else
        counter = (counter + 1) % nElemInLine;
        if (inFile.peek() == ',') { // ignores commas
            inFile.ignore();
        } // end if
    } // end while
    inFile.close();

    /* If constant, set a margin of 0.01 just to make possible to visualize */
    if(y1_min == y1_max) { // y1 margins
        y1_min -= 0.01;
        y1_max += 0.01;
    }
    if(y2_min == y2_max) { // y2 margins
        y2_min -= 0.01;
        y2_max += 0.01;
    }

    /* Converting vectors to QVector */
    x = QVector<double>::fromStdVector(vect_x);
    y1 = QVector<double>::fromStdVector(vect_y1);
    y2 = QVector<double>::fromStdVector(vect_y2);

    /* Plotting module response */
    // create graph and assign data to it
    modulePlot->addGraph();
    modulePlot->graph(0)->setData(x, y1);
    // give the axes some labels
    modulePlot->xAxis->setLabel("Frequency (Hz)");
    modulePlot->yAxis->setLabel("Module (dB)");
    // set axes ranges, so we see all data
    modulePlot->xAxis->setRange(x_min, x_max);
    modulePlot->xAxis->setScaleType(QCPAxis::stLogarithmic);
    modulePlot->yAxis->setRange(y1_min, y1_max);
    modulePlot->replot();

    /* Plotting phase response */
    phasePlot->show();
    // create graph and assign data to it
    phasePlot->addGraph();
    phasePlot->graph(0)->setData(x, y2);
    // give the axes some labels
    phasePlot->xAxis->setLabel("Frequency (Hz)");
    phasePlot->yAxis->setLabel("Phase (°)");
    // set axes ranges, so we see all data
    phasePlot->xAxis->setRange(x_min, x_max);
    phasePlot->xAxis->setScaleType(QCPAxis::stLogarithmic);
    phasePlot->yAxis->setRange(y2_min, y2_max);
    phasePlot->replot();

    /* Adding plots to layout */
    verticalLayout->addWidget(modulePlot); // adds module plot to layout
    verticalLayout->addWidget(phasePlot); // adds phase plot to layout

    vect_x.clear();
    vect_y1.clear();
    vect_y2.clear();
    x_max = x_min = y1_max = y1_min = y2_max = y2_min = -1;

    if (!maximizedWindow) {
        this->showMaximized();
        maximizedWindow = true;
    }
} // end analyzeFreq function

/* Chooses node and show frequency-domain response */
void PlotWindow::analyzeTime() {
    node = atoi(chosenNode->text().toStdString().c_str());

    /* Local variables */
    std::ifstream inFile("time_results.txt"); // input file
    std::string blank; // stores \n after reading n
    double d; // stores read element from file
    double x_max, x_min, y1_max, y1_min; // limits to the plots
    x_max = x_min = y1_max = y1_min = 0;
    int counter = 0; // counts position in element-reading

    /* Storing data from file */
    inFile >> nElemInLine; // first element of file is n
    std::getline(inFile, blank); // \n after n
    while (inFile >> d) { // loop through file
        if (counter == 0) { // it's a time value
            vect_x.push_back(d);
            if(-1 == x_min || d < x_min)
                x_min = d;
            if(-1 == x_max || d > x_max)
                x_max = d;
        }
        else if (counter == node) {
            vect_y1.push_back(d);
            if(d < y1_min)
                y1_min = d;
            if(d > y1_max)
                y1_max = d;
        }
        counter = (counter + 1) % nElemInLine;
        if (inFile.peek() == ',') { // ignores commas
            inFile.ignore();
        } // end if
    } // end while
    inFile.close();

    /* If constant, set a margin of 0.01 just to make possible to visualize */
    if(y1_min == y1_max) { // y1 margins
        y1_min -= 0.01;
        y1_max += 0.01;
    }

    /* Converting vectors to QVector */
    x = QVector<double>::fromStdVector(vect_x);
    y1 = QVector<double>::fromStdVector(vect_y1);

    phasePlot->hide();

    /* Plotting module response */
    // create graph and assign data to it
    modulePlot->addGraph();
    modulePlot->graph(0)->setData(x, y1);
    // give the axes some labels
    modulePlot->xAxis->setLabel("Time (s)");
    modulePlot->yAxis->setLabel("Module");
    // set axes ranges, so we see all data
    modulePlot->xAxis->setRange(x_min, x_max);
    modulePlot->xAxis->setScaleType(QCPAxis::stLinear);
    modulePlot->yAxis->setRange(y1_min, y1_max);
    modulePlot->replot();

    /* Adding plots to layout */
    verticalLayout->addWidget(modulePlot); // adds module plot to layout

    vect_x.clear();
    vect_y1.clear();
    x_max = x_min = y1_max = y1_min = -1;

    if (!maximizedWindow) {
        this->showMaximized();
        maximizedWindow = true;
    }
} // end analyzeTime function
