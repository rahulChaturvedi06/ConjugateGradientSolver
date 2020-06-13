#include "MatrixIO.hpp"

void DenseMatIO::ReadAndStoreMatrix(std::string& filename, Eigen::MatrixXd& K)
{
  int row = K.rows();
  double value;
  std::ifstream file;
  
  file.open(path_testcases+filename);
  if(!file.is_open()) throw std::runtime_error(filename + " could not be opened!");
  
  int ii = 0;
  int jj = 0;
  while(file >> value)
  {
    if( jj == row  )
    {
      jj = 0;
      ii++;    
    }
    K(ii,jj) = value;
    jj++;
  }
  file.close();
}

void DenseMatIO::ReadAndStoreVector(std::string& filename, Eigen::VectorXd& F)
{
  double value;
  std::ifstream file;
  
  file.open(path_testcases+filename);
  if(!file.is_open()) throw std::runtime_error(filename + " could not be opened!");
  int ii = 0;
  while(file >> value)
  {
    F(ii,0) = value;
    ii++;
  }
  file.close();
  
}

void DenseMatIO::WriteToFile()
{

}
