/**
@file	 AudioDecoderAlaw.cpp
@brief   An audio decoder for ITU G.711 A-law
@author  Célestine Gramaize
@date	 2023-06-10

\verbatim
Async - A library for programming event driven applications
Copyright (C) 2003-2008 Tobias Blomberg / SM0SVX

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
\endverbatim
*/



/****************************************************************************
 *
 * System Includes
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Project Includes
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Local Includes
 *
 ****************************************************************************/

#include "AsyncAudioDecoderAlaw.h"



/****************************************************************************
 *
 * Namespaces to use
 *
 ****************************************************************************/

using namespace std;
using namespace Async;



/****************************************************************************
 *
 * Defines & typedefs
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Local class definitions
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Prototypes
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Exported Global Variables
 *
 ****************************************************************************/




/****************************************************************************
 *
 * Local Global Variables
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Public member functions
 *
 ****************************************************************************/

AudioDecoderAlaw::AudioDecoderAlaw(void)
  : frame_len(0)
{

} /* AudioDecoderAlaw::AudioDecoderAlaw */


AudioDecoderAlaw::~AudioDecoderAlaw(void)
{

} /* AudioDecoderAlaw::~AudioDecoderAlaw */


void AudioDecoderAlaw::writeEncodedSamples(void *buf, int size)
{
  unsigned char *ptr = (unsigned char *)buf;
  short decoded_sample, s, m, e;
  float samples[ALAW_FRAME_SAMPLE_CNT];
  
  for (int i=0; i<size && i<ALAW_FRAME_SAMPLE_CNT; ++i)
  {
    s = (short)(ptr[i] & 0x80 >> 7);
    e = (short)(ptr[i] & 0x70 >> 4);
    m = (short)(ptr[i] & 0x0F);
    decoded_sample = ( (s==0) ? 1 :-1 ) * ( min( e, 1)<<5 + m<<1 + 1 )<<( max(e,1)+2 );
    samples[i] = static_cast<float>(decoded_sample) / 32768.0;
  }
  sinkWriteSamples(samples, ALAW_FRAME_SAMPLE_CNT);
} /* AudioDecoderAlaw::writeEncodedSamples */



/****************************************************************************
 *
 * Protected member functions
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Private member functions
 *
 ****************************************************************************/



/*
 * This file has not been truncated
 */
