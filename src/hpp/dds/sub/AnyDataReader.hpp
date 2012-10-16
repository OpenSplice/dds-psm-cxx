#ifndef OMG_DDS_SUB_ANY_DATA_READER_HPP_
#define OMG_DDS_SUB_ANY_DATA_READER_HPP_

/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Corp.
 * Copyright 2010, Real-Time Innovations, Inc.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <dds/core/Exception.hpp>
#include <dds/core/ref_traits.hpp>
#include <dds/sub/detail/AnyDataReader.hpp>


namespace dds { 
  namespace sub {

    class AnyDataReader;
   
  /**
   * Extracts a typed <code>DataReader</code> from an 
   * <code>AnyDataReader</code>.
   */
    template <typename T>
    DataReader<T> get(const AnyDataReader& adr);
  }
}

class dds::sub::AnyDataReader {
public:
    template <typename T>
    AnyDataReader(const dds::sub::DataReader<T>& dr);

    inline const detail::DRHolderBase* operator->() const;

    inline detail::DRHolderBase* operator->();


public:
    inline AnyDataReader& swap(AnyDataReader& rhs);

    template <typename T>
    AnyDataReader& operator =(const DataReader<T>& rhs);

    inline AnyDataReader& operator =(AnyDataReader rhs);

public:
    /**
     * Get a typed <code>DataReader</code> from this.
     */
    template <typename T>
    dds::sub::DataReader<T> get();

private:
    dds::core::smart_ptr_traits<detail::DRHolderBase>::ref_type holder_;
};

#endif /* OMG_DDS_SUB_ANY_DATA_READER_HPP_ */
