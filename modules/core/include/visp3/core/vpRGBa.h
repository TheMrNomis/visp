/****************************************************************************
 *
 * This file is part of the ViSP software.
 * Copyright (C) 2005 - 2015 by Inria. All rights reserved.
 *
 * This software is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * ("GPL") version 2 as published by the Free Software Foundation.
 * See the file LICENSE.txt at the root directory of this source
 * distribution for additional information about the GNU GPL.
 *
 * For using ViSP with software that can not be combined with the GNU
 * GPL, please contact Inria about acquiring a ViSP Professional
 * Edition License.
 *
 * See http://visp.inria.fr for more information.
 *
 * This software was developed at:
 * Inria Rennes - Bretagne Atlantique
 * Campus Universitaire de Beaulieu
 * 35042 Rennes Cedex
 * France
 *
 * If you have questions regarding the use of this file, please contact
 * Inria at visp@inria.fr
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Description:
 * RGBA pixel.
 *
 * Authors:
 * Eric Marchand
 * Fabien Spindler
 *
 *****************************************************************************/


#ifndef vpRGBa_h
#define vpRGBa_h

/*!
  \file vpRGBa.h
  \brief Define the object vpRGBa that is used to build color
  images (it define a RGB 32 bits structure, fourth byte is not used)
*/

#include <visp3/core/vpColVector.h>


/*!
  \class vpRGBa

  \ingroup group_core_image

  \brief Class that defines a RGB 32 bits structure.

  Define the object vpRGBa that is used to build color
  images (it define a RGB 32 bits structure, fourth byte is not used)

  \sa vpImage
*/
class VISP_EXPORT vpRGBa
{
public:
  /*!
    Basic constructor.
    
    Build a black value.
    
  */
  inline vpRGBa() : R(0), G(0), B(0), A(0) {};
  
  /*!
    Constructor.
    
    Initialize the color with R, G, B, A values.
    
    \param r : Red value.
    \param g : Green value.
    \param b : Blue value.
    \param a : Additional value.
    
  */
  inline vpRGBa(const unsigned char &r, const unsigned char &g,
    const unsigned char &b, const unsigned char &a=0)
    : R(r), G(g), B(b), A(a) {};


  /*!
    Constructor.
    
    Initialize all the R, G, B, A components to \e v.
    
    \param v : Value to set.
    
  */
  inline vpRGBa(const unsigned char &v) : R(v), G(v), B(v), A(v) {};


  /*!
    Copy constructor.
  */
  inline vpRGBa(const vpRGBa &v) : R(v.R), G(v.G), B(v.B), A(v.A) {};

  /*!
    Create a RGBa value from a 4 dimension column vector.

    R=v[0]
    G=v[1]
    B=v[2]
    A=v[3]
    
  */
  inline vpRGBa(const vpColVector &v) : R(0), G(0), B(0), A(0)
  {
    *this = v;
  };

  // We cannot add here the following destructor without changing the hypothesis that the size of this class is 4.
  // With the destructor it becomes 16 that does break a lot of things arround image conversions
  // virtual ~vpRGBa() {}; // Not to implement

  vpRGBa & operator=(const unsigned char &v) ;
  vpRGBa & operator=(const vpRGBa &v) ;
  vpRGBa & operator=(const vpColVector &v) ;
  bool operator==(const vpRGBa &v);
  bool operator!=(const vpRGBa &v);

  vpColVector operator-(const vpRGBa &v) const;
  vpRGBa operator+(const vpRGBa &v) const;
  vpColVector operator-(const vpColVector &v) const;
  vpColVector operator+(const vpColVector &v) const;
  vpColVector operator*(const float &v) const;
  vpColVector operator*(const double &v) const;

  bool operator<(const vpRGBa &v) const;
  bool operator>(const vpRGBa &v) const;

 public:
  unsigned char R ; //!< Red component.
  unsigned char G ; //!< Green component.
  unsigned char B ; //!< Blue component.
  unsigned char A ; //!< Additionnal component.

  friend VISP_EXPORT vpRGBa operator*(const double &x, const vpRGBa  &rgb);

} ;

#endif

/*
 * Local variables:
 * c-basic-offset: 2
 * End:
 */
