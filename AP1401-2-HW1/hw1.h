#ifndef HW1_H
#define HW1_H

// primary library files
#include <cmath>    // exp
#include <vector>   // vector
#include <memory>   // shared_ptr
#include <iostream> // cout
#include <iomanip>  // stod string to double
#include <fstream>  // read file

double sigmoid(double z);
std::vector<std::shared_ptr<std::vector<double>>> read_csv(std::string filename); // csv reading function
int predict(std::vector<double> X, std::vector<double> weights); // predict classification result for a single data row
std::vector<double> train(std::vector<std::shared_ptr<std::vector<double>>> train_data, double learning_rate, double num_iter); // train perceptron net

#endif