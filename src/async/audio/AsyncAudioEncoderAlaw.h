/**
@file	 AsyncAudioEncoderAlaw.h
@brief   An audio encoder that encodes to ITU G.711 A-law
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

#ifndef ASYNC_AUDIO_ENCODER_ALAW_INCLUDED
#define ASYNC_AUDIO_ENCODER_ALAW_INCLUDED


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

#include <AsyncAudioEncoder.h>


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
@brief	An audio encoder that encodes to ITU G.711 A-law
@author Célestine Gramaize
@date   2023-06-10

This class implements an audio encoder that converts the native sample
format to A-law audio blocks.
*/
class AudioEncoderAlaw : public AudioEncoder
{
  public:
    /**
     * @brief 	Default constuctor
     */
    AudioEncoderAlaw(void);
  
    /**
     * @brief 	Destructor
     */
    virtual ~AudioEncoderAlaw(void);
  
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
     * @brief 	Write samples into this audio sink
     * @param 	samples The buffer containing the samples
     * @param 	count The number of samples in the buffer
     * @return	Returns the number of samples that has been taken care of
     *
     * This function is used to write audio into this audio sink. If it
     * returns 0, no more samples should be written until the resumeOutput
     * function in the source have been called.
     * This function is normally only called from a connected source object.
     */
    virtual int writeSamples(const float *samples, int count);
    
    
  protected:
    
  private:
    static const int ALAW_FRAME_SAMPLE_CNT = 320; // 40ms
    static const int ALAW_FRAME_COUNT      = 4;
    static const int ALAW_BUF_SIZE     = ALAW_FRAME_COUNT * ALAW_FRAME_SAMPLE_CNT;
    
    unsigned char  alaw_buf[ALAW_BUF_SIZE];
    int         alaw_buf_len;
    
    AudioEncoderAlaw(const AudioEncoderAlaw&);
    AudioEncoderAlaw& operator=(const AudioEncoderAlaw&);
    
};  /* class AudioEncoderAlaw */


} /* namespace */

#endif /* ASYNC_AUDIO_ENCODER_ALAW_INCLUDED */



/*
 * This file has not been truncated
 */

