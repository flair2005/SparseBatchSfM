#ifndef PROTOS_HPP_
#define PROTOS_HPP_

#include <Eigen/Dense>
#include <Eigen/Sparse>

struct FeaturePoint {
  Eigen::Vector2d pos;
  Eigen::Vector3i rgb;
};

struct FeatureStruct {
  std::vector<std::vector<FeaturePoint>> feature_point;
  std::vector<std::vector<std::vector<Eigen::Triplet<double>>>> feature_matches;
  Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> skeleton;
};

struct NviewRelationStruct {
  std::vector<FeaturePoint> points;
  Eigen::SparseMatrix<int, Eigen::RowMajor> releation_idx;
};

struct GraphStruct {
  std::vector<int> frame_idx;
  std::vector<Eigen::Matrix<double, 3, 3, Eigen::ColMajor>> K;
  std::vector<Eigen::Matrix<double, 3, 4, Eigen::ColMajor>> Mot;
  Eigen::Matrix<double, 6, Eigen::Dynamic, Eigen::ColMajor> Str; // x, y, z, r, g, b
};

#endif
