/* Copyright (C) 2003 MySQL AB

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA */

#ifndef INDX_ATTRINFO_HPP
#define INDX_ATTRINFO_HPP

#include "SignalData.hpp"

class IndxAttrInfo {
  /**
   * Sender(s)
   */
  friend class NdbIndexOperation;
  
  /**
   * Receiver(s)
   */
  friend class Dbtc;
  
  friend bool printINDXATTRINFO(FILE *, const Uint32 *, Uint32, Uint16);
  
public:
  STATIC_CONST( HeaderLength = 3 );
  STATIC_CONST( DataLength = 22 );
  STATIC_CONST( MaxSignalLength = HeaderLength + DataLength);

  // Public methods
public:
 Uint32* getData() const;

private:
  Uint32 connectPtr;
  Uint32 transId[2];
  Uint32 attrData[DataLength];
};

inline
Uint32* IndxAttrInfo::getData() const
{
  return (Uint32*)&attrData[0];
}

#endif
