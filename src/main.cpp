#include "solver/ConjugateGradientSolver.hpp"

#define PyScript "../src/plotter/run_plotter.sh"

void plot_init()
{
  std::system(PyScript);
}

int main()
{
  // Launch an independent thread for Python script
  std::thread plt_thread(plot_init);
  plt_thread.detach();
 
  // solver object
  ConjugateGradientSolver cgs("testK.txt","testF.txt",3);
  cgs.Solve();
  
  return 0;
}
