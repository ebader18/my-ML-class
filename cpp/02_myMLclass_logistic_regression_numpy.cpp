#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "eigen/Eigen/Dense"

using Eigen::MatrixXd;

class Dataset {
public:
    Dataset(const std::string& outputPath, uint32_t n, uint32_t m)
        : outputPath(outputPath) {    // Constructor initializer list. Directly initialize the member variables of a class
        mat.resize(n, m);
    }

    bool load_File(const std::string& filename) {
        std::cout << "Using " << outputPath << " and " << filename << std::endl;

        mat.load(outputPath + "/" + filename);

        std::cout << "Matrix size: " << mat.size() << std::endl;

        /*std::ifstream file(outputPath + "/" + filename);

        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return false;
        }

        std::string line;
        uint32_t i, j = 0;
        double value;
        while (getline(file, line)) {
            i = 0;
            std::istringstream my_stream(line);
            while (my_stream >> value) {
                mat(j, i) = value;
                i += 1;
            }
            j += 1;
        }

        file.close();

        std::cout << "Dataset size: " << j << " x " << i << std::endl;*/

        return true;
    }

private:
    std::string outputPath; // Declare member variable
    MatrixXd mat;
};

int main() {
    bool result;

    std::string output_path = "C:/_SW/my-ML-class";

    Dataset Ytest(output_path, 1, 1639);
    result = Ytest.load_File("dogs_Ytest.txt");

    /*Dataset Ytrain(output_path, 1, 6553);
    result = Ytrain.load_File("dogs_Ytrain.txt");

    Dataset Xtest(output_path, 12288, 1639);
    result = Xtest.load_File("dogs_Xtest.txt");

    Dataset Xtrain(output_path, 12288, 6553);
    result = Xtrain.load_File("dogs_Xtrain.txt");*/
    
    // std::cout << "Complete" << std::endl;

    /*MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << std::endl;*/

    return 0;
}