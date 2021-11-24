import time
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QLabel, QLineEdit, QGridLayout, QMessageBox
import sys


class Thermo(QWidget):

    def __init__(self):
        super(Thermo, self).__init__()
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Air Quality Monitoring')
        self.setGeometry(300, 300, 300, 300)
        self.setStyleSheet("background-image=")
        

def main():
    app = QApplication([sys.argv])
    ex = Thermo()
    ex.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()