#include <stan/math/prim/mat.hpp>
#include <gtest/gtest.h>

TEST(MathMatrix,mdivide_right_spd_val) {
  using stan::math::mdivide_right_spd;
  Eigen::MatrixXd Ad(2,2);
  Eigen::MatrixXd I;

  Ad << 2.0, 3.0, 
        3.0, 7.0;

  I = mdivide_right_spd(Ad,Ad);
  EXPECT_NEAR(1.0,I(0,0),1.0E-12);
  EXPECT_NEAR(0.0,I(0,1),1.0E-12);
  EXPECT_NEAR(0.0,I(1,0),1.0E-12);
  EXPECT_NEAR(1.0,I(1,1),1.0e-12);
}
