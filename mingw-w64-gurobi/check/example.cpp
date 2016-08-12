#include <gurobi_c++.h>
#include <iostream>
#include <cassert>
#include <boost/filesystem.hpp>
using namespace std;
namespace fs = boost::filesystem;

int main() {
  fs::remove(fs::path("example.log"));

  try {
    GRBEnv env("example.log");
    GRBModel model(env);
    model.set(GRB_StringAttr_ModelName, "model1");

    auto x = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "x");
    auto y = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "y");
    auto z = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "z");
    model.update();

    model.setObjective(x + 2.0 * y + z, GRB_MINIMIZE);

    model.addConstr(x + y + z <= 2.0, "c0");
    model.addConstr(x + y == 1.0, "c1");

    model.optimize();

    assert(model.get(GRB_DoubleAttr_ObjVal) == 1.0);
    assert(x.get(GRB_DoubleAttr_X) == 1);
    assert(y.get(GRB_DoubleAttr_X) == 0);
    assert(z.get(GRB_DoubleAttr_X) == 0);

  } catch (GRBException e) {
    cout << e.getErrorCode() << endl;
    cout << e.getMessage() << endl;
    return 1;
  }

  assert(fs::exists(fs::path("example.log")));
}
