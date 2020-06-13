/*
==================================================

CONJUGATE GRADIENT SOLVER CLASS

AUTHOR : GAUTAM D GHOSH
DATE   : 06/07/2020

==================================================
*/

#include<iostream>
#include<vector>
#include<fstream>
#include<stdlib.h>
#include<time.h>

#include<Eigen/Dense>
#include "../utility/MatrixIO.hpp"

#ifndef CONJUGATEGRADIENTSOLVER
#define CONJUGATEGRADIENTSOLVER

typedef Eigen::MatrixXd DenseMatrix;
typedef Eigen::VectorXd Vector;

class ConjugateGradientSolver
{
 // Constuctor/destructor
  public:
    ConjugateGradientSolver(std::string K_file, std::string F_file, const unsigned total_equations);
   ~ConjugateGradientSolver();
 
 // private vectors/matrices
  private:
    DenseMatrix K;
    Vector d, f, r, u_guess, q;   
  
  // private member variables
  private:
    const double tolerance; 
    const int max_iterations, total_equations;
  
    std::ofstream file_writer; 
   
  // public member functions 
  public:
    void Solve();
    Vector GetSolution() const;
    void PrintSolutionToConsole() const;
    
};

#endif
