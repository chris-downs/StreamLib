// BLOBOutputStream.h: interface for the BLOBOutputStream class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLOBOUTPUTSTREAM_H__C010D93B_B3D6_46DB_B787_E8912CBB140C__INCLUDED_)
#define AFX_BLOBOUTPUTSTREAM_H__C010D93B_B3D6_46DB_B787_E8912CBB140C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace Stream
{

class BLOBOutputStream : public IOutputStream
{
public:
	BLOBOutputStream(Blob<char>& blob);
	virtual ~BLOBOutputStream();

	///Closes this output stream and releases any system resources associated with this stream. 
	virtual void close();
	///Flushes this output stream and forces any buffered output bytes to be written out. 
	virtual void flush();
	///Writes b.length bytes from the specified byte array to this output stream. 
	virtual void write(unsigned char* b,long length);
	///Writes len bytes from the specified byte array starting at offset off to this output stream. 
	virtual void write(unsigned char* b, int off, int len);
	///Writes the specified byte to this output stream. 
	virtual void write(int b);


private:
	Blob<char>& m_blob;
};

} // namespace Stream

#endif // !defined(AFX_BLOBOUTPUTSTREAM_H__C010D93B_B3D6_46DB_B787_E8912CBB140C__INCLUDED_)
