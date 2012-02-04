// __BEGIN_LICENSE__
// Copyright (C) 2006-2011 United States Government as represented by
// the Administrator of the National Aeronautics and Space Administration.
// All Rights Reserved.
// __END_LICENSE__


#ifndef __VW_FILEIO_MEMORYIMAGERESOURCEOPENEXR_H__
#define __VW_FILEIO_MEMORYIMAGERESOURCEOPENEXR_H__

#include <vw/FileIO/MemoryImageResource.h>
#include <boost/noncopyable.hpp>

namespace vw {

  class SrcMemoryImageResourceOpenEXR : public SrcMemoryImageResource, private boost::noncopyable {
    struct Data;
    mutable boost::shared_ptr<Data> m_data;

  public:
    SrcMemoryImageResourceOpenEXR(boost::shared_array<const uint8> buffer, size_t len);

    virtual void read( ImageBuffer const& buf, BBox2i const& bbox ) const;

    virtual ImageFormat format() const;

    virtual bool has_block_read() const  {return false;}
    virtual bool has_nodata_read() const {return false;}
  };

  class DstMemoryImageResourceOpenEXR : public DstMemoryImageResource {
    struct Data;
    boost::shared_ptr<Data> m_data;

  public:
    DstMemoryImageResourceOpenEXR(const ImageFormat& fmt);

    virtual void write( ImageBuffer const& buf, BBox2i const& bbox );
    virtual void flush() {}

    virtual bool has_block_write()  const {return false;}
    virtual bool has_nodata_write() const {return false;}

    virtual const uint8* data() const;
    virtual size_t size() const;
  };
}

#endif//__VW_FILEIO_MEMORYIMAGERESOURCEOPENEXR_H__
