#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

#include<Eigen/Dense>

#ifndef MATRIXIO_HPP
#define MATRIXIO_HPP

static const std::string path_testcases = "../src/testcases/";

namespace DenseMatIO
{
  void ReadAndStoreMatrix(std::string& filename, Eigen::MatrixXd& K ); // Reads data from text file and stores in a dense eigen matrix
  void ReadAndStoreVector(std::string& filename, Eigen::VectorXd& F ); // Reads data from text file and stores in a dense eigen vector
  void WriteToFile();                                                  // Writes entries of a matrix into a text file
}

namespace SparseMatIO
{

}

#endif
