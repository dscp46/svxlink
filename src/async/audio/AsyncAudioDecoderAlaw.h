/**
@file	 AsyncAudioDecoderAlaw.h
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

#ifndef ASYNC_AUDIO_DECODER_ALAW_INCLUDED
#define ASYNC_AUDIO_DECODER_ALAW_INCLUDED


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

#include <AsyncAudioDecoder.h>


/****************************************************************************
 *
 * Local Includes
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Forward declarations
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Namespace
 *
 ****************************************************************************/

namespace Async
{


/****************************************************************************
 *
 * Forward declarations of classes inside of the declared namespace
 *
 ****************************************************************************/

  

/****************************************************************************
 *
 * Defines & typedefs
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Exported Global Variables
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Class definitions
 *
 ****************************************************************************/

/**
@brief	An audio decoder for ITU G.711 A-law
@author Célestine Gramaize
@date   2023-06-10

This class implements an audio decoder that converts A-law frames into
the native sample format.
*/
class AudioDecoderAlaw : public AudioDecoder
{
  public:
    /**
     * @brief 	Default constuctor
     */
    AudioDecoderAlaw(void);
  
    /**
     * @brief 	Destructor
     */
    virtual ~AudioDecoderAlaw(void);
  
    /**
     * @brief   Get the name of the codec
     * @returns Return the name of the codec
     */
    virtual const char *name(void) const { return "ALAW"; }
  
    /**
     * @brief 	A_brief_member_function_description
     * @param 	param1 Description_of_param1
     * @return	Return_value_of_this_member_function
     */
    
    /**
     * @brief 	Write encoded samples into the decoder
     * @param 	buf  Buffer containing encoded samples
     * @param 	size The size of the buffer
     */
    virtual void writeEncodedSamples(void *buf, int size);
    

  protected:
    
  private:
    static const int ALAW_FRAME_SAMPLE_CNT = 320;
    
    unsigned char *frame;
    int       frame_len;
    
    AudioDecoderAlaw(const AudioDecoderAlaw&);
    AudioDecoderAlaw& operator=(const AudioDecoderAlaw&);
    
};  /* class AudioDecoderAlaw */


} /* namespace */

#endif /* ASYNC_AUDIO_DECODER_ALAW_INCLUDED */



/*
 * This file has not been truncated
 */

