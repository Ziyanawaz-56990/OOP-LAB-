#include <iostream>
using namespace std;

class Document {
public:
    virtual void exportFile() {
        cout << "Exporting document..." << endl;
    }

    virtual ~Document() {}
};

class PDFDocument : public Document {
public:
    void exportFile() override {
        cout << "Exporting as PDF (.pdf)" << endl;
    }
};

class TextDocument : public Document {
public:
    void exportFile() override {
        cout << "Exporting as Text (.txt)" << endl;
    }
};

class CSVDocument : public Document {
public:
    void exportFile() override {
        cout << "Exporting as CSV (.csv)" << endl;
    }
};

int main() {
    PDFDocument pdf;
    TextDocument txt;
    CSVDocument csv;

    Document* doc;

    doc = &pdf;
    doc->exportFile();

    doc = &txt;
    doc->exportFile();

    doc = &csv;
    doc->exportFile();

    return 0;
}