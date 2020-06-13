#include "ConjugateGradientSolver.hpp"

ConjugateGradientSolver::ConjugateGradientSolver(std::string K_file, std::string f_file,const unsigned total_equations)
 : tolerance(0.00001),
   max_iterations(total_equations),
   total_equations(total_equations)                                    
{
  std::cout << "================= Initialzing Solver =================\n" << std::endl;
  
  // Allocate memory
  d.resize(this->total_equations,1);
  f.resize(this->total_equations,1);
  r.resize(this->total_equations,1);
  u_guess.resize(this->total_equations,1);
  q.resize(this->total_equations,1);
  
  K.resize(this->total_equations,this->total_equations);
  
  // Load data from text files
  DenseMatIO::ReadAndStoreVector(f_file,f);
  DenseMatIO::ReadAndStoreMatrix(K_file,K);
  
  // Print information to console
  std::cout << "Number of equations = " << total_equations << std::endl;
  std::cout << "Size of K = " << this->total_equations << "x" << this->total_equations << std::endl;
  std::cout << "Size of f = " << this->total_equations << "x" << "1" << std::endl; 
  std::cout << "Taking inital guess as zero vector" << std::endl;
  std::cout << "error tolerance = " << tolerance << "\n" << std::endl;
  
  // for viewing the K and f, only meant for debugging (NOTE: It is not a good idea for huge linear systems)
  #if 0
    std::cout << K << std::endl;
    std::cout << f << std::endl;
  #endif
  
  std::cout << "=============== Initialization Finished ==============\n" << std::endl; 
  
}

ConjugateGradientSolver::~ConjugateGradientSolver()
{
}

void ConjugateGradientSolver::Solve()
{
  unsigned niter;
  clock_t start, end;
  double alpha, beta, rho_new, rho_initial, rho_old, time;
  
  file_writer.open("../src/plotter/coords.csv");
  if(!file_writer.is_open()) throw std::runtime_error("ERROR: Unable to open file!");
  file_writer.clear();
  
  std::cout << "\n================= Execution begin =================\n" << std::endl;
  
  start = clock();
  
  niter = 0;
  r = f - (K * u_guess);
  d = r;
  rho_new     = r.transpose() * r;
  rho_initial = rho_new;
  
  while( niter < max_iterations && rho_new > (tolerance*rho_initial) )
  {
    q       = K * d;
    alpha   = rho_new / ( d.transpose() * q );
    u_guess = u_guess + (alpha * d);
    
    if( (niter % 50) == 0 )
    {
       r = f - (K*u_guess);       
    }
    else
    {
       r = r - (alpha*q);
    }
    
    rho_old = rho_new;
    rho_new = r.transpose() * r;
    
    beta = rho_new / rho_old;
    
    d = r + (beta * d);
    
    niter++;
   
    file_writer << niter << "," << rho_new << "\n";
    file_writer.flush();
  }
  
  end  = clock();
  time = ((double)(end-start))/CLOCKS_PER_SEC;
  printf("\nTime taken is %f seconds\n", time);
  
  #if 1
    printf("\nTotal iterations is %d \n",niter);
  #endif  

  file_writer.close();
  
  std::cout << "\n================== Execution end ==================\n" << std::endl;
}

Vector ConjugateGradientSolver::GetSolution() const
{
  return u_guess;
}

void ConjugateGradientSolver::PrintSolutionToConsole() const
{
  std::cout << u_guess << std::endl;
}















