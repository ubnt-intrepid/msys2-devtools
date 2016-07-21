#include <gurobi_c++.h>
#include <iostream>

int main() {
  try {
    GRBEnv env;
    GRBModel model(env);

    model.optimize();
  } catch (GRBException e) {
    std::cout << e.getErrorCode() << std::endl;
    std::cout << e.getMessage() << std::endl;
  }
}
