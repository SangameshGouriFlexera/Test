#if !defined _IS_TEMPFILE_DELETER_H_
#define _IS_TEMPFILE_DELETER_H_

//Utility class used to delete any created temp files
class CTempFileDeleter
{
	
public:
    CTempFileDeleter(const stringx& sTempfile)
		: m_sTempFile(sTempfile)
    {        
	}
	
    CTempFileDeleter()
    {        
	}
	
    ~CTempFileDeleter()
    {
		Cleanup();
    }
	
	void Cleanup()
	{
		if(m_sTempFile.length() > 0)
		{
			::DeleteFile(m_sTempFile);
		}
	}
	
	void SetTempFile(const stringx& sTempfile)
	{
		m_sTempFile = sTempfile;
	}

	stringx GetTempFilePath()
	{
		return m_sTempFile;
	}

	void Clear()
	{
		m_sTempFile.erase();
	}
	
private:
    stringx m_sTempFile;
};

#endif