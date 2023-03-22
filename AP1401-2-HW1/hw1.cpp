#include "hw1.h"

//define sigmoid function
double sigmoid (double z)
{
    return 1.0/(1.0 + std::exp(-z));
}

// define function to read csv files
std::vector<std::shared_ptr<std::vector<double>>> read_csv(std::string filename)
{
    // define output table variable
    std::vector<std::shared_ptr<std::vector<double>>> table;

    // Read from the csv file which is similar to text
    std::ifstream fin(filename);

    // define read line variable
    std::string myLine , myElement;

    // define splitting variable first
    long unsigned int pos;

    // Use a while loop together with the getline() function to read the file line by line
    while (std::getline (fin, myLine)) {
        // define new row
        std::vector<double> row;

        // Split line with comma and make row
        while ((pos = myLine.find(",")) != std::string::npos) {

            // save element string and rest of line
            myElement = myLine.substr(0 , pos);
            myLine = myLine.substr(pos+1 , myLine.size()+1);

            // pusb back double value of saved element
            row.push_back(std::stod(myElement));
        }

        // insert last element to row 
        row.push_back(std::stod(myLine));

        // push back new row
        table.push_back(std::make_shared<std::vector<double>>(row));
    }

    fin.close();

    // return value
    return table;
}

// define a predict function for perceptron single data row and weights
int predict(std::vector<double> X, std::vector<double> weights)
{
    // define output and put bias value in it
    double output {weights[0]};

    // calculate each part of summation and update output value
    for (long unsigned int i = 0; i < weights.size()-1; i++)
        output += weights[i+1]*X[i];

    // effect threshold
    return output >= 0;  
}

// train perceptron net by data table with any learning rate and iteration 
std::vector<double> train(std::vector<std::shared_ptr<std::vector<double>>> train_data, double learning_rate, double num_iter)
{
    // define empty weights
    std::vector<double> weights {};

    // define temp_outputs
    double temp_output;

    // define iterator variable
    long unsigned int i , j , k;
    
    // define temp learning coef
    double temp_coef;

    // initialize weights with 0
    for (i = 0; i < train_data[0]->size(); i++)
    {
        weights.push_back(0.0);
    }

    // start epochs
    for (i = 0; i < num_iter; i++)
    {
        // read each row
        for(j = 0; j < train_data.size(); j++)
        {
            // evaluate perceptron value
            temp_output = predict(*train_data[j] , weights);
            
            // evaluate learning coef
            temp_coef = learning_rate*(train_data[j]->back() - temp_output);
            
            // update weights
            weights[0] += temp_coef;
            for(k = 1; k < weights.size(); k++)
            {
                weights[k] += temp_coef*train_data[j]->at(k-1);
            }
        }
    }

    return weights;
}
