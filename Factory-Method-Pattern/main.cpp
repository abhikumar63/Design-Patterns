#include <iostream>
using namespace std;

class IDocumentExporter {
public:
    virtual void exportReport(const std::string& content) = 0;
};

class PDFExporter : public IDocumentExporter {
public:
    void exportReport(const std::string& content) override {
        std::cout << "Exporting as PDF: " << content << "\n";
    }
};

class HTMLExporter : public IDocumentExporter {
public:
    void exportReport(const std::string& content) override {
        std::cout << "Exporting as HTML: <html><body>" << content << "</body></html>\n";
    }
};

class TextExporter : public IDocumentExporter {
public:
    void exportReport(const std::string& content) override {
        std::cout << "Exporting as Text: " << content << "\n";
    }
};

class IExporterFactory {
public:
    virtual IDocumentExporter* createExporter() = 0;
};

class PDFExporterFactory : public IExporterFactory {
public:
    IDocumentExporter* createExporter() override {
        return new PDFExporter();
    }
};

class HTMLExporterFactory : public IExporterFactory {
public:
    IDocumentExporter* createExporter() override {
        return new HTMLExporter();
    }
};

class TextExporterFactory : public IExporterFactory {
public:
    IDocumentExporter* createExporter() override {
        return new TextExporter();
    }
};

void generateReport(IExporterFactory* factory, const std::string& content) {
    IDocumentExporter* exporter = factory->createExporter();
    exporter->exportReport(content);
    delete exporter;
}

int main() {
    PDFExporterFactory pdfFactory;
    HTMLExporterFactory htmlFactory;
    TextExporterFactory textFactory;

    std::string report = "Design Pattern Summary";
    generateReport(&pdfFactory, report);
    generateReport(&htmlFactory, report);
    generateReport(&textFactory, report);
    return 0;
}