#include <omp.h>
#include <Rcpp.h>

// [[Rcpp::export]]
void rcpp_hello_()
{
  int tid, nthreads;
  
  #pragma omp parallel default(shared) private(tid, nthreads)
  {
    tid = omp_get_thread_num();
    nthreads = omp_get_num_threads();
    
    Rcpp::Rcout << "Hello from thread " << tid << " of " << nthreads << std::endl;
  }
}



// [[Rcpp::export]]
double rcpp_sum_(Rcpp::NumericVector x)
{
  double ret = 0;
  
  #pragma omp parallel for default(shared) reduction(+:ret)
  for (int i=0; i<x.size(); i++)
    ret += x[i];
  
  return ret;
}



// [[Rcpp::export]]
Rcpp::NumericMatrix rcpp_sweep_(Rcpp::NumericMatrix x)
{
  Rcpp::NumericMatrix ret(x);
  
  return ret;
}