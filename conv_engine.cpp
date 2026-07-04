#include <iostream>
#include <vector>
using namespace std;

void conv2d(vector<vector<float>>& img,
            vector<vector<float>>& kernel,
            vector<vector<float>>& out) {

    int n = img.size();
    int k = kernel.size();

    for (int i = 0; i < n - k; i++) {
        for (int j = 0; j < n - k; j++) {

            float sum = 0;

            for (int ki = 0; ki < k; ki++) {
                for (int kj = 0; kj < k; kj++) {
                    sum += img[i + ki][j + kj] * kernel[ki][kj];
                }
            }

            out[i][j] = sum;
        }
    }
}

int main() {

    vector<vector<float>> img(64, vector<float>(64, 1.0));

    vector<vector<float>> kernel = {
        {1, 0, -1},
        {1, 0, -1},
        {1, 0, -1}
    };

    vector<vector<float>> out(64, vector<float>(64, 0));

    conv2d(img, kernel, out);

    cout << "Conv complete | Sample: " << out[10][10] << endl;
}
