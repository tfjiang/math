#include <stan/math/prim/mat.hpp>
#include <test/unit/math/prim/mat/typedefs.hpp>
#include <gtest/gtest.h>

TEST(MathMatrix, max) {
  using stan::math::max;
  std::vector<int> n;
  EXPECT_THROW(max(n),std::invalid_argument);
  n.push_back(1);
  EXPECT_EQ(1,max(n));
  n.push_back(2);
  EXPECT_EQ(2,max(n));
  n.push_back(0);
  EXPECT_EQ(2,max(n));
  
  std::vector<double> x;
  EXPECT_FLOAT_EQ(-std::numeric_limits<double>::infinity(),max(x));
  x.push_back(1.0);
  EXPECT_FLOAT_EQ(1.0,max(x));
  x.push_back(0.0);
  EXPECT_FLOAT_EQ(1.0,max(x));
  x.push_back(2.0);
  EXPECT_FLOAT_EQ(2.0,max(x));
  x.push_back(-10.0);
  EXPECT_FLOAT_EQ(2.0,max(x));

  stan::math::vector_d v;
  EXPECT_FLOAT_EQ(-std::numeric_limits<double>::infinity(),max(v));
  v = stan::math::vector_d(1);
  v << 1.0;
  EXPECT_FLOAT_EQ(1.0,max(v));
  v = stan::math::vector_d(2);
  v << 1.0, 0.0;
  EXPECT_FLOAT_EQ(1.0,max(v));
  v = stan::math::vector_d(3);
  v << 1.0, 0.0, 2.0;
  EXPECT_FLOAT_EQ(2.0,max(v));
  v = stan::math::vector_d(4);
  v << 1.0, 0.0, 2.0, -10.0;
  EXPECT_FLOAT_EQ(2.0,max(v));

  stan::math::row_vector_d rv;
  EXPECT_FLOAT_EQ(-std::numeric_limits<double>::infinity(),max(rv));
  rv = stan::math::row_vector_d(1);
  rv << 1.0;
  EXPECT_FLOAT_EQ(1.0,max(rv));
  rv = stan::math::row_vector_d(2);
  rv << 1.0, 0.0;
  EXPECT_FLOAT_EQ(1.0,max(rv));
  rv = stan::math::row_vector_d(3);
  rv << 1.0, 0.0, 2.0;
  EXPECT_FLOAT_EQ(2.0,max(rv));
  rv = stan::math::row_vector_d(4);
  rv << 1.0, 0.0, 2.0, -10.0;
  EXPECT_FLOAT_EQ(2.0,max(rv));

  Eigen::MatrixXd m;
  EXPECT_FLOAT_EQ(-std::numeric_limits<double>::infinity(),max(m));
  m = Eigen::MatrixXd(1,1);
  m << 1.0;
  EXPECT_FLOAT_EQ(1.0,max(m));
  m = Eigen::MatrixXd(2,2);
  m << 1.0, 0.0, 2.0, -10.0;
  EXPECT_FLOAT_EQ(2.0,max(m));
}

TEST(MathMatrix, max_exception) {
  using Eigen::Matrix;
  using Eigen::Dynamic;
  using std::numeric_limits;
  Matrix<double,Dynamic,Dynamic> m;
  Matrix<double,Dynamic,1> v;
  Matrix<double,1,Dynamic> rv;
 
  EXPECT_EQ(-numeric_limits<double>::infinity(),
            stan::math::max(m));
  EXPECT_EQ(-numeric_limits<double>::infinity(),
            stan::math::max(v));
  EXPECT_EQ(-numeric_limits<double>::infinity(),
            stan::math::max(rv));

  Matrix<double,Dynamic,Dynamic> m_nz(2,3);
  Matrix<double,Dynamic,1> v_nz(2);
  Matrix<double,1,Dynamic> rv_nz(3);
  
  EXPECT_NO_THROW(stan::math::max(m_nz));
  EXPECT_NO_THROW(stan::math::max(v_nz));
  EXPECT_NO_THROW(stan::math::max(rv_nz));
}
