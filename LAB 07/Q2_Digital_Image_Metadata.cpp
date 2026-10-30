#include <iostream>
#include <string>
using namespace std;

class Image {
protected:
    int width, height;

public:
    Image(int w, int h) {
        width = w;
        height = h;
    }
};

class CompressedImage : public Image {
protected:
    double compressionRatio;

public:
    CompressedImage(int w, int h, double ratio)
        : Image(w, h) {
        compressionRatio = ratio;
    }
};

class EncryptedImage : public CompressedImage {
private:
    string algorithm;

public:
    EncryptedImage(int w, int h, double ratio, string algo)
        : CompressedImage(w, h, ratio) {
        algorithm = algo;
    }

    void displayMetadata() {
        long long originalPixels = 1LL * width * height;
        double effectivePixels = originalPixels * compressionRatio / 100.0;

        cout << "Image Width: " << width << " pixels" << endl;
        cout << "Image Height: " << height << " pixels" << endl;
        cout << "Original Pixel Count: " << originalPixels << endl;
        cout << "Compression Ratio: " << compressionRatio << "%" << endl;
        cout << "Effective Pixel-equivalent Size: " << effectivePixels << endl;
        cout << "Encryption Algorithm: " << algorithm << endl;
    }
};

int main() {
    EncryptedImage img(1920, 1080, 50, "abc");
    img.displayMetadata();
    return 0;
}