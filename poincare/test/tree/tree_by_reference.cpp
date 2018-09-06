#include <quiz.h>
#include <poincare.h>
#include <assert.h>

#include "helpers.h"

using namespace Poincare;

QUIZ_CASE(tree_by_reference_are_discared_after_block) {
  int initialPoolSize = pool_size();
  {
    BlobByReference b(0);
    assert_pool_size(initialPoolSize+1);
  }
  assert_pool_size(initialPoolSize);
}

static void make_temp_blob() {
  BlobByReference b(5);
}
QUIZ_CASE(tree_by_reference_are_discared_after_function_call) {
  int initialPoolSize = pool_size();
  make_temp_blob();
  assert_pool_size(initialPoolSize);
}

QUIZ_CASE(tree_by_reference_can_be_copied) {
  int initialPoolSize = pool_size();
  BlobByReference b(123);
  assert_pool_size(initialPoolSize+1);
  TreeByReference t = b;
  assert_pool_size(initialPoolSize+1);
}

static TreeByReference blob_with_data_3() {
  return BlobByReference(3);
}

QUIZ_CASE(tree_by_reference_can_be_returned) {
  int initialPoolSize = pool_size();
  TreeByReference b = blob_with_data_3();
  assert_pool_size(initialPoolSize+1);
}

//TODO QUIZ_CASE(tree_by_reference_allocation_failures) {

QUIZ_CASE(tree_by_reference_does_not_copy) {
  int initialPoolSize = pool_size();
  BlobByReference b1(1);
  BlobByReference b2(2);
  assert_pool_size(initialPoolSize+2);
  PairByReference p(b1, b2);
  assert_pool_size(initialPoolSize+3);
  PairByReference p2 = p;
  assert_pool_size(initialPoolSize+3);
}