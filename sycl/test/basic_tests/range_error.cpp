// RUN: %clang -std=c++11 -Xclang -verify %s -Xclang -verify-ignore-unexpected=note,warning -fsyntax-only
//==--------------- range_error.cpp - SYCL range error test ----------------==//
//
// The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include <CL/sycl.hpp>
#include <iostream>
#include <cassert>

using namespace std;
int main() {
  cl::sycl::range<1> one_dim_range(64);
  cl::sycl::range<2> two_dim_range(64, 1);
  cl::sycl::range<3> three_dim_range(64, 1, 2);
  assert(one_dim_range.size() ==64);
  assert(one_dim_range.get(0) ==64);
  assert(one_dim_range[0] ==64);
  cout << "one_dim_range passed " << endl;
  assert(two_dim_range.size() ==64);
  assert(two_dim_range.get(0) ==64);
  assert(two_dim_range[0] ==64);
  assert(two_dim_range.get(1) ==1);
  assert(two_dim_range[1] ==1);
  cout << "two_dim_range passed " << endl;
  assert(three_dim_range.size() ==128);
  assert(three_dim_range.get(0) ==64);
  assert(three_dim_range[0] ==64);
  assert(three_dim_range.get(1) ==1);
  assert(three_dim_range[1] ==1);
  assert(three_dim_range.get(2) ==2);
  assert(three_dim_range[2] ==2);
  cout << "three_dim_range passed " << endl;
  cl::sycl::range<1> one_dim_range_f1(64, 2, 4);//expected-error {{no matching constructor for initialization of 'cl::sycl::range<1>'}}
  cl::sycl::range<2> two_dim_range_f1(64);//expected-error {{no matching constructor for initialization of 'cl::sycl::range<2>'}}
}
