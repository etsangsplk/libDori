// The MIT License (MIT)
//
// Copyright (c) 2016 Jordi Montes Sanabria
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef LIBSTREAM_RECORD_SET_HPP
#define LIBSTREAM_RECORD_SET_HPP


#include <cstdint>
#include <set>
#include <map>
#include <string>

#include "../../utils/hash/hash.hpp"

namespace ls { namespace stream {

class RecordSet {
 public:
  RecordSet(std::uint64_t size_, bool isSampling_=false);

  bool offer(const std::string &str);

  std::uint64_t getSize();
  std::uint64_t getCounter();
  std::uint64_t getRecordCounter();

  std::set<std::string> getSample();

  ~RecordSet();

  private:
    ls::utils::IHasher* hasher;
    
    std::uint64_t size;
    std::uint64_t counter;
    std::uint64_t recordCounter;

    bool isGrowing;
    bool isSampling;

    std::set<std::uint64_t> records;
    std::map<std::uint64_t, std::string> sample;

};

}  // namespace stream
}  // namespace ls

#endif //LIBSTREAM_RECORD_SET_HPP
