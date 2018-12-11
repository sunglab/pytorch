#define __STDC_FORMAT_MACROS

#include <torch/csrc/python_headers.h>
#ifdef _MSC_VER
#include <Windows.h>
#endif
#include <structmember.h>

#define THP_HOST_HALF

#include <TH/TH.h>
// See Note [TH abstraction violation]
//  - Used to get at the allocator associated with a storage
#include <TH/THStorageFunctions.hpp>
#include <libshm.h>
#include <torch/csrc/THP.h>
#include <torch/csrc/copy_utils.h>
#include <torch/csrc/DynamicTypes.h>

#include <torch/csrc/generic/Storage.cpp>
#include <TH/THGenerateAllTypes.h>

#include <torch/csrc/generic/Storage.cpp>
#include <TH/THGenerateHalfType.h>

template<>
void THPPointer<THStorage>::free() {
  if (ptr) {
    THStorage_free(ptr);
  }
}
