#include <QApplication>
#include <QWidget>
#include <QPainter>

class MyWidget : public QWidget {
public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        this->resize(200, 200);  // Set the size of the window
    }

private:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.fillRect(rect(), Qt::green);  // Fill the background with green

        painter.setBrush(Qt::red);  // Set the brush to red for the circle
        painter.drawEllipse(QPoint(100, 100), 50, 50);  // Draw a red circle
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWidget widget;
    widget.show();

    return app.exec();
}


/*
#include <QApplication>
#include <QWidget>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setFixedSize(200, 100);

    QLabel *label = new QLabel("Hello World", &window);
    label->setAlignment(Qt::AlignCenter);

    window.show();

    return app.exec();
}
*/