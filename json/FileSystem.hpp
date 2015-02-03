#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include<cstdio>
#include<string>
#include"config.hpp"

namespace MEOJ
{
	class FileSystem
	{
	public:
		FileSystem(){}
		~FileSystem(){}
		//�趨�ļ�����
		void setFileContext(const std::string& context)
		{
			fileContext = context;
		}
		//��ȡ�ļ�����
		std::string getFileContext()
		{
			return fileContext;
		}
		//�����ļ�·����ȡ�ļ�����
		bool readFileContext(const char* fileName)
		{
			std::FILE* fp = NIL;
			fp = std::fopen(fileName,"r");
			//��ʱfp��ȻΪnullֵ���ȡ�ļ�ʧ�ܣ�����false
			if(!fp)
			{
				return false;
			}
			fileContext = "";
			while(!std::feof(fp))
			{
				fileContext += std::fgetc(fp);
			}
			if(!!fp)
			{
				std::fclose(fp);
			}
			return true;
		}
		bool writeFileContext(const char* fileName)
		{
			std::FILE* fp = NIL;
			fp = std::fopen(fileName,"w");
			if(!fp)
			{
				return false;
			}
			for(int i = 0;i < fileContext.length(); i++)
			{
				std::fputc(fileContext[i],fp);
			}
			if(!!fp)
			{
				std::fclose(fp);
			}
			return true;
		}
	private:
		std::string fileContext;
	};
}


#endif // FILESYSTEM_HPP
